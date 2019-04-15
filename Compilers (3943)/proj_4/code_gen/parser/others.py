'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''
import re

# Input: string of id_data which is one line from file after being scanned
# Output: a list of the tokens from the input
def convert_to_list(id_data):
	info = []
	for identifier in id_data:
		token = identifier.split()[2]
		info.append(token[1:-1])
	return info


# Input: a token to be tested if its a semi colon or not
# Output: True if the last token is useable to search the last line of code
# 		  False if the last token is a semi colon
def last_token_useable(last):
	data = last.split()[2]
	data = data[1:-1]
	if data is ';' or data is '{':
		return False
	return True


# Input: a list of strings
# Output: that list of strings as a reg ex
# The output will allow a space between each item in list
def get_as_reg_ex(lst_of_strings):
	result = ''
	for string in lst_of_strings:
		if re.search('\w', string):
			result = result + string + '\s*'
		# In case of special char
		else:
			result = result + '\\' + string + '\s*'
	return result


# Input: a reg ex to match, an int line_number, a dict[line_number] = string line of code
# Output: the int line_number that the reg ex matches
# Function will match a regular expression with a line of code
# If there is no match, the funcion tries the next line
def get_line(reg_ex, line_number, dict_of_line_numbers):
	while line_number < len(dict_of_line_numbers):
		match = re.search(reg_ex, dict_of_line_numbers[line_number])
		if match:
			return line_number
		else:
			line_number = line_number + 1
	return None


# Input: lst of tokens seperated by token, int line_number, 
# 		 list of lists id_data of [[token, line_number], ]
# Adds the tokens as a string to the data with the line they appeard in
def add_data(lst, line_number, id_data):
	# # If this is a function deff (at the call time)
	# if len(lst) is 6 and lst[-1] != ';':




	# 	print 'HIT ME'
	# 	print id_data





	# 	new_lst = list(lst)

	# 	print new_lst

	# 	del new_lst[4]
	# 	new_lst.append(';')


	# 	print new_lst


	# 	string = list_to_string(new_lst)
	# 	print string

	# 	index = -1
	# 	for i, func in enumerate(id_data):
	# 		if func[0] == string:
	# 			index = i


	# 	print 'INDEX'
	# 	print index

	# 	if index > -1:
	# 		old_line = id_data[index][1]
	# 		id_data[index] = [string, old_line]
	# 	else:
	# 		string = list_to_string(lst)
	# 		if [string, line_number] not in id_data:
	# 			id_data.append([string, line_number])


	# 	print '\n'
	# 	# if index > -1:
	# 	# 	id_data[index] = [string, line_number]
	# # For everything else
	# else:
	# 	string = list_to_string(lst)
	# 	if [string, line_number] not in id_data:
	# 		id_data.append([string, line_number])
	string = list_to_string(lst)
	if [string, line_number] not in id_data:
		id_data.append([string, line_number])


# Input: lst of tokens seperated by token
# Output: string of the tokens seperated by space
# If the keywork 'int' or 'float' appears, a space is added
def list_to_string(lst):
	string = ''
	for item in lst:
		if item == 'int' or item == 'float':
			string = string + item + ' '
		else:
			string = string + item
	return string



# To print all the data..can prob make this one or 2 functions and make nicer...
def global_var_on_line(line_number, global_vars):
	for item in global_vars:
		if item[1] is line_number:
			var_data = item[0].split()
			print 'Global ' + var_data[0] + ' variable ' + var_data[1] + ' declared in line ' + str(line_number) + '.'


def func_def_on_line(line_number, func_def):
	for item in func_def:
		if item[1] is line_number:
			func = item[0].split('(')
			parameter = func[1].split()[0]
			print 'Function ' + func[0] + '(' + parameter + ')' + ' defined in line ' + str(line_number) + '.'


def local_var_on_line(line_number, local_vars):
	for key in local_vars:
		for item in local_vars[key]:
			if item[1] is line_number:
				var_data = item[0].split()
				print 'Local ' + var_data[0] + ' variable ' + var_data[1] + ' declared in line ' + str(line_number) + '.'


def func_call_on_line(line_number, func_calls, func_def):
	for item in func_calls:
		if item[1] is line_number:
			func_name = item[0].split('(')[0]
			# This logic should prob be done elsewhere
			# This is also suuuuper messy
			for deff in func_def:
				if func_name == deff[0].split()[1].split('(')[0]:
					func = deff[0].split('(')
					parameter = func[1].split()[0]
					print 'Function ' + func[0] + '(' + parameter + ')' + ' defined in line ' + str(deff[1]) + ' used in line ' + str(line_number)+ '.'


# Messy and logic should be elsehwere..
def use_var_on_line(line_number, used_locals, declared_global_vars, declared_local_vars):
	for key in used_locals:
		for item in used_locals[key]:
			if item[1] is line_number:
				declared = True
				if key in declared_local_vars.keys():
					for identifier in declared_local_vars[key]:
						declared_line = identifier[1]
						variable_data = identifier[0].split()
						if item[0] is variable_data[1]:
							declared = False
							print 'Local variable ' + item[0] + ' declared in line ' + str(declared_line) + ' used in line ' + str(line_number) + '.'
				for identifier in declared_global_vars:
					declared_line = identifier[1]
					variable_data = identifier[0].split()
					if item[0] is variable_data[1]:
						declared = False
						print 'Global variable ' + item[0] + ' declared in line ' + str(declared_line) + ' used in line ' + str(line_number) + '.'
				if declared:
					print 'Error: variable ' + item[0] + ' was used in line ' + str(line_number) + ' but was never declared.'




