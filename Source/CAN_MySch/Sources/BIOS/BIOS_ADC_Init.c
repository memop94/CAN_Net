/*
 * ADC_Init.c
 *
 *  Created on: Dec 14, 2015
 *      Author: x
 */

#include "BIOS\BIOS_ADC_Init.h"

uint16_t Pot_Get_Value(uint8_t ch)
{
	return (A2D_GetSingleCh_10bit(ch));
}

uint16_t A2D_GetSingleCh_10bit(uint32_t ch)
{
    uint16_t result;
    
    ADC_0.NCMR0.R = (uint32_t)(0x00000001 << ch);
    if (ch >= 32)
    {
        ADC_0.NCMR1.R = (uint32_t)(0x00000001 << (ch - 32));
    }
    if (ch >= 64)
    {
        ADC_0.NCMR2.R = (uint32_t)(0x00000001 << (ch - 64));
    }

    ADC_0.MCR.B.NSTART = 1;  /* Trigger ADC Conversion */
   
    /*Don't use a breakpoint between the triggering and this*/
    while (ADC_0.CDR[ch].B.VALID != 1)
    {
    }
    result = (uint16_t)((ADC_0.CDR[ch].B.CDATA));

    return(result);
}

void adc_0_init_fnc(void)
{

    ADC_0.MCR.B.PWDN = 0x1;
        /* Enter power down state */
    ADC_0.MCR.B.ABORT =0x1;
        /* Abort all conversion in process */

/*-----------------------------------------------------------*/
/* Clear All Interrupt Flags - Write 1 to Clear              */
/*-----------------------------------------------------------*/
    ADC_0.ISR.R = 0x0000001F; 
        /* B27: End of CTU Conversion EOCTU Flag */
        /* B28: End of Injected Channel Conversion JEOC Flag */
        /* B29: End of Injected Chain Conversion interrupt JECH Flag */
        /* B30: End of Channel Conversion EOC Flag */
        /* B31: End of Chain Conversion ECH Flag */

/*-----------------------------------------------------------*/
/* All Init that can be done in Power Down State             */
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* ADC General Setup                                         */
/*-----------------------------------------------------------*/
    ADC_0.MCR.R = 0x00000000;
        /* Conversion data Overwrite : Disabled */
        /* Conversion Data Aligned: Right Aligned */
        /* Conversion Mode Selected :  One Shot */
        /* Normal Start conversion Disabled :- can be configured using adc_normal_Start_fnc */
        /* Injected Start conversion Disabled :- can be configured using adc_injected_Start_fnc */
        /* Injection external trigger : Configured in adc_trigger_setup_fnc */
        /* Injection trigger edge : Configured in adc_trigger_setup_fnc */
        /* Cross Triggering Unit needs to be configured after CTU initialization */
        /* ADC Conversion clock selected as :  System Clock/2 */
        /* ADCLKSEL Init needs to be done in POWER DOWN State */
        /* Abort chain Conversion Disabled can be configured using adc_abort_chain_fnc */
        /* Abort Normal Conversion Disabled can be configured using adc_normal_stop_fnc */
        /* Auto Clock Off feature: Disabled */
        /* Power Down Mode is Enabled while ADC Clock initialization */


/*-----------------------------------------------------------*/
/*      Conversion Timing Register 0(ADC_0_CTR0)               */
/*-----------------------------------------------------------*/
    ADC_0.CTR0.R = 0x00000203;
        /* Phase duration Latch : 0 */
        /* Input Sampling Duration : 3 clock Cycles  */
        /* Input Comparison Duration : 1 clock Cycles*/
        /* Offset Shift Duration : 0 clock Cycles*/

/*-----------------------------------------------------------*/
/*      Conversion Timing Register 0(ADC_0_CTR1)               */
/*-----------------------------------------------------------*/
    ADC_0.CTR1.R = 0x00000203;
        /* Phase duration Latch : 0 */
        /* Input Sampling Duration : 3 clock Cycles  */
        /* Input Comparison Duration : 1 clock Cycles*/

/*-----------------------------------------------------------*/
/*      Conversion Timing Register 0(ADC_0_CTR2)               */
/*-----------------------------------------------------------*/
    ADC_0.CTR2.R = 0x00000203;
        /* Phase duration Latch : 0 */
        /* Input Sampling Duration : 3 clock Cycles  */
        /* Input Comparison Duration : 1 clock Cycles*/

/*-----------------------------------------------------------*/
/*  ADC Channel/Interrupt/Watchdog/DMA Configuration         */
/*-----------------------------------------------------------*/
    
    /*-----------------------------------------------------------*/
    /* Normal Channel Conversion Mask Register 0(ADC_0_NCMR0)      */
    /*-----------------------------------------------------------*/
    	ADC_0.NCMR0.B.CH0 = 1;
            /* ADC Channel 0 in Normal Mode : Enabled */
    	
        /*-----------------------------------------------------------*/
        /*     Threshold Register 0 (ADC_0_THRHLR0)                    */
        /*-----------------------------------------------------------*/
     
            ADC_0.THRHLR0.R = 0x03FF0000;
                /* Lower Threshold value : 0 */
                /* Higher Threshold value : 1023 */

        /*-----------------------------------------------------------*/
        /*     Threshold Register 1 (ADC_0_THRHLR1)                    */
        /*-----------------------------------------------------------*/
            ADC_0.THRHLR1.R = 0x03FF0000;
                /* Lower Threshold value : 0 */
                /* Higher Threshold value : 1023 */

        /*-----------------------------------------------------------*/
        /*     Threshold Register 2 (ADC_0_THRHLR2)                    */
        /*-----------------------------------------------------------*/
            ADC_0.THRHLR2.R = 0x03FF0000;
                /* Lower Threshold value : 0 */
                /* Higher Threshold value : 1023 */

        /*-----------------------------------------------------------*/
        /*     Threshold Register 3 (ADC_0_THRHLR3)                    */
        /*-----------------------------------------------------------*/
            ADC_0.THRHLR3.R = 0x03FF0000;
                /* Lower Threshold value : 0 */
                /* Higher Threshold value : 1023 */

        /*-----------------------------------------------------------*/
        /*     Threshold Register 4 (ADC_0_THRHLR4)                    */
        /*-----------------------------------------------------------*/
            ADC_0.THRHLR4.R = 0x03FF0000;
                /* Lower Threshold value : 0 */
                /* Higher Threshold value : 1023 */

        /*-----------------------------------------------------------*/
        /*     Threshold Register 5 (ADC_0_THRHLR5)                    */
        /*-----------------------------------------------------------*/
            ADC_0.THRHLR5.R = 0x03FF0000;
                /* Lower Threshold value : 0 */
                /* Higher Threshold value : 1023 */


/*-----------------------------------------------------------*/
/* ADC Trigger Configuration                                 */
/*-----------------------------------------------------------*/
            /*Here goes trigger configuration*/
/*-----------------------------------------------------------*/
/* All Init that can be done in Normal State                 */
/*-----------------------------------------------------------*/

    ADC_0.MCR.B.ABORT =0x0;  
            /* ADC can start conversion */

}
