import sys
from functions import *


def main():
    # table_input = 'table1'
    print "Which table would you like to use? (enter 'table1', 'table2', 'table3', or 'table4'"
    table_input = raw_input()

    table = convert_to_table(table_input)

    # standard_input = 'if (X == 100)'
    args = sys.argv[1:]
    if args:
        for input_file in args:
            f = open(input_file, 'rU')
            standard_input = f.read()
            result = scanner(standard_input, table)
            output(result)
    else:
        standard_input = raw_input('Please enter some input:')
        result = scanner(standard_input, table)
        output(result)

    # result = scanner(standard_input, table)
    # output(result)


main()
