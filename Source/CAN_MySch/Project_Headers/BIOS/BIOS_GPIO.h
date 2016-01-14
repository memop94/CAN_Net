/*******************************************************************************/
/**

\file       GPIO.h
\brief      Macro definitions for registers access and I/O handling
\author     Abraham Tezmol
\version    0.2
\date       09/05/2013
*/
/*******************************************************************************/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/

#define LED1      					68
#define LED2       					69
#define LED3       					70
#define LED4        				71

#define ADC_D_SB   					20
#define ADC_P_SB  					21
#define ADC_P_SS   					22

#define GPIO_INPUT					0
#define GPIO_OUTPUT					1
#define GPIO_ADC					2

#define EN_ANALOG_INP 				0x2000

#define GPIO_OPEN_DRAIN_DISABLE		0
#define GPIO_OPEN_DRAIN_ENABLE		1

/*-- Macros ------------------------------------------------------------------*/
/* Indicator LEDs handling */

/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  0)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  1)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= 1) 


/*-- Function Prototypes -----------------------------------------------------*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain);
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value);
void vfnGPIO_FlashMainLED(void);
void vfnGPIO_LED_Init(void);


#endif /* _GPIO_H */

/*******************************************************************************/
