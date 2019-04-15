from classes import contents
from moves import get_moves, make_move, can_eat

# Global variables
NODES_MADE = 1
MAX_PRUNES = 1
MIN_PRUNES = 1


# Main function of the computer's turn
# Input: A board of the current state, the computer's pieces, the human's pieces, int level of depth for search
def computer_turn(playing_board, comp_pieces, human_pieces, difficulty):
    # Get globals
    global MAX_PRUNES
    global MIN_PRUNES
    global NODES_MADE

    # Set globals to 0
    MAX_PRUNES = 0
    MIN_PRUNES = 0
    NODES_MADE = 0

    # Call the alpha beta search to find best move
    result = alpha_beta_max(playing_board, comp_pieces, human_pieces, difficulty, -1000, 1000)

    # Get the depth that the tree was searched at
    depth = result[2]

    # Output data
    print 'Depth searched: ', depth
    print 'Number of nodes: ', NODES_MADE
    print 'Number of MAX prunes: ', MAX_PRUNES
    print 'Number of MIN prunes: ', MIN_PRUNES

    # Find the new locations of computer's pieces
    new_spaces = result[0]

    # Find the new and old moves
    new_move = []
    old_move = []
    for move in new_spaces:
        if move not in comp_pieces:
            new_move = move
    for move in comp_pieces:
        if move not in new_spaces:
            old_move = move
    eaten = False

    # Find if a piece was eaten or not on computer's turn
    change_row = old_move[0] - new_move[0]
    change_col = old_move[1] - new_move[1]
    if abs(change_col) > 1 or abs(change_row) > 1:
        if change_row > 0:
            check_row = old_move[0] - 1
        elif change_row is 0:
            check_row = old_move[0]
        else:
            check_row = old_move[0] + 1
        if change_col > 0:
            check_col = old_move[1] - 1
        elif change_col is 0:
            check_col = old_move[1]
        else:
            check_col = old_move[1] + 1
        # If a piece was eaten
        if playing_board[check_row][check_col] is contents.WHITE:
            eaten = True

    # Print the computer's move
    print 'The computer moved from: ', old_move, ' to: ', new_move

    # Move the computer's piece
    make_move(playing_board, old_move, new_move, eaten)


# Alpha beta search - Max player
# Input: Current playing board, computer's pieces, human's pieces, int of the iteration, alpha, beta
# Output: a list of [newly moved pieces, utility value, depth that the tree searched]
def alpha_beta_max(playing_board, comp_pieces, human_pieces, iteration, alpha, beta):
    # Get globals
    global NODES_MADE
    global MAX_PRUNES

    # Find if this node is a terminal node
    if is_terminal(playing_board, contents.BLACK):
        return [comp_pieces, 1000, iteration]
    if is_terminal(playing_board, contents.WHITE):
        return [human_pieces, -1000, iteration]

    # If this iteration is as far down as the tree should go
    if iteration is 0:
        # Get a utility of this node
        utility = get_utility(comp_pieces, human_pieces, contents.BLACK)
        return [comp_pieces, utility, iteration]

    # Start the search!
    smallest_value = -1000
    potential_moves = list(comp_pieces)

    # Find all the pieces that can be moved
    edible = can_eat(playing_board, comp_pieces, contents.BLACK, contents.WHITE)

    # For each piece that can be moved
    for i, piece in enumerate(edible[0]):
        # Get the moves for that piece
        all_moves_for_piece = get_moves(playing_board, piece, contents.BLACK, contents.WHITE)

        # If a piece has to be eaten
        if edible[1] is True:
            current_max = -1001
            potential_eating_moves = None
            # For all the moves that can be taken
            for move in all_moves_for_piece:
                # Accounts for the return of get_moves
                if type(all_moves_for_piece[move]) is bool:
                    continue
                # A new node was created
                NODES_MADE += 1
                # Find the new move
                new_moves = list(comp_pieces)
                piece_index = comp_pieces.index(piece)
                new_moves[piece_index] = all_moves_for_piece[move]

                # Get the utility of the node
                eating_utility = get_utility(new_moves, human_pieces, contents.BLACK)

                # If this move is the best move so far
                if eating_utility > current_max:
                    current_max = eating_utility
                    potential_eating_moves = list(new_moves)

            # Return best move for eating
            return [potential_eating_moves, current_max, iteration]

        # If no piece can be eaten
        for move in all_moves_for_piece:
            # Accounts for the return of get_moves
            if type(all_moves_for_piece[move]) is bool:
                continue

            # A new node was created
            NODES_MADE += 1
            # Find the new move
            new_moves = list(comp_pieces)
            new_moves[i] = all_moves_for_piece[move]

            # Call the min player
            minimum = alpha_beta_min(playing_board, new_moves, human_pieces, iteration - 1, alpha, beta)

            # Get the min utility
            min_utility = minimum[1]

            # If the min utility is a min value
            if min_utility > smallest_value:
                smallest_value = min_utility
                potential_moves = list(new_moves)

            # If the tree can be pruned
            if smallest_value >= beta:
                # Prune!
                MAX_PRUNES += 1
                return [list(new_moves), smallest_value, iteration]

            # Fix alpha value
            if alpha < smallest_value:
                alpha = smallest_value

    # If potential moves did not work out
    if potential_moves is comp_pieces:
        return [new_moves, smallest_value, iteration]
    # If potential moves did work out
    else:
        return [potential_moves, smallest_value, iteration]


