#ifndef opcode_table_h
#define opcode_table_h 1

enum ac_register
{
	ac_register_r0 = 0,
	ac_register_r1,
	ac_register_r2,
	ac_register_r3,
	ac_register_r4,
	ac_register_r5,
	ac_register_r6,
	ac_register_r7,
	ac_register_r8,
	ac_register_r9,
	ac_register_r10,
	ac_register_r11,
	
	ac_register_sp = ac_register_r8,
	ac_register_bp = ac_register_r9,
	ac_register_flags = ac_register_r10,
	ac_register_ip = ac_register_r11,
	
	ac_register_r255 = 255,
	ac_register_nullreg = ac_register_r255
}

enum ac_instruction
{
	ac_instruction_nop,
	ac_instruction_add,
	ac_instruction_sub,
	ac_instruction_umul,
	ac_instruction_udiv,
	ac_instruction_smul,
	ac_instruction_sdiv,
	ac_instruction_neg,
	ac_instruction_fadd,
	ac_instruction_fsub,
	ac_instruction_fmul,
	ac_instruction_fdiv,
	ac_instruction_fpow,
	ac_instruction_fabs,
	ac_instruction_ftrig,
	ac_instruction_flog,
	ac_instruction_itf,
	ac_instruction_fti,
	ac_instruction_not,
	ac_instruction_or,
	ac_instruction_and,
	ac_instruction_xor,
	ac_instruction_memb,
	ac_instruction_memd,
	ac_instruction_memq,
	ac_instruction_ldb,
	ac_instruction_ldd,
	ac_instruction_ldq,
	ac_instruction_mov,
	ac_instruction_set,
	ac_instruction_swap,
	ac_instruction_push,
	ac_instruction_pop,
	ac_instruction_jmpa,
	ac_instruction_jmpr,
	ac_instruction_call,
	ac_instruction_callr,
	ac_instruction_ret,
	ac_instruction_shr
	ac_instruction_shl,
	ac_instruction_ror,
	ac_instruction_rol,
	ac_instruction_setbit,
	ac_instruction_cc,
	ac_instruction_save,
	ac_instruction_rest
}

#endif