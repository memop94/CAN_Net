/*
 * APP_Basic_Enhanced_Cmd_Telltale.h
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
 * $Source: APP_Basic_Enhanced_Cmd_Telltale.h
 * $Revision: 22
 * $Author: Guillermo Ramirez, Oscar Miranda
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
/*                     |        PSS_ACU     |     22                          */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: APP_Basic_Enhanced_Cmd_Telltale.h
  ============================================================================*/

#ifndef APP_BASIC_ENHANCED_CMD_TELLTALE_H_
#define APP_BASIC_ENHANCED_CMD_TELLTALE_H_

/* Includes */
/*============================================================================*/
//#include "stdtypedef.h"
#include "BIOS\BIOS_GPIO.h"
#include "APPLICATION\APP_Sensors_Flags.h"

/* Constants and types */
/*============================================================================*/


#define TIMEOUT_ENABLED 0
#define FLASH_PERIOD 5

extern enum CMDTELLTALE
{
	E_FLASHING,
	E_CONTINUOUS_ON,
	E_OFF, 
	E_CMD_ERROR
};

/* Exported Variables */
/*============================================================================*/
extern T_UBYTE rub_ON_Timer;
extern T_UBYTE rub_FlashingTime;

/* Exported functions prototypes */
/*============================================================================*/

void cmd_Telltale_StMach(void);

#endif /* APP_BASIC_ENHANCED_CMD_TELLTALE_H_ */
