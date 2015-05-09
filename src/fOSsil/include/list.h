/*
 * @file list.h
 * @brief list data structure header implementation for QTwister framework.
 *
 *  @date Mar 4, 2015
 *      @author: c_rajend
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include "types.h"

/**
 * @struct list
 * @brief  List data structure for QTwister framework.
 * */
struct list{
	void * data;
	uint8 i_size;
	uint32 len;
	uint32 alloc_len;
};

typedef struct list LIST;

void	list_init		(LIST * l, 	uint8 i_size);
void	list_add		(LIST * l,	void * item);
void *	list_index		(LIST * l,	int index);
void	list_deinit		(LIST * l);

#endif
