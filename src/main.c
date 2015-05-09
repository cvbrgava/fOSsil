#include "fOSsil.h"

void task1() {
	static uint32 i = 0;
	while(i<10)
		i ++;
}

void task2() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void task3() {
	static uint32 i = 0;
	while(1)
		i ++;
}

void main() {
	// Interrupt registration.
	//vv_int_set_vector (PendSV_IRQn, PENDSV_Handler);
	ds_stacked_list_test();

	// OS init.
	os_init();

	// Register tasks.
	task_create(&task1, 0x10, 0, 1);
	task_create(&task2, 0x10, 0, 2);
	task_create(&task3, 0x10, 0, 3);

	// OS init.
	os_run();

	// Unreachable.
	while(1);
}
