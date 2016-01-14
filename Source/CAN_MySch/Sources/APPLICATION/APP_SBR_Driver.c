/*
 * APP_SBR_Driver.c
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
 * $Source: APP_SBR_Driver.c
 * $Revision: 22
 * $Author: Guillermo Ramírez/Oscar Miranda
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
 * $Log: APP_SBR_Driver.c
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "APPLICATION\APP_SBR_Driver.h"

/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
T_UBYTE rub_EnhancedSequence = E_ENH_1;
T_UBYTE rub_EuroSequence = E_EURO_1;
T_UBYTE driver_SB_State;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
void cmdEuroSequence(void)
{

	static T_ULONG lul_FlashingCounter = 0;
	
	if(0 == (lul_FlashingCounter % 500))
	{
		LED_TOGGLE(LED1);
	}else if(100000 == lul_FlashingCounter)
	{
		LED_ON(LED1);
		lul_FlashingCounter = 0;
	}
	
	lul_FlashingCounter++;
}

void BasicReminder(void)
{
	driver_SB_State = (T_UBYTE)Driver_Seatbelt();
	if(UNBUCKLE == driver_SB_State)
	{
		cmd_Telltale_StMach();
	}
	else if(BUCKLE == driver_SB_State)
	{
		LED_OFF(LED1);
	}
}


void EnhancedReminder(void)
{
	if(UNBUCKLE == driver_SB_State)
	{
		switch(rub_EnhancedSequence)
		{
		case E_ENH_1:	
			
			cmd_Telltale_StMach();
			if((MAX_TIME_ENH_2 < rul_TimeDelay) && (rub_VehicleSpeed > MAX_SPEED))
			{
				rub_EnhancedSequence = E_ENH_2;
			}
						
			break;
		case E_ENH_2:
						
			cmd_Telltale_StMach();
			if((rul_TimeDelay > MAX_TIME_ENH_3) && (rub_VehicleSpeed > MAX_SPEED))
			{
				rub_EnhancedSequence = E_ENH_3;
			}
				
				
			break;
		case E_ENH_3:
			
			cmd_Telltale_StMach();
				
			break;
		default:
			break;
		}

	}
	else if(BUCKLE == driver_SB_State)
	{
		LED_OFF(LED1);
		rub_EnhancedSequence = E_ENH_1;
	}
}

void EuroReminder(void)
{
	if(UNBUCKLE == driver_SB_State)
	{
		switch(rub_EuroSequence)
		{
		case E_EURO_1:
		{
			static lul_ClusterDelay = 0;
			
			if(lul_ClusterDelay<4000)
			{
				LED_OFF(LED1);
				lul_ClusterDelay++;
			}
			else
			{
				LED_ON(LED1);
			}
			
			if(TRUE==rub_EngineActive)
			{
				rub_EuroSequence = E_EURO_2;
				lul_ClusterDelay = 0;
			}
			else
			{
				/*Do nothing*/
			}
		}	
			break;
		
		case E_EURO_2:
			
			cmdEuroSequence();
			
			if( (rub_VehicleSpeed > MAX_SPEED) || (rub_Distance > MAX_DISTANCE ))
			{
				rub_EuroSequence = E_EURO_3;
			}
			else
			{
				
			}
			
			if( (rub_VehicleSpeed > MAX_SPEED) || (rub_Door > OPEN ))
			{
				rub_EuroSequence = E_EURO_1;
			}
			break;
		case E_EURO_3:
			
			cmdEuroSequence();
			
			if( (rub_VehicleSpeed > MAX_SPEED) || (rub_Door > OPEN ))
			{
				rub_EuroSequence = E_EURO_1;
			}
			
			break;
		default:
			break;
		}
		
	}
	else if(BUCKLE == driver_SB_State)
	{
		LED_OFF(LED1);
		rub_EuroSequence = E_EURO_1;
	}
}

/* Exported functions */
/*============================================================================*/


void Driver_SB_SensorState(void)
{	/* ------------------------------------------------------------------------
	*  Name                 :  	Driver_SB_SensorState  
	*  Description          :  	Check the state of the driver seatbelt sensor. This function
	*  							shall be call by the scheduler every 10ms and respond 
	*  							every 200ms. 							
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	
	T_SLONG Seatbelt_Sensor;
	T_UBYTE SB_Sampler;
	T_UBYTE SB_B_Counter;
	T_UBYTE SB_UB_Counter;

	/* Since this function have a tolerance of +/- 10ms it has to be called every 25ms by the scheduler. 
	 * But the sensor is sample every 200ms, therefore, it has to wait 20 calls to be sample (200/10 = 20).
	 * To accomplish this condition, an IF structure is conditioned by the SB_Sampler counter, which increases
	 * when it has not reach 20 (see the else condition), once it has reach the SAMPLE_TIME (macro for 20), 
	 * it samples and realize the processing of the sensor.   */	
	if (SB_Sampler >= SAMPLE_TIME)
	{
		Seatbelt_Sensor = Driver_Seatbelt();
	
	/* If the sensor reads a FAULTY state the counter will be reseted and the flag will indicate FAULTY */
		if (Seatbelt_Sensor == FAULTY)
		{
			SB_UB_Counter = 0;
			SB_B_Counter = 0;
			driver_SB_State = FAULTY;
		}
		
	/* If the sensor reads a BUCKLE state the buckle counter will increase, if it reaches the SB_VALID		*
	 * value, indicates that the state has been the same enough time to be changed. Therefore the global 	*
	 * variable SB_State changes to BUCKLE. Once the state is changed the counter is reseted				*/
		else if (Seatbelt_Sensor == BUCKLE)
		{
			SB_UB_Counter = 0;
			SB_B_Counter++;
			if (SB_B_Counter == SB_VALID)
			{
				driver_SB_State = BUCKLE;
			}
		}
		
	/* If the sensor reads a UNBUCKLE state the unbuckle counter will increase, if it reaches the SB_VALID	*
	 * value, indicates that the state has been the same enough time to be changed. Therefore the global 	*
	 * variable SB_State changes to UNBUCKLE. Once the state is changed the counter is reseted				*/
		else if (Seatbelt_Sensor == UNBUCKLE)
		{
			SB_B_Counter = 0;
			SB_UB_Counter++;
			if (SB_B_Counter == SB_VALID)
			{
				driver_SB_State = UNBUCKLE;
			}
		}
		else
		{
			/* DO NOTHING */
		}
		SB_Sampler = 0;
	}
	else
	{
		SB_Sampler++;
	}
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */


