/*~A*/
/*~+:Header*/
/*******************************************************************************/
/**
\file       can_types.c
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/
/*~E*/
#ifndef CAN_TYPES_H
#define CAN_TYPES_H
/*~A*/
/*~+:Imports*/
/*Microcontroller specific*/
#include "MCU_derivative.h" 

#include "typedefs.h"
/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Typedefs*/
typedef volatile struct FLEXCAN_tag    FLEXCAN2_Type;
/*~E*/
/*~A*/
/*~+:Structs*/
typedef struct{
uint32_t msg_id_field;                          /* CAN Message ID field */
uint16_t msg_time_stamp;                        /* CAN Message timestamp */
uint8_t msg_data_field[8];                      /* CAN Message Struct for Data field  */
uint8_t msg_dlc_field;                          /* CAN Message Data Length Code field */
uint8_t msg_ide;                                /* CAN Message ID Extended field */
uint8_t msg_buff_nr;                            /* CAN Message Buffer Number */
}CAN_MessageDataType;


typedef void (*CanCallbackNotification)(CAN_MessageDataType CanMessage);
typedef struct{
uint8_t     can_mb_nr;
uint8_t     can_dlc;
uint8_t     *can_sdu;
}CAN_PduType;


typedef struct{
unsigned  	can_ctrl_clksrc :1; /* Clock Source from pin EXTAL or System Clock */
unsigned	can_ctrl_presdiv:8; /* Prescaler Division Factor */
unsigned  	can_ctrl_rjw    :2; /* Resync Jump Width */
unsigned  	can_ctrl_pseg1  :3; /* Phase Segment 1 */
unsigned  	can_ctrl_pseg2  :3; /* Phase Segment 2 */
unsigned  	can_ctrl_propseg:3; /* Propagation Segment */
}CAN_DevBaudrateType;

typedef struct{
uint8_t     can_msg;                 /* CAN Message Buffer number */
unsigned    can_msg_op          :1;  /* Message operation mode as Tx or Rx */
unsigned    can_msg_rtr        :1;  /* Message Remote Transmission Request */
unsigned    can_msg_id_length  :1;  /* Message Length */
unsigned    can_msg_id         :29; /* Message Identifier */
unsigned    can_msg_mask       :29; /* Message Mask */
CanCallbackNotification CallbackFcnt;                /* Callback  */
}CAN_ConfigMsgType;

typedef struct{
uint8_t     can_eng_dev;                         /* CAN Engine device number */
uint8_t     can_nr_of_msg;                        /* Number of Channles for this device */
unsigned    can_ctrl_boffrec:1;                 /* Automatic recovery from Bus Off state */
unsigned    can_ctrl_lbuf   :1;                 /* Ordering mechanism for Message Buffer transmission */
unsigned    can_ctrl_fifo   :1;                 /* FIFO feature is enabled or disable */
unsigned    can_ctrl_mbfen  :1;                 /* Enable individual masking or global masking */
CAN_DevBaudrateType *can_dev_baudrate;         /* CAN Baudrate Configuration */
CAN_ConfigMsgType *can_dev_messages;           /* Configured channels for this CAN Engine */
}CAN_ConfigDeviceType;

typedef struct{
uint8_t can_nr_of_devices;                  /* Number of CAN Engines */
CAN_ConfigDeviceType *can_device;             /* Pointer to CAN Config */
}CAN_ConfigType;


/*~E*/
#endif
