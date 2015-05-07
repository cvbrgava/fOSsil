
/*
 * main.h
 *
 *  Created on: May 3, 2015
 *      Author: c_rajend
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct stask {
	uint32 * func_pointer;
	uint32 * sp_process;
	int8 priority;
} TASK;

typedef struct context_frame {
	uint32 reg[8];	//r4-r11
} CONTEXT_FRAME;

typedef struct stacking_frame {
	uint32 r0;
	uint32 r1;
	uint32 r2;
	uint32 r3;
	uint32 r12;
	uint32 LR;
	uint32 return_addr;
	uint32 psr;
} STACKING_FRAME;

typedef struct task_reg {
	uint32 LR;
	uint32 return_addr;
	uint32 psr;
} TASK_REG;

typedef struct context {
	CONTEXT_FRAME cf;
	STACKING_FRAME sf;
} CONTEXT;

#endif /* MAIN_H_ */
