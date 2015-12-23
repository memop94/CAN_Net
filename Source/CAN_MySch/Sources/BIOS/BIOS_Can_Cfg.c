/*~A*/
/*~+:Header*/
/*******************************************************************************/
/**
\file       can_cfg.c
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/
/*~E*/
/*~A*/
/*~+:Imports*/
#include "BIOS/BIOS_Can_Cfg.h"
#include "SERVICES/SERV_Can_Manager.h"
/*~E*/
/*~A*/
/*~+:Defines*/
#define MAX_NUM_RX_FILTERS  (4)
#define MAX_NUM_TX_FILTERS  (2)
/*~E*/
/*~A*/
/*~+:External Interfaces*/
extern uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len);
/*~E*/
/*~A*/
/*~+:Variables*/
/*~A*/
/*~+:CAN Baudrate Configuration*/
CAN_DevBaudrateType bios_cnf_can_baudrate_options[] = {
/***********************************************************************************/
/* Propagation Segment------------------------------+                              */
/* Phase Segment 2-------------------------------+  |                              */
/* Phase Segment 1----------------------------+  |  |                              */
/* Resync Jump Width-----------------------+  |  |  |                              */
/* Baudrate Prescaler------------------+   |  |  |  |                              */
/* Clock Source ------------+          |   |  |  |  |                              */
/*                          |          |   |  |  |  |                              */
                     {CNF_CAN_OSC_CLK, 1,  2, 2, 2, 3},     /* BR 1Mbps            */
                     {CNF_CAN_OSC_CLK, 2,  2, 2, 2, 3},     /* BR 500kbps          */
                     {CNF_CAN_OSC_CLK, 4,  2, 2, 2, 3},     /* BR 250kbps          */
                     {CNF_CAN_OSC_CLK, 8,  2, 2, 2, 3}      /* BR 125kbps          */
};



/*~E*/
/*~A*/
/*~+:CAN Messages Configuration*/
CAN_ConfigMsgType bios_cnf_can_messages[] = {
 /* MB#, Message      , Message transmit ,  Message length , Message   ,	Message	  ,	Callback function 
  *     operation		remote request							ID			Mask
  *      TX / RX
  */
	{ 0, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x1A0,         0x1F8,      Can_Manager_PduHandler0  },
	{ 1, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_EXT, 0x12345600,    0x1FFFFFF8, NULL  },
	{ 2, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x1B0,         0x000,      NULL  },
	{ 3, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_EXT, 0x13579B00,    0x00000000, NULL  },
	{ 4, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x1A7,         0x1F8,      NULL  },
	{ 5, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_EXT, 0x12345604,    0x1FFFFFF8, NULL  },
	{ 6, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x052,         0x1F7,      NULL  },
	{ 7, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_EXT, 0x123456AA,    0x1FFFFFF8, Can_Manager_PduHandler7  },
	{ 8, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x1CF,         0x1FFFFFFF, NULL  },
	{ 9, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_EXT, 0x1A654321,    0x1FFFFFFF, NULL  }
};

/*~E*/
/*~A*/
/*~+:CAN Device Configuration*/
CAN_ConfigDeviceType bios_cnf_can_dev[] = 
{
	{
		CANB,                                           						/* CAN Device */
		( sizeof(bios_cnf_can_messages)/sizeof(bios_cnf_can_messages[0]) ),		/* Number of channels */
		CNF_CAN_BOFF_DIS,                               						/* Automatic Recovery OFF */
		CNF_CAN_LBUF_ON,                                						/* Lower buffer is transmitted first */
		CNF_CAN_FIFO_DIS,                               						/* FIFO Disabled */
		CNF_CAN_IND_MASK,                               						/* Filter mode Individual Mask */
		&bios_cnf_can_baudrate_options[1],              						/* CAN Baud rate Configuration */
		bios_cnf_can_messages,                  								/* Configured channels for this CAN Engine */
	}
};

/*~E*/
/*~A*/
/*~+:CAN Driver Configuration*/
CAN_ConfigType can_driver_config = {
( sizeof(bios_cnf_can_dev)/sizeof(bios_cnf_can_dev[0]) ),   /* Number of devices */
bios_cnf_can_dev                                            /* Pointer to devices configuration */
};

/*~E*/
/*~E*/
