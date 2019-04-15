'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

from function_checking import find_current_function
from assignment_checking import find_expressions
from check_operators import find_const_ints, find_const_floats, find_vars


# Prints out any errors with returns
# Input: line number, list of all returns, list of func deffs, dict of locals, list of globals
def check_returns(line_number, returns, func_def, declared_local_vars, declared_global_vars):
	for single_return in returns:
		if line_number is single_return[1]:
			current_func = find_current_function(line_number, func_def)
			line_of_code = single_return[0]
			identifiers = find_expressions(line_of_code)
			const_ints = find_const_ints(line_of_code)
			const_floats = find_const_floats(line_of_code)
			var_ints, var_floats = find_vars(identifiers, declared_local_vars, declared_global_vars, current_func)
			type_needed = find_type(func_def, current_func)
			if type_needed == 'int' and (const_floats or var_floats):
				error = 'Type error on line ' + str(line_number) + ': trying to return "' + line_of_code.split()[1] + '" which contains floats'
				error = add_to_error(error, const_floats, var_floats)
				error = error + 'but should be of type int'
				print error
			elif type_needed == 'float' and (const_ints or var_ints):
				error = 'Type error on line ' + str(line_number) + ': trying to return "' + line_of_code.split()[1] + '" which contains ints'
				error = add_to_error(error, const_ints, var_ints)
				error = error + ' but should be of type float'
				print error


# Input: list of func deffs, name of current function
# Output: the return type the current func
def find_type(func_def, current_func):
	return find_function_def(func_def, current_func)[0].split()[0]


# Input: list of function defs, name of the current function
# Output: the entire function call of the current function
def find_function_def(func_def, current_func):
	for function in func_def:
		function_call = function[0].split()[1].split('(')[0]
		if current_func == function_call:
			return function


# Input: error message, list of const nums, list of variables
# Output: error message with approriate list of either ints or floats attatched
def add_to_error(error, consts, variables):
	try:
		for num in consts:
			error = error + ' ' + num
	except TypeError as err:
		pass
	try:
		for num in variables:
			error = error + ' ' + num
	except TypeError as err:
		pass
	return error