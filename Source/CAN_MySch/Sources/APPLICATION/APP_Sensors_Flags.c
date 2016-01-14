/*******************************************************************************/
/**
\file       dummy.c
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "APPLICATION/APP_Sensors_Flags.h"

/* GPIO routines prototypes */ 
#include "BIOS/BIOS_GPIO.h"

/** Used modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/
int D_SB_FLAG;
int P_SB_FLAG;
int P_S_FLAG;
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Turn a combination of 4 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Francisco Martinez
* \return   void
*/
T_SLONG Driver_Seatbelt()
{
	T_UWORD D_SB_Sensor;
	
	D_SB_Sensor = Pot_Get_Value(D_SB);
	
	if(D_SB_Sensor >= 922) 
	{
		D_SB_FLAG = FAULTY;
	}
	else if (D_SB_Sensor < 922 && D_SB_Sensor >= 614)
	{
		D_SB_FLAG = BUCKLE;
	}
	else if (D_SB_Sensor < 614 && D_SB_Sensor >= 512)
	{
		D_SB_FLAG = UNDERTERMINED;
	}
	else if (D_SB_Sensor < 512 && D_SB_Sensor >= 102)
	{
		D_SB_FLAG = UNBUCKLE;
	}
	else if (D_SB_Sensor < 102)
	{
		D_SB_FLAG = FAULTY;
	}
	
	return D_SB_FLAG;
} 

T_SLONG Passenger_Seatbelt()
{
	T_UWORD P_SB_Sensor;
	
	P_SB_Sensor = Pot_Get_Value(P_SB);
	
	if(P_SB_Sensor >= 922) 
	{
		P_SB_FLAG = FAULTY;
	}
	else if (P_SB_Sensor < 922 && P_SB_Sensor >= 614)
	{
		P_SB_FLAG = BUCKLE;
	}
	else if (P_SB_Sensor < 614 && P_SB_Sensor >= 512)
	{
		P_SB_FLAG = UNDERTERMINED;
	}
	else if (P_SB_Sensor < 512 && P_SB_Sensor >= 102)
	{
		P_SB_FLAG = UNBUCKLE;
	}
	else if (P_SB_Sensor < 102)
	{
		P_SB_FLAG = FAULTY;
	}
	
	return P_SB_FLAG;
}

T_SLONG Passenger_Seat()
{
	T_UWORD P_S_Sensor;
	
	P_S_Sensor = Pot_Get_Value(P_SS);
	
	if(P_S_Sensor >= 922) 
	{
		P_S_FLAG = FAULTY;
	}
	else if (P_S_Sensor < 922 && P_S_Sensor >= 614)
	{
		P_S_FLAG = UNOCCUPIED;
	}
	else if (P_S_Sensor < 614 && P_S_Sensor >= 512)
	{
		P_S_FLAG = UNDERTERMINED;
	}
	else if (P_S_Sensor < 512 && P_S_Sensor >= 102)
	{
		P_S_FLAG = OCCUPIED;
	}
	else if (P_S_Sensor < 102)
	{
		P_S_FLAG = FAULTY;
	}
	
	return P_S_FLAG;
}
