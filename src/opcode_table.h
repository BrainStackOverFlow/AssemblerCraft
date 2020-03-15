#ifndef opcode_table_h
#define opcode_table_h 1

enum ac_reg_index
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
};

enum ac_flag_index
{
	ac_flag_cb,
	ac_flag_zf,
	ac_flag_sf,
	ac_flag_cf,
	ac_flag_of,
	ac_flag_idbz,
	ac_flag_fdbz,
	ac_flag_ur,
	ac_flag_maf
};

enum ac_instruction_opcode
{
	ac_instruction_nop_opcode,
	ac_instruction_add_opcode,
	ac_instruction_sub_opcode,
	ac_instruction_umul_opcode,
	ac_instruction_udiv_opcode,
	ac_instruction_smul_opcode,
	ac_instruction_sdiv_opcode,
	ac_instruction_neg_opcode,
	ac_instruction_fadd_opcode,
	ac_instruction_fsub_opcode,
	ac_instruction_fmul_opcode,
	ac_instruction_fdiv_opcode,
	ac_instruction_fpow_opcode,
	ac_instruction_fabs_opcode,
	ac_instruction_ftrig_opcode,
	ac_instruction_flog_opcode,
	ac_instruction_itf_opcode,
	ac_instruction_fti_opcode,
	ac_instruction_not_opcode,
	ac_instruction_or_opcode,
	ac_instruction_and_opcode,
	ac_instruction_xor_opcode,
	ac_instruction_memb_opcode,
	ac_instruction_memd_opcode,
	ac_instruction_memq_opcode,
	ac_instruction_ldb_opcode,
	ac_instruction_ldd_opcode,
	ac_instruction_ldq_opcode,
	ac_instruction_lea_opcode,
	ac_instruction_mov_opcode,
	ac_instruction_set_opcode,
	ac_instruction_swapm_opcode,
	ac_instruction_cmpswapm_opcode,
	ac_instruction_push_opcode,
	ac_instruction_pop_opcode,
	ac_instruction_jmpa_opcode,
	ac_instruction_jmpr_opcode,
	ac_instruction_call_opcode,
	ac_instruction_callr_opcode,
	ac_instruction_ret_opcode,
	ac_instruction_shr_opcode,
	ac_instruction_shl_opcode,
	ac_instruction_ror_opcode,
	ac_instruction_rol_opcode,
	ac_instruction_setbit_opcode,
	ac_instruction_cc_opcode,
	ac_instruction_save_opcode,
	ac_instruction_rest_opcode,
	ac_instruction_int_opcode,
	ac_instruction_in_opcode,
	ac_instruction_out_opcode
};

#endif