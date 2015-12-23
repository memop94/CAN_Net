#include "BIOS/BIOS_bspi.h"
#include "MCU_derivative.h" 


/*******************************************************************************
* Global variables
*******************************************************************************/
uint16_t RecDataMaster = 0;           /* Data recieved on master SPI */
/*******************************************************************************
* Constants and macros
*******************************************************************************/

/*******************************************************************************
Function Name : InitDSPI_1
Engineer      : stnp002
Date          : Sep-20-2012
Parameters    : NONE
Modifies      : NONE
Returns       : NONE
Notes         : DSPI1 init for communication with the SBC chip on TRK-MPC5604B.
Issues        : NONE
*******************************************************************************/
void InitDSPI_1(void) 
{
  DSPI_1.MCR.R = 0x80010001;     /* Configure DSPI_1 as master */
  DSPI_1.CTAR[0].R = 0x7A0A7727; /* Configure CTAR0  */
  DSPI_1.MCR.B.HALT = 0x0;	     /* Exit HALT mode: go from STOPPED to RUNNING state*/      
  
  SIU.PCR[112].R = 0x0903;  /* Config pad as DSPI_1 SIN input */
  SIU.PCR[113].R = 0x0A04;  /* Config pad as DSPI_1 SOUT output */
  SIU.PCR[114].R = 0x0A04;  /* Config pad as DSPI_1 SCK output */
  SIU.PCR[115].R = 0x0A04;  /* Config pad as DSPI_1 CS0 output */    
  
  SIU.PSMI[7].R = 2;  /* Select PCR 114 for SCK */
  SIU.PSMI[8].R = 2;  /* Select PCR 112 for SIN */
  SIU.PSMI[9].R = 3;  /* Select PCR 115 for CS0 */
}

/*******************************************************************************
Function Name : ReadDataDSPI_1
Engineer      : stnp002
Date          : Sep-20-2012
Parameters    : NONE
Modifies      : NONE
Returns       : NONE
Notes         : read data received by SPI
Issues        : NONE
*******************************************************************************/
void ReadDataDSPI_1(void) 
{
  while (DSPI_1.SR.B.RFDF != 1){};  /* Wait for Receive FIFO Drain Flag = 1 */
  RecDataMaster = (uint16_t)DSPI_1.POPR.R;    /* Read data received by slave SPI */
  DSPI_1.SR.R = 0x80020000;        /* Clear TCF, RDRF flags by writing 1 to them */ 
}

/*******************************************************************************
Function Name : ReadDataDSPI_1
Engineer      : stnp002
Date          : Sep-20-2012
Parameters    : NONE
Modifies      : NONE
Returns       : NONE
Notes         : read data received by SPI
Issues        : NONE
*******************************************************************************/
void ConfigureMZC33905DSPI_1(void) 
{
	//AFTER POWER UP DEVICE IS IN INIT MODE
	DSPI_1.PUSHR.R = 0x0001DF80; // read  BAT FAIL
	ReadDataDSPI_1();          
	DSPI_1.PUSHR.R = 0x00011D80; // read  mode
	ReadDataDSPI_1();         
	DSPI_1.PUSHR.R = 0x00014C00; // write Init W/D  (simple W/D time out)
	ReadDataDSPI_1();          
	DSPI_1.PUSHR.R = 0x00010D00; // read  init W/D
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x00014E28; // write init LIN
	ReadDataDSPI_1(); 
	DSPI_1.PUSHR.R = 0x00010F00; // read init LIN
	ReadDataDSPI_1(); 
	DSPI_1.PUSHR.R = 0x00015A00; // write normal mode
	ReadDataDSPI_1(); 
	//DEVICE IS IN NORMAL MODE
	DSPI_1.PUSHR.R = 0x00011D80; // read device mode
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x00015A00; // W/D refresh
	ReadDataDSPI_1();
	//CONFIGURATION OF CAN/LIN
	DSPI_1.PUSHR.R = 0x000160C0; // write CAN
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x00012100; // read CAN
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x000166C0; // write LIN1
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x00012700; // read LIN1
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x000168C0; // write LIN1
	ReadDataDSPI_1();
	DSPI_1.PUSHR.R = 0x00012900; // read LIN1
	ReadDataDSPI_1(); 
}
