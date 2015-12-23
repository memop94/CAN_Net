#include "MemAlloc.h"
/*
 * MemAlloc.c
 *
 *  Created on: Dec 3, 2015
 *      Author: uidp2581
 */

/**
 * Globals
 */
static u8 * pool_start;
static u8 * pool_end;

/** 
 * Function: MemAllocInit  
 * @brief Initializes a memory pool for dynamic memory allocation.
 * @param MemAllocConfigParam
 * */

void MemAllocInit(const MemAllocConfigType *MemAllocConfigParam)
{
	pool_start = (u8 *)(MemAllocConfigParam->MemAllocHeapStartAddr);
	pool_end = (u8 *)(MemAllocConfigParam->MemAllocHeapEndAddr);
}

/**
 * Function MemAlloc
 * @brief Returns a pointer to a free memory area to use as you wish.
 */

void * MemAlloc(u32 size)
{
	if(size < (pool_end - pool_start))
	{
		return (void *)pool_start;
	}
	else
		return (void *)0x00000000;
}


