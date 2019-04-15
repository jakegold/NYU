'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import sys
sys.path.insert(0, '../parser/line_numbers')
from parser.line_numbers import dict_of_line_numbers

from assignments import find_assigns
from operators import find_ops
from returns import find_returns
from function_checking import check_function_calls
from assignment_checking import check_assingments
from check_operators import check_math
from check_returns import check_returns

# This function just makes it so that the parameters are more readable to pass everything to the semantic checker
# Input: [decarled_globals, function_deffs, declared_locals, function_calls, used_locals]
# Output: declared_global_vars, func_def, declared_local_vars, func_calls, used_locals
def unpack(values):
	declared_global_vars = values[0]
	func_def = values[1]
	declared_local_vars = values[2]
	func_calls = values[3]
	used_locals = values [4]
	return declared_global_vars, func_def, declared_local_vars, func_calls, used_locals


# The main part of the semantic checker
# Input: file of tokens (taken from the scanner) , and a values list to unpack 
def semantic_check(file_name, values):
	declared_global_vars, func_def, declared_local_vars, func_calls, used_locals = unpack(values)

	# Get all the times there is an assignment in the code
	assignments = find_assigns(declared_global_vars, declared_local_vars, used_locals, dict_of_line_numbers)

	# Get all the times that there is some type of math operation in the code
	math_operations = find_ops(declared_global_vars, declared_local_vars, func_calls, used_locals, dict_of_line_numbers)

	# Get all the times that there is a return statment in the code
	returns = find_returns(file_name, dict_of_line_numbers)

	# For every line of code
	for line_number in range(len(dict_of_line_numbers)):
		# Check all the function calls for correct type
		check_function_calls(line_number, func_calls, func_def, declared_global_vars, declared_local_vars)
		# Check all the assignments
		check_assingments(line_number, assignments, func_def, declared_local_vars, declared_global_vars)
		# Check all the math
		check_math(line_number, math_operations, func_def, declared_local_vars, declared_global_vars)
		# Check all the returns
		check_returns(line_number, returns, func_def, declared_local_vars, declared_global_vars)
