/*
 * ds_stacked_list.c
 *
 *  Created on: May 9, 2015
 *      Author: c_rajend
 */
#include "ds_stacked_list.h"

void ds_stacked_list_int(DS_STACKED_LIST * sl) {
	sl->container = ( DS_NODE*)malloc( DS_STACKED_LIST_DEFAULT_LEN * sizeof( DS_NODE ));
	sl->alloc_len = DS_STACKED_LIST_DEFAULT_LEN ;
	sl->len = 0 ;

	ds_stack_init(&(sl->holes), sizeof(DS_NODE *));
}

void ds_stacked_list_add(DS_STACKED_LIST * sl, DS_NODE n) {
	if( sl->len == sl->alloc_len){
		sl->alloc_len = 2*(sl->alloc_len);
		sl->container = (DS_NODE*)realloc(sl->container, (sl->alloc_len) * sizeof( DS_NODE ));
	}

	memcpy(sl->container + sl->len, &n, sizeof( DS_NODE ));

	if(sl->len != 0) {
		sl->container[sl->len - 1 ].next_data =&(sl->container[sl->len]); //Point last element's next to present one.
	}

	sl->container[sl->len ].next_data = &(sl->container[0]);	//Pointing last to fist.

	sl->len++;
}

void ds_stacked_list_test() {
	int i = 0;
	DS_STACKED_LIST sl;
	DS_NODE n = {0,0};

	ds_stacked_list_int(&sl);

	for (i =0; i< 12; i++)
	{
		n.data = i;
		ds_stacked_list_add(&sl, n);
	}

}

void ds_stacked_list_free(DS_STACKED_LIST * sl) {
	free(sl->container);
}
