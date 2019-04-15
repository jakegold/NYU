'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import sys
sys.path.insert(0, '../semantics/semantics')
from semantics.semantics import unpack

sys.path.insert(0, '../parser/line_numbers')
from parser.line_numbers import dict_of_line_numbers

from code_generator import *
from label import *
from func_funcs import *


# Input: [decarled_globals, function_deffs, declared_locals, function_calls, used_locals]
def generate_code(values, input_file):
	declared_global_vars, func_def, declared_local_vars, func_calls, used_locals = unpack(values)
	for item in unpack(values):
		print item

	mass_code = write_start()

	make_global_registers(declared_global_vars)
	mass_code = write_globals_label(mass_code)

	print '\n'

	for i, func in enumerate(func_def):
		start_line = func[1]
		whole_start_of_func = dict_of_line_numbers[start_line]

		if declaration(whole_start_of_func):
			continue
		try:

			mass_code = build_function(mass_code, start_line, func_def, declared_local_vars, i)
		except TypeError as err:
			pass

	mass_code += '\n' 

	print mass_code

	return mass_code
