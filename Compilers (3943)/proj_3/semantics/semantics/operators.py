'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

# Global of all the operators that can appear in the code 
ops = ['+','-','*','/','==','>','>=','<','<=']


# Input: list of globals, dict of locals, list of all the function calls, dict of used locals, dict of all line number and code on that line
# Output: list of all the [[line of code that uses an operator, line of code], ...]
def find_ops(declared_global_vars, declared_local_vars, func_calls, used_locals, dict_of_line_numbers):
	operators = []

	# Look for operators in global declarations
	for var in declared_global_vars:
		find_operators(var, operators, dict_of_line_numbers)

	# Look for operators in local declarations
	for key in declared_local_vars:
		for var in declared_local_vars[key]:
			find_operators(var, operators, dict_of_line_numbers)

	# Look for operators in function calls
	for call in func_calls:
		find_operators(var, operators, dict_of_line_numbers)

	# Look for operators in local usages
	for key in used_locals:
		for var in used_locals[key]:
			find_operators(var, operators, dict_of_line_numbers)

	return operators


# Input: var of [line of code, line number], list of any time there is an assignment, dict[line number] = line of code
def find_operators(var, operators, dict_of_line_numbers):
	line_number = var[1]
	line_of_code = dict_of_line_numbers[line_number]
	# If there is an operator in the line of code
	for op in ops:
		if op in line_of_code and [line_of_code, line_number] not in operators:
			operators.append([line_of_code, line_number])

	