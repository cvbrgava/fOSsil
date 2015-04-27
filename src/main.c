#include "cm3_lib.h"
#include <stdio.h>
#include <time.h>

time_t start_t, time_now;

void main(){
	//printf("Hello World!\n");
	start_t = time(NULL);
	
	//Little
	SysTick_Config( 100000 );

	while(1){;}

}


