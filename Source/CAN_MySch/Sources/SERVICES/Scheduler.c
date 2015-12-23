/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Scheduler.c $
 * $Revision: 28 $
 * $Author: Guillermo Ramírez Vázquez, Óscar Francisco Miranda García
 * $Date: 08/12/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "SERVICES\Scheduler.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/

const S_TASK cas_TaskList[E_TASK_NUM] = {
  /*{Task, 				 Period , Offset}*/
	{SchM_3p125ms_Task	, 	3	, 	0},
	{SchM_6p25ms_Task  	, 	6	, 	1},
	{SchM_12p5ms_Task	, 	12	, 	2},
	{SchM_25ms_Task  	, 	25	, 	3},
	{SchM_50ms_Task		, 	50	, 	5},
	{SchM_100ms_Task  	, 	100	, 	6}
};

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/
/*============================================================================*/
/* ---------------------------- DO NOT MODIFIED ----------------------------- */
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
	 *							will be active and will stablish the period of the 
	 *							task and will call it using the pointer previously defined. 
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------*/
	for (rul_Index = 0; rul_Index < E_TASK_NUM; rul_Index ++){
		raul_NTask[rul_Index] = cas_TaskList[rul_Index].rul_Offset;
	}
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

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

