/*******************************************************************************/
/**
\file       MemAlloc_Cfg.c
\brief      Memowy Allocation configuration
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/

#include "MemAlloc_Cfg.h"

extern const u32 _heap_start_addr;   //En este quite el extern
extern const u32 _heap_end_addr;     //En este quitar el extern

const MemAllocConfigType MemAllocConfig = 
{
	(void*)&_heap_start_addr,
	(void*)&_heap_end_addr	
};
