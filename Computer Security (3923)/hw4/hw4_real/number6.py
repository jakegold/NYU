from number2 import XOR
from number3 import single_XOR

def edit_distance(left, right):
	result = 0
	for pair in XOR(left, right):
		pair = bin(pair)
		result = result + pair.count('1')
	return result

# left = 'this is a test'
# right = 'wokka wokka!!!'

# left = bytearray(left)
# right = bytearray(right)

# edit_distance(left, right)

file_input = open('file_6.txt')
lines = file_input.read()
lines = lines.decode('base64')
lines = bytearray(lines)

distances = []
for keysize in range(2, 40):
    first = lines[: keysize]
    second = lines[keysize: keysize * 2]
    third = lines[keysize * 2: keysize * 3]
    fourth = lines[keysize * 3: keysize * 4]

    first_pair = edit_distance(first, second)
    second_pair = edit_distance(second, third)
    third_pair = edit_distance(third, fourth)

    dist = float((first_pair + second_pair + third_pair)/keysize*3)

    distances.append([dist, keysize])

distances = sorted(distances)[:10]


for _, keysize in distances:
	block = [[] for _ in range(keysize)]
	index = 0
	for byte in lines:
		block[index % keysize].append(byte)
		index = index + 1

	keys = ''
	for byte in block:
		add_on = single_XOR(byte)[0]
		keys = keys + str(add_on)

	key = keys * len(lines)
	key = bytearray(key)
	result = XOR(lines, key)
	result = bytes(result)

	print keys
	print keysize
	print result


