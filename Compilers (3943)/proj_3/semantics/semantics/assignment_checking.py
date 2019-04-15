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


# Prints any error with assignment typings
# Input: line number that is being checked, list of all assignments, list of func defs, dict of locals, list of globals
def check_assingments(line_number, assignments, func_def, declared_local_vars, declared_global_vars):
	for assignment in assignments:
		if line_number is assignment[1]:
			assignment = assignment[0].split('=')
			lhs = assignment[0]
			rhs = find_expressions(assignment[1])
			current_func = find_current_function(line_number, func_def)
			lhs_type = find_local(declared_local_vars, current_func, lhs)
			lhs_line_dec = get_local_line(declared_local_vars, current_func, lhs)
			for var in rhs:
				rhs_type = find_local(declared_local_vars, current_func, var)
				rhs_type = find_global(rhs_type, declared_global_vars, var)
				rhs_line_dec = get_local_line(declared_local_vars, current_func, var)
				rhs_line_dec = get_global_line(rhs_line_dec, declared_global_vars, var)
				if lhs_type != rhs_type:
					print 'Type error on line ' + str(line_number) + ': trying to assign "' + lhs + '" of type ' + lhs_type + ' (declared on line ' + str(lhs_line_dec) + ' ) with "' + var + '" of type ' + rhs_type + ' (declared on line ' + str(rhs_line_dec) + ')'
					break
			

# Input: an expression of assignment
# Output: a list of all the identifiers in the expression
def find_expressions(expression):
	match = re.findall(r'[a-zA-Z_][a-zA-Z_0-9]*', expression)
	if match:
		return match


# Input: dict of locals, name of currect function, variable of specific type
# Output: line where var was declared. If var is global, None
def get_local_line(declared_local_vars, current_func, var):
	return get_line(declared_local_vars[current_func], var)


# Input: Initial line number, list of globals, variable of specific type
# Output: line where var was declared. If var is local, return initial_line
def get_global_line(initial_line, declared_global_vars, rhs):
	if initial_line is None:
		return get_line(declared_global_vars, rhs)
	else:
		return initial_line


# Input: Iterable of variables, original of what the original type is
# Output: line number of where this variable comes up
def get_line(iterable, original):
	for var in iterable:
		variable = var[0].split()[1]
		if original == variable:
			return var[1]
