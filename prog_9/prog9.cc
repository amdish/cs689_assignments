/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 9
Due: November 4, 2016
File: prog9.cc
Purpose: To print a solution for the n queens problem or state it does not exist.
Input: Size of board and # of queens.
Output: Whether or not a solution exists, if it does, prints board showing queens respectively.
**********************************/
#include "prog9.h"

int main()
{
	//Loop to check n-values from 1 to 8
	for (boardSize = 1; boardSize < 9; boardSize++)
		solveNQueens(boardSize);

	return 0;
}
//Set up neccessary vectors and output solution if one exists.
void solveNQueens(const unsigned& n)
{
	//Creates, initializes board and marked vectors.
	vector < vector<bool> > chessBoard(n, vector<bool>(n));
	vector < vector<bool> > checked(n, vector<bool>(n));
	initBoard(chessBoard, checked);

	//Prints board if solution exists or states one does not exist.
	cout << "Board Size = " << boardSize << endl;
	if (solveNQueensUtil(chessBoard, checked, 0))
		printBoard(chessBoard);
	else
		cout << "Solution does not exist." << endl << endl;
}
//Checks if solution exists for n-sized board and n queens
bool solveNQueensUtil(vector < vector<bool> >& board, vector <vector<bool> >&checked, const unsigned &row)
{
	rndCol = rand() % boardSize + 0;
	//Simple/base cases
	if (row == boardSize) return true;
	if (row == 0 && allColumnsChecked(checked, row)) return false;
	
	//Clears queen from row  when backtracking.
	for (unsigned i = 0; i < boardSize; i++)
		board[row][i] = false;

	checked[row][rndCol] = true;
	//Checks columns for safe placement and places queens if safe
	//And progresses forward or backtracks based on previous decision
	//And whether all columns have been checked or not
	if (isSafe(board, row, rndCol))
	{
		board[row][rndCol] = true;
		return solveNQueensUtil(board, checked, row+1);
	}
	else if (allColumnsChecked(checked, row))
	{
		resetColsChecked(checked, row);
		return solveNQueensUtil(board, checked, row-1);
	}
	else return solveNQueensUtil(board, checked, row);
}
//Checks is param row and col is safe to place a queen.
bool isSafe(const vector < vector<bool> >& board, const int& row, const int& col)
{
	//Checks if row is same as one that already has queen.
	//Needed for to reach base case
	for (int currCol = 0; currCol < (int)boardSize; currCol++)
	{
		if (board[row][currCol] == true)
			return false;	
	}
	//Checks if any queens in same column.
	for (int currRow = 0; currRow < (int)boardSize; currRow++)
	{
		if (board[currRow][col] == true)
			return false;
	}
	//Checks diagonals.
	for (int currRow = 0; currRow < (int)boardSize; currRow++)
	{
		for (int currCol = 0; currCol < (int)boardSize; currCol++)
		{
			if (board[currRow][currCol] == true)
				if (abs(currRow-row) == abs(currCol-col))
					return false;
		}
	}
	return true;
}
//Reset marked columns when backtracking.
void resetColsChecked(vector < vector<bool> >& colsChecked, const unsigned& row)
{
	for (unsigned i = 0; i < boardSize; i++)
		colsChecked[row][i] = false;
}
//Checks if all columns have been tried.
bool allColumnsChecked(vector <vector<bool> >& colsChecked, const unsigned& row)
{	
	for (unsigned i = 0; i < boardSize; i++)
	{
		if (colsChecked[row][i] == false)
			return false;
	}
	return true;
}
//Initializes board and marked vectors to default false state.
void initBoard(vector < vector<bool> >& chessBoard, vector < vector<bool> >& marked)
{
	srand(time(SEED_VAL));
	
	//Initialize all cells to false.
	for (unsigned rows = 0; rows < boardSize; rows++)
	{
		for (unsigned cols = 0; cols < boardSize; cols++)
			chessBoard[rows][cols] = false;
	}
	//Initialze empty marked board
	for (unsigned rows = 0; rows < boardSize; rows++)
	{
		for (unsigned cols = 0; cols < boardSize; cols++)
			marked[rows][cols] = false;
	}
}
//Prints formatted chessBoard.
void printBoard(vector < vector<bool> >& chessBoard)
{
	//Outer loop to iterate through rows
	for (unsigned rows = 0; rows < boardSize; rows++)
	{
		printRowLine();
		printRowSpace();
		cout << "|";
		//Loop to print presence of queen in cell
		for (unsigned cols = 0; cols < boardSize; cols++)
		{
			cout << setw(2) << left << "";
			if (chessBoard[rows][cols] == true)
				cout << "Q" << setw(3) << right << "|";
			else
				cout << " " << setw(3) << right << "|";
		}
		cout << endl;
		printRowSpace();
	}
	printRowLine();
	cout << endl;
}
//Prints row padding of each cell.
void printRowSpace()
{
	cout << "|";
	for (unsigned cols = 0; cols < boardSize; cols++)
		cout << setw(6) << right << "|";
	cout << endl;
}
//Contains equation to print each row separator according to board size.
void printRowLine()
{
	cout << " " << setfill('-') << setw((boardSize * 5)+(boardSize - 1)) << "" << endl << setfill(' ');
}
