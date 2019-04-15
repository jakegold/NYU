'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import re
from set_up import free_use
from free_use_registers import *

ops = {
	'(' : 5,
	'*' : 4,
	'/' : 3,
	'+' : 2,
	'-' : 1,
	')' : 0,
}

def shunting_yards(expression):
	stack = []
	operator_stack = []

	while expression:
		if expression[0] not in ops.keys():
			sub_string = expression
			for i, char in enumerate(expression):
				if char in ops.keys():
					sub_string = expression[:i]
					break
			stack.append(sub_string)
			expression = re.sub(sub_string, '', expression)
		else:
			if len(operator_stack) is 0 or operator_stack[-1] == '(':
				operator_stack.append(expression[0])
				expression = expression[1:]
			else:
				if ops[operator_stack[-1]] <= ops[expression[0]]:
					operator_stack.append(expression[0])
					expression = expression[1:]
				else:
					while len(operator_stack) > 0:
						curr = expression[0]
						last_on = operator_stack[-1]
						if ops[last_on] > ops[curr]:
							for_stack = operator_stack.pop()
							if for_stack is not '(':
								stack.append(for_stack)
						else:
							operator_stack.append(curr)
							expression = expression[1:]

	while len(operator_stack) > 0:
		stack.append(operator_stack.pop())

	for i, item in enumerate(stack):
		if item is ' ':
			stack.remove(item)
		item = re.sub(';', '', item)
		stack[i] = item
	return stack


def evaluate(order_of_ops, mass_code):
	reg_type = free_use[find_register(order_of_ops[0])][1].split()[0]
	
	i = 0
	new_reg = get_open_register()
	mark_for_use(new_reg)

	while len(order_of_ops) > 2:
		item = order_of_ops[i]
		if not (item is '+' or item is '-' or item is '*' or item is '/'):
			i = i + 1
		else:
			if reg_type is 'int':
				if item is '+':
					mass_code += 'ADD '
				if item is '-':
					mass_code += 'SUB '
				if item is '*':
					mass_code += 'MUL '
				if item is '/':
					mass_code += 'DIV '
			else:
				if item is '+':
					mass_code += 'ADDF '
				if item is '-':
					mass_code += 'SUBF '
				if item is '*':
					mass_code += 'MULF '
				if item is '/':
					mass_code += 'DIVF '
			data = order_of_ops[i-2:i + 1]

			src1 = find_register(order_of_ops[i-2].strip())
			src2 = find_register(order_of_ops[i-1].strip())
			if src2 is None:
				src2 = new_reg
			mass_code += str(src1) + ' ' + str(src2) + ' ' + str(new_reg) + '\n'
			
			order_of_ops[i] = '!'
			order_of_ops.pop(i-1)
			i = 0

	return mass_code, new_reg

