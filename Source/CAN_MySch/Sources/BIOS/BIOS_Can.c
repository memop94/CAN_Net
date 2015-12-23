/*~A*/
/*~+:Header*/
/*******************************************************************************/
/**
\file       can.c
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/
/*~E*/
/*~A*/
/*~+:Imports*/
#include "BIOS/BIOS_Can.h"
#include "SERVICES/SERV_IntcInterrupts.h"
/*~E*/
/*~A*/
/*~+:Defines*/
/* CAN Engine Devices */
#define BIOS_CAN_CANA    (0) /* CAN A */
#define BIOS_CAN_CANB    (1) /* CAN B */
#define BIOS_CAN_CANC    (2) /* CAN C */
#define BIOS_CAN_CAND    (3) /* CAN D */
/* Channel Operation Mode */
#define BIOS_CAN_CH_TX    (1) /* Channel Mode Tx */
#define BIOS_CAN_CH_RX    (0) /* Channel Mode Rx */
/*~E*/
/*~A*/
/*~+:Variables*/
FLEXCAN2_Type			*bios_cnf_can_eng[2];
CAN_ConfigDeviceType	*can_config_dev_ptr[2];
CAN_ConfigType			*can_config_ptr;
/* Containers for the RXD and TXD messages per MB*/
CAN_MessageDataType		received_messages[64];
CAN_MessageDataType		txd_messages[64];
/* Mask bitfield used to prevent clearing interrupt flags to be polled */
uint32_t bios_can_prevent_clear_flag_low = 0;
uint32_t bios_can_prevent_clear_flag_high = 0;
/*~E*/
/*~A*/

/*~+:Private Operations*/
/*~A*/
/*~+:uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len)*/
uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len)
{
	/*~A*/
	/*~+:Local Variables*/
	uint8_t i;
	/*~E*/
	/* MB Tx not Active */
	bios_cnf_can_eng[can_eng]->BUF[can_channel].CS.B.CODE = 0x8; /* Corresponding IFLAG must be cleared */
	if (can_channel<32)
	{
		bios_cnf_can_eng[can_eng]->IFRL.R = (0x1 << can_channel); }
	else
	{
		bios_cnf_can_eng[can_eng]->IFRH.R = (0x1 << (can_channel-32)); 
	}
	
	/* Write LENGTH and DATA BYTES */
	/* Set DLC of MB Format (Bytes to be transmitted)  */
	bios_cnf_can_eng[can_eng]->BUF[can_channel].CS.B.LENGTH = len; 
	
	for (i = 0; i < len; i++)
	{
		bios_cnf_can_eng[can_eng]->BUF[can_channel].DATA.B[i] = can_msg_buf[i];
	}
	/* Write Control & Code Fields */
	bios_cnf_can_eng[can_eng]->BUF[can_channel].CS.B.RTR = can_config_dev_ptr[can_eng]->can_dev_messages[can_channel].can_msg_rtr; 
	bios_cnf_can_eng[can_eng]->BUF[can_channel].CS.B.CODE = 0xC; /* Tx MB */
	return (0);
}
/*~E*/
/*~A*/
/*~+:void CANB_Isr(void)*/
void CANB_Isr(void)
{
	/*~A*/
	/*~+:Local Variables*/
	uint8_t mb_idx;
	uint8_t mask_flag;
	uint8_t data_idx;
	uint8_t code;
	uint8_t dummy;
	volatile uint32_t mb_int_flag_low;
	volatile uint32_t mb_int_flag_high;
	CAN_MessageDataType *message_data_ptr;
	/*~E*/
	/*Disable Interrupts */
	mb_int_flag_low = (uint32_t)bios_cnf_can_eng[BIOS_CAN_CANB]->IFRL.R;
	mb_int_flag_high = (uint32_t)bios_cnf_can_eng[BIOS_CAN_CANB]->IFRH.R;
	mb_int_flag_low &= bios_can_prevent_clear_flag_low;
	mb_int_flag_high &= bios_can_prevent_clear_flag_high;
	/* Clear MBIF */
	bios_cnf_can_eng[BIOS_CAN_CANB]->IFRL.R = mb_int_flag_low;
	bios_cnf_can_eng[BIOS_CAN_CANB]->IFRH.R = mb_int_flag_high;
	/*Enable Interrupts */
	for (mb_idx=0; mb_idx<can_config_ptr->can_device->can_nr_of_msg; mb_idx++)
	{
		if (mb_idx<32)
		{
			mask_flag = (uint8_t)( (mb_int_flag_low >> mb_idx) & 0x1);
		}
		else
		{
			mask_flag = (uint8_t)( (mb_int_flag_high >> (mb_idx-(uint8_t)32)) & 0x1);
		}
		if (mask_flag == 1)
		{
			/*Disable Interrupts */
			/*~A*/
			/*~+:Get Message Data*/
			if ((bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].CS.B.CODE)<8)
			{
				message_data_ptr = &received_messages[0];
			}
			else
			{
				message_data_ptr = &txd_messages[0];
			}
			if (bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].CS.B.IDE) 
			{
				/*Extended ID */
				message_data_ptr[mb_idx].msg_id_field = (bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].ID.R) & (uint32_t)(0x1FFFFFFF);
			}
			else
			{
				/* Standard ID */
				message_data_ptr[mb_idx].msg_id_field = (bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].ID.B.STD_ID) & (uint32_t)0x7FF;
			}
			
			message_data_ptr[mb_idx].msg_buff_nr = mb_idx;
			message_data_ptr[mb_idx].msg_ide = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].CS.B.IDE;
			message_data_ptr[mb_idx].msg_time_stamp = (uint16_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].CS.B.TIMESTAMP;
			message_data_ptr[mb_idx].msg_dlc_field = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].CS.B.LENGTH;
			code = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].CS.B.CODE;
			for (data_idx=0; data_idx<(message_data_ptr[mb_idx].msg_dlc_field); data_idx++) 
			{
				message_data_ptr[mb_idx].msg_data_field[data_idx] = bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[mb_idx].DATA.B[data_idx];
			}
			/* Read TIMER to unlock message buffers */
			dummy = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->TIMER.R;
			/*~E*/
			/*Enable Interrupts */
			/* If configured, call function from upper layer */
			/* Test against NULL in case any other Interrupt Flag has been set which ID matched from configuration and not callback function is configured */
			if ( NULL != can_config_dev_ptr[0]->can_dev_messages[mb_idx].CallbackFcnt)
			{
				can_config_dev_ptr[0]->can_dev_messages[mb_idx].CallbackFcnt(message_data_ptr[mb_idx]);
			}
		}
		else
		{
			/* No RX not TX to process*/
		}
	}
}

