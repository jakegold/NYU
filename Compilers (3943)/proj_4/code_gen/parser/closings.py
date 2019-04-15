'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

import re


def check_closings(lines):
	stack = []
	for line in lines:
		lpar = re.search('LPAR', line)
		rpar = re.search('RPAR', line)
		lbrace = re.search('LBRACE', line)
		rbrace = re.search('RBRACE', line)
		if lpar:
			stack.append('(') #also maybe a line...
		if lbrace:
			stack.append('{') #also maybe a line...
		if rpar:
			if stack[-1] is '(':
				stack.pop()
			# else:
			# 	print 'Error: Closing parentheses without an opening!' #Also should have a line number...
		if rbrace:
			if stack[-1] is '{':
				stack.pop()
			# else:
			# 	print 'Error: Closing brace without an opening!' #Also should have a line number
	if len(stack) > 0:
		top_of_stack = stack.pop()
		if top_of_stack is '(':
			print 'Error: Did not close a parentheses!'#Also should have a line number
		else:
			print 'Error: Did not close a brace!'#Also should have a line number


