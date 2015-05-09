#include <stdlib.h>
#include "ds_stack.h"

void ds_stack_init(DS_STACK* s, uint32 elem_len ) {
	s->len = 0;
	s->alloc_len = DS_STACK_INIT_DEF_LEN;
	s->elem_len = elem_len;

	s->sp = malloc(DS_STACK_INIT_DEF_LEN * s->elem_len ) ;

}

void ds_stack_push( DS_STACK* s, void * data) {
	if(s->len == s->alloc_len)
	{
		s->alloc_len = 2 * s->alloc_len;
		s->sp = realloc(s->sp, (s->alloc_len)*(s->elem_len));
	}

	memcpy(s->sp + s->len, data, s->elem_len);
	s->len++;
}

void * ds_stack_pop( DS_STACK* s) {
	if(s->len == 0)
		return NULL;

	s->len--;

	return (s->sp + s->len + 1);
}

void ds_stack_free( DS_STACK* s){
	free(s->sp);
}
