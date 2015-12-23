/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       SchM_Tasks.c
\brief      Application Tasks
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "SERVICES/SERV_SchM_Tasks.h"
#include "SERVICES/SERV_Can_Manager.h"
#include "APPLICATION/APP_dummy.h"
/*~E*/
/*~A*/
/*~+:Scheduler Tasks*/
/*~A*/
/*~+:SchM_3p125ms_Task*/

void SchM_3p125ms_Task(void)
{

}
/*~E*/
/*~A*/
/*~+:SchM_6p25ms_Task*/

void SchM_6p25ms_Task(void)
{
	Test();
}
/*~E*/
/*~A*/
/*~+:SchM_12p5ms_Task*/

void SchM_12p5ms_Task(void)
{
	CanManager_SendMessage_12p5ms();
}
/*~E*/
/*~A*/
/*~+:SchM_25ms_Task*/

void SchM_25ms_Task(void)
{
	CanManager_SendMessage_25ms();
}
/*~E*/
/*~A*/
/*~+:SchM_50ms_Task*/

void SchM_50ms_Task(void)
{
	
}
/*~E*/
/*~A*/
/*~+:SchM_100ms_Task*/

void SchM_100ms_Task(void)
{
	CanManager_SendMessage_100ms();
}
/*~E*/
/*~E*/
