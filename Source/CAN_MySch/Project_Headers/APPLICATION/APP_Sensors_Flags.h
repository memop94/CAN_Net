/*******************************************************************************/
/**
\file       dummy.h
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/*******************************************************************************/

#ifndef _DUMMY_H        /*prevent duplicated includes*/
#define _DUMMY_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"
#include "driver_channel_MPC5606B.h"
#include "BIOS\BIOS_ADC_Init.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/
extern enum SEATBELT
{
	FAULTY,
	BUCKLE,
	UNDERTERMINED,
	UNBUCKLE
};

extern enum SEAT
{
	FT,
	UNOCCUPIED,
	UN,
	OCCUPIED
};

/*-- Defines -----------------------------------------------------------------*/
#define D_SB   					0
#define P_SB  					1
#define P_SS   					2

/*-- Function Prototypes -----------------------------------------------------*/
T_SLONG Driver_Seatbelt(void);
T_SLONG Passenger_Seatbelt(void);
T_SLONG Passenger_Seat(void);


#endif /* _DUMMY_H */

/*******************************************************************************/
