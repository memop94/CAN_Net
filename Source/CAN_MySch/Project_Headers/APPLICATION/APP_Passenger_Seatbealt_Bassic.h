/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * Source: APP_Passenger_Seatbealt.h
 * Revision:  
 * Author: GuillermoFrancisco
 * Date: Jan 13, 2016
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
 * Log: APP_Passenger_Seatbealt.h
  ============================================================================*/
#ifndef APP_PASSENGER_SEATBEALT_H_
#define APP_PASSENGER_SEATBEALT_H_


/* Includes */
/*============================================================================*/
#include "typedefs.h"
#include "APPLICATION/APP_Sensors_Flags.h"

/* Constants and types */
/*============================================================================*/
#define SAMPLE_TIME 20
#define SB_VALID 5
#define S_VALID 6

extern enum STATES
{
	FASTENED_NOT_OCCUPIED,
	UNFASTENED_OCCUPIED,
	CONTINUOUS_INDICATION,
	FLASHING,
	CONTINUOUS,
	NO_INDICATION
};

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void BasicReminder_PSR (void);
void Unfastened_Occupies_StateMachine(void);
void P_SB_SensorState (void);
void P_S_SensorState (void);

#endif /* APP_PASSENGER_SEATBEALT_H_ */

/* Notice: the file ends with a blank new line to avoid compiler warnings */
