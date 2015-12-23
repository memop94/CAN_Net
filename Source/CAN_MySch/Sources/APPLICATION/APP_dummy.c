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
#include "APPLICATION/APP_dummy.h"

/* GPIO routines prototypes */ 
#include "BIOS/BIOS_GPIO.h"

/** Used modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

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
void Test(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
switch (rub_U16Counter)
{
case 1:
{
LED_ON(LED1);
LED_OFF(LED2);
LED_ON(LED3);
LED_OFF(LED4);
break;
}
case 6:
{
LED_OFF(LED1);
LED_ON(LED2);
LED_OFF(LED3);
LED_ON(LED4);
break;
}
case 12:
{
LED_ON(LED1);
LED_OFF(LED2);
LED_ON(LED3);
LED_OFF(LED4);
break;
}
case 18:
{
LED_OFF(LED1);
LED_ON(LED2);
LED_OFF(LED3);
LED_ON(LED4);
break;
}
case 24:
{
LED_OFF(LED1);
LED_OFF(LED2);
LED_OFF(LED3);
LED_OFF(LED4);
break;
}
case 160:
{
rub_U16Counter = 0;
break;
}
}


}
