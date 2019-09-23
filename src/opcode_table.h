#ifndef opcode_table_h
#define opcode_table_h

//some documention:

//instructions:
#define instr(x) INSTRUCTION_ ## x

//no op
#define INSTRUCTION_NOP 0x00

//integer operations
#define INSTRUCTION_ADD
#define INSTRUCTION_SUB
#define INSTRUCTION_MUL
#define INSTRUCTION_DIV 
#define INSTRUCTION_IMUL
#define INSTRUCTION_IDIV
#define INSTRUCTION_NEG

// float operations
#define INSTRUCTION_FADD
#define INSTRUCTION_SUB 
#define INSTRUCTION_FMUL 
#define INSTRUCTION_FDIV 
#define INSTRUCTION_FPOW 
#define INSTRUCTION_FROT

//convertion operations
// convert integer to float
#define INSTRUCTION_ITF
//convert float to int
#define INSTRUCTION_FTI


//binary operation
#define INSTRUCTION_NOT 
#define INSTRUCTION_OR 
#define INSTRUCTION_AND
#define INSTRUCTION_XOR 

//data moving

// load = moving values between memory to registers
// src1 is the pointer
// src2 is the value
// res1 will hold result
// load to memory byte
#define INSTRUCTION_LOADMB
// load to memory double byte
#define INSTRUCTION_LOADMD
// load to memory quad byte
#define INSTRUCTION_LOADMQ

// load from memory
#define INSTRUCTION_LOADR
// src1 pointer to memory
// res1 will hold result
// if u want specific size of data you can use the and opreation on the answer 

// mov move values between registers
#define INSTRUCTION_MOV
// uses 2 bytes to determine what registers to move between (one byte for each register)

// set instruction. set the res1 register
#define INSTRUCTION_SET

//stack manipulation
#define INSTRUCTION_PUSH 
#define INSTRUCTION_POP 

//pushes all the registers to the stack to save them
#define INSTRUCTION_SAVE

//pop all the registers from the stack to restore them
#define INSTRUCTION_REST


//control flow
#define INSTRUCTION_JMP 
#define INSTRUCTION_CALL
#define INSTRUCTION_RET
#define INSTRUCTION_INT 

//io operations
#define INSTRUCTION_IN
#define INSTRUCTION_OUT


//misc
#define CPUID

#endif