def XOR(left, right):
	length = len(left)
	result = bytearray(length)
	for i in range(length):
		result[i] = left[i] ^ right[i]
	return result


left, right = '1c0111001f010100061a024b53535009181c', '686974207468652062756c6c277320657965'
left = bytearray.fromhex(left)
right = bytearray.fromhex(right)
result = XOR(left, right)
result = bytes(result)
# print result.encode('hex')