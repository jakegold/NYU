'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''
import sys
sys.path.insert(0, '../helpers/helpers')
import re

from helpers.helpers import open_me, add_to_dict
from line_numbers import dict_of_line_numbers
from others import *
from closings import check_closings

FUNC_DEFF = 0
FUNC_CALL = 1
VAR_DEFF = 2
VAR_CALL = 3


# Tokens is a list of strings
def parse(tokens):
	func_def, func_calls, var_def, var_call = find_identifiers(tokens) #still could be cleaned up
	func_scopes = find_func_scope(func_def)
	declared_global_vars, declared_local_vars = find_globals_and_locals(func_scopes, var_def)
	used_globals, used_locals = find_globals_and_locals(func_scopes, var_call)
	# print_data(declared_global_vars, func_def, declared_local_vars, func_calls, used_locals)
	return_values = [declared_global_vars, func_def, declared_local_vars, func_calls, used_locals]
	return return_values


def find_identifiers(tokens):
	func_def = []
	func_calls = []
	var_def = []
	var_call = []

	line_number = 0

	for i in range(0, len(tokens)):
		try:
			token = tokens[i]
			identifier = re.search('identifier', token)

			# If the token is an id
			if identifier:

				# Get the next and last tokens
				last = tokens[i - 1]
				next = tokens[i + 1]

				# Search next and last tokens for '(', 'int', 'float'
				lpar = re.search('LPAR', next)
				last_int = re.search('int', last)
				last_float = re.search('float', last)
				comma = re.search('COMMA', last)

				# Declaring a function
				if lpar:
					if last_int or last_float:
						add_token_data(tokens, i, line_number, func_def, FUNC_DEFF)
					# Calling a function
					else:
						add_token_data(tokens, i, line_number, func_calls, FUNC_CALL)
				# Declaring a variable
				elif last_int or last_float:
					add_token_data(tokens, i, line_number, var_def, VAR_DEFF)
				# Declaring a variable with commas
				elif comma:
					backwards = 1
					while True:
						try:
							previous = tokens[i-backwards]
							previous_token = re.search('COMMA', previous)
							previous_int = re.search('int', previous)
							previous_float = re.search('float', previous)
							if previous_token:
								backwards = backwards + 2
							if previous_int or previous_float:
								same_type = var_def[-1][0].split()[0]
								identifier = token.split()[-1]
								identifier = identifier[1:-1]
								identifier = same_type + ' ' + identifier
								var_def.append([identifier, var_def[-1][1]])
								break
						except Exception as err:
							break
				# Calling a variable
				else:
					exists = check_exists(token, var_def)
					if not exists:
						nonexistent = token.split()[-1]
						nonexistent = nonexistent[1:-1]
						print 'Error: Tried to use variable ' + nonexistent + ', but it was never declared.'
						continue
					# THIS ISNT WORKING?!?!?!?!?
					# add_token_data(tokens, i, line_number, var_call, VAR_CALL)

					# print last
					lst = convert_to_list(tokens[i:i+1])
					# Last token semi-colon
					if last_token_useable(last):
						regex_lst = convert_to_list(tokens[i-1:i]) + lst
					else:
						regex_lst = lst + convert_to_list(tokens[i+1:i+2])
					reg_ex =  get_as_reg_ex(regex_lst)
					line_number =  get_line(reg_ex, line_number, dict_of_line_numbers)
					add_data(lst, line_number, var_call)
					
		except Exception as err:
			continue
	# print func_def
	# print func_calls
	# print var_def
	# print var_call
	return func_def, func_calls, var_def, var_call
		

def check_exists(token, defined):
	potential_var = token.split()[-1]	
	potential_var = potential_var[1:-1]
	for var in defined:
		if potential_var is var[0].split()[1]:
			return True
	return False

# Input: list of functions [[function name, starting line], ]
# Output: dictionary[function name] = [start of function, end of function]
# Gets all of the starting and ending lines of the functions
def find_func_scope(functions):
	function_scopes = {}
	for i in range(len(functions)):
		func = functions[i]
		# Ugly way to get function name
		func_name = func[0].split()[1].split('(')[0]
		start_of_func = func[1]
		try:
			# Function ends line before next one starts
			end_of_func = functions[i + 1][1] - 1
		except IndexError as err:
			end_of_func = len(dict_of_line_numbers) - 1
		function_scopes[func_name] = [start_of_func, end_of_func]
	return function_scopes


# Input: scopes of all the functions as dict[function name] = [start of function, end of function]
#		 definitions of the tokens as they are first introduced
# Output: all global tokens as a list, all local tokens as a dict
# Globals: [[token, line], ] Locals: {'function name': [[id, line], ]}
def find_globals_and_locals(scopes, definitions):
	global_tokens = []
	local_tokens = {}
	# For each token
	for var in definitions:
		global_token = True
		line = var[1]
		# Check if it falls in this functions scope
		for key in scopes:
			start, end = scopes[key]
			# If it falls within the range
			if line in range(start, end):
				# It is not global
				global_token = False
				add_to_dict(key, var, local_tokens)
				break
		# If global
		if global_token:
			global_tokens.append(var)
	return global_tokens, local_tokens




def print_data(declared_global_vars, func_def, declared_local_vars, func_calls, used_locals):
	for line_number in range(len(dict_of_line_numbers)):
		global_var_on_line(line_number, declared_global_vars)
		func_def_on_line(line_number, func_def)
		local_var_on_line(line_number, declared_local_vars)
		func_call_on_line(line_number, func_calls, func_def)
		use_var_on_line(line_number, used_locals, declared_global_vars, declared_local_vars)


# want to move VVV
def get_as_list(tokens, index, command):
	if command is FUNC_DEFF:
		return convert_to_list(tokens[index-1:index+5])
	if command is FUNC_CALL:
		return convert_to_list(tokens[index:index+4])
	if command is VAR_DEFF:
		return convert_to_list(tokens[index-1:index+1])
	if command is VAR_CALL:
		return convert_to_list(tokens[i:i+1])

# THIS IS BREAKING IT FOR SOME REASON?!?!
def add_calling_variable(tokens, index, line_number, result):
	last = tokens[index - 1]
	lst = convert_to_list(tokens[index:index+1])
	if last_token_useable(last):
		regex_lst = convert_to_list(tokens[index-1:index]) + lst
	else:
		regex_lst = lst + convert_to_list(tokens[index+1:index+2])
	reg_ex =  get_as_reg_ex(regex_lst)
	line_number =  get_line(reg_ex, line_number, dict_of_line_numbers)
	add_data(lst, line_number, result)


def add_token_data(tokens, index, line_number, result, command):
	if command is VAR_CALL:
		add_calling_variable(tokens, index, line_number, result)
	else:
		lst = get_as_list(tokens, index, command)
		reg_ex = get_as_reg_ex(lst)
		line_number = get_line(reg_ex, line_number, dict_of_line_numbers)
		# print line_number
		if line_number is not None:
			add_data(lst, line_number, result)
		else:
			print_error(command)


def print_error(command):
	if command is FUNC_DEFF:
		print 'Error: Declaring Function incorrectly!' #Should also give a line number


def parser(input_file):
	scanned = open_me(input_file)
	lines = scanned.split('\n')
	check_closings(lines) # Not ideal because looping twice through everything...
	return parse(lines)
