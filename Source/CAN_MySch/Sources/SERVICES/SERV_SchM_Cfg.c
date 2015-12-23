/*******************************************************************************/
/**
\file       SchM_Cfg.c
\brief      SchM Configuration
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/

#include "SERVICES/SERV_SchM_Cfg.h"
#include "SERVICES/SERV_SchM_Tasks.h"


const SchM_TaskDescriptorType SchMTaskDescConfig [] =
{
    /* Offset,  Mask,		  Task ID,		Function Pointer */
	{ 0, SCHM_MASK_3P125MS, SCHM_TASKID_3P125MS, SchM_3p125ms_Task	},
	{ 1, SCHM_MASK_6P25MS,  SCHM_TASKID_6P25MS,  SchM_6p25ms_Task	},
	{ 2, SCHM_MASK_12P5MS,  SCHM_TASKID_12P5MS,  SchM_12p5ms_Task	},
	{ 3, SCHM_MASK_25MS,  	SCHM_TASKID_25MS,  	 SchM_25ms_Task		},
	{ 5, SCHM_MASK_50MS,  	SCHM_TASKID_50MS,  	 SchM_50ms_Task		},
	{ 6, SCHM_MASK_100MS,  	SCHM_TASKID_100MS,   SchM_100ms_Task	}
};

const SchM_ConfigType SchMConfig =
{
	(sizeof(SchMTaskDescConfig)/sizeof(SchMTaskDescConfig[0])),
	SchMTaskDescConfig
};