/**
 * Temporary, this shouldn't be here 
 */
void CAN_IO_Config(void)
{
	/*~A*/
	/*~+:Temporary configuration for CAN B - This belongs to IO Configuration*/
	SIU.PCR[42].B.PA = 1; /* Primary function */
	SIU.PCR[42].B.OBE = 1; /* Enable output buffer for the pad */
	SIU.PCR[42].B.IBE = 0; /* 0 Disable input buffer for the pad */
	/* SIU.PCR[42].B.DSC = 0; Not available on this MCU*/  /* 10 pF drive strength */
	SIU.PCR[42].B.ODE = 0; /* Enable open drain for the pad */
	/* SIU.PCR[42].B.HYS = 0; Not available on this MCU*/  /* Disable hysteresis for the pad */
	SIU.PCR[42].B.SRC = 0; /* Minimum slew rate */
	SIU.PCR[42].B.WPE = 0; /* Enable weak pull device for the pad */
	SIU.PCR[42].B.WPS = 0; /* Pulldown is enabled for the pad */
	/* Rx */
	SIU.PSMI[0].B.PADSEL = 0x01; /* CAN1RX / FlexCAN_1 --> 01: PCR[43]*/
	SIU.PCR[43].B.PA = 0; /* Primary function */
	SIU.PCR[43].B.OBE = 0; /* 0 Disable output buffer for the pad */
	SIU.PCR[43].B.IBE = 1; /* Enable input buffer for the pad */
	/*SIU.PCR[43].B.DSC = 0; Not available on this MCU*/ /* 10 pF drive strength */
	SIU.PCR[43].B.ODE = 0; /* Disable open drain for the pad */
	/*SIU.PCR[43].B.HYS = 0; Not available on this MCU*/ /* Disable hysteresis for the pad */
	SIU.PCR[43].B.SRC = 0; /* Minimum slew rate */
	SIU.PCR[43].B.WPE = 0; /* Enable weak pull device for the pad */
	SIU.PCR[43].B.WPS = 0; /* Pulldown is enabled for the pad */
}

