from number2 import XOR
from number3 import find_best_answer

input_file = open('file_4.txt')
all_lines = []
for line in input_file:
    line = line.strip()
    line = bytearray.fromhex(line)
    all_lines.append(line)


length = len(all_lines[0])
left = [None] * length
potential_answers = []
for right in all_lines:
    for i in range(256):
        for j in range(length):
            left[j] = i
        try:
            answer = XOR(left, right)
            potential_answers.append([answer, i])
        except IndexError as err:
            continue

key, line = find_best_answer(potential_answers)
print key
print line
