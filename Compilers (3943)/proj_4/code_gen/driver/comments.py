'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''


import re


# Input: a single line of code
# Output: the same line of code without // comment
def find_comment(line_of_code):
	# Also need to find open ended comment?...Nope. Turns out that ply does this on its own
	return find_single_line_comment(line_of_code)
	

# Returns the line of code starting from before the comment
def find_single_line_comment(line_of_code):
	try:
		match = re.search('\/\/', line_of_code)
		return line_of_code[:match.start()]
	except Exception as err:
		return line_of_code

