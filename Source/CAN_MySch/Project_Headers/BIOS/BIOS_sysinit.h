/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            sysinit.h
* version:         1.0
* created_by:      Carlos Calvillo
* date_created:    May 17 2010
*=============================================================================*/
/* DESCRIPTION : Header file for the sysinit.c C source.                      */
/*============================================================================*/
/* FUNCTION COMMENT : Provides symbols related to the code to initialize the  */
/* system. Stuff like clocking, mode selection, etc.                          */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 17/may/2010 |                               | Carlos Calvillo  */
/* Initial version for the Smart Car Race 2010 contest using Freescale        */
/* Bolero micro.                                                              */
/*============================================================================*/
#ifndef SYSINIT_H                                /* To avoid double inclusion */
#define SYSINIT_H

/* Includes */
/* -------- */
#include "typedefs.h"
#include "MCU_derivative.h" 



/* Exported types and constants */
/* ---------------------------- */

/* Types definition */

/* typedef */
enum my_enum
{
	VALUE_0,
	VALUE_1,
	VALUE_2,
	VALUE_3,
	VALUE_4,
	VALUE_5	
};

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */

/* WORD constants */

/* LONG and STRUCTURE constants */

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */

/* WORD RAM variables */

/* LONG and STRUCTURE RAM variables */

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* ========================================================================== *
 *                           MODE SELECTION DEFINES                           *
 * ========================================================================== */

/* Mode Control Register (ME_MCTL) */
/* ------------------------------- */
#define MCTL_RESET				0b0000
#define MCTL_TEST				0b0001
#define MCTL_SAFE				0b0010
#define MCTL_DRUN				0b0011
#define MCTL_RUN0				0b0100
#define MCTL_RUN1				0b0101
#define MCTL_RUN2				0b0110
#define MCTL_RUN3				0b0111
#define MCTL_HALT0				0b1000
#define MCTL_STOP0				0b1010
#define MCTL_STANDBY0			0b1101


/* Mode Enable Register (ME_ME) */
/* ---------------------------- */
#define ME_STANDBY0				0x00002000 
#define ME_STOP0				0x00000400
#define ME_HALT0				0x00000100
#define ME_RUN3					0x00000080
#define ME_RUN2					0x00000040
#define ME_RUN1					0x00000020
#define ME_RUN0					0x00000010
#define ME_DRUN					0x00000008
#define ME_SAFE					0x00000004
#define ME_TEST					0x00000002
#define ME_RESET				0x00000001

/* Mode Confutation Registers (ME_<mode>_MC) Field Descriptions */
/* ------------------------------------------------------------ */
/* PDO (I/O output power-down control) Field options */
#define MC_PDO_OFF				0x00000000 
#define MC_PDO_ON				0x00800000
/* MVRON (Main voltage regulator control) Field options */
#define MC_MVR_OFF				0x00000000 
#define MC_MVR_ON				0x00100000
/* DFLAON (Data flash power-down control) Field options */
#define MC_DFLA_PDOWN			0x00000000		/* 01 Data flash is in power-down mode */ 	
#define MC_DFLA_LPOWER			0x00080000		/* 10 Data flash is in low-power mode */
#define MC_DFLA_NORMAL			0x000C0000		/* 11 Data flash is in normal mode */
/* CFLAON (Code flash power-down control) Field options */
#define MC_CFLA_PDOWN			0x00010000		/* 01 Code flash is in power-down mode */ 	
#define MC_CFLA_LPOWER			0x00020000		/* 10 Code flash is in low-power mode */
#define MC_CFLA_NORMAL			0x00030000		/* 11 Code flash is in normal mode */
/* FMPLLON (frequency modulated phase locked loop control) Field options */
#define MC_FMPLL_OFF			0x00000000 
#define MC_FMPLL_ON				0x00000040
/* FXOSCON (fast external crystal oscillator (4-16 MHz) control) Field options */
#define MC_FXOSC_OFF			0x00000000 
#define MC_FXOSC_ON				0x00000020
/* FIRCON (fast internal RC oscillator (16 MHz) control) Field options */
#define MC_FIRC_OFF				0x00000000 
#define MC_FIRC_ON				0x00000010
/* SYSCLK (System clock switch control) Field options */
#define MC_SYSCLK_INT			0x00000000		/* 16 MHz int. RC osc. */ 	
#define MC_SYSCLK_INT_DIV		0x00000001		/* div. 16 MHz int. RC osc. */
#define MC_SYSCLK_EXT			0x00000002		/* 4-16 MHz ext. xtal osc. */
#define MC_SYSCLK_EXT_DIV		0x00000003		/* div. ext. xtal osc. */
#define MC_SYSCLK_FMPLL			0x00000004		/* freq. mod. PLL */
				
/* PCTL values */
#define PCTL_DSPI0			4
#define PCTL_DSPI1			5
#define PCTL_DSPI2			6
#define PCTL_FlexCAN0		16
#define PCTL_FlexCAN1		17
#define PCTL_FlexCAN2		18
#define PCTL_FlexCAN3		19
#define PCTL_FlexCAN4		20
#define PCTL_FlexCAN5		21
#define PCTL_ADC0			32
#define PCTL_I2C0			44
#define PCTL_LINFlex0		48
#define PCTL_LINFlex1		49
#define PCTL_LINFlex2		50
#define PCTL_LINFlex3		51
#define PCTL_CTU				57
#define PCTL_CANSampler		60
#define PCTL_SIUL			68
#define PCTL_WKPU			69
#define PCTL_eMIOS0			72
#define PCTL_eMIOS1			73
#define PCTL_RTC_API			91
#define PCTL_PIT_RTI			92
#define PCTL_CMU				104


