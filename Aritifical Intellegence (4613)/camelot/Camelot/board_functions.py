from classes import contents

# Global variables
ROWS = 14
COLUMNS = 8


# Builds the game board
# Returns a 2D array of the board
def build_board():
    # Build an empty board
    board = [[contents.NOCONTENT] * COLUMNS for _ in range(ROWS)]
    # For each row in the board
    for row in range(ROWS):
        # The first and last row
        if (row is 0) or (row is ROWS - 1):
            board[row][3] = contents.EMPTY
            board[row][4] = contents.EMPTY
        # The second and second to last row
        elif (row is 1) or (row is ROWS - 2):
            board[row][2] = contents.EMPTY
            board[row][3] = contents.EMPTY
            board[row][4] = contents.EMPTY
            board[row][5] = contents.EMPTY
        # The third and third to last row
        elif (row is 2) or (row is ROWS - 3):
            # For all the columns
            for column in range(COLUMNS):
                board[row][column] = contents.EMPTY
            board[row][0] = contents.NOCONTENT
            board[row][COLUMNS - 1] = contents.NOCONTENT
        # For the middle rows and and fourth and fourth to last row
        elif (row is 3) or (row is ROWS - 4) or (row is 6) or (row is 7):
            # For all the columns
            for column in range(COLUMNS):
                board[row][column] = contents.EMPTY
        # Add Black pieces
        elif row is 4:
            for column in range(COLUMNS):
                board[row][column] = contents.BLACK
            board[row][0] = contents.EMPTY
            board[row][1] = contents.EMPTY
            board[row][COLUMNS - 1] = contents.EMPTY
            board[row][COLUMNS - 2] = contents.EMPTY
        elif row is 5:
            for column in range(COLUMNS):
                board[row][column] = contents.EMPTY
            board[row][3] = contents.BLACK
            board[row][4] = contents.BLACK
        # Add White pieces
        elif row is ROWS - 5:
            for column in range(COLUMNS):
                board[row][column] = contents.WHITE
            board[row][0] = contents.EMPTY
            board[row][1] = contents.EMPTY
            board[row][COLUMNS - 1] = contents.EMPTY
            board[row][COLUMNS - 2] = contents.EMPTY
        else:
            for column in range(COLUMNS):
                board[row][column] = contents.EMPTY
            board[row][3] = contents.WHITE
            board[row][4] = contents.WHITE
    return board


# Print the board
# Input: 2D array
def print_board(board):
    rows = '[  ] [ 0 ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ]'
    print rows
    counter = 0
    for item in board:
        # Add '0' to output for consistency
        if counter < 10:
            num = '0' + str(counter)
        else:
            num = str(counter)
        # Print the actual contents
        to_print = str(item)
        to_print = '[' + num + '] ' + to_print
        print to_print
        counter = counter + 1
    print '\n'


# Finds all the pieces of a certain color
# Input: A 2D board, contents.color
# Output: A list of length 2 lists of each row, column of each piece
def find_my_pieces(board, color):
    results = []
    # Loop through all rows and columns
    for row in range(ROWS):
        for col in range(COLUMNS):
            # If the content is my color
            if board[row][col] is color:
                piece = [row, col]
                # Add that piece to my results
                results.append(piece)
    return results


# Finds the depth that the tree should be searched
# Input: the number of pieces left on the board, the user input difficulty
# Output: int of how deep the tree should be searched
def find_depth(num_pieces, diff):
    # If user is on level 1
    if diff is 2:
        return diff
    # If there are too many pieces for an intensive search
    if num_pieces > 9:
        return 4
    # With enough pieces
    else:
        return diff
