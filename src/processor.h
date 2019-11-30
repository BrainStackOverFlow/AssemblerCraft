#ifndef processor_h
#define processor_h 1

#include <stdint.h>
#include <jni.h>

// a register in the processor is in the size of 32bits
typedef uint32_t reg_t; 

typedef union core_t {
	struct {
		reg_t res1; //r0
		// result value 1 of operations
		
		reg_t res2; //r1
		// result value 2 of operations
		
		reg_t src1; //r2
		// source value 1 of operations
		
		reg_t src2; //r3
		// source value 2 of operations
		
		reg_t dr1; //data register no 1
		reg_t dr2; //data register no 2
		reg_t dr3; //data register no 3
		reg_t dr4; //data register no 4
		
		reg_t sp; //
		// stack pointer
		
		reg_t bp;
		// base pointer
		
		reg_t flags;
		//flag register
		
		reg_t ip;
		// instruction pointer
	};
	
	reg_t regs[sizeof(reg_t) * 12];
} core;

#endif