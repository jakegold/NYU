from number2 import XOR

def single_XOR(left):
	length = len(left)

	right = [None] * length

	potential_answers = []

	for i in range(256):
		for j in range(length):
			right[j] = i
		option = XOR(left, right)
		potential_answers.append([option, i])

	return find_best_answer(potential_answers)

def find_best_answer(potential_answers):
	f = open('/usr/share/dict/words')
	all_words = f.read().split('\n')

	best = 0
	result = ''
	char = ''
	for line, key in potential_answers:
		try:
			string = bytes(line).decode('utf-8').encode('ascii')
			split_string = string.split()
			if len(split_string) > 0:
				counter = 0
				for word in split_string:
					if word in all_words:
						counter = counter + 1
				if counter > best:
					best = counter
					result = string
					char = key
		except UnicodeDecodeError as err:
			continue
		except UnicodeEncodeError as err:
			continue
	return char, result

string = '1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736'
byte = bytearray.fromhex(string)
key, result = single_XOR(byte)
# print chr(key)
# print result
