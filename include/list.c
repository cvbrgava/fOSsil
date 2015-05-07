/*
 * @file list.c
 * @brief list data structure implementation.
 *
 *  @date Mar 4, 2015
 *      @author: c_rajend
 */

#include "list.h"

/**
 * @fn void list_init(LIST * l, uint8 i_size)
 * @param LIST * l - list data structure to init with default state. Allocate memory for members.
 * @param uint8 i_size - element size.
 * @return -
 * */
void list_init(LIST * l, uint8 i_size){
	l->alloc_len = 10;
	l->data = malloc(10 * i_size);
	l->len = 0;
	l->i_size = i_size;
}

/**
 * @fn void list_add_item(LIST * l, int item)
 * @param LIST * l - list data structure to add member.
 * @param int item - Item member to add in given list.
 * @return -
 * */
void list_add(LIST * l, void * item) {
	if(l->len == l->alloc_len) {
		l->data = realloc(l->data, 2 * l->alloc_len);
		l->alloc_len = 2 * l->alloc_len;
	}
	//l->data[l->len] = item;
	memcpy((l->len * l->i_size) + (uint32)l->data, item, l->i_size);
	l->len++;
}

/**
 * @fn void * list_index(LIST *l, uint8 index)
 * @brief	Get the item from list at given index. Index implementation is make like circular list.
 * 			You can provide index more than list length, and can be provided negative index as well.
 * @param LIST * l - list data structure to read index member.
 * @param uint8 index - index no. to read in given list data structure.
 * @return void * - Pointer to data at index.
 * */
void * list_index(LIST *l, int index) {
	//Index processing.
	if (index < 0) {		//Negative index
		while (index < 0)
			index += (l->len);
	}
	else if (index >= l->len ) {		//Too large index.
		while (index >= l->len )
			index -= (l->len);
	}
	else {
		//index is in range of 0 to ((l->len) -1) .
	}

	return (void *)((uint32)l->data + (index * (l->i_size)));
}

/**
 * @fn void	list_deinit		(LIST * l)
 * @brief	Destruct given list and free the allocated memory.
 * @param LIST * l - list data structure to destruct.
 * @return -
 * */
void	list_deinit		(LIST * l) {
	free(l->data);
}

/**
 * @fn void list_testing()
 * @brief	List test function.
 * @return -
 * */
void list_testing() {
	LIST l;
	char * value;
	char c = 'a';

	list_init(&l, sizeof(c));

	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);
	list_add(&l, &c);

	value = list_index(&l,1);
	value = list_index(&l,-1);
	value = list_index(&l,1100);
	value = list_index(&l,-101);
	value = list_index(&l,5);
}
