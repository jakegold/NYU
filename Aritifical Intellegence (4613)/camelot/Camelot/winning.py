from board_functions import find_my_pieces


# Checks to see if there is a winner
# Input: Current board, row of winning square, color, opponent's color
# Output: Bool
# True if there is a winner, otherwise false
def check_win(board, row, my_color, opponent_color):
    return board[row][3] is my_color and board[row][4] is my_color \
           or len(find_my_pieces(board, opponent_color)) is 0 and len(find_my_pieces(board, my_color)) >= 1


# Checks to see if there is a tie
# Input: Current board, color, opponent's color
# Output: Bool
# True if there is a draw, otherwise false
def check_tie(board, my_color, opponent_color):
    return len(find_my_pieces(board, my_color)) is 1 and len(find_my_pieces(board, opponent_color)) is 1
