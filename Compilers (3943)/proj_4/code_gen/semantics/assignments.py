'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''


# Input: list of globals, dict of locals, dict of used locals, dict of all line number and code on that line
# Output: list of all the [[line of code that has an assignment, line of code], ...]
def find_assigns(declared_global_vars, declared_local_vars, used_locals, dict_of_line_numbers):
	assignments = []

	# Look for assignment in global declarations
	for var in declared_global_vars:
		find_assignments(var, assignments, dict_of_line_numbers)

	# Look for assignment in local declarations
	for key in declared_local_vars:
		for var in declared_local_vars[key]:
			find_assignments(var, assignments, dict_of_line_numbers)

	# Look for assignment in local usages

	for key in used_locals:
		for var in used_locals[key]:
			find_assignments(var, assignments, dict_of_line_numbers)

	return assignments


# Input: var of [line of code, line number], list of any time there is an assignment, dict[line number] = line of code
def find_assignments(var, assignments, dict_of_line_numbers):
	line_number = var[1]
	line_of_code = dict_of_line_numbers[line_number]
	# If there is an assignment in the line of code
	if '=' in line_of_code and [line_of_code, line_number] not in assignments:
		if '<=' not in line_of_code and '>=' not in line_of_code and '==' not in line_of_code:
			assignments.append([line_of_code, line_number])
