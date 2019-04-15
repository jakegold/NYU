def hex_to_64(string):

	# string = '49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d'
	decoded = string.decode('hex')
	encoded = decoded.encode('base64')

	# print decoded
	# print encoded

	return encoded

print hex_to_64('49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d')