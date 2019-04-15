import itertools
from Crypto.Cipher import AES
from collections import defaultdict

def number1(hex_string):
	print hex_string.decode('hex').encode('base64')

def number2(left, right):
	first = left.decode('hex')
	second = right.decode('hex')
	result = ''.join(chr(ord(a) ^ ord(b)) for a,b in zip(first, second))
	print result.encode('hex')

def number3(hex_string):
	results = []
	decode = hex_string.decode('hex')
	for key in range(48, 91):
		result = ''
		for letter in decode:
			result = result + ''.join(chr(key ^ ord(letter)))
		results.append(result)
	print find_answer(results)

def find_answer(results):
	answer = ''
	longest = 0
	for result in results:
		if len(result.split()) > longest:
			answer = result
			longest = len(result.split())
	return answer

def number4():
	lines = []
	f = open('file.txt')
	for line in f:
		lines.append(line)

	for line in lines:
		line = line[:-1]
		decode = line.decode('hex')
		for key in range(48, 91):
			result = ''
			for letter in decode:
				result = result + ''.join(chr(key ^ ord(letter)))
			print line
			print key
			print result

def number5():
	quote = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal"
	result = []
	counter = 0
	for letter in quote:
		if counter is 0:
			result.append(ord('I') ^ ord(letter))
			counter = counter + 1
		elif counter is 1:
			result.append(ord('C') ^ ord(letter))
			counter = counter + 1
		else:
			result.append(ord('E') ^ ord(letter))
			counter = 0
	output = ''
	for num in result:
		output = output + hex(num)[2:]
	print output

def number6():
	input_file = ''.join(list(open('file_part_6.txt')))
	decoded = input_file.decode('base64')

	keys = []
	for keysize in range(2, 41):
		left = decoded[0:keysize] 
		right = decoded[keysize:keysize*2]
		dist = edit_distance(left, right)
		normalized = dist/keysize
		keys.append([normalized, keysize])

	keysizes = []
	for item in sorted(keys):
		keysizes.append(item[1])


# STUCK AFTER THIS!!!

	for keysize in keysizes:
		blocks = []
		for i in range(keysize):
			blocks.append([])

		for i, byte in enumerate(decoded):
			current_block = i % keysize
			blocks[current_block].append(byte)

		print keysize
		print blocks
		print '\n'

		keys = ''
		for byte in blocks:
			# key = key + modified_number3(byte)
			# modified_number3(byte)
			print ''.join(byte)
		# result = ''
  #   	for byte in blocks:
  #   		test = ''.join(byte).encode('hex')
 
  #   		result = result + number3(test)
  #   	# print result

		

def edit_distance(left, right):
	dist = 0
	pairs = zip(left, right)

	for left_bit, right_bit in pairs:
		difference = bin(ord(left_bit) ^ ord(right_bit))[2:]
		for bit in difference:
			if bit is '1':
				dist = dist + 1
	return dist

# def modified_number3(byte):
# 	for i in range(len(byte)):
# 		lst = []
# 		lst.append(i)
# 		modified_number2(lst, byte)

def number7():
	# After much google-ing
	obj = AES.new("YELLOW SUBMARINE", AES.MODE_ECB)

	file_7 = "".join(list(open("file_7.txt", "r")))
	decoded = file_7.decode("base64")
	print obj.decrypt(decoded)

def number8():
	lines = []
	file_8 = open("file_8.txt", "r")

	for line in file_8:
		line = line.strip()
		lines.append(line)
	# print lines

	for line in lines:
		reps = defaultdict(lambda: -1)
		for i in range(0, len(line), 16):
			block = bytes(line[i:i + 16])
			reps[block] += 1
		print sum(reps.values())


# number1('49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d')
# number2('1c0111001f010100061a024b53535009181c', '686974207468652062756c6c277320657965')
number3('1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736')
# number4()
# number5()
# number6()
# number7()
# number8()
