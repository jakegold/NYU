'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

from driver.driver import driver
from scanner.scanner import scanner
from parser.parser import parser
from helpers.helpers import make_file_name
from semantics.semantics import semantic_check


def main():
	input_file = 'test_decl_x.c' # CHANGE ME!!!

	# Call a driver to get rid of single line comments
	driver(input_file)
	file_name = make_file_name(input_file, 'driver')
	# Scanner
	scanner(file_name)
	file_name = make_file_name(file_name, 'scanner')
	# Parser
	return_values = parser(file_name)
	# Semantic Checker
	semantic_check(file_name, return_values)
	

main()
