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
from helpers.helpers import open_me

# Ideally this would be done by the scanner...
# Also not sure if this needs to be a dict...
# Output: a dictionary of dict[line_number] = string line_of_code
def get_line_numbers():
	result = {}
	line_number = 0
	string = open_me('test.txt') # CHANGE ME!!!!
	lines = string.split('\n')
	for line in lines:
		result[line_number] = line
		line_number = line_number + 1
	return result

dict_of_line_numbers = get_line_numbers()
