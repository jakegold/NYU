import sys
from functions import *
from tables import table


def main():
    args = sys.argv[1:]
    if args:
        for input_file in args:
            f = open(input_file, 'rU')
            standard_input = f.read()
            result = scanner(standard_input, tables.table)
            output(result)
    else:
        print 'Please just use an input file'

main()
