# from flask import *
from enum import Enum
# import operator, calendar, time
# app = Flask(__name__)
# app.secret_key = 'secret_key'

ROWS = 14
COLUMNS = 8

class contents(Enum):
	NOCONTENT = 'X'
	EMPTY = '-'
	WHITE = 'W'
	BLACK = 'B'

class player_color(Enum):
	WHITE = 'W'
	BLACK = 'B'


def build_board():
	board = [[contents.NOCONTENT]*COLUMNS for _ in range(ROWS)]
	for row in range(ROWS):
		if (row is 0) or (row is ROWS-1):
			board[row][3] = contents.EMPTY
			board[row][4] = contents.EMPTY
		elif (row is 1) or (row is ROWS-2):
			board[row][2] = contents.EMPTY
			board[row][3] = contents.EMPTY
			board[row][4] = contents.EMPTY
			board[row][5] = contents.EMPTY
		elif (row is 2) or (row is ROWS-3):
			for column in range(COLUMNS):
				board[row][column] = contents.EMPTY
			board[row][0] = contents.NOCONTENT
			board[row][COLUMNS-1] = contents.NOCONTENT
		elif (row is 3) or (row is ROWS-4) or (row is 6) or (row is 7):
			for column in range(COLUMNS):
				board[row][column] = contents.EMPTY
		elif (row is 4):
			for column in range(COLUMNS):
				board[row][column] = contents.BLACK
			board[row][0] = contents.EMPTY
			board[row][1] = contents.EMPTY
			board[row][COLUMNS-1] = contents.EMPTY
			board[row][COLUMNS-2] = contents.EMPTY
		elif (row is 5):
			for column in range(COLUMNS):
				board[row][column] = contents.EMPTY
			board[row][3] = contents.BLACK
			board[row][4] = contents.BLACK
		elif (row is ROWS-5):
			for column in range(COLUMNS):
				board[row][column] = contents.WHITE
			board[row][0] = contents.EMPTY
			board[row][1] = contents.EMPTY
			board[row][COLUMNS-1] = contents.EMPTY
			board[row][COLUMNS-2] = contents.EMPTY
		else:
			for column in range(COLUMNS):
				board[row][column] = contents.EMPTY
			board[row][3] = contents.WHITE
			board[row][4] = contents.WHITE
	return board 

def print_board(board):
	rows = '[  ] [ 0 ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ]'
	print rows
	counter = 0
	for item in board:
		if counter < 10:
			num = '0' + str(counter)
		else:
			num = str(counter)
		to_print = str(item)
		to_print = '[' + num + '] ' + to_print
		print to_print
		counter = counter + 1

def set_up():
	print "Please enter either 'white' or 'black' to choose a color"
	color = raw_input()
	color = player_color.WHITE
	if color is 'black':
		color = player_color.BLACK
		print 'Okay, you will play as black'
	else:
		print 'Okay, you will play as white'
	return color

def get_machine_color(human_color):
	if human_color is player_color.WHITE:
		return player_color.BLACK
	else:
		return player_color.WHITE

def get_piece():
	row = -1
	col = -1
	while row <= 0 and row < 13:
		print 'Please follow the instructions.'
		print 'If you enter a coordinate that does not contain your peice,'
		print ' you will be asked for another input \n'
		print 'Please enter the row of the piece you would like to move (0-13)'
		row = raw_input()
		row = int(row)

	while col <= 0 and col < 8:
		print 'Please follow the instructions.'
		print 'If you enter a coordinate that does not contain your peice,'
		print ' you will be asked for another input \n'
		print 'Please enter the column of the piece you would like to move (0-8)'
		col = raw_input()
		col = int(col)
	print '\n'
	return [row, col]

def get_moves(playing_board, color, index):
	row = index[0]
	col = index[1]
	if playing_board[row][col] is not color:
		print 'Not your color. Please try again'
		return ['data....']
	row = index[0] - 1
	col = index[1] - 1
	results = []
	for i in range(3):
		for j in range(3):
			if playing_board[i + row][j + col] is contents.EMPTY:
				coordinate = [i + row, j + col]
				results.append(coordinate) 
	return lst_to_dct(results)

def lst_to_dct(lst):
	result = {}
	i = 1
	for item in lst:
		result[i] = item
		i = i + 1
	return result

def print_dct(dct):
	for item in dct:
		print item, ':', dct[item]

def get_move(dct):
	move = -1
	while move < 1 and move < len(dct):
		print 'Please input which move you would like to make: ( 1-', len(dct), ')'
		move = raw_input()
		move = int(move)
	print '\n'
	return dct[move]

def make_move(board, old_coord, new_coord):
	old_row = old_coord[0]
	old_col = old_coord[1]

	new_row = new_coord[0]
	new_col = new_coord[1]

	board[new_row][new_col] = board[old_row][old_col]
	board[old_row][old_col] = contents.EMPTY
	# board


def main():
	playing_board = build_board()
	human_color = set_up()
	machine_color = get_machine_color(human_color)

	turn = player_color.WHITE

	while True:
		if turn is player_color.WHITE:
			turn = player_color.BLACK
		else:
			turn = player_color.WHITE

	print_board(playing_board)

	
	# color = player_color.WHITE
	index = get_piece()
	moves = get_moves(playing_board, color, index)
	print_dct(moves)
	move = get_move(moves)
	make_move(playing_board, index, move)

	print_board(playing_board)



main()