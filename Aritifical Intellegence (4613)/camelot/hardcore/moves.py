from classes import contents, can_capture


# Gets a list of all the pieces that can be moved.
# Does this by checking to see if any pieces can eat any other ones.
# Input: Current board, list of pieces, color, opponent's color
# Output: A list of [all the pieces that can be moved, True/False]
# If a piece can eat another piece return True, else False
def can_eat(playing_board, my_pieces, my_color, opponent_color):
    hungry_pieces = []
    bool_result = False
    # Get all the moves for each piece
    for piece in my_pieces:
        moves = get_moves(playing_board, piece, my_color, opponent_color)

        # If any of the moves are capturing moves
        if moves[len(moves)] is can_capture.POSSIBLE:
            # Add that move to a separate list
            hungry_pieces.append(piece)
            bool_result = True
    # If a piece can be captured
    if bool_result:
        # Return reduced list
        return [hungry_pieces, bool_result]
    else:
        # Return all the pieces
        return [my_pieces, bool_result]


# Gets all the possible moves of a piece
# Input: current board, [row, column] of a piece to find its possible moves, color, opponent's color
# Output: dictionary {1:first move...., n:True/False}
# If a piece is being captured, true, else false
def get_moves(playing_board, index, my_color, opponent_color):
    row = index[0] - 1
    col = index[1] - 1
    results = []
    capture_results = []
    # Check all possible moves
    for i in range(3):
        # If row is out of bounds
        if i + row > 13 or i + row < 0:
            continue
        for j in range(3):
            # If column is out of bounds
            if j + col > 7 or j + col < 0:
                continue
            # Potential move
            row_coord = i + row
            col_coord = j + col
            # If that potential move is empty
            if playing_board[row_coord][col_coord] is contents.EMPTY:
                coordinate = [row_coord, col_coord]
                results.append(coordinate)

            # If I can jump my own piece
            elif playing_board[row_coord][col_coord] is my_color:
                row_difference = index[0] - row_coord
                col_difference = index[1] - col_coord
                # Check what is on the other side of my own piece
                try:
                    # If the space is empty
                    if playing_board[row_coord - row_difference][col_coord - col_difference] is contents.EMPTY:
                        # That is a possible move
                        coordinate = [row_coord - row_difference, col_coord - col_difference]
                        results.append(coordinate)
                except IndexError:
                    continue

            # If I can eat an opponents piece
            elif playing_board[i + row][j + col] is opponent_color:
                row_difference = index[0] - row_coord
                col_difference = index[1] - col_coord
                # Check what is on the other side of opponent's piece
                try:
                    # If the space is empty
                    if playing_board[row_coord - row_difference][col_coord - col_difference] is contents.EMPTY:
                        # That is a possible move
                        coordinate = [row_coord - row_difference, col_coord - col_difference]
                        capture_results.append(coordinate)
                except IndexError:
                    continue

    # If a capture move is possible
    if len(capture_results) > 0:
        return lst_to_dct(capture_results, True)
    else:
        return lst_to_dct(results, False)


# Turns A list to a dictionary
# Input: List, bool
# Output: A dictionary of {1:first item in list, ..., n-1:last item in list, n:bool}
def lst_to_dct(lst, capture_status):
    result = {}
    i = 1
    # Add list items to dictionary
    for item in lst:
        result[i] = item
        i = i + 1

    # Add bool to dictionary
    if capture_status:
        result[i] = can_capture.POSSIBLE
    else:
        result[i] = can_capture.IMPOSSIBLE
    return result


# Finds out which piece was eaten
# Input: A set of old coordinates and new coordinates by [row, column]
# Output: A [row, column] of which piece was eaten
def who_was_eaten(old_coord, new_coord):
    result = old_coord

    old_row = old_coord[0]
    old_col = old_coord[1]

    new_row = new_coord[0]
    new_col = new_coord[1]

    # Get change from old move to new move
    change_in_row = old_row - new_row
    change_in_col = old_col - new_col

    # If there is a negative change in the row
    if change_in_row < 0:
        result[0] = result[0] + 1
    # If there positive change in the row
    elif change_in_row > 0:
        result[0] = result[0] - 1

    # If there was a negative change in the column
    if change_in_col < 0:
        result[1] = result[1] + 1
    # If there was a positive change in the column
    elif change_in_col > 0:
        result[1] = result[1] - 1

    return result


# Makes the actual move
# Input: current board, old coordinate, new coordinate (both of form [row, column], bool
# True if a piece is getting eaten, otherwise false
def make_move(board, old_coord, new_coord, bool_eating):
    old_row = old_coord[0]
    old_col = old_coord[1]

    new_row = new_coord[0]
    new_col = new_coord[1]

    # Adjust the board
    board[new_row][new_col] = board[old_row][old_col]
    board[old_row][old_col] = contents.EMPTY

    # If a piece is being eaten
    if bool_eating:
        # Find out which piece is being eaten
        eaten_piece = who_was_eaten(old_coord, new_coord)
        eaten_row = eaten_piece[0]
        eaten_col = eaten_piece[1]
        board[eaten_row][eaten_col] = contents.EMPTY
