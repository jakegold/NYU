from number2 import XOR

quote = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal"
right = bytearray(quote)

left = "ICE" * len(quote)
left = left[:len(quote)]
left = bytearray(left)

result = XOR(left, right)
result = bytes(result)
result = result.encode('hex')
print result
