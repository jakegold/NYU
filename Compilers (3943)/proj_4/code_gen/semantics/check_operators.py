'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import re
from function_checking import find_current_function, find_local, find_global
from assignment_checking import find_expressions


# Prints out any errors with operators
# Input: line number, list of all operators, list of func deffs, dict of locals, list of globals
def check_math(line_number, math_operations, func_def, declared_local_vars, declared_global_vars):
	for operation in math_operations:
		if line_number is operation[1]:
			current_func = find_current_function(line_number, func_def)
			line_of_code = operation[0]
			identifiers = find_expressions(line_of_code)
			const_ints = find_const_ints(line_of_code)
			const_floats = find_const_floats(line_of_code)
			var_ints, var_floats = find_vars(identifiers, declared_local_vars, declared_global_vars, current_func)

			# If there are some combo of ints and floats
			if not ((const_floats is None and var_floats is None) or (const_ints is None and var_ints is None)):
				error = 'Type error on line ' + str(line_number) + ': trying to do math operation on two different types: ' + line_of_code + ' where the ints are:'
				print report_problem(error, const_ints, const_floats, var_ints, var_floats)


# Input: some expression of code
# Output: list of all the constant ints in the expression
def find_const_ints(expression):
	# Match only ints and not floats (ugly expression is thanks to https://stackoverflow.com/questions/28030520/python-regex-to-match-integers-but-not-floats?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)
	match = re.findall(r'(?<![\d.])[0-9]+(?![\d.])', expression)
	if match:
		return match


# Input: some expression of code
# Output: list of all the constant floats in the expression
def find_const_floats(expression):
	match = re.findall(r'[0-9]*\.[0-9]*', expression)
	if match:
		return match


# Input: a list of identifiers, dict of local, list of globals, name of current function
# Output: all the variables that are ints, all the variables that are floats
def find_vars(identifiers, declared_local_vars, declared_global_vars, current_func):
	var_ints = []
	var_floats = []
	for identifier in identifiers:
		identifier_type = find_local(declared_local_vars, current_func, identifier)
		identifier_type = find_global(identifier_type, declared_global_vars, identifier)
		if identifier_type == 'int':
			var_ints.append(identifier)
		elif identifier_type == 'float':
			var_floats.append(identifier)
	# Return None to keep consistent with reg ex returning None
	if len(var_ints) < 1:
		var_ints = None
	if len(var_floats) < 1:
		var_floats = None
	return var_ints, var_floats


# Input: error message, list of const ints, list of const floats, list of variable ints, list of variable floats
# Output: error message with approriate list of ints and floats attatched
def report_problem(error, const_ints, const_floats, var_ints, var_floats):
	try:
		for num in const_ints:
			error = error + ' ' + num
	except TypeError as err:
		pass
	try:
		for num in var_ints:
			error = error + ' ' + num
	except TypeError as err:
		pass
	error = error + ' and the floats are: '
	try:
		for num in const_floats:
			error = error + ' ' + num
	except TypeError as err:
		pass
	try:
		for num in var_floats:
			error = error + ' ' + num
	except TypeError as err:
		pass

	return error
