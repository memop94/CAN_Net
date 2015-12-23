/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Scheduler.h $
 * $Revision: 18 $
 * $Author: Guillermo Ramírez Vázquez, Óscar Francisco Miranda García
 * $Date: 12/06/2015 $
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
 * $Log: filename.h  $
  ============================================================================*/
#ifndef SCHEDULER_H_
#define SCHEDULER_H_


/* Includes */
/*============================================================================*/
#include "BIOS\BIOS_sysinit.h"
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
T_ULONG rul_Count;
T_ULONG rul_Index;
T_ULONG raul_NTask[E_TASK_NUM];
T_UBYTE rub_TickFlag;

typedef struct {
	void(* rp_Tasks)(void); /*Pointer that'll call the task*/
	T_ULONG rul_Period; 	/*Period of task*/
    T_ULONG rul_Offset; 	/*Offset of task*/
}S_TASK;

/* Exported functions prototypes */
/*============================================================================*/
void kernel (void);

#endif /* SCHEDULER_H_ */

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
