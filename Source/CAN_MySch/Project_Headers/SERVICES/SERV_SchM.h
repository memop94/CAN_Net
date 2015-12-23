/*******************************************************************************/
/**
\file       SchM.h
\brief      SchM header file
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
#ifndef __SchM_H
#define __SchM_H

#include "SERVICES/SERV_SchM_Types.h"

extern void SchM_Init(const SchM_ConfigType *SchMConfigParam);
extern void SchM_Start(void);
extern void SchM_Stop(void);
extern void SchM_OsTick(void); //Yo la puse
extern void SchM_Background(void);  //Yo la puse


#endif /* __SchM_H */
