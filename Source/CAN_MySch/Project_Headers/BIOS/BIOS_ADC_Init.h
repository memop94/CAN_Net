/*
 * ADC_Init.h
 *
 *  Created on: Dec 14, 2015
 *      Author: x
 */

#ifndef ADC_INIT_H_
#define ADC_INIT_H_
#include "typedefs.h"
#include "MPC5606B.h"
uint16_t Pot_Get_Value(uint8_t);
uint16_t A2D_GetSingleCh_10bit(uint32_t);
void adc_0_init_fnc(void);
#endif /* ADC_INIT_H_ */
