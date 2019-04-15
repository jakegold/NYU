file_8 = open('file_8.txt')
file_8 = file_8.read().split('\n')

best = 0
result = None

for line in file_8:

    line = line.strip()
    line = bytearray(line)

    block_size = 16
    length = len(line)

    data = {}

    for i in range(0, length, block_size):
        block = line[i:i + block_size]
        block = bytes(block)

        if block in data:
            data[block] = data[block] + 1
        else:
            data[block] = 1

    count = 0

    for key in data:

        count = data[key]

        if count > best:
            best = count

            for sub_line in file_8:
                if key in sub_line:
                    result = sub_line
                    break


print result