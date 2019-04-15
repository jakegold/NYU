# -*- coding: utf-8 -*-
import re
import tables


# Input a string to convert to a table that is being used for the tokens
def convert_to_table(string):
    if string is 'table4':
        return tables.table4
    elif string is 'table3':
        return tables.table3
    elif string is 'table2':
        return tables.table2
    else:
        return tables.table1


# Takes some input and scans it
# Input: a string
# Return: a list of what each token is
def scanner(std_input, table):
    # Break up the input by white space
    smaller_strings = std_input.split()
    result = []
    for sub_string in smaller_strings:
        # Scan each of these smaller stings
        local_result = scan_sub_string(sub_string, table)
        # If result is a list of lists
        if isinstance(local_result[0], list):
            # Append each list
            for row in local_result:
                result.append(row)
        # If result is just a list
        else:
            result.append(local_result)
    return result


# Scans a small string with no white space
# Input: a string (no white space)
# Return: a list of [regex, token number, token name, string]
def scan_sub_string(string, table):
    match = find_match(string, table)
    # If the match is None
    if match is None:
        # Illegal Char
        error = ['', 'Illegal character # in input', '', string]
        return error
    # If the entire string matches that pattern
    if match_full_string(match[0], string):
        result = list(match)
        result.append(string)
        return result
    # If there is more than one token in string
    else:
        return sub_scan(string, table)


# Checks to see if the match matches to the entire string
# Input: a pattern to match and a string
# Return: True if the entire string is that pattern
def match_full_string(pattern, string):
    try:
        m = re.match(pattern, string)
        if len(m.group(0)) == len(string):
            return True
        return False
    except AttributeError as err:
        return False


# The real work of the scanner (a string with more than one token)
# Input: a string of more than one token (no white space)
# Return: a list of lists [[regex, token number, token name, string], ...]
def sub_scan(string, table):
    start = 0
    end = 1

    result = []
    # While the start index is not past the end of the string
    while start < len(string):
        # Get a substring
        sub_str = string[start:end]
        # Find a match
        match = find_match(sub_str, table)
        # If there is not a match of this string yet (It will always get one because tested for illegal char already)
        # An example of when this wouldn't happen is if you can have '==' but not '='
        while match is None:
            # Find the first match
            end = end + 1
            sub_str = string[0:end]
            match = find_match(sub_str, table)

        # Find the last index of this pattern
        pattern = match[0]
        end_index = same_token(start, end, string, pattern)

        # Add this token to return value
        temp_list = list(match)
        temp_list.append(string[start:end_index])
        result.append(temp_list)
        start = end_index
        end = start + 1

    return result


# Finds the longest match of token from the table
# Input: a string of what is being matched
# Return: a row from table [regex, token number, token name]
def find_match(string, table):
    longest_match = 0
    best_match = None
    # Search for best token
    for row in table:
        pattern = row[0]
        potential_match = re.match(pattern, string)
        try:
            # If len(potential_match) > (longest_match)
            if len(potential_match.group(0)) > longest_match:
                best_match = row
                longest_match = len(potential_match.group(0))
        except AttributeError as err:
            continue
    return best_match


# Checks to see how long a given string or number pattern is
# Input: the starting index, the end index, the string itself, and the pattern to match
# Return: the index of the last char of the given string or number
def same_token(start, end, string, pattern):
    while True:
        sub_string = string[start:end]
        potential_match = re.match(pattern, sub_string)
        try:
            if len(potential_match.group(0)) == end - start:
                end = end + 1
            else:
                return end - 1
        except AttributeError as err:
            continue


# Formats the output
# Input: list of things
def output(result):
    for row in result:
        print row[1], ' ', row[2], ' ', row[3]
