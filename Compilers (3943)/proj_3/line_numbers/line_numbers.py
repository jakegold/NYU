

# Ideally this would be done by the scanner...
# Input: an input_file of
# Output: a dictionary of dict[line_number] = string line_of_code
def get_line_numbers(input_file):
    result = {}
    line_number = 0
    string = open_me(input_file)
    lines = string.split('\n')
    for line in lines:
        result[line_number] = line
        line_number = line_number + 1
    return result
