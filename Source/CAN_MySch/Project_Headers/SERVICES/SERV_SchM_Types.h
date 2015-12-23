/*******************************************************************************/
/**
\file       SchM_Types.h
\brief      SchM Types
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
#ifndef __SchM_TYPES_H
#define __SchM_TYPES_H

#include "typedefs.h"

typedef void (*SchM_TaskFunctionPtrType)(void);
typedef u8 SchM_TaskOffsetType;
typedef u8 SchM_CounterType;
typedef u8 SchM_NumberOfTasks;


typedef enum
{
	SCHM_MASK_3P125MS	=	0x03,
	SCHM_MASK_6P25MS 	=	0x07,
	SCHM_MASK_12P5MS 	= 	0x0F,
	SCHM_MASK_25MS  	=	0x1F,
	SCHM_MASK_50MS  	=	0x3F,
	SCHM_MASK_100MS 	=	0x7F
}SchM_TaskMaskType;

typedef enum
{
	SCHM_TASKID_BKG,
	SCHM_TASKID_3P125MS,
	SCHM_TASKID_6P25MS,
	SCHM_TASKID_12P5MS,
	SCHM_TASKID_25MS,
	SCHM_TASKID_50MS,
	SCHM_TASKID_100MS
}SchM_TaskIDType;

typedef enum
{
	SCHM_TASK_STATE_SUSPENDED,
	SCHM_TASK_STATE_READY,
	SCHM_TASK_STATE_RUNNING
}SchM_TaskStateType;

typedef enum
{
	SCHM_UNINIT,
	SCHM_INIT,
	SCHM_IDLE,
	SCHM_RUNNING,
	SCHM_OVERLOAD,
	SCHM_HALTED
}SchM_SchedulerStateType;

typedef struct
{
	SchM_TaskStateType SchMTaskState;
	SchM_TaskFunctionPtrType TaskFunctionControlPtr;
}SchM_TaskControlBlockType;

typedef struct
{
	SchM_CounterType SchMCounter;
	SchM_TaskIDType SchMTaskRunning;
	SchM_SchedulerStateType SchMStatus;
}SchM_ControlType;

typedef struct
{
	SchM_TaskOffsetType SchMTaskOffset;
	SchM_TaskMaskType SchMTaskMask;
	SchM_TaskIDType SchMTaskId;
	SchM_TaskFunctionPtrType TaskFunctionPtr;
}SchM_TaskDescriptorType;

typedef struct
{
	SchM_NumberOfTasks SchMNumberOfTasks;
	const SchM_TaskDescriptorType *SchMTaskDescriptor;
}SchM_ConfigType;

#endif