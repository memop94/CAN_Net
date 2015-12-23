/*~A*/
/*~+:Header*/
/*******************************************************************************/
/**
\file       can.h
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/
/*~E*/
#ifndef CAN_H
#define CAN_H
/*~A*/
/*~+:Imports*/
#include "BIOS/BIOS_Can_Types.h"

/*~E*/
/*~A*/
/*~+:Defines*/
#define MAX_MSG_TO_DISP (10)
#define MAX_MSG_TX_TO_DISP (3)
/*~E*/
/*~A*/
/*~+:Public Variables*/
extern CAN_MessageDataType    received_messages[64];
extern CAN_MessageDataType    txd_messages[64];
/*~E*/
/*~A*/
/*~+:Public Operations*/
extern void CAN_Initialization(CAN_ConfigType *can_config);
extern void CAN_SendFrame(CAN_PduType *pdu_handler);
extern uint8_t CAN_ReceiveFrame(uint8_t message_buffer, CAN_MessageDataType *can_message );
extern void CAN_Stop(void);
extern uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len);  //Yo la puse
extern void CANB_Isr(void); //Yo l apuse
extern void CAN_IO_Config(void);  //Yo la puse
/*~E*/
#endif
