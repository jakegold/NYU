'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''

# NOTE: LARGEST LABEL IS: 999999
from set_up import labels

# Output: a new label number
# Returns a new label and adds one to it for next time
def get_new_label(label, name):
	labels[label] = name
	return label + 1


# Input: a label to convert to output for MASS
# Output: LABEL label (where label is a number)
def create_label(label):
	lables[label] = name
	return 'LABEL ' + str(label) + '// ' + name