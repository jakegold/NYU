'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import re
from set_up import free_use, open_for_use, LABEL
from label import *
from free_use_registers import *
from shunting_yards import *


def write_start():
	return 'START 0 \n \n'


def make_global_registers(declared_global_vars):
	assign_global_registers(declared_global_vars)
	

def write_globals_label(mass_code):
	mass_code += 'LABEL 0 //setting up \n'
	index = 0
	while type(free_use[index]) is not int:

		mass_code += 'PUSH ' + str(index) + '// ' + free_use[index][1] + '\n'
		index += 1

	mass_code += 'CALL 1 \n \n'
	return mass_code


def build_main(mass_code):
	label = LABEL[0]
	mass_code += 'LABEL 1 \n'
	mass_code += 'CALL ' + str(label + 1) + ' // call main \n'
	mass_code += 'STOP \n \n'
	LABEL[0] = label + 1
	return mass_code


def build_label_for_deepest(mass_code, partial_func, func_def):

	label = LABEL[0]

	# THIS PART IS PROB BUGGY
	mass_code, function_call = add_func_call(mass_code, partial_func, func_def)
	if function_call:
		return mass_code

	mass_code += 'LABEL ' + str(label) + '// ' + partial_func[0] + '\n'

	for line in partial_func:
		if 'read' in line:
			mass_code = add_read(mass_code, line)
		if 'write' in line:
			mass_code = add_write(mass_code, line, func_def)
		if 'return' in line:
			add_return(mass_code, line, func_def)
		if 'int' in line or 'float' in line:
			continue
		# if 'if' in line or 'else' in line or 'while' in line:
		# 	add_logic()
		if '{' in line or '}' in line:
			continue
		if ('+' in line or '-' in line or '*' in line or '/' in line) and 'return' not in line and 'write' not in line:
			mass_code = add_math(mass_code, line)	

	LABEL[0] = label + 1

	mass_code += 'RETURN \n \n'
	return mass_code


def add_func_call(mass_code, partial_func, func_def):
	label = LABEL[0]

	for func in func_def:
		func = func[0]

		try:
			func_name = partial_func[0].split()[1].split('(')[0]
			match = re.search(func_name, func)
		except IndexError as err:
			continue

		if match and func_name != 'main':

			mass_code += 'LABEL ' + str(label) + '// ' + partial_func[0] + '\n'
			mass_code += 'CALL ' + str(label - 1) + '// Call the actual function \n \n'

			LABEL[0] = label + 1

			return mass_code, True

		if match and func_name == 'main':
			return mass_code, True

	return mass_code, False


def add_read(mass_code, line):
	var = line.split('read')[1]
	var = var.split(';')[0]
	var = var.strip()
	register = find_register(var)

	if 'int' in free_use[register][1]:
		mass_code += 'READ '
	else:
		mass_code += 'READF '
	mass_code += str(register) + '\n'

	return mass_code

def add_write(mass_code, line, func_def):
	# If write a string
	if '"' in line:
		if ',' not in line.split('"')[2]:
			words = line.split('"')[1]
			mass_code += 'WRITES "' + words + '"\n'
			mass_code += 'NEWLINE \n'
		else:
			words = line.split(',')[1]
			words = words.split(';')[0]
			words = words.strip()
			register = find_register(words)
			if 'int' in free_use[register][1]:
				mass_code += 'WRITE '
			else:
				mass_code += 'WRITEF '
			mass_code += str(register) + '\n'



	# If write from a return
	elif calls_func(line, func_def):
		return_reg = 999
		output = free_use[return_reg]
		done_with_register(return_reg)
		if '.' in output[0]:
			mass_code += 'WRITEF '
		else:
			mass_code += 'WRITE '
		mass_code += str(output[1]) + '\n'
	# if write an int or float
	elif ('+' in line or '-' in line or '*' in line or '/' in line):
		expression = line.split('write')[1]
		expression = expression.split(';')[0]
		expression = expression.strip()

		order_of_ops = shunting_yards(expression)
		mass_code, new_reg = evaluate(order_of_ops, mass_code)
		mass_code += 'WRITE ' + str(new_reg) + '\n'

	else:
		var = line.split('write')[1]
		var = var.split(';')[0]
		var = var.strip()
		register = find_register(var)



		if 'int' in free_use[register][1]:
			mass_code += 'WRITE '
		else:
			mass_code += 'WRITEF '
		mass_code += str(free_use[register][0]) + '\n'
	mass_code += 'NEWLINE \n'
	return mass_code


# THE RETURNED REGISTER IS 999...prob not working right..
def add_return(mass_code, line, func_def):
	return_reg = 999
	mark_for_use(return_reg)
	# Return with math
	if '+' in line or '-' in line or '*' in line or '/' in line:
		result = add_math_return(line)
		free_use[return_reg] = result
	# Return with func call
	elif calls_func(line, func_def):
		print 'calls a func....not ready yet'
	# Normal return
	else:
		returned = line.split('return')[1].split(';')[0]
		if returned.isdigit():
			free_use[return_reg] = returned
		else:
			value = find_register(returned)[0]
			free_use[return_reg] = value


def calls_func(line, func_def):
	for func in func_def:
		func_title = func[0].split()[1].split('(')[0]
		func_title = func_title + '('
		if func_title in line:
			return True
	return False


def add_math_return(line):
	expression = line.split('return')[1].split(';')[0]
	if all_nums(expression):
		result = all_num_math(expression)
	else:
		result = calculate_expersion(expression)
	return result


def all_nums(line):
	match = re.search(r'[a-zA-Z_][a-zA-Z_0-9]*', line)
	if match:
		return False
	return True


def all_num_math(expression):
	return eval(expression)


def calculate_expersion(expression):
	all_terms = re.findall(r'[a-zA-Z_][a-zA-Z_0-9]*', expression)
	for term in all_terms:
		index = find_register(term)
		value = free_use[index][0]
		expression = re.sub(term, str(value), expression)
	return all_num_math(expression)


def add_math(mass_code, line):
	line = line.split('=')
	lhs = line[0]
	var = find_register(lhs)

	register = free_use[var]
	var_type = register[1].split()[0]

	rhs = line[1]
	expression = shunting_yards(rhs)

	
	mass_code, new_reg = evaluate(expression, mass_code)
	return mass_code

def add_assignment(mass_code, line):
	if ('+' in line or '-' in line or '*' in line or '/' in line):
		add_math(mass_code, line)
	else:
		variables = line.split('=')
		lhs = variables[0]
		rhs = variables[1]

		lhs = lhs.strip()
		rhs = rhs.strip()
		rhs = rhs.split(';')[0]

		lhs_register = find_register(lhs)
		rhs_register = find_register(rhs)

		if 'int' in free_use[lhs_register][1]:
			mass_code += 'COPY '
		else:
			mass_code += 'COPY '
		mass_code += str(rhs_register) + ' ' + str(lhs_register) + '\n'
		return mass_code
