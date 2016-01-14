/*
 * APP_Basic_Enhanced_Cmd_Telltale.c
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
 * $Source:  APP_Basic_Enhanced_Cmd_Telltale.c
 * $Revision: 22
 * $Author: Guillermo Ramirez, Oscar Miranda
 * $Date: Jan/12th/2016
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    This function command the telltale
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
/*                     |       PSS_ACU      |    22                           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: APP_Basic_Enhanced_Cmd_Telltale.c
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "APPLICATION\APP_Basic_Enhanced_Cmd_Telltale.h"

/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
/*State variable needed to command the telltale*/
T_UBYTE rub_cmdTelltaleStateVar = E_FLASHING;
T_UBYTE rub_TimeoutConf = TIMEOUT_ENABLED;
T_ULONG rul_TimeDelay = 0;
/* Private functions prototypes */
/*============================================================================*/


/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

void cmd_Telltale_StMach(void)
{

	switch(rub_cmdTelltaleStateVar)
	{
	case E_FLASHING:
	{
			static T_ULONG lul_FlashingCounter = 1;
		/*It counts up to 500 ms*/
			if(lul_FlashingCounter < FLASH_PERIOD )
			{
				LED_TOGGLE(LED1);
			}else if(20 == lul_FlashingCounter )
			{
				rub_cmdTelltaleStateVar = E_CONTINUOUS_ON;
				lul_FlashingCounter = 0;
			}
			
			lul_FlashingCounter++;
			
	}
		break;
	case E_CONTINUOUS_ON:
		
		
		LED_ON(LED1);
		if(TIMEOUT_ENABLED == rub_TimeoutConf)
		{
			static T_ULONG lul_OnCounter = 1;
			if(55 == lul_OnCounter)
			{
				rub_cmdTelltaleStateVar = E_OFF;
				rul_TimeDelay = 0;
				lul_OnCounter = 0;
			}
			lul_OnCounter++;
		}
		else
		{
			/*Do nothing*/
		}

		
		break;
	case E_OFF:
		
		LED_OFF(LED1);
		
		
		/*Change state variable into Flashing mode if seatbelt is FASTENED*/
		/*if( BUCKLE == rub_SeatBelt)
		{
			
			rub_cmdTelltaleStateVar = E_FLASHING;
			
		}*/
		rul_TimeDelay++;
		break;
	default:
		
		rub_cmdTelltaleStateVar = E_CMD_ERROR;
		
		break;
	}
	
}


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

