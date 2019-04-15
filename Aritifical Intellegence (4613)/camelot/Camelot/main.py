from classes import contents
from board_functions import build_board, find_depth, print_board
from human_functions import human_turn
from player_choice import pick_difficulty, pick_turn
from computer_functions import computer_turn
from winning import find_my_pieces, check_win, check_tie


# The main method call
def main():
    print 'Please follow the instructions on the screen.'

    # Build the board
    playing_board = build_board()

    # User input to pick the difficulty
    difficulty = pick_difficulty()

    # User input to choose first or second
    player_turn = pick_turn()

    # Loop switching off who's turn it is
    while True:
        # Player's turn
        if player_turn:
            print 'It is your turn.'

            # Find all of the pieces on the board
            white_pieces = find_my_pieces(playing_board, contents.WHITE)
            black_pieces = find_my_pieces(playing_board, contents.BLACK)

            # Human makes a moves
            human_turn(playing_board, white_pieces, black_pieces)

            # Print the new board state
            print_board(playing_board)

            # Check if human wins
            if check_win(playing_board, 0, contents.WHITE, contents.BLACK):
                print 'You WIN!'
                break
            # Check if there is a draw
            if check_tie(playing_board, contents.WHITE, contents.BLACK):
                print 'There was a tie'
                break
        # Computer's turn
        else:
            print "It is the computer's turn. Please wait"

            # Find all of the pieces on the board
            white_pieces = find_my_pieces(playing_board, contents.WHITE)
            black_pieces = find_my_pieces(playing_board, contents.BLACK)

            # Find the appropriate depth to search tree
            total_pieces = len(white_pieces) + len(black_pieces)
            depth = find_depth(total_pieces, difficulty)

            # Computer makes a move
            computer_turn(playing_board, black_pieces, white_pieces, depth)

            # Print the new board
            print_board(playing_board)

            # Check if computer wins
            if check_win(playing_board, 13, contents.BLACK, contents.WHITE):
                print 'You LOSE!'
                break
            # Check for a draw
            if check_tie(playing_board, contents.BLACK, contents.WHITE):
                print 'There was a tie'
                break
        # Change who's turn it is
        player_turn = not player_turn

# Function call
main()
