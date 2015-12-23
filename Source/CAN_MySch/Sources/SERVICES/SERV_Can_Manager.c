/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "SERVICES/SERV_Can_Manager.h"
/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Variables*/

/* Temporary CAN Data Messages */
uint8_t dummy_msg0[8] = {0xCA,0x83,0x15,0x77,0x19,0x56,0x65,0x00};
uint8_t dummy_msg1[8] = {0x00,0x65,0x56,0x19,0x77,0x15,0x83,0xCA};
uint8_t dummy_msg2[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};
uint8_t dummy_msg8[2] = {0x00,0x00};
uint8_t dummy_msg9[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};

/** PDU: Protocol data unit */
CAN_PduType    pdu_handler4 = { 4, 8, dummy_msg0};
CAN_PduType    pdu_handler5 = { 5, 6, dummy_msg1};
CAN_PduType    pdu_handler6 = { 6, 2, dummy_msg2};
CAN_PduType    pdu_handler7 = { 2, 4, dummy_msg2};
CAN_PduType    pdu_handler8 = { 8, 2, dummy_msg8};
CAN_PduType    pdu_handler9 = { 9, 8, dummy_msg9};

uint32_t PduHandlerCnt0 = 0;
uint32_t PduHandlerCnt6 = 0;
uint16_t pdu_handler8_cnt = 0;


/*~E*/
/*~A*/
/*~+:Private Operations*/

/*~E*/
/*~A*/
/*~+:Public Operations*/
/*~A*/
/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;
CAN_MessageDataType CanMessage_PduHandler7;
uint8_t msg_rx_pdu0 = 0;
uint8_t msg_rx_pdu7 = 0;
void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler0 = CanMessage;
	pdu_handler7.can_mb_nr = 7;
	pdu_handler7.can_dlc = CanMessage_PduHandler0.msg_dlc_field;
	pdu_handler7.can_sdu = CanMessage_PduHandler0.msg_data_field;
	msg_rx_pdu0 = 1;
	PduHandlerCnt0++;
}

void Can_Manager_PduHandler7(CAN_MessageDataType CanMessage)
{
	
	CanMessage_PduHandler7 = CanMessage;
	msg_rx_pdu7 = 1;
	pdu_handler8_cnt++;
	dummy_msg8[0]++;
	if (256 == pdu_handler8_cnt)
	{
		pdu_handler8_cnt = 0;
		dummy_msg8[0] = 0;
		dummy_msg8[1]++;
	}
	PduHandlerCnt6++;
}

/*~E*/
/*~A*/
/*~+:Can Manager Periodic Functions*/
/*~A*/
/*~+:CanManager_SendMesage_12p5ms*/
CAN_MessageDataType CanMessage_PduHandler2;
void CanManager_SendMessage_12p5ms(void)
{
	CAN_SendFrame(&pdu_handler4);
	if ( 1 == CAN_ReceiveFrame(2, &CanMessage_PduHandler2 ))
	{
		pdu_handler9.can_mb_nr = 9;
		pdu_handler9.can_dlc = CanMessage_PduHandler2.msg_dlc_field;
		pdu_handler9.can_sdu = CanMessage_PduHandler2.msg_data_field;
		CAN_SendFrame(&pdu_handler9);
	}
}
/*~E*/
/*~A*/
/*~+:CanManager_SendMesage_25ms*/
void CanManager_SendMessage_25ms(void)
{
	CAN_SendFrame(&pdu_handler6);
	/*~A*/
	/*~+:PDU 0*/
	
	
	if (msg_rx_pdu0)
	{
		msg_rx_pdu0 = 0;
		CAN_SendFrame(&pdu_handler7);
	}
	
	/*~E*/
	/*~A*/
	/*~+:PDU 7*/
	
	if (msg_rx_pdu7)
	{
		msg_rx_pdu7 = 0;
		CAN_SendFrame(&pdu_handler8);
	}
	
	/*~E*/
}
/*~E*/
/*~A*/
/*~+:CanManager_SendMessage_100ms*/
void CanManager_SendMessage_100ms(void)
{
	CAN_SendFrame(&pdu_handler5);
}
/*~E*/
/*~E*/
/*~E*/