/*~E*/
/*~E*/
/*~A*/
/*~+:Public Operations*/
/*~A*/
/*~+:void CAN_Initialization(CAN_ConfigType *can_config)*/
void CAN_Initialization(CAN_ConfigType *can_config)
{
	/*~A*/
	/*~+:Local Variables*/
	uint8_t dev_idx, mb_idx, message_buffer;
	uint16_t delay = 2000;

	/*~E*/
	can_config_ptr = can_config;
	can_config_dev_ptr[0] = can_config_ptr->can_device;
	bios_cnf_can_eng[0] = &CAN_0;	/** Address of the CAN_0 peripheral */
	bios_cnf_can_eng[1] = &CAN_1;	/** Address of CAN_1 peripheral */

	/* Initialize pads, pins, etc. This should go somewhere else */
	CAN_IO_Config();
	
	/*~E*/
	for (dev_idx=0; dev_idx<can_config_ptr->can_nr_of_devices; dev_idx++)
	{
		/*~A*/
		/*~+:Device level initialization*/
		/* Reset the CAN Module. No waiting for softreset confirmation */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.SOFTRST = 0x1;       
		do
		{
			delay--; /* Wait for Soft Reset */
		}while ((bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.SOFTRST) && (delay > 0));

		/* Entering Disable Mode */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.MDIS = 0x1;          /* Disable the CAN module */ 
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.CLKSRC = can_config_dev_ptr[dev_idx]->can_dev_baudrate->can_ctrl_clksrc;
		/* FLEXCAN must be put in Freeze Mode before accessing (writing) into any of its configuration registers */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.MDIS = 0x0;          /* Module automatically goes to FRZ mode once the clock source is selected and module is enabled */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.HALT = 0x1;          /* HALT bit is set */

		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.MAXMB= (uint32_t)(can_config_dev_ptr[dev_idx]->can_nr_of_msg-1);/* Enable the required MB */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.BCC = (uint32_t)can_config_dev_ptr[dev_idx]->can_ctrl_mbfen;/* Enable individual filtering per MB and reception */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.WRNEN = 0x0; /* Enable warning interrupts */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.SRXDIS = 0x1; /* Disable frame self reception */

		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.FEN = can_config_dev_ptr[dev_idx]->can_ctrl_fifo; /* Disable FIFO */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.AEN = 0x0; /* "DIS" Enable the Abort Mechanism */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.LPRIO_EN = 0x0; /* Enable the local priority feature */

		for (mb_idx=0; mb_idx < 64; mb_idx++) /* Clear the MB's */
		{
			bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[mb_idx].CS.R = 0x0;
		}

		/* Initialize the Control Register */

		/* Determine Timing Parameters */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.LPB = 0; /* Loop Back disabled */
		/* Selects the Clock Source */

		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.PROPSEG = can_config_dev_ptr[dev_idx]->can_dev_baudrate->can_ctrl_propseg - 1;
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.PSEG1 = can_config_dev_ptr[dev_idx]->can_dev_baudrate->can_ctrl_pseg1 - 1;
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.PSEG2 = can_config_dev_ptr[dev_idx]->can_dev_baudrate->can_ctrl_pseg2 - 1;
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.RJW = can_config_dev_ptr[dev_idx]->can_dev_baudrate->can_ctrl_rjw - 1;
		/* Determine Bit Rate */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.PRESDIV = can_config_dev_ptr[dev_idx]->can_dev_baudrate->can_ctrl_presdiv - 1;

		/* Determine the internal arbitration mode */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->CR.B.LBUF = can_config_dev_ptr[dev_idx]->can_ctrl_lbuf; /* Highest priority buffer is transmitted first */

		/* Message Buffers and the RX individual mask registers are not affected by reset and they are not automatically initialized*/
		/* Configure the Message Buffers and Mask's */
		for (mb_idx=0; mb_idx < (can_config_dev_ptr[dev_idx]->can_nr_of_msg); mb_idx++)
		{
			message_buffer = can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg;
			bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].CS.B.IDE = can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_id_length; /* ID Format */
			if (can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_id_length)
			{
				/* Extended ID */
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].ID.R &= 0xE0000000;
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].ID.R |= (uint32_t)can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_id;
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].CS.B.SRR = 0x1; /* 0x1 for ID extended format */
			}
			else
			{
				/* Standard ID*/
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].ID.B.STD_ID = can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_id;
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].CS.B.SRR = 0x0; 
			}
			if (can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_op == BIOS_CAN_CH_TX)
			{
				/* MB used for TX */
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].CS.B.CODE = 0x8; /* 0x8 = MB TX not Active */

			}
			else
			{
				/* MB used for RX */
				bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->BUF[message_buffer].CS.B.CODE = 0x4; /* 0x4 = MB RX Active and Empty */
				if (can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_id_length)
				{
					/* Extended Filter*/
					/* Setting the RX IMASK's & Global Mask */
					bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->RXIMR[message_buffer].R =(uint32_t) can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_mask;
				}
				else
				{
					/* Standard Filter */
					/* Setting the RX IMASK's & Global Mask */
					bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->RXIMR[message_buffer].R = (uint32_t)(0x0003FFFF)|((can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].can_msg_mask)<<18);
				}
			}
			
			/*~A*/
			/*~+:Enable Interrupt for each Message Buffer*/
			if ( NULL != can_config_dev_ptr[dev_idx]->can_dev_messages[mb_idx].CallbackFcnt )
			{
				if ( message_buffer < 32 )
				{
					bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->IMRL.R |= (uint32_t)(1<<(message_buffer));
					bios_can_prevent_clear_flag_low |= (1<<(message_buffer));
				}
				else
				{
					bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->IMRH.R |= (uint32_t)(1<<((message_buffer)-32));
					bios_can_prevent_clear_flag_high |= (1<<((message_buffer)-32));
				}
			}
			/*~E*/
		}

		/* Negate the HALT bit to enable the module */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.HALT = 0x0;
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.FRZ = 0x0;
		/*~E*/
	}

	/*~A*/

	/*~+:Temporary configuration for interrupt handler*/

	/* Install Interrupt routine for all MB */

	/*from interrupt vector table, IRQ #'s*/

	INTC_InstallINTCInterruptHandler(CANB_Isr,88,4); /**< FLEXCAN buff 00_03 */
	INTC_InstallINTCInterruptHandler(CANB_Isr,89,4); /**< FLEXCAN buff 04_07 */
	INTC_InstallINTCInterruptHandler(CANB_Isr,90,4); /**< FLEXCAN buff 08_11 */
	INTC_InstallINTCInterruptHandler(CANB_Isr,91,4); /**< FLEXCAN buff 12_15 */
	INTC_InstallINTCInterruptHandler(CANB_Isr,92,4); /**< FLEXCAN buff 16_31 */
	INTC_InstallINTCInterruptHandler(CANB_Isr,93,4); /**< FLEXCAN buff 32_63 */

	/*~E*/
}
	/*~E*/
	/*~A*/
	/*~+:void CAN_SendFrame(CAN_PduType *pdu_handler)*/
