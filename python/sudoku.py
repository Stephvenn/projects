# Stephen Shin
# Sudoku Solving program


board=[
    [8,0,0,0,0,0,0,0,0],
    [0,0,3,6,0,0,0,0,0],
    [0,7,0,0,9,0,2,0,0],
    [0,5,0,0,0,7,0,0,0],
    [0,0,0,0,4,5,7,0,0],
    [0,0,0,1,0,0,0,3,0],
    [0,0,1,0,0,0,0,6,8],
    [0,0,8,5,0,0,0,1,0],
    [0,9,0,0,0,0,4,0,0]]

iterations = 0

# printboard prints sudoku board to console
#
# param 1: {list} board The sudoku board.
# return: N/A
def printboard(board):

    for i in board:
        if len(i) != len(board):
            print("Invalid board")
            return -1

    count = 0
    for i in board:
        if count % 3 == 0 and count != 0:
            print("-"*len(i) + "-" * (len(i)//3))
        for j in range(len(i)):
            print(i[j], end="")
            if (j+1) % 3 == 0 and j != (len(i)-1) and j != 0:
                print("|", end="")
        print("")
        count += 1

        
# isempty returns cell position if number in cell is 0, else returns false
#
# param 1: {list} board The sudoku board.
# return: {tuple/boolean} tuple if empty cell is found, false if no empty cells are found
def isempty(board):
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 0:
                return (i, j)
    return False

# solve returns true if board is solved, false if unsolved.
#
# param 1: {list} board The sudoku board.
# return: {boolean} the solved state of the board
def solve(board):
    global iterations
    iterations += 1

    cell = isempty(board)
    if not cell:
        return True
    
    row = cell[0]
    col = cell[1]
    
    for i in range(1, 10):
        if valid(board, i, cell):
            board[row][col] = i
            if solve(board):
                return True
            board[row][col] = 0

    return False

# valid returns true or false if number in given cell is valid according to sudoku rules.
# 
# param 1: {list} board The sudoku board.
# param 2: {int} num The number being tested.
# param 3: {int} cell The cell the number is being tested in.
# return: {boolean} validity of number in cell
def valid(board, num, cell):
    for i in range(len(board)):
        if (board[i][cell[1]] == num and i != cell[0]) or (board[cell[0]][i] == num and i != cell[1]):
            return False
    
    box_x = cell[1]//3
    box_y = cell[0]//3
    for i in range(3):
        for j in range(3):
            if board[i + (box_y * 3)][j + (box_x * 3)] == num and (i + (box_y*3) != cell[0] and j + (box_x*3) != cell[1]):
                return False

    return True

def main():
    printboard(board)
    if not (solve(board)):
        print("board is unsolvable")
    else:
        print("----------------------------")
        print("Solved board in " + str(iterations) + " iterations")
        printboard(board)

main()
