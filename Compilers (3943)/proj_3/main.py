# from driver.driver import driver
# from scanner.scanner import scanner
# from parser.parser import parser
# from helpers.helpers import make_file_name
import sys
from line_numbers.line_numbers import *


def main():
    args = sys.argv[1:]
    if args:
        for input_file in args:

            code_with_lines = get_line_numbers(input_file)
    else:
        print 'Usage: python main.py filename [filename2...]'
    # print args
#     input_file = 'test.txt'  # CHANGE ME!!!
#
# # Call a driver to get rid of single line comments
#     driver(input_file)
#     file_name = make_file_name(input_file, 'driver')
# # Scanner
#     scanner(file_name)
#     file_name = make_file_name(file_name, 'scanner')
# # Parser
#     parser(file_name)

main()
