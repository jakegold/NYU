'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
'''
# Some Generic helper functions


# Input: a file
# Output: a string of the file
def open_me(input_file):
	with open(input_file, 'r') as inf:
		string = inf.read()
	return string


# Input: an output file name, an iterable to be written
# Creates a file with that name containing the iterable
def write_to_me(output_file, output):
	with open(output_file, 'w') as f:
		for line in output:
			f.write(line + '\n')


# Input: a key for a dict, 
# 		 a value to add for that key,
# 		 a dict of form dict[key] = [value1, value2...]
# Adds the passed value to the dict at index key
def add_to_dict(key, value, dct):
	if key not in dct:
		dct[key] = [value,]
	else:
		dct[key].append(value)


# Input: input_file of form file.txt, a string word
# Output: file_word.txt
def make_file_name(input_file, string):
	return input_file.split('.')[0] + '_' + string + '.txt'
