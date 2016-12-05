/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 9
Due: November 4, 2016
File: prog9.h
Purpose: Header file; contains function prototypes to build and initialize board, find queen placements, keep record of checked cells and output board. 
*********************************/
#ifndef PROG9_H
#define PROG9_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <math.h>

using namespace std;

#define SEED_VAL 0

	//Prototypes for initializing default values and solving n-queens puzzle.
	void initBoard(vector < vector<bool> >&, vector < vector<bool> >&);
	void solveNQueens(const unsigned&);
	bool solveNQueensUtil(vector < vector<bool> >&, vector <vector<bool> >&, const unsigned&);
	bool isSafe(const vector < vector<bool> >&, const int&, const int&);
	
	//Prototypes for printing and formatting board output.
	void printBoard(vector < vector<bool> >&);
	void printRowSpace();
	void printRowLine();

	//For marking and unmarking of checking row columns.
	void markColumn(bool[], int);
	bool allColumnsChecked(vector < vector<bool> >&, const unsigned&);
	void resetColsChecked(vector <vector<bool> >&, const unsigned&);		

	unsigned 
			boardSize,
			rndCol;
#endif
