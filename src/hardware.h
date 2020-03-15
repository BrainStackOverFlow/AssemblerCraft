#ifndef hardware_h
#define hardware_h 1

#include <stdint.h>


typedef int8_t byte;
typedef int16_t doublebyte;
typedef int32_t quadbyte;

// a register in the processor is in the size of 32bits
typedef quadbyte ac_reg_t; 

typedef doublebyte ac_instruction_t;

typedef union ac_core {
	struct {
		// general general purpose registers r0-r7
		ac_reg_t r0;
		ac_reg_t r1;
		ac_reg_t r2;
		ac_reg_t r3;
		ac_reg_t r4;
		ac_reg_t r5;
		ac_reg_t r6;
		ac_reg_t r7;
		
		ac_reg_t sp; // the stack pointer, its r8
		
		ac_reg_t bp; // the base pointer, its r9
		
		ac_reg_t flags; // the flag register, its r10
		
		ac_reg_t ip; // the instruction pointer, r11
	};
	
	ac_reg_t regs[sizeof(ac_reg_t) * 12];
} ac_core_t;

typedef struct ac_processor 
{
	ac_core_t* processor_cores;
	ac_reg_t number_of_cores;
	
} ac_processor_t;

typedef struct ac_ram
{
	// get a value from the ingame computer ram
	ac_reg_t (*get_value_from_ram)(ac_reg_t ptr, int how_many_bytes);
	
	// put a value to the ingame computer ram
	// how_many_bytes should be 1, 2 or 4
	int (*put_value_to_ram)(ac_reg_t ptr, ac_reg_t value, int how_many_bytes);
} ac_ram_t;

typedef struct ac_motherboard {
	ac_processor_t processor;
	ac_reg_t number_of_processors;
	
	ac_ram_t ram;
	
	ac_core_t input_coprocessor;
} ac_motherboard_t;

// tell the processor to execute one instruction
void ac_processor_execute_instruction(ac_motherboard_t* motherboard, ac_reg_t core_num);

// a function type for instructions
typedef void (*ac_instruction_func_t)(ac_motherboard_t* motherboard, ac_reg_t core_num);

ac_instruction_func_t get_instruction_func(ac_instruction_t opcode);
#endif