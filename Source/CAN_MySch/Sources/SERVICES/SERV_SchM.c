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
#include "MemAlloc.h"

/********************************************************************************
	Defines
********************************************************************************/


/********************************************************************************
	Type Definitions
********************************************************************************/


/********************************************************************************
	Variable Declarations
********************************************************************************/

SchM_ControlType SchMControl;
SchM_TaskControlBlockType *SchMTaskControlBlock;
const SchM_ConfigType *SchMConfigGlob;

/********************************************************************************
	Private Functions
********************************************************************************/

void SchM_OsTick(void)
{
	u8 TaskIdx;
	u8 TaskMark;
	
	SchMControl.SchMCounter++;
	
	for(TaskIdx = 0; TaskIdx < SchMConfigGlob->SchMNumberOfTasks; TaskIdx++)	
	{
		TaskMark = SchMControl.SchMCounter & SchMConfigGlob->SchMTaskDescriptor[TaskIdx].SchMTaskMask;
		if (TaskMark == SchMConfigGlob->SchMTaskDescriptor[TaskIdx].SchMTaskOffset) //SchMConfigGlob->SchMTaskDescriptor[TaskIdx].SchMTaskMask) //
		{
			/* Mark TaskID to Run */
			SchMTaskControlBlock[TaskIdx].SchMTaskState = SCHM_TASK_STATE_READY;
		}
	}
	
}

void SchM_Background(void)
{	
	u8 TaskIdx;
	/* Infinite Loop */
	for(;;)
	{
		for(TaskIdx = 0; TaskIdx < SchMConfigGlob->SchMNumberOfTasks; TaskIdx++)
		{
			if ( SCHM_TASK_STATE_READY == SchMTaskControlBlock[TaskIdx].SchMTaskState )
			{
				/* Execute Task */
				SchMControl.SchMTaskRunning = SchMConfigGlob->SchMTaskDescriptor[TaskIdx].SchMTaskId;
				SchMTaskControlBlock[TaskIdx].SchMTaskState = SCHM_TASK_STATE_RUNNING;
				SchMControl.SchMStatus = SCHM_RUNNING;
				SchMTaskControlBlock[TaskIdx].TaskFunctionControlPtr();
				SchMTaskControlBlock[TaskIdx].SchMTaskState = SCHM_TASK_STATE_SUSPENDED;
				SchMControl.SchMStatus = SCHM_IDLE;
			}
		}
	}
}

/********************************************************************************
	Public Functions
********************************************************************************/

void SchM_Init(const SchM_ConfigType *SchMConfigParam)
{
	u8 TaskIdx;
	SchMConfigGlob = SchMConfigParam;
		/* PIT initialization and Configuration */
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);	
	SchMTaskControlBlock = (SchM_TaskControlBlockType*)MemAlloc(sizeof(SchM_TaskControlBlockType)*SchMConfigGlob->SchMNumberOfTasks);
	for(TaskIdx = 0; TaskIdx < SchMConfigGlob->SchMNumberOfTasks; TaskIdx++)
	{
		SchMTaskControlBlock[TaskIdx].SchMTaskState = SCHM_TASK_STATE_SUSPENDED;
		SchMTaskControlBlock[TaskIdx].TaskFunctionControlPtr = SchMConfigGlob->SchMTaskDescriptor[TaskIdx].TaskFunctionPtr;
	}
	SchMControl.SchMStatus = SCHM_INIT;
}

void SchM_Start(void)
{
    PIT_channel_start(PIT_CHANNEL_0);
    SchMControl.SchMStatus = SCHM_IDLE;
    SchM_Background();
}

void SchM_Stop(void)
{

    PIT_channel_stop(PIT_CHANNEL_0);
    SchMControl.SchMStatus = SCHM_HALTED;
}
