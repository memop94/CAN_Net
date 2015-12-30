/*******************************************************************************/
/**
\file       SchM.h
\brief      SchM header file
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
#ifndef __SchM_H
#define __SchM_H

/* MCU-specific derivative */
#include "MCU_derivative.h" 

#include "SERVICES/SERV_SchM_Types.h"
#include "SERVICES/SERV_SchM_Tasks.h"

/* Constants and types */
/*============================================================================*/
extern enum{
	E_TASK1, 
	E_TASK2,
	E_TASK3,
	/*DO NOT MODIFIED OR ERASE*/
	E_TASK_NUM
	
};


/* Exported Variables */
/*============================================================================*/

typedef struct {
	void(* rp_Tasks)(void); /*Pointer that'll call the task*/
	T_ULONG rul_Period; 	/*Period of task*/
    T_ULONG rul_Offset; 	/*Offset of task*/
}S_TASK;

/* Exported functions prototypes */
/*============================================================================*/
void kernel (void);

extern void SchM_Init(void);

/* Tick Interrupt  */
void TickFlag( void  );


#endif /* __SchM_H */
