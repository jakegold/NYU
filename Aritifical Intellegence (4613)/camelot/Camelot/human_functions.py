from classes import contents
from board_functions import print_board
from moves import get_moves, can_eat, make_move


# Main Function of the human move
# Input: Current playing board, human pieces, computer pieces
def human_turn(playing_board, my_pieces, computer_pieces):
    print_board(playing_board)

    # Get a list of all the pieces that can be moved
    edible = can_eat(playing_board, my_pieces, contents.WHITE, contents.BLACK)

    # Print the list of pieces
    print_pieces(edible[0])

    # Get which piece the user wants to move
    index = get_piece(edible[0])

    # Get where the user would like to move that piece
    print 'Please select where to move this piece to'
    moves = get_moves(playing_board, index, contents.WHITE, contents.BLACK)
    print_dct(moves)
    move = get_move(moves)

    # Make the move
    make_move(playing_board, index, move, edible[1])


# Prints A list of pieces
# Input: List of pieces
def print_pieces(pieces):
    i = 1
    # Print all pieces
    for lst in pieces:
        print i, ': ', lst
        i = i + 1


# Gets The input of which piece will be moved
# Input: A list of all pieces
# Output: A list of [row, column] of which piece is being moved
def get_piece(my_pieces):
    move = -1
    # While user is not giving good input
    while move < 1 and move < len(my_pieces):
        print 'Please input which piece you would like to move: ( 1 -', len(my_pieces), ')'
        # Get input
        move = raw_input()
        move = int(move)
    print 'Ok. You are going to move: ', my_pieces[move-1], '\n'
    return my_pieces[move-1]


# Prints a dict
# Input: A dict
def print_dct(dct):
    for i in range(len(dct)-1):
        print i + 1, ':', dct[i+1]


# Gets which move a player would like to make
# Input: A dict of moves
# Output: One of the moves from the dict
def get_move(dct):
    move = -1
    # While user is not giving good input
    while move < 1 and move < len(dct):
        print 'Please input which move you would like to make: ( 1-', len(dct), ')'
        # Get input
        move = raw_input()
        move = int(move)
    print '\n'
    return dct[move]
