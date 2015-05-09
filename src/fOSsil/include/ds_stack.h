/*
 * ds_stack.h
 *
 *  Created on: May 9, 2015
 *      Author: c_rajend
 */

#ifndef DS_STACK_H_
#define DS_STACK_H_

#include "types.h"

#define DS_STACK_INIT_DEF_LEN 10

typedef struct ds_stack {
	uint32 elem_len;
	uint32 len;
	uint32 alloc_len;
	uint32 * sp;
} DS_STACK;

void  	ds_stack_init	( DS_STACK* s, uint32 elem_len );
void 	ds_stack_push	( DS_STACK* s, void * data );
void * 	ds_stack_pop	( DS_STACK* s );
void 	ds_stack_free	( DS_STACK* s );

#endif
