/*
 * ds_stacked_list.h
 *
 *  Created on: May 9, 2015
 *      Author: c_rajend
 */

#ifndef DS_STACKED_LIST_H_
#define DS_STACKED_LIST_H_

#include "ds_stack.h"

#define DS_STACKED_LIST_DEFAULT_LEN 10

typedef struct ds_node {
	int data;			//TODO: make it generic.
	struct ds_node* next_data;
} DS_NODE;

typedef struct stacked_list {
	int len;
	int alloc_len;
	// STACK* holes;
	DS_NODE * container;
	DS_STACK holes;
} DS_STACKED_LIST;

void ds_stacked_list_int(DS_STACKED_LIST * sl);
void ds_stacked_list_free(DS_STACKED_LIST * sl);

#endif /* STACKED_LIST_H_ */
