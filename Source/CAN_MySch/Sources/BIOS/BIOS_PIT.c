/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/* MCU-specific derivative */
#include "MCU_derivative.h" 
/* Data types */
#include "typedefs.h"

#include "SERVICES/SERV_IntcInterrupts.h"

/* Own Headers */
#include "BIOS/BIOS_PIT.h"

/*****************************************************************************************************
* Definition of  VARIABLEs - 
*****************************************************************************************************/

/* PIT_Callback, function to be called upon timeout of PIT channel N */
tCallbackFunction PIT_Callback[8];

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    PIT device - Low level initialization
* 			Resets channel and enable PIT debug mode
* \author   Abraham Tezmol
* \param    void
* \return   void
*/
void PIT_device_init(void) 
{
	
	PIT.PITMCR.B.MDIS = DISABLE_PIT_CLOCKS;
	PIT.PITMCR.B.FRZ = DEBUG_MODE_ENABLE;     /* Enable PIT and configure timers to stop in debug mode */
}

/****************************************************************************************************/
/**
* \brief    PIT Channel Low level configuration
* 			Sets timer compare value, enable PIT interrupts,
*			and enable PIT module 			
* \author   Abraham Tezmol
* \param    uint8_t channel - Channel to be configured
* \param    tCallbackFunction Callback - Function to invoke upon PIT count to zero event
* \return   void
*/
void PIT_channel_configure(uint8_t channel) 
{
    PIT.CH[channel].LDVAL.R = PIT_CHANNEL_VALUE;      /* PIT1 timeout --> Refer to PIT.h file for calculations */
	PIT.CH[channel].TCTRL.B.TIE = ENABLE_INTERRUPT; /*Verify if necessary*/
	PIT.PITMCR.B.MDIS = ENABLE_PIT_CLOCKS;
    INTC.CPR.R = 0;
}

/****************************************************************************************************/
/**
* \brief    PIT channel Low level Start procedure
* \author   Abraham Tezmol
* \param    uint8_t channel - PIT channel to start
* \return   void
*/
void PIT_channel_start(uint8_t channel)
{
	PIT.CH[channel].TCTRL.B.TEN = ENABLE_TIMER;           /* Enable PIT1 interrupt and make PIT active to count */
}


/****************************************************************************************************/
/**
* \brief    PIT channel Low level Stop procedure
* \author   Abraham Tezmol
* \param    uint8_t channel - PIT channel to stop
* \return   void
*/
void PIT_channel_stop(uint8_t channel)
{
	PIT.CH[channel].TCTRL.R = 0x000000000;            /* Disable PIT channel interrupt and make PIT inactive to count */
}


/***************************************************************************************************/
/**
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo
*/

