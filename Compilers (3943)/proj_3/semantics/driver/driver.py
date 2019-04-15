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
from helpers.helpers import *
from comments import find_comment


# Input: a file containing code
# Saves a new file of the same code without single line comments
def driver(input_file):
	output = []
	# Opens and reads the file to a string
	string = open_me(input_file)
	lines = string.split('\n')
	# Find single line comments
	for line in lines:
		new_line = find_comment(line)
		# If the comment is the entire line
		if new_line is '':
			continue
		output.append(new_line)
	# Write the entire file to output called test.
	output_file = make_file_name(input_file, 'driver')
	write_to_me(output_file, output)
