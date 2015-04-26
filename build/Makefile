VPATH=../include/:../src/

CC=/pkg/qct/software/arm/RVDS/4.1BLD894/RVCT/Programs/4.1/462/linux-pentium/armcc
CFLAGS= -c  -O0  -g --cpu=Cortex-M3 --fpu softvfp --loose_implicit_cast
CFLAGS+=--split_sections
INC=-I/pkg/qct/software/arm/RVDS/4.1BLD894/RVCT/Data/4.1/462/include/unix/ -I../include/
MACRO=

LINKER=/pkg/qct/software/arm/RVDS/4.1BLD894/RVCT/Programs/4.1/462/linux-pentium/armlink
SCATTERFILE=/prj/vlsi/vlsi_verify/vi_estel/ASIC/c_rajend/c_rajend_blr-vilab27_memvex_estel/shared_code/vi/rpm_proc/scf/rpm_coderam_nobootrom.scf 
LDFLAGS=--info totals --entry=Reset_Handler --map --scatter $(SCATTERFILE)  --info sizes --callgraph --datacompressor off --map

AS=/pkg/qct/software/arm/RVDS/4.1BLD894/RVCT/Programs/4.1/462/linux-pentium/armasm
ASFLAGS=--keep -g --cpu=Cortex-M3 --fpu=softvfp
ARMLIB=/pkg/qct/software/arm/RVDS/4.1BLD894/RVCT/Data/4.1/462/lib/armlib/c_w.l /pkg/qct/software/arm/RVDS/4.1BLD894/RVCT/Data/4.1/462/lib/armlib/fz_ws.l 

OBJ=cm3_handlers.o\
	cm3_vec_table.o\
	core_cm3.o\
	process_stack.o\
	stack.o\
	heap.o\
	retarget.o\
	main.o \


%.o : %.s

	$(CC)  -E $(CFLAGS) $(INC) $(MACRO) <$(basename $<).s | perl /prj/vlsi/vlsi_verify/vi_shere/Tools/v1_24/build/ppasm.pl - > $(basename $<).i   
	$(AS) $(ASFLAGS) $(basename $<).s -o $@ 

%.o : %.c

	$(CC) $(CFLAGS) $(INC) $(MACRO) -c $< -o $@

all: $(OBJ)

	$(LINKER) $(LDFLAGS) $(ARMLIB) -o fOSsil.axf $^ 

clean:
	rm -rf *.o *.i *.axf
