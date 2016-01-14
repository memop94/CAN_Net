/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * Source: Passenger_Seatbealt.c 
 * Revision: version 
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
 * Log: Passenger_Seatbealt.c  
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APPLICATION/APP_Passenger_Seatbealt_Bassic.h"

/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
T_UBYTE SB_State;
T_UBYTE S_State;

/* Private functions prototypes */
/*============================================================================*/


/* In-line functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/
void BasicReminder_PSR ()
{
	T_UBYTE BasicReminder_State;
	
	switch (BasicReminder_State)
	{
	case FASTENED_NOT_OCCUPIED:
		if (SB_State == UNBUCKLE && S_State == OCCUPIED)
		{
			BasicReminder_State = UNFASTENED_OCCUPIED;
		}
		else if (SB_State == BUCKLE || S_State == UNOCCUPIED)
		{
			BasicReminder_State = FASTENED_NOT_OCCUPIED;
		}
		else
		{
			/* DO NOTHING */
		}
		break;

	case UNFASTENED_OCCUPIED:
		if (SB_State == UNBUCKLE && S_State == OCCUPIED)
		{
			BasicReminder_State = UNFASTENED_OCCUPIED;
		}
		else if (SB_State == BUCKLE || S_State == UNOCCUPIED)
		{
			BasicReminder_State = FASTENED_NOT_OCCUPIED;
		}
		else
		{
			/* DO NOTHING */
		}
		
		Unfastened_Occupies_StateMachine();
		
		break;
		
	default:
		if (SB_State == UNBUCKLE && S_State == OCCUPIED)
		{
			BasicReminder_State = UNFASTENED_OCCUPIED;
		}
		else if (SB_State == BUCKLE || S_State == UNOCCUPIED)
		{
			BasicReminder_State = FASTENED_NOT_OCCUPIED;
		}
		else
		{
			/* DO NOTHING */
		}
		break;
	}
}

void Unfastened_Occupies_StateMachine()
{
	T_UBYTE UnO_State = CONTINUOUS_INDICATION;
	T_ULONG UnO_Counter;
	switch (UnO_State)
	{
	case CONTINUOUS_INDICATION:
		if (UnO_Counter <= 250)
		{
			/* poner valor a variable global que se enviara en CAN */
			UnO_Counter++;
		}
		else
		{
			UnO_State = 0;
			UnO_State = FLASHING;
		}
		break;

	case FLASHING:
		if (UnO_Counter <= 200)
		{
			/* poner valor a variable global que se enviara en CAN */
			UnO_Counter++;
		}
		else
		{
			UnO_State = 0;
			UnO_State = CONTINUOUS;
		}
		break;
		
	case CONTINUOUS:
		if (UnO_Counter <= 550)
		{
			/* poner valor a variable global que se enviara en CAN */
			UnO_Counter++;
		}
		else
		{
			UnO_State = 0;
			UnO_State = NO_INDICATION;
		}
		break;
		
	case NO_INDICATION:
		
		break;
	
	default:
		UnO_State = CONTINUOUS_INDICATION;
		break;
	}
}

/* Exported functions */
/*============================================================================*/

void P_SB_SensorState ()
{	/* ------------------------------------------------------------------------
	*  Name                 :  	SB_SensorState  
	*  Description          :  	Check the state of the seatbelt sensor. This function
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
		Seatbelt_Sensor = Passenger_Seatbelt();
	
	/* If the sensor reads a FAULTY state the counter will be reseted and the flag will indicate FAULTY */
		if (Seatbelt_Sensor == FAULTY)
		{
			SB_UB_Counter = 0;
			SB_B_Counter = 0;
			SB_State = FAULTY;
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
				SB_State = BUCKLE;
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
				SB_State = UNBUCKLE;
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

void P_S_SensorState ()
{	/* ------------------------------------------------------------------------
	*  Name                 :  	S_SensorState  
	*  Description          :  	Check the state of the seat sensor. This function
	*  							shall be call by the scheduler every 25ms and sample 
	*  							the sensor value every 500ms. 							
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	
	T_SLONG Seat_Sensor;
	T_UBYTE S_Sampler;
	T_UBYTE S_O_Counter;
	T_UBYTE S_UO_Counter;
	
	/* Since this function have a tolerance of +/- 25ms it has to be called every 25ms by the scheduler. 		*
	 * But the sensor is sample every 500ms, therefore, it has to wait 20 calls to be sample (500/25 = 20).		*
	 * To accomplish this condition, an IF structure is conditioned by the S_Sampler counter, which increases	*
	 * when it has not reach 20 (see the else condition), once it has reach the SAMPLE_TIME (macro for 20), 	*
	 * it samples and realize the processing of the sensor.  									 				*/
	if (S_Sampler >= SAMPLE_TIME)
	{
		Seat_Sensor = Passenger_Seat();
		
	/* If the sensor reads a FAULTY state the counter will be reseted and the flag will indicate FAULTY 	*/
		if (Seat_Sensor == FAULTY)
			{
				S_UO_Counter = 0;
				S_O_Counter = 0;
				S_State = FAULTY;
			}
		
	/* If the sensor reads a OCCUPIED state the occupied counter will increase, if it reaches the S_VALID	*
	 * value, indicates that the state has been the same enough time to be changed. Therefore the global 	*
	 * variable S_State changes to OCCUPIED. Once the state is changed the counter is reseted				*/
		else if (Seat_Sensor == OCCUPIED)
		{
			S_UO_Counter = 0;
			S_O_Counter++;
			if (S_O_Counter == S_VALID)
			{
				S_State = OCCUPIED;
				S_O_Counter = 0;
			}
		}
		
	/* If the sensor reads a UNOCCUPIED state the unoccupied counter will increase, if it reaches the S_VALID	*
	 * value, indicates that the state has been the same enough time to be changed. Therefore the global 		*
	 * variable S_State changes to UNOCCUPIED. Once the state is changed the counter is reseted					*/		
		else if (Seat_Sensor == UNOCCUPIED)
		{
			S_O_Counter = 0;
			S_UO_Counter++;
			if (S_O_Counter == S_VALID)
			{
				S_State = UNOCCUPIED;
			}
		}
		else
		{
			/* DO NOTHING */
		}
		
		S_Sampler = 0;
	}
	
	else
	{
		S_Sampler++;
	}
	
}



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
