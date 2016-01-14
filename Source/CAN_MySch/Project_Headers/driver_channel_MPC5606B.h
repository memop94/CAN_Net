/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: driver.channel_MPC5606B.h $
 * $Revision: 1.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 19/11/2015 $
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
 * $Log: driver_channel_MPC5606B.h  $
  ============================================================================*/
#ifndef DRIVER_CHANNEL_MPC5606B_H_
#define DRIVER_CHANNEL_MPC5606B_H_

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/
extern enum E_PORT
{
	PA00,  /*Port A, Pin 0.  Functions: GPIO[0], E0UC[0], CLKOUT, E0UC[13] and WKPU[19]^5              */
	PA01,  /*Port A, Pin 1.  Functions: GPIO[1], E0UC[1], NMI^6 and WKPU[2]^5                          */
	PA02,  /*Port A, Pin 2.  Functions: GPIO[2], E0UC[2], MA[2] and WKPU[3]^5                          */
	PA03,  /*Port A, Pin 3.  Functions: GPIO[3], E0UC[3], LIN5TX, CS4_1, EIRQ[0] and ADC1_S[0]         */
	PA04,  /*Port A, Pin 4.  Functions: GPIO[4], E0UC[4], CS0_1, LIN5RX and WKPU[9]^5                  */
	PA05,  /*Port A, Pin 5.  Functions: GPIO[5], E0UC[5] and LIN4TX                                    */
	PA06,  /*Port A, Pin 6.  Functions: GPIO[6], E0UC[6], CS1_1, EIRQ[1] and LIN4RX                    */
	PA07,  /*Port A, Pin 7.  Functions: GPIO[7], E0UC[7], LIN3TX, EIRQ[2] and ADC1_S[2]                */
	PA08,  /*Port A, Pin 8.  Functions: GPIO[8], E0UC[8], E0UC[14], EIRQ[3], ABS[0] and LIN3RX         */
	PA09,  /*Port A, Pin 9.  Functions: GPIO[9], E0UC[9], CS2_1 and FAB                                */
	PA10,  /*Port A, Pin 10. Functions: GPIO[10], E0UC[10], SDA, LIN2TX and ADC1_S[2]                   */
	PA11,  /*Port A, Pin 11. Functions: GPIO[11], E0UC[11], SCL, EIRQ[16], LIN2RX and ADC1_S[3]           */
	PA12,
	PA13,  /*Port A, Pin 13. Functions: GPIO[13], SOUT_0 and E0UC[29]                                       */
	PA14,  /*Port A, Pin 14. Functions: GPIO[14], SCK_0, CS0_0, E0UC[0] and EIRQ[4]                         */
	PA15,  /*Port A, Pin 15. Functions: GPIO[15], CS0_0, SCK_0, E0UC[1] and WKPU[10]^5                      */
	
	PB00,  /*Port B, Pin 0.  Functions: GPIO[16] - Potentiometer without ADC, CAN0TX, E0UC[30] and LIN0TX   */
	PB01,  /*Port B, Pin 1.  Functions: GPIO[17], E0UC[31], WKPU[4]^5, CAN0RX and LIN0RX                    */
	PB02,  /*Port B, Pin 2.  Functions: GPIO[18], LIN0TX, SDA and E0UC[30]                                  */
	PB03,  /*Port B, Pin 3.  Functions: GPIO[19], E0UC[31], SCL, WKPU[11]^5 and LIN0RX                      */
	PB04,  /*Port B, Pin 4.  Functions: GPIO[20], (use bridge to use Potentiometer) ADC0_P[0] and ADC1_P[0] */
	PB05,  /*Port B, Pin 5.  Functions: GPIO[21] - Photo sensor, ADC0_P[1] and ADC1_P[1]                    */
	PB06,  /*Port B, Pin 6.  Functions: GPIO[22], ADC0_P[2] and ADC1_P[2]                                   */
	PB07,  /*Port B, Pin 7.  Functions: GPIO[23], ADC0_P[3] and ADC1_P[3]                                   */
	PB08,  /*Port B, Pin 8.  Functions: GPIO[24], OSC32K_XTAL^8, WKPU[25]^5, ADC0_S[0] and ADC1_S[4]        */
	PB09,  /*Port B, Pin 9.  Functions: GPIO[25], OSC32K_EXTAL^8, WKPU[26]^5, ADC0_S[1] and ADC1_S[5]       */
	PB10,  /*Port B, Pin 10. Functions: GPIO[26], WKPU[8]^5, ADC0_S[2] and ADC1_S[6]                        */
	PB11,  /*Port B, Pin 11. Functions: GPIO[27], E0UC[3], CS0_0 and ADC0_S[3]                              */
	PB12,  /*Port B, Pin 12. Functions: GPIO[28], E0UC[4], CS1_0 and ADC0_X[0]                              */ 
	PB13,  /*Port B, Pin 13. Functions: GPIO[29], E0UC[5], CS2_0 and ADC0_X[1]                              */
	PB14,  /*Port B, Pin 14. Functions: GPIO[30], E0UC[6], CS3_0 and ADC0_X[2]                              */
	PB15,  /*Port B, Pin 15. Functions: GPIO[31], E0UC[7], CS4_0 and ADC0_X[3]                              */
	
	PC00,  /*Port C, Pin 0.  Functions: GPIO[32] and TDI                                                    */
	PC01,  /*Port C, Pin 1.  Functions: GPIO[33] and TDO                                                    */
	PC02,  /*Port C, Pin 2.  Functions: GPIO[34], SCK_1, CAN4TX, DEBUG[0] and EIRQ[5]                       */
	PC03,  /*Port C, Pin 3.  Functions: GPIO[35], CS0_1, MA[0], DEBUG[1], EIRQ[6], CAN1RX and CAN4RX        */
	PC04,  /*Port C, Pin 4.  Functions: GPIO[36], E1UC[31], DEBUG[2], EIRQ[18], SIN_1 and CAN3RX            */
	PC05,  /*Port C, Pin 5.  Functions: GPIO[37], SOUT_1, CAN3TX, DEBUG[3] and EIRQ[7]                      */
	PC06,  /*Port C, Pin 6.  Functions: GPIO[38], LIN1TX, E1UC[28] and DEBUG[4]                             */
	PC07,  /*Port C, Pin 7.  Functions: GPIO[39], E1UC[29], DEBUG[5], LIN1RX and WKPU[12]^5                 */
	PC08,  /*Port C, Pin 8.  Functions: GPIO[40], LIN2TX, E0UC[3] and DEBUG[6]                              */
	PC09,  /*Port C, Pin 9.  Functions: GPIO[41], E0UC[7], DEBUG[7], WKPU[13]^5 and LIN2RX                  */
	PC10,  /*Port C, Pin 10. Functions: GPIO[42], CAN1TX, CAN4TX and MA[1]                                  */
	PC11,  /*Port C, Pin 11. Functions: GPIO[43], MA[2], WKPU[5]^5, CAN1RX and CAN4RX                       */
	PC12,  /*Port C, Pin 12. Functions: GPIO[44], E0UC[12], EIRQ[19] and SIN_2                              */
	PC13,  /*Port C, Pin 13. Functions: GPIO[45], E0UC[13] and SOUT_2                                       */
	PC14,  /*Port C, Pin 14. Functions: GPIO[46], E0UC[14], SCK_2 and EIRQ[8]                               */
	PC15,  /*Port C, Pin 15. Functions: GPIO[47], E0UC[15], CS0_2 and EIRQ[20]                              */
	
	PD00,  /*Port D, Pin 0.  Functions: GPIO[48], WKPU[27]^5, ADC0_P[4] and ADC1_P[4]                       */
	PD01,  /*Port D, Pin 1.  Functions: GPIO[49], WKPU[28]^5, ADC0_P[5] and ADC1_P[5]                       */
	PD02,  /*Port D, Pin 2.  Functions: GPIO[50], ADC0_P[6] and ADC1_P[6]                                   */
	PD03,  /*Port D, Pin 3.  Functions: GPIO[51], ADC0_P[7] and ADC1_P[7]                                   */
	PD04,  /*Port D, Pin 4.  Functions: GPIO[52], ADC0_P[8] and ADC1_P[8]                                   */
	PD05,  /*Port D, Pin 5.  Functions: GPIO[53], ADC0_P[9] and ADC1_P[9]                                   */
	PD06,  /*Port D, Pin 6.  Functions: GPIO[54], ADC0_P[10] and ADC1_P[10]                                 */
	PD07,  /*Port D, Pin 7.  Functions: GPIO[55], ADC0_P[11] and ADC1_P[11]                                 */
	PD08,  /*Port D, Pin 8.  Functions: GPIO[56], ADC0_P[12] and ADC1_P[12]                                 */
	PD09,  /*Port D, Pin 9.  Functions: GPIO[57], ADC0_P[13] and ADC1_P[13]                                 */
	PD10,  /*Port D, Pin 10. Functions: GPIO[58], ADC0_P[14] and ADC1_P[14]                                 */
	PD11,  /*Port D, Pin 11. Functions: GPIO[59], ADC0_P[15] and ADC1_P[15]                                 */
	PD12,  /*Port D, Pin 12. Functions: GPIO[60], CS5_0, E0UC[24] and ADC0_S[4]                             */
	PD13,  /*Port D, Pin 13. Functions: GPIO[61], CS0_1, E0UC[25] and ADC0_S[5]                             */
	PD14,  /*Port D, Pin 14. Functions: GPIO[62], CS1_1, E0UC[26] and ADC0_S[6]                             */
	PD15,  /*Port D, Pin 15. Functions: GPIO[63], CS2_1, E0UC[27] and ADC0_S[7]                             */
		
	SW_DOWN,  	/*Port E, Pin 0.  Functions: GPIO[64] - PUSHBUTTON1, E0UC[16], WKPU[6]^5 and CAN5RX         */
	SW_UP,  	/*Port E, Pin 1.  Functions: GPIO[65] - PUSHBUTTON2, E0UC[17] and CAN5TX                    */
	SW_A_PINCH, /*Port E, Pin 2.  Functions: GPIO[66] - PUSHBUTTON3, E0UC[18], EIRQ[21] and SIN_1           */
	PE03,  /*Port E, Pin 3.  Functions: GPIO[67] - PUSHBUTTON4, E0UC[19] and SOUT_1                         */
	LED_1,  /*Port E, Pin 4.  Functions: GPIO[68] - LED1, E0UC[20], SCK_1 and EIRQ[9]                        */
	LED_2,  /*Port E, Pin 5.  Functions: GPIO[69] - LED2, E0UC[21], CS0_1 and MA[2]                          */
	LED_3,  /*Port E, Pin 6.  Functions: GPIO[70] - LED3, E0UC[22], CS3_0, MA[1] and EIRQ[22]                */
	LED_4,  /*Port E, Pin 7.  Functions: GPIO[71] - LED4, E0UC[23], CS2_0, MA[0] and EIRQ[23]                */
	PE08,  /*Port E, Pin 8.  Functions: GPIO[72], CAN2TX, E0UC[22] and CAN3TX                               */
	PE09,  /*Port E, Pin 9.  Functions: GPIO[73], E0UC[23], WKPU[7]^5, CAN2RX and CAN3RX                    */
	PE10,  /*Port E, Pin 10. Functions: GPIO[74], LIN3TX, CS3_1, E1UC[30] and EIRQ[10]                      */
	PE11,  /*Port E, Pin 11. Functions: GPIO[75], E0UC[24], CS4_1, LIN3RX and WKPU[14]^5                    */
	PE12,  /*Port E, Pin 12. Functions: GPIO[76], E1UC[19]^12, EIRQ[11], SIN_2 and ADC1_S[7]                */
	PE13,  /*Port E, Pin 13. Functions: GPIO[77], SOUT_2 and E1UC[20]                                       */
	PE14,  /*Port E, Pin 14. Functions: GPIO[78], SCK_2, E1UC[21] and EIRQ[12]                              */
	PE15,  /*Port E, Pin 15. Functions: GPIO[79], CS0_2 and E1UC[22]                                        */
	
	PF00,  /*Port F, Pin 0.  Functions: GPIO[80], E0UC[10], CS3_1 and ADC0_S[8]                             */
	PF01,  /*Port F, Pin 1.  Functions: GPIO[81], E0UC[11], CS4_1 and ADC0_S[9]                             */
	PF02,  /*Port F, Pin 2.  Functions: GPIO[82], E0UC[12], CS0_2 and ADC0_S[10]                            */
	PF03,  /*Port F, Pin 3.  Functions: GPIO[83], E0UC[13], CS1_2 and ADC0_S[11]                            */
	PF04,  /*Port F, Pin 4.  Functions: GPIO[84], E0UC[14], CS2_2 and ADC0_S[12]                            */
	PF05,  /*Port F, Pin 5.  Functions: GPIO[85], E0UC[22], CS3_2 and ADC0_S[13]                            */
	PF06,  /*Port F, Pin 6.  Functions: GPIO[86], E0UC[23], CS1_1 and ADC0_S[14]                            */
	PF07,  /*Port F, Pin 7.  Functions: GPIO[87], CS2_1 and ADC0_S[15]                                      */
	PF08,  /*Port F, Pin 8.  Functions: GPIO[88], CAN3TX, CS4_0 and CAN2TX                                  */
	PF09,  /*Port F, Pin 9.  Functions: GPIO[89], E1UC[1], CS5_0, WKPU[22]^5, CAN2RX and CAN3RX             */
	PF10,  /*Port F, Pin 10. Functions: GPIO[90], CS1_0, LIN4TX and E1UC[2]                                 */
	PF11,  /*Port F, Pin 11. Functions: GPIO[91], CS2_0, E1UC[3], WKPU[15]^5 and LIN4RX                     */
	PF12,  /*Port F, Pin 12. Functions: GPIO[92], E1UC[25] and LIN5TX                                       */
	PF13,  /*Port F, Pin 13. Functions: GPIO[93], E1UC[26], WKPU[16]^5 and LIN5                             */
	PF14,  /*Port F, Pin 14. Functions: GPIO[94], CAN4TX, E1UC[27] and CAN1TX                               */
	PF15,  /*Port F, Pin 15. Functions: GPIO[95], E1UC[4], EIRQ[13], CAN1RX and CAN4RX                      */
	 
	PG00,  /*Port G, Pin 0.  Functions: GPIO[96], CAN5TX and E1UC[23]                                       */
	PG01,  /*Port G, Pin 1.  Functions: GPIO[97], E1UC[24], EIRQ[14] and CAN5RX                             */
	PG02,  /*Port G, Pin 2.  Functions: GPIO[98], E1UC[11] and SOUT_3                                       */
	PG03,  /*Port G, Pin 3.  Functions: GPIO[99], E1UC[12], CS0_3 and WKPU[17]^5                            */
	PG04,  /*Port G, Pin 4.  Functions: GPIO[100], E1UC[13] and SCK_3                                       */
	PG05,  /*Port G, Pin 5.  Functions: GPIO[101], E1UC[14], WKPU[18]^5 and SIN_3                           */
	PG06,  /*Port G, Pin 6.  Functions: GPIO[102] - DipSwitch 01, E1UC[15] and LIN6TX                       */
	PG07,  /*Port G, Pin 7.  Functions: GPIO[103] - DipSwitch 02, E1UC[16], E1UC[30], WKPU[20]^5 and LIN6RX */
	PG08,  /*Port G, Pin 8.  Functions: GPIO[104] - DipSwitch 03, E1UC[17], LIN7TX, CS0_2 and EIRQ[15]      */
	PG09,  /*Port G, Pin 9.  Functions: GPIO[105] - DipSwitch 04, E1UC[18], SCK_2, WKPU[21]^5 and LIN7RX    */
	PG10,  /*Port G, Pin 10. Functions: GPIO[106], E0UC[24], E1UC[31] and SIN_4                             */
	PG11,  /*Port G, Pin 11. Functions: GPIO[107], E0UC[25] and CS0_4                                       */
	PG12,  /*Port G, Pin 12. Functions: GPIO[108], E0UC[26] and SOUT_4                                      */
	PG13,  /*Port G, Pin 13. Functions: GPIO[109], E0UC[27] and SCK_4                                       */
	PG14,  /*Port G, Pin 14. Functions: GPIO[110], E1UC[0] and LIN8TX                                       */
	PG15,  /*Port G, Pin 15. Functions: GPIO[111], E1UC[1] and LIN8RX                                       */
		
	PH00,  /*Port H, Pin 0.  Functions: GPIO[112], E1UC[2] and SIN_1                                        */
	PH01,  /*Port H, Pin 1.  Functions: GPIO[113], E1UC[3] and SOUT_1                                       */
	PH02,  /*Port H, Pin 2.  Functions: GPIO[114], E1UC[4] and SCK_1                                        */
	PH03,  /*Port H, Pin 3.  Functions: GPIO[115], E1UC[5] and CS0_1                                        */
	PH04,  /*Port H, Pin 4.  Functions: GPIO[116] and E1UC[6]                                               */
	PH05,  /*Port H, Pin 5.  Functions: GPIO[117] and E1UC[7]                                               */
	PH06,  /*Port H, Pin 6.  Functions: GPIO[118], E1UC[8] and MA[2]                                        */
	PH07,  /*Port H, Pin 7.  Functions: GPIO[119], E1UC[9], CS3_2 and MA[1]                                 */
	PH08,  /*Port H, Pin 8.  Functions: GPIO[120], E1UC[10], CS2_2 and MA[0]                                */
	PH09,  /*Port H, Pin 9.  Functions: GPIO[121] and TCK                                                   */
	PH10,  /*Port H, Pin 10. Functions: GPIO[122] and TMS                                                   */
	PH11,  /*Port H, Pin 11. Functions: GPIO[123], SOUT_3, CS0_4 and E1UC[5]                                */
	PH12,  /*Port H, Pin 12. Functions: GPIO[124], SCK_3, CS1_4 and E1UC[25]                                */
	PH13,  /*Port H, Pin 13. Functions: GPIO[125], SOUT_4, CS0_3 and E1UC[26]                               */
	PH14,  /*Port H, Pin 14. Functions: GPIO[126], SCK_4, CS1_3 and E1UC[27]                                */
	PH15,  /*Port H, Pin 15. Functions: GPIO[127], SOUT_5 and E1UC[17]                                      */
		 
	PI00,  /*Port I, Pin 0.  Functions: GPIO[128], E0UC[28] and LIN8TX                                      */
	PI01,  /*Port I, Pin 1.  Functions: GPIO[129], E0UC[29], WKPU[24]^5 and LIN8RX                          */
	PI02,  /*Port I, Pin 2.  Functions: GPIO[130], E0UC[30] and LIN9TX                                      */
	PI03,  /*Port I, Pin 3.  Functions: GPIO[131], E0UC[31], WKPU[23]^5 and LIN9RX                          */
	PI04,  /*Port I, Pin 4.  Functions: GPIO[132], E1UC[28] and SOUT_4                                      */
	PI05,  /*Port I, Pin 5.  Functions: GPIO[133], E1UC[29] and SCK_4                                       */
	PI06,  /*Port I, Pin 6.  Functions: GPIO[134], E1UC[30] and CS0_4                                       */
	PI07,  /*Port I, Pin 7.  Functions: GPIO[135], E1UC[31] and CS1_4                                       */
	PI08,  /*Port I, Pin 8.  Functions: GPIO[136] and ADC0_S[16]                                            */
	PI09,  /*Port I, Pin 9.  Functions: GPIO[137] and ADC0_S[17]                                            */
	PI10,  /*Port I, Pin 10. Functions: GPIO[138] and ADC0_S[18]                                            */
	PI11,  /*Port I, Pin 11. Functions: GPIO[139], SIN_3 and ADC0_S[19]                                     */
	PI12,  /*Port I, Pin 12. Functions: GPIO[140], CS0_3 and ADC0_S[20]                                     */
	PI13,  /*Port I, Pin 13. Functions: GPIO[141], CS1_3 and ADC0_S[21]                                     */
	PI14,  /*Port I, Pin 14. Functions: GPIO[142], SIN_4 and ADC0_S[22]                                     */
	PI15,  /*Port I, Pin 15. Functions: GPIO[143], CS0_4 and ADC0_S[23]                                     */
	
	PJ00,  /*Port J, Pin 0.  Functions: GPIO[144], CS1_4 and ADC0_S[24]                                     */
	PJ01,  /*Port J, Pin 1.  Functions: GPIO[145], SIN_5 and ADC0_S[25]                                     */
	PJ02,  /*Port J, Pin 2.  Functions: GPIO[146], CS0_5 and ADC0_S[26]                                     */
	PJ03,  /*Port J, Pin 3.  Functions: GPIO[147], CS1_5 and ADC0_S[27]                                     */
	PJ04   /*Port J, Pin 4.  Functions: GPIO[148], SCK_5 and E1UC[18]                                       */
			
}; 

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */

