/*
 * APP_SBR_Driver.h
 *
 *  Created on: Jan 12, 2016
 *      Author: x
 */

/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: APP_SBR_Driver.h
 * $Revision: 22
 * $Author: Guillermo Ramírez, Oscar Miranda
 * $Date: Jan/12th/2016
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
 * $Log: APP_SBR_Driver.h
  ============================================================================*/
#ifndef APP_SBR_DRIVER_H_
#define APP_SBR_DRIVER_H_

/* Includes */
/*============================================================================*/
#include "APPLICATION\APP_Basic_Enhanced_Cmd_Telltale.h"

/* Constants and types */
/*============================================================================*/
/*Maximum speed in km/h*/
#define MAX_SPEED 22

/*Maximum distance in m*/
#define MAX_DISTANCE 250
/*Maximum time in seconds*/
#define MAX_TIME_ENH_2 850

/*Maximum time in seconds*/
#define MAX_TIME_ENH_3 235
#define TRUE 1
#define FALSE 0
#define OPEN 0

#define SAMPLE_TIME 20
#define SB_VALID 5
#define S_VALID 6

extern enum ENHANCED
{
	E_ENH_1,
	E_ENH_2,
	E_ENH_3
};

extern enum EURO
{
	E_EURO_1,
	E_EURO_2,
	E_EURO_3
};

/* Exported Variables */
/*============================================================================*/

extern T_ULONG rul_TimeDelay;
extern T_UBYTE rub_VehicleSpeed;
extern T_UBYTE rub_Distance;
extern T_UBYTE rub_EngineActive;
extern T_UBYTE rub_Door;

/* Exported functions prototypes */
/*============================================================================*/
void cmdEuroSequence(void);
void BasicReminder(void);
void EnhancedReminder(void);
void EuroReminder(void);
void Driver_SB_SensorState(void);

#endif /* APP_SBR_DRIVER_H_ */
