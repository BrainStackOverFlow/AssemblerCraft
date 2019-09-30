#ifndef opcode_table_h
#define opcode_table_h



//instructions:
#define instr(x) INSTRUCTION_ ## x

//no op
#define INSTRUCTION_NOP 0x00

//integer operations
#define INSTRUCTION_ADD 0x01
#define INSTRUCTION_SUB 0x02
#define INSTRUCTION_UMUL 0x03
#define INSTRUCTION_UDIV 0x04
#define INSTRUCTION_SMUL 0x05
#define INSTRUCTION_SDIV 0x06
#define INSTRUCTION_NEG 0x07

// float operations
#define INSTRUCTION_FADD 0x08
#define INSTRUCTION_FSUB 0x09
#define INSTRUCTION_FMUL 0x0a
#define INSTRUCTION_FDIV 0x0b
#define INSTRUCTION_FPOW 0x0c
#define INSTRUCTION_FROT 0x0d
#define INSTRUCTION_FABS 0x26
#define INSTRUCTION_FSIN 0x27
#define INSTRUCTION_FCOS 0x28
#define INSTRUCTION_FLOG 0x29

//convertion operations
// convert integer to float
#define INSTRUCTION_ITF 0x0e
//convert float to int
#define INSTRUCTION_FTI 0x0f


//binary operation
#define INSTRUCTION_NOT 0x10
#define INSTRUCTION_OR 0x11
#define INSTRUCTION_AND 0x12
#define INSTRUCTION_XOR 0x13

//data moving

// load = moving values between memory to registers
// src1 is the pointer
// src2 is the value
// res1 will hold result
// load to memory byte
#define INSTRUCTION_LOADMB 0x14
// load to memory double byte
#define INSTRUCTION_LOADMD 0x15
// load to memory quad byte
#define INSTRUCTION_LOADMQ 0x16

// load from memory
#define INSTRUCTION_LOADR 0x17
// src1 pointer to memory
// res1 will hold result
// if u want specific size of data you can use the and opreation on the answer 

// mov move values between registers
#define INSTRUCTION_MOV 0x18
// uses 2 bytes to determine what registers to move between (one byte for each register)

// set instruction. set the res1 register
#define INSTRUCTION_SET 0x19

#define INSTRUCTION_SWAP 0x1a

//stack manipulation
#define INSTRUCTION_PUSH 0x1b
#define INSTRUCTION_POP 0x1c

//pushes all the registers to the stack to save them
#define INSTRUCTION_SAVE 0x1d

//pop all the registers from the stack to restore them
#define INSTRUCTION_REST 0x1e


//control flow
#define INSTRUCTION_JMP 0x1f
#define INSTRUCTION_CALL 0x20
#define INSTRUCTION_RET 0x21
#define INSTRUCTION_INT 0x22

//io operations
#define INSTRUCTION_IN 0x23
#define INSTRUCTION_OUT 0x24


//misc
#define CPUID 0x25

#endif