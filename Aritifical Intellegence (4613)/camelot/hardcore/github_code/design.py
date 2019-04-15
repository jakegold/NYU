from Tkinter import *


def make_squares(cv, size):
    for j in range(0, 14):
        for i in range(0, 8, 1):
            cv.create_rectangle(i * size, j * size, (i + 1) * size, (j + 1) * size, fill="LightBlue", tag="Square")
            if j == 0 or j == 13:
                if i <= 2 or i >= 5:
                    cv.create_rectangle(i * size, j * size, (i + 1) * size, (j + 1) * size, fill="black", tag="Square")
            if j == 1 or j == 12:
                if i <= 1 or i >= 6:
                    cv.create_rectangle(i * size, j * size, (i + 1) * size, (j + 1) * size, fill="black", tag="Square")
            if j == 2 or j == 11:
                if i <= 0 or i >= 7:
                    cv.create_rectangle(i * size, j * size, (i + 1) * size, (j + 1) * size, fill="black", tag="Square")


def make_pieces(xx, color):
    i = xx[0]
    j = xx[1]
    t = canvas.create_oval(i * SqSize + 2, j * SqSize + 2, (i + 1) * SqSize - 2, (j + 1) * SqSize - 2, fill=color, tag="Piece")
    return t


def set_layout():
    global x, y

    x = [b1, b2, b3, b4, b5, b6]
    y = [w1, w2, w3, w4, w5, w6]

    make_squares(canvas, SqSize)

    for i in x:
        AIids.append(make_pieces(i, 'black'))
    for i in y:
        Myids.append(make_pieces(i, 'white'))

    # if (v.get() == 1):
        # ComputerTurn()
        # HumanTurn1

w1 = (3, 5)
w2 = (4, 5)
w3 = (2, 4)
w4 = (3, 4)
w5 = (4, 4)
w6 = (5, 4)
b1 = (3, 8)
b2 = (4, 8)
b3 = (2, 9)
b4 = (3, 9)
b5 = (4, 9)
b6 = (5, 9)

SqSize = 40
master = Tk()

canvas = Canvas(master, height=560, width=320)
canvas.grid(row=4, column=0)

x = []
y = []

Flag3 = 0  # Checks whether two clicks are done on radiobutton for color
AIids = []  # Stores piece ids on the canvas
Myids = []
SqID = ()  # stores clicked square id
PieceID = ()  # stores cliced piece id
PI = ()  # stores Human player clicked piece id

set_layout()

master.mainloop()
