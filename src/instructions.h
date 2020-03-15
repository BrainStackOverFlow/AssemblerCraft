#ifndef instructions_h
#define instructions_h 1

// read from a register
ac_reg_t register_read(ac_motherboard_t* motherboard, ac_reg_t core_num, enum ac_reg_index reg_number);

// write to a register
// if return value = 0 -> success
int register_write(ac_motherboard_t* motherboard, ac_reg_t core_num, enum ac_reg_index reg_number, ac_reg_t value);

// get 1/2/4 bytes from the instruction memory 
ac_reg_t get_instruction_memory(ac_motherboard_t* motherboard, ac_reg_t core_num, int how_many_bytes);

// get the bit mask of a flag
ac_reg_t get_flag_bitmask(enum ac_flag_index flag_index);

#endif