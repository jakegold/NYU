'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

from set_up import free_use, open_for_use

# NOTE: LARGEST REGISTER IS: 999


# Output: the index of a open register
# If no open register, returns -1
# Finds the index of an open register
def get_open_register():
	for reg in range(len(free_use)):
		if open_for_use[reg]:
			mark_for_use(reg)
			return reg
	return -1


# Input: index of an open register
# Marks the register as being used
def mark_for_use(index):
	open_for_use[index] = False


# Input: index of a closed register
# Marks the register as being open
def done_with_register(index):
	open_for_use[index] = True


# Helper for assign global and local
def assign_register(var_name):
	reg_index = get_open_register()
	mark_for_use(reg_index)
	free_use[reg_index] = [0, var_name]
	return reg_index


# GLOBALS
# Input: list of globals and lines ex: [int x, 1]
# Gives each global a register in free use assigning it 0
def assign_global_registers(declared_global_vars):
	for var in declared_global_vars:
		assign_register(var[0])


def assign_local_registers(local_vars):
	local_registers = []
	for var in local_vars:
		register_used = assign_register(var[0])
		local_registers.append(register_used)
	return local_registers


def clean_local_registers(local_registers):
	for register in local_registers:
		free_use[register] = register
		done_with_register(register)


def find_register(var):
	var = var.strip()
	for i, reg in enumerate(free_use):
		if var in reg[1].split()[1]:
			return i
