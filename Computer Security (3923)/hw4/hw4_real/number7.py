from Crypto.Cipher import AES

# After much google-ing
obj = AES.new("YELLOW SUBMARINE", AES.MODE_ECB)

file_7 = open("file_7.txt", "r")
file_7 = file_7.read()

decoded = file_7.decode("base64")
print obj.decrypt(decoded)