/* Generic Defines */
#define MODE_CHANGE_KEY				0x00005AF0l
#define MODE_CHANGE_INV_KEY			0x0000A50Fl


/* Function-like macros */

/* Set Mode Enable Register (ME_ME) */
#define WRITE_ME_ME(val)						(ME.MER.R = (val))
/* RUN0 Mode Configuration Register */
#define WRITE_ME_RUN0_MC(val)					(ME.RUN[0].R = (val))
/* RUN1 Mode Configuration Register */
#define WRITE_ME_RUN1_MC(val)					(ME.RUN[1].R = (val))
/* RUN2 Mode Configuration Register */
#define WRITE_ME_RUN2_MC(val)					(ME.RUN[2].R = (val))
/* RUN3 Mode Configuration Register */
#define WRITE_ME_RUN3_MC(val)					(ME.RUN[3].R = (val))
/* PCTL Configuration Registers */
#define WRITE_ME_PCTL(pheripheral, val)			(ME.PCTL[pheripheral].R = (val))
/* Run Peripheral Configuration Registers (ME_RUN_PC0...7) */
#define WRITE_ME_RUN_PC(cfgNumber, val) 		(ME.RUNPC[(cfgNumber)].R = (val))


/* ========================================================================== *
 *                      CLOCK GENERATION MODULE DEFINES                       *
 * ========================================================================== */

/* Output Clock Division Select */
#define CGM_SELDIV_0				0
#define CGM_SELDIV_2				1
#define CGM_SELDIV_4				2
#define CGM_SELDIV_8				3

/* Output Clock Source Selection Control */
#define CGM_SELCTL_EXTAL			0
#define CGM_SELCTL_INT				1
#define CGM_SELCTL_PLL				2

/* System Clock Divider Configuration Registers */
#define CGM_CFG_DIV0(enable,divider)		( CGM.SC_DC0.R = (T_UBYTE)( (enable << 7u) | (divider & 0x0F) ) )
#define CGM_CFG_DIV1(enable,divider)		( CGM.SC_DC1.R = (T_UBYTE)( (enable << 7u) | (divider & 0x0F) ) )
#define CGM_CFG_DIV2(enable,divider)		( CGM.SC_DC2.R = (T_UBYTE)( (enable << 7u) | (divider & 0x0F) ) )

#define PLL_SET_IDF(val)			( (((val) & 0x0F) << 26u ) )
#define PLL_SET_ODF(val)			( (((val) & 0x03) << 24u ) )
#define PLL_SET_NDIV(val)			( (((val) & 0x7F) << 16u ) )
#define PLL_SET_EN_PLL_SW(val)		( (((val) & 0x01) << 8u  ) )		

#define PLL_SET(idf, odf, ndiv, en_pll_sw)				( CGM.FMPLL_CR.R = (T_ULONG)(PLL_SET_IDF((idf)) | PLL_SET_ODF((odf)) | PLL_SET_NDIV((ndiv)) | PLL_SET_EN_PLL_SW((en_pll_sw)) ))
#define PLL_SETtest(var,idf, odf, ndiv, en_pll_sw)		( (var) = (T_ULONG)(PLL_SET_IDF((idf)) | PLL_SET_ODF((odf)) | PLL_SET_NDIV((ndiv)) | PLL_SET_EN_PLL_SW((en_pll_sw)) ))

/* ========================================================================== *
 *                      RTC MODULE FOR TICK GENERATION                        *
 * ========================================================================== */


#define RTCC_CNTEN_EN        0x80000000
#define RTCC_RTCIE_EN        0x40000000
#define RTCC_FRZEN_FREEZE    0x20000000
#define RTCC_ROVREN_EN       0x10000000

#define RTCC_RTCVAL(val)     ( (((val) & 0xFFF) << 16u) )

#define RTCC_APIEN_EN        0x00008000
#define RTCC_APIIE_EN        0x00004000
#define RTCC_CLKSEL_SXOSC    0x00000000
#define RTCC_CLKSEL_SIRC     0x00001000
#define RTCC_CLKSEL_FIRC     0x00002000
#define RTCC_DIV512EN_EN     0x00000800
#define RTCC_DIV32EN_EN      0x00000400

#define RTCC_APIVAL(val)     ( ((val) & 0x3FF) )


#define SIRC_SIRCDIV_1       0x00000000
/* Appling user configurations */
#ifndef FROZEEN_TICK
#define RTC_CFG (RTCC_CNTEN_EN|RTCC_APIEN_EN|RTCC_APIIE_EN|RTCC_CLKSEL_SIRC|RTCC_APIVAL(SCHEDULER_RATE))
#endif
#ifdef FROZEEN_TICK
#if FROZEEN_TICK==0
#define RTC_CFG (RTCC_CNTEN_EN|RTCC_APIEN_EN|RTCC_APIIE_EN|RTCC_CLKSEL_SIRC|RTCC_APIVAL(SCHEDULER_RATE))
#else
#define RTC_CFG (RTCC_CNTEN_EN|RTCC_FRZEN_FREEZE|RTCC_APIEN_EN|RTCC_APIIE_EN|RTCC_CLKSEL_SIRC|RTCC_APIVAL(SCHEDULER_RATE))
#endif
#endif

/* Functions prototypes */
extern void sysinit_InitSysClock(void);
extern void sysinit_InitMode(void);
extern void sysinit_ChangeMode(T_ULONG lub_newMode);


#endif
