#include <limits.h>
#include "opcode_table.h"
#include "hardware.h"
#include "instructions.h"

ac_reg_t get_flag_bitmask(enum ac_flag_index flag_index)
{
	return 1 << flag_index;
}

ac_reg_t register_read(ac_motherboard_t* motherboard, ac_reg_t core_num, enum ac_reg_index reg_number)
{
	if (reg_number == ac_register_nullreg) // if is the null register
	{
		return (ac_reg_t)0;
	}
	else if(sizeof(ac_core_t) < reg_number) // if register doesnt exist
	{
		register_write(motherboard, core_num, ac_register_flags, get_flag_bitmask(ac_flag_ur) | register_read(motherboard, core_num, ac_register_flags));
		return (ac_reg_t)0;
	}
	
	return (*motherboard).processor.processor_cores[core_num].regs[reg_number];
}

int register_write(ac_motherboard_t* motherboard, ac_reg_t core_num, enum ac_reg_index reg_number, ac_reg_t value)
{
	if (reg_number == ac_register_nullreg) // if is the null register
	{
		return 0;
	}
	else if(sizeof(ac_core_t) < reg_number) // if register doesnt exist
	{
		// set the unnexpected register true
		register_write(motherboard, core_num, ac_register_flags, get_flag_bitmask(ac_flag_ur) | register_read(motherboard, core_num, ac_register_flags));
		return -1;
	}
	
	(*motherboard).processor.processor_cores[core_num].regs[reg_number] = value;
	return 0;
}

ac_reg_t get_instruction_memory(ac_motherboard_t* motherboard, ac_reg_t core_num, int how_many_bytes)
{
	ac_reg_t ip = register_read(motherboard, core_num, ac_register_ip);

	ac_reg_t mem = (*motherboard).ram.get_value_from_ram(ip, how_many_bytes);

	ip = ip + how_many_bytes;

	register_write(motherboard, core_num, ac_register_ip, ip);

	return mem;
}

// nop instruction
void ac_instructions_nop(ac_motherboard_t* motherboard, ac_reg_t core_num)
{
	
}


void ac_instructions_internal_add(ac_motherboard_t* motherboard, ac_reg_t core_num, enum ac_reg_index dest, enum ac_reg_index src1, enum ac_reg_index src2)
{
	ac_reg_t number1 = register_read(motherboard, core_num, src1);
	ac_reg_t number2 = register_read(motherboard, core_num, src2);

	ac_reg_t sum;
	ac_reg_t flags = register_read(motherboard, core_num, ac_register_flags);

	sum = number1 + number2;

	if (((number2 > 0) && (number1 > (INT32_MAX - number2))) || ((number2 < 0) && (number1 < (INT32_MIN - number2)))) // if overflow set overflow flag
	{
    	flags = get_flag_bitmask(ac_flag_of) | flags;
	}
	else // if no overflow disable overflow flag
	{
		flags = ~get_flag_bitmask(ac_flag_of) & flags;
	}

    if (sum < 0) // if negative set sign flag
    {
    	flags = get_flag_bitmask(ac_flag_sf) | flags;
    }
    else // if not negative disable sign flag
    {
    	flags = ~get_flag_bitmask(ac_flag_sf) & flags; 
    }
	
	if (sum == 0) // if zero set the zero flag
	{
		flags = get_flag_bitmask(ac_flag_zf) | flags;
	}
	else // if not zero disable the zero flag
	{
		flags = ~get_flag_bitmask(ac_flag_zf) & flags; 
	}

	register_write(motherboard, core_num, dest, sum);
	register_write(motherboard, core_num, ac_register_flags, flags);
}

// add instruction
void ac_instructions_add(ac_motherboard_t* motherboard, ac_reg_t core_num)
{
	byte dest = get_instruction_memory(motherboard, core_num, 1);
	byte src1 = get_instruction_memory(motherboard, core_num, 1);
	byte src2 = get_instruction_memory(motherboard, core_num, 1);

	ac_instructions_internal_add(motherboard, core_num, (enum ac_reg_index)dest, (enum ac_reg_index)src1, (enum ac_reg_index)src2);
}

void ac_instructions_internal_sub(ac_motherboard_t* motherboard, ac_reg_t core_num, enum ac_reg_index dest, enum ac_reg_index src1, enum ac_reg_index src2)
{
	ac_reg_t number1 = register_read(motherboard, core_num, src1);
	ac_reg_t number2 = register_read(motherboard, core_num, src2);

	ac_reg_t diff;
	ac_reg_t flags = register_read(motherboard, core_num, ac_register_flags);

	diff = number1 - number2;

	if ((number2 > 0 && number1 < INT32_MIN + number2) || (number2 < 0 && number1 > INT32_MAX + number2)) // if overflow set overflow flag
	{
    	flags = get_flag_bitmask(ac_flag_of) | flags;
	}
	else // if no overflow disable overflow flag
	{
		flags = ~get_flag_bitmask(ac_flag_of) & flags;
	}

    if (diff < 0) // if negative set sign flag
    {
    	flags = get_flag_bitmask(ac_flag_sf) | flags;
    }
    else // if not negative disable sign flag
    {
    	flags = ~get_flag_bitmask(ac_flag_sf) & flags; 
    }
	
	if (diff == 0) // if zero set the zero flag
	{
		flags = get_flag_bitmask(ac_flag_zf) | flags;
	}
	else // if not zero disable the zero flag
	{
		flags = ~get_flag_bitmask(ac_flag_zf) & flags; 
	}

	register_write(motherboard, core_num, dest, diff);
	register_write(motherboard, core_num, ac_register_flags, flags);
}

void ac_instructions_sub(ac_motherboard_t* motherboard, ac_reg_t core_num)
{
	byte dest = get_instruction_memory(motherboard, core_num, 1);
	byte src1 = get_instruction_memory(motherboard, core_num, 1);
	byte src2 = get_instruction_memory(motherboard, core_num, 1);

	ac_instructions_internal_sub(motherboard, core_num, (enum ac_reg_index)dest, (enum ac_reg_index)src1, (enum ac_reg_index)src2);
}

ac_instruction_func_t ac_instructions_funcs[] =
{
	ac_instructions_nop,
	ac_instructions_add,
	ac_instructions_sub
};

ac_instruction_func_t get_instruction_func(ac_instruction_t opcode)
{
	if(sizeof(ac_instructions_funcs) <= opcode)
	{
		return NULL;
	}
	return ac_instructions_funcs[opcode];
}

void ac_processor_execute_instruction(ac_motherboard_t* motherboard, ac_reg_t core_num)
{
	ac_instruction_t opcode = (ac_instruction_t)get_instruction_memory(motherboard, core_num, sizeof(ac_instruction_t));

	ac_instruction_func_t instruction_func = get_instruction_func(opcode);

	instruction_func(motherboard, core_num);
}