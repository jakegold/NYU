from enum import Enum


# A class that is used for user colors and for filling the board
class contents(Enum):
    # No piece is allowed to be here
    NOCONTENT = 'X'
    # An empty piece
    EMPTY = '-'
    # White pieces
    WHITE = 'W'
    # Black pieces
    BLACK = 'B'


# A class that is used if a piece can be captured
class can_capture(Enum):
    POSSIBLE = True
    IMPOSSIBLE = False