# Alpha beta search - Min player
# Input: Current playing board, computer's pieces, human's pieces, int of the iteration, alpha, beta
# Output: a list of [newly moved pieces, utility value, depth that the tree searched]
def alpha_beta_min(playing_board, comp_pieces, human_pieces, iteration, alpha, beta):
    # Get globals
    global NODES_MADE
    global MIN_PRUNES

    # Find if this node is a terminal node
    if is_terminal(playing_board, contents.WHITE):
        return [human_pieces, -1000, iteration]
    if is_terminal(playing_board, contents.BLACK):
        return [comp_pieces, 1000, iteration]

    # If this iteration is as far down as the tree should go
    if iteration is 0:
        # Get a utility of this node
        utility = get_utility(human_pieces, comp_pieces, contents.WHITE)
        return [human_pieces, utility, iteration]

    # Start the search!
    largest_value = 1000
    potential_moves = list(human_pieces)

    # Find all the pieces that can be moved
    edible = can_eat(playing_board, human_pieces, contents.WHITE, contents.BLACK)

    # For each piece that can be moved
    for i, piece in enumerate(edible[0]):
        # Get the moves for that piece
        all_moves_for_piece = get_moves(playing_board, piece, contents.WHITE, contents.BLACK)

        # If a piece has to be eaten
        if edible[1] is True:
            current_min = 1001
            potential_eating_moves = None
            # For all the moves that can be taken
            for move in all_moves_for_piece:
                # Accounts for the return of get_moves
                if type(all_moves_for_piece[move]) is bool:
                    continue

                # A new node was created
                NODES_MADE += 1

                # Check for a bad output
                if piece in comp_pieces:
                    piece_index = comp_pieces.index(piece)
                else:
                    continue

                # Find the new move
                new_moves = list(comp_pieces)
                new_moves[piece_index] = all_moves_for_piece[move]

                # Get the utility of the node
                eating_utility = get_utility(new_moves, human_pieces, contents.WHITE)

                # If this move is the best move so far
                if eating_utility < current_min:
                    current_min = eating_utility
                    potential_eating_moves = list(new_moves)

            # Return best move for eating
            return [potential_eating_moves, current_min, iteration]

        # If no piece can be eaten
        for move in all_moves_for_piece:
            # Accounts for the return of get_moves
            if type(all_moves_for_piece[move]) is bool:
                continue

            # A new node was created
            NODES_MADE += 1

            # Find the new move
            new_moves = list(human_pieces)
            new_moves[i] = all_moves_for_piece[move]

            # Call the max player
            maximum = alpha_beta_max(playing_board, comp_pieces, new_moves, iteration - 1, alpha, beta)

            # Get the max utility
            max_utility = maximum[1]

            # If the max utility is a max value
            if max_utility < largest_value:
                largest_value = max_utility
                potential_moves = list(new_moves)

            # If the tree can be pruned
            if largest_value <= alpha:
                # Prune!
                MIN_PRUNES += 1
                return [list(new_moves), largest_value, iteration]

            # Fix beta value
            if beta > largest_value:
                beta = largest_value

    # If potential moves did not work out
    if potential_moves is comp_pieces:
        return [new_moves, largest_value, iteration]
    # If potential moves did work out
    else:
        return [potential_moves, largest_value, iteration]


# Finds out if a node in a tree is a terminal node
# Input: current playing board, and a color
# Output: bool of true if the node is terminal, else false
def is_terminal(playing_board, content):
    # Testing for Black
    if content is contents.BLACK:
        if playing_board[0][3] is contents.BLACK and playing_board[0][4] is contents.BLACK:
            return True
        else:
            return False
    # Testing for White
    if playing_board[13][3] is contents.WHITE and playing_board[0][4] is contents.WHITE:
        return True
    else:
        return False


# Driver for finding the utility of a node
# Input: list of pieces, opponents pieces, and player's color
# Output: value of the node
def get_utility(pieces, opp_pieces, color):
    # Find utility for Black
    if color is contents.BLACK:
        return evaluation(pieces, color) - (evaluation(pieces, contents.WHITE)/2)
    # Find utility for White
    else:
        return evaluation(pieces, color) - (evaluation(pieces, contents.BLACK)/2)


# Calculates the utility of a node
# Input: pieces and the color of those pieces
# Output: int of the value of the pieces
def evaluation(pieces, color):
    # Check for a win
    if color is contents.WHITE:
        if [0, 3] in pieces and [0, 4] in pieces:
            return 1000
    if color is contents.BLACK:
        if [13, 3] in pieces and [13, 4] in pieces:
            return 1000

    result = 0

    # Values of each column
    col_vales = [150, 75, 175, 250, 250, 175, 75, 150]

    # Find utility for the human player
    if color is contents.WHITE:
        # Values of each row
        row_values = [600, 500, 400, 350, 200, 100, 50, 0, -50, -100, -150, -200, -250, -300]
        # Compute the value of each piece
        for piece in pieces:
            result = result + row_values[piece[0]] + col_vales[piece[1]]

    # Find the utility for the computer player
    else:
        # Values for each row
        row_values = [-300, -250, -200, -150, -100, -50, 0, 50, 100, 200, 350, 400, 500, 600]
        # Compute the value of each piece
        for piece in pieces:
            result = result + row_values[piece[0]] + col_vales[piece[1]]

    return result
