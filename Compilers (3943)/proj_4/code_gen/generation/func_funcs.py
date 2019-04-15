'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import sys
sys.path.insert(0, '../semantics/function_checking')
from semantics.function_checking import find_current_function

sys.path.insert(0, '../parser/line_numbers')
from parser.line_numbers import dict_of_line_numbers

from free_use_registers import assign_local_registers, clean_local_registers
from code_generator import build_label_for_deepest, build_main

from set_up import LABEL


# Input: a line of code
# Output: True if that line of code is for a declarations
# 		  False if that line is for a function deffinition
# Takes a line of code and returns true if its just the declaration
def declaration(line_of_code):
	if ';' not in line_of_code:
		return False
	first_split = line_of_code.split(';')[0]
	if first_split[-1] is not ')':
		return False
	return True


def build_function(mass_code, start_line, func_def, declared_local_vars, index):
	func_name = find_current_function(start_line, func_def)
	
	if func_name == 'main' and index is 0:
		mass_code = build_main(mass_code)
	if func_name == 'main' and index is not 0:
		LABEL[0] = LABEL[0] - 1
		mass_code = build_main(mass_code)

	local_vars = declared_local_vars[func_name]
	local_registers = assign_local_registers(local_vars)
	try:
		next_func = func_def[index + 1]
	except IndexError as err:
		next_func = ['', len(dict_of_line_numbers)]

	whole_func = get_whole_func(dict_of_line_numbers, start_line, next_func)

	mass_code = build_each_label(mass_code, whole_func, func_def)

	clean_local_registers(local_registers)


	return mass_code


def get_whole_func(dict_of_line_numbers, start_line, next_func):
	whole_func = []
	for key in sorted(dict_of_line_numbers.keys()):
		if key >= start_line and key < next_func[1]:
			whole_func.append(dict_of_line_numbers[key])
	return whole_func


def build_each_label(mass_code, whole_func, func_def):
	function = list(whole_func) # a just in case type thing
	while function:
		start, end = get_deepest_part(function)

		mass_code = build_label_for_deepest(mass_code, whole_func[start:end], func_def)
		function = remove_deepest_part(function, start, end)
	return mass_code


def get_deepest_part(func):
	stack = []
	largest = 0
	current = 0
	sub_labels = []
	for i, line in enumerate(func):
		if '{' in line:
			stack.append(i)
			current += 1
			if current > largest:
				largest = i
		if '}' in line:
			starting = stack.pop()
			sub_labels.append([starting, i])
			current -= 1
	if len(sub_labels) > 0:
		for pair in sub_labels:
			if pair[0] is largest:
				return pair[0], pair[1] + 1
	else:
		return 0, 1


def remove_deepest_part(function, start, end):
	if function[-1].isspace():
		function.pop(-1)

	end = end - 1
	while end is not start:
		function.pop(end)
		end = end - 1 
	function.pop(end)

	return function
