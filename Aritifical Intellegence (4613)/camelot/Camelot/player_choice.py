# Lets a user pick if he will go first of second
# Output: bool
# True if first, otherwise false
def pick_turn():
    print 'You will play as white.'
    print "Choose to go first or second by entering 'first' or 'second'." \
          " (It will default to you playing first on typos)"

    # Get input
    user_input = raw_input()

    # If second
    if user_input == 'second':
        print 'Ok. You will play second \n'
        return False
    # If first
    else:
        print 'Ok. You will play first \n'
        return True


# Lets a user pick the difficulty of the game
# Output: int of how deep the tree should search
def pick_difficulty():
    test = 0

    # While user gives invalid input
    while test <= 0 or test > 3:
        print 'Please choose a valid difficulty to play on, either 1, 2 or 3.\n'
        # Get input
        test = raw_input()
        try:
            test = int(test)
        except ValueError:
            test = 0
    print 'Ok. The computer will play on level ', test, '\n'

    # Convert user input to depth tree should search
    return convert_to_node_depth(test)


# Converts a number to a node depth
# Input: int level of difficulty
# Output: int depth that the AI should search in tree
def convert_to_node_depth(number):
    # Level 1
    if number is 1:
        return 2
    # Level 2
    if number is 2:
        return 4
    # Level 3
    if number is 3:
        return 6
    return 4