void CAN_SendFrame(CAN_PduType *pdu_handler)
{
	/* CAN Engine ID -Driver ID-*/ 		
	if (can_config_ptr->can_device[0].can_dev_messages[pdu_handler->can_mb_nr].can_msg_op == BIOS_CAN_CH_TX)
	{
		CAN_SendFrameInt(BIOS_CAN_CANB,pdu_handler->can_mb_nr,pdu_handler->can_sdu,pdu_handler->can_dlc);
	}
	else
	{
		/* Else is a placeholder for error return*/
	}
}

	/*~E*/
	/*~A*/
/*~+:uint8_t CAN_ReceiveFrame(uint8_t message_buffer, CAN_MessageDataType *can_message )*/
/*
CAN_ReceiveFrame function return val:
	0:  No Message Received
	1:  Message Received
	2:  Error
	*/
uint8_t CAN_ReceiveFrame(uint8_t message_buffer, CAN_MessageDataType *can_message )
{
	/*~A*/
	/*~+:Local Variables*/
	uint8_t mask_flag;
	uint8_t data_idx;
	uint8_t code;
	uint8_t dummy;
	uint8_t return_val = 0;
	volatile uint32_t mb_int_flag_low;
	volatile uint32_t mb_int_flag_high;
	CAN_MessageDataType *message_data_ptr;
	
	/*~E*/
	if (can_config_ptr->can_device[0].can_dev_messages[message_buffer].can_msg_op == BIOS_CAN_CH_RX)
	{
		if (message_buffer < 32)
		{
			mb_int_flag_low = (uint32_t)bios_cnf_can_eng[BIOS_CAN_CANB]->IFRL.R;
			mask_flag = (uint8_t)( (mb_int_flag_low >> message_buffer) & 0x1);
		}
		else
		{
			mb_int_flag_high = (uint32_t)bios_cnf_can_eng[BIOS_CAN_CANB]->IFRH.R;
			mask_flag = (uint8_t)( (mb_int_flag_high >> (message_buffer-(uint8_t)32)) & 0x1);
		}
		if (mask_flag == 1){
			/* Clear the MB Flag */
			if (message_buffer < 32)
			{
				bios_cnf_can_eng[BIOS_CAN_CANB]->IFRL.R = (uint32_t)(0x1 << message_buffer);   		
			}
			else
			{
				bios_cnf_can_eng[BIOS_CAN_CANB]->IFRH.R = (uint32_t)(0x1 << (message_buffer-(uint8_t)32));   
			}
			/*~A*/
			/*~+:Get Message Data*/
			if ((bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].CS.B.CODE)<8)
			{
				message_data_ptr = can_message;
				if (bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].CS.B.IDE) 
				{
					/*Extended ID */
					message_data_ptr->msg_id_field = (bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].ID.R) & (uint32_t)(0x1FFFFFFF);

				}
				else
				{
					/* Standard ID */
					message_data_ptr->msg_id_field = (bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].ID.B.STD_ID) & (uint32_t)0x7FF;
				}
				message_data_ptr->msg_buff_nr = message_buffer;
				message_data_ptr->msg_ide = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].CS.B.IDE;
				message_data_ptr->msg_time_stamp = (uint16_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].CS.B.TIMESTAMP;
				message_data_ptr->msg_dlc_field = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].CS.B.LENGTH;
				code = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].CS.B.CODE;
				
				for (data_idx = 0; data_idx < (message_data_ptr->msg_dlc_field); data_idx++) 
				{
					message_data_ptr->msg_data_field[data_idx] = bios_cnf_can_eng[BIOS_CAN_CANB]->BUF[message_buffer].DATA.B[data_idx];
				}
				/* Read TIMER to unlock message buffers */
				dummy = (uint8_t)bios_cnf_can_eng[BIOS_CAN_CANB]->TIMER.R;
			}
			else
			{
				return_val = 2;
			}
			/*~E*/
			return_val = 1;
		}
		else
		{
			/* No message received */
		}
	}
	else
	{
		return_val = 2;
	}
	return (return_val);
}

