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

from helpers.helpers import open_me


# Input: file_name of all the tokens (taken from the scanner), a dict[line number] = line of code
# Output: list of all the [[line of code that has a return statment, line of code], ...]
def find_returns(file_name, dict_of_line_numbers):
	scanned = open_me(file_name)
	lines = scanned.split('\n')
	return find_all_returns(lines, dict_of_line_numbers)


# Input: a list of all the tokens in the code, a dict[line number] = line of code
# Output: list of all the [[line of code that has a return statment, line of code], ...]
def find_all_returns(tokens, dict_of_line_numbers):
	returns = []
	# For all the tokens
	for i in range(len(tokens)):
		try:
			token = tokens[i]
			# If it is a return statment
			identifier = re.search('return_kw', token)
			if identifier:
				# Get the entire line of the return statment
				single_return = get_line_of_code(tokens, i)
				# Make the line readable
				single_return = beautify(single_return)
				# Get the line number
				line_number = find_line_number(single_return, dict_of_line_numbers)
				returns.append([single_return, line_number])
		except Exception as err:
			continue
	return returns


# Input: a list of all the tokens in the code, index of a return statment
# Output: the entire line of code containing the return
def get_line_of_code(tokens, index):
	start = index

	while True:
		next_token = tokens[index]
		try:
			# Look for the semi-colon at the end of the line
			identifier = re.search('SEMI', next_token)
			# If found, return
			if identifier:
				return tokens[start:index]
			# Else, try next token 
			else:
				index = index + 1
		except Exception as err:
			continue


# Input: a line of code that has a return statment
# Output: a more readable version of the input
def beautify(tokens):
	result = ''
	for i, token in enumerate(tokens):
		token = token.split()[-1]
		token = token[1:-1]
		if i is 0:
			result = token + ' '
		else:
			result = result + token
	return result


# Input: a readable line of code, a dict[line number] = line of code
# Output: the line number of the line of code
def find_line_number(line_of_code, dict_of_line_numbers):
	for key in dict_of_line_numbers:
		if line_of_code in dict_of_line_numbers[key]:
			return key
