/*~A*/
/*~+:Import*/
#include    "BIOS/BIOS_GPIO.h"
#include    "BIOS/BIOS_PIT.h"
#include    "BIOS/BIOS_bspi.h"
#include    "MemAlloc_Cfg.h"
#include    "SERVICES/SERV_SchM_Cfg.h"
#include    "BIOS/BIOS_Can.h"
#include    "BIOS/BIOS_Can_Cfg.h"
#include    "BIOS/BIOS_sysinit.h"
#include 	"SERVICES/SERV_Exceptions.h"
#include 	"SERVICES/SERV_IntcInterrupts.h"

/*~E*/
/*~A*/
/*~+:Main Code*/
int main(void) 

{
	/* Mode initializations */
	sysinit_InitMode();
	/* Clock initializations */
	sysinit_InitSysClock();
	/* Memory Allocation Initialization NOT RELEVANT FOR YOUR SCHEDULER */
	MemAllocInit(&MemAllocConfig);
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init(); 
	/* SBC (System Basis Chip (the transceiver, you know)) dependencies */
	/* The SBC is initialized by SPI */
	InitDSPI_1();
	/* SBC configuration */
	ConfigureMZC33905DSPI_1();
    /* CAN Initialization */
	CAN_Initialization(&can_driver_config);
	/* Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	/* SchM Initialization */
	SchM_Init(&SchMConfig);
    /* Enable External Interrupts*/
    INTC_EnableInterrupts();
    /* SchM Start */
    SchM_Start();
	/* Infinite loop - Should never reach this point */
	for (;;) 
	{

	}
}
/*~E*/
