'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''


# Prints out any errors with function callings
# Input: line number, list of all function calls, list of func deffs, list of globals, dict of locals, 
def check_function_calls(line_number, func_calls, func_def, declared_global_vars, declared_local_vars):
	if len(func_def) is 0:
		return
	for call in func_calls:
		if line_number is call[1]:
			var = get_var(call)
			func_call, type_needed, declared = find_function_def(func_def, call)
			current_func = find_current_function(line_number, func_def)
			initial_type = find_local(declared_local_vars, current_func, var)
			initial_type = find_global(initial_type, declared_global_vars, var)
			if type_needed != initial_type:
				print 'Type error on line ' + str(line_number) + ': calling function "' +  func_call + '" (declared on line ' + str(declared) + ') with wrong type'
			

# Input: a function call
# Output: the variable that is being passed into the function
def get_var(call):
	return call[0].split('(')[1].split(')')[0]
			

# Input: list of func defs, a function call
# Output: the name of a function, the type that that function needs, the line that function is declared on
def find_function_def(func_def, call):
	for function in func_def:
		func_call = function[0].split()[1].split('(')
		type_needed = func_call[1]
		func_call = func_call[0]
		my_call = call[0].split('(')[0]
		if my_call == func_call:
			declared = function[1]
			return func_call, type_needed, declared
	return None, None, None


# Input: line number, list of function deffs
# Output: the name of the function that this line is in
def find_current_function(line_number, func_def):
	best = line_number + 1
	result = None
	for func in func_def:
		start_line = func[1]
		if start_line > line_number:
			continue
		if line_number - start_line < best:
			result = func[0].split()[1].split('(')[0]
			best = line_number - start_line
	return result


# Input: dict of declared locals, name of current function, variable being looked for
# Output: type that is being passed to function. If varibale is global, None
def find_local(declared_local_vars, current_func, var):
	if current_func is not None:
		if current_func in declared_local_vars.keys():
			variables = declared_local_vars[current_func]
			return find_var(variables, var)
		else:
			print 'Function "' + current_func + '" not yet declared.' #Shoudl also give a line num


# Input: initial type, list of globals, variable being looked for
# Output: type that is being passed to function. If varibale is local, initial type
def find_global(initial_type, declared_global_vars, var):
	if initial_type is None:
		return find_var(declared_global_vars, var)
	else:
		return initial_type


# Input: list of variables, a variable to check for
# Output: type of the var
def find_var(variables, var):
	for variable in variables:
		variable = variable[0].split()
		if var == variable[1]:
			return variable[0]
	return None

