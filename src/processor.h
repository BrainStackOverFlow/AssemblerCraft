#ifndef processor_h
#define processor_h 1

#include <stdint.h>

// a register in the processor is in the size of 32bits
typedef uint32_t reg_t; 

typedef union core_t {
	struct {
		// general general purpose registers r0-r7
		reg_t r0;
		reg_t r1;
		reg_t r2;
		reg_t r3;
		reg_t r4
		reg_t r5;
		reg_t r6;
		reg_t r7;
		
		reg_t sp; // the stack pointer, its r8
		
		reg_t bp; // the base pointer, its r9
		
		reg_t flags; // the flag register, its r10
		
		reg_t ip; // the instruction pointer, r11
	};
	
	reg_t regs[sizeof(reg_t) * 12];
} core;

#endif