/*~E*/
/*~A*/
/*~+:void CAN_Stop(void)*/
void CAN_Stop(void){
	uint8_t dev_idx;
	uint32_t delay =200;
	for (dev_idx=0; dev_idx<can_config_ptr->can_nr_of_devices; dev_idx++)
	{
		do
		{
			delay--; /* Wait for TX */
		}while (((bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->ESR.R & 0xC0) == 0x40 )&& (delay > 0));
		
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.HALT = 1; /* Stop the module */
		delay = 200;
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.SOFTRST = 0x1;       /* Reset the CAN Module */
		do
		{
			delay--; /* Wait for Soft Reset */
		}while ((bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.SOFTRST)  && (delay > 0));

		/* Entering Disable Mode */
		bios_cnf_can_eng[can_config_dev_ptr[dev_idx]->can_eng_dev]->MCR.B.MDIS = 0x1;          /* Disable the CAN module */ 
	}
	/* Disable Interrupt routines for all MB */
	INTC_InstallINTCInterruptHandler(CANB_Isr,88,0);
	INTC_InstallINTCInterruptHandler(CANB_Isr,89,0);
	INTC_InstallINTCInterruptHandler(CANB_Isr,90,0);
	INTC_InstallINTCInterruptHandler(CANB_Isr,91,0);
	INTC_InstallINTCInterruptHandler(CANB_Isr,92,0);
	INTC_InstallINTCInterruptHandler(CANB_Isr,93,0);
	}
/*~E*/
/*~E*/
