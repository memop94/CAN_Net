/*******************************************************************************/
/**
\file       SchM.c
\brief      Main SchM functionality
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
#include "SERVICES/SERV_SchM.h"

/********************************************************************************
	Includes
********************************************************************************/
#include "BIOS/BIOS_PIT.h"
#include 	"SERVICES/SERV_IntcInterrupts.h"
/********************************************************************************
	Defines
********************************************************************************/


/********************************************************************************
	Type Definitions
********************************************************************************/


/********************************************************************************
	Variable Declarations
********************************************************************************/
T_ULONG rul_Count;
T_ULONG rul_Index;
T_ULONG raul_NTask[E_TASK_NUM];
T_UBYTE rub_TickFlag;

/*Tasks definition*/
const S_TASK cas_TaskList[E_TASK_NUM] = {
  /*{Task, 				 Period , Offset}*/
	{SchM_6p25ms_Task  	, 	6	, 	1},
	{SchM_12p5ms_Task	, 	12	, 	2}, 
	{SchM_25ms_Task  	, 	25	, 	3},
};

/********************************************************************************
	Private Functions
********************************************************************************/


/********************************************************************************
	Public Functions
********************************************************************************/

void SchM_Init(void)
{
	/* ------------------------------------------------------------------------
	 *  Name                 :	SchM_Init
	 *  Description          :  PIT module and interrupt are enabled.
	 *  						Tick flag is initialized.  
	 *  						Also the offset of every task is assigned.
	 *   
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------*/
	
	/* PIT initialization and Configuration */
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0);	
    
    /* Install Interrupt routine of PIT channel 0 as the Tick of the scheduler*/
    INTC_InstallINTCInterruptHandler(&TickFlag,59,5);
    
    /*Flag of TickFlag() interrupt is initialized*/
    rub_TickFlag = 0;
    
    /*The offset of every task is initialized*/
	for (rul_Index = 0; rul_Index < E_TASK_NUM; rul_Index ++){
		raul_NTask[rul_Index] = cas_TaskList[rul_Index].rul_Offset;
	}
	
	/*Enable PIT Timer*/
	PIT_channel_start(PIT_CHANNEL_0);
}

void kernel (void){
	/* ------------------------------------------------------------------------
	 *  Name                 :	kernel
	 *  Description          :  This function starts by doing an indexing of the 
	 *  						task, assigning the offset. This process occurs 
	 *  						only once in each execution of the code.
	 *							Then an infinite loop starts, the tick of the 
	 *							scheduler is defined by a flag called ub_TickFlag, 
	 *							which was configured to raise every millisecond. 
	 *							Once it was acquired it is restarted to zero. 
	 *							Now, inside the if there is a for cycle which who 
	 *							through all the task accessing to their offset with 
	 *							and if, whenever the offset is over zero it will 
	 *							decrease, for every task. When one of the offset, 
	 *							of whichever task, reach zero, the else of the if 
	 *							will be active and will establish the period of the 
	 *							task and will call it using the pointer previously defined. 
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------*/
		/* Loop Forever */
		while (1) {
			if (rub_TickFlag){
				rub_TickFlag = 0;
				for(rul_Count = 0; rul_Count < E_TASK_NUM; rul_Count++){
					if (raul_NTask[rul_Count] > 0){
						raul_NTask[rul_Count]--;
					}
					else{
						raul_NTask[rul_Count] = cas_TaskList[rul_Count].rul_Period;
						cas_TaskList[rul_Count].rp_Tasks();
					}
				}
			}
			else{}
		}
	
/* ---------------------------- DO NOT MODIFIED ----------------------------- */
}

void TickFlag(void)
{
	/* ------------------------------------------------------------------------
	 *  Name                 :	TickFlag
	 *  Description          :  This interrupt sets  the tick flag rub_TickFlag 
	 *  						to tell the scheduler a tick has occurred. 
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------*/
  if (PIT.CH[0].TFLG.B.TIF)
  {
    /* Clear the time-base interrupt flag */
    PIT.CH[0].TFLG.B.TIF = 1;
    rub_TickFlag = 1;

  }
}
