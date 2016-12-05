/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 5
Due: September 30, 2016
File: prog5.cc
Purpose: Replication of the minesweeper game. Takes the size of the field and likelihood of mines from stdin and outputs the mine field showing location of mines and an associated field showing mine counts. 
Input: Size of mine field and likelihood of mines 
Output: Field showing mines and field showing counts of mines
**********************************/
#include "prog5.h"

int main()
{
	//Game loop until no more input
	while(cin >> fieldSize)
	{
		cin >> diffProb;
	
	//Create neccessary two-dimensional vectors
		vector < vector<bool> > mineLocations(fieldSize, vector<bool>(fieldSize));
		vector < vector<unsigned> > mineCounts(fieldSize, vector<unsigned>(fieldSize));

	//Build field,create counts,output tables
		buildMineField (mineLocations, diffProb);
		fixCounts (mineLocations, mineCounts);
		displayMineLocations (mineLocations);
		displayMineCounts (mineCounts);
	}
	return 0;
}

//Takes supplied input from stdin and builds mine field of specified size
//and density as specified through mineProb
void buildMineField(vector < vector<bool> >& mines, const double& mineProb)
{
	cout << "Mine Locations: size =  " << fieldSize << " x " << fieldSize 
		<< ",  prob of mine = " << fixed << setprecision(2) << mineProb << endl;

	srand(SEEDval);
	double rnd;
	
	//Outer and inner loops to assign mine status to cells
	for (unsigned rows = 0; rows < fieldSize; rows++)
	{
		for (unsigned cols = 0; cols < fieldSize; cols++)
		{
			rnd = rand() / (double(RAND_MAX) + 1);
			if (rnd < mineProb)
				mines[rows][cols] = true;
			else
				mines[rows][cols] = false;
		}
	}
}

//Calculates number of surrounding mines for each cell
void fixCounts(const vector < vector<bool> >& mines, vector < vector<unsigned> >& counts)
{
	for (unsigned rows = 0; rows < fieldSize; rows++)
	{
		for (unsigned cols = 0; cols < fieldSize; cols++)
		{
			//Checks self
			if (mines[rows][cols] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check above
			if (rows >= 1 && mines[rows-1][cols] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check below
			if (rows < fieldSize - 1 && mines[rows+1][cols] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check left
			if (cols >= 1 && mines[rows][cols-1] == true)
				counts[rows][cols] = counts[rows][cols] + 1;
			//Check right
			if (cols < fieldSize - 1 && mines[rows][cols+1] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check bottom left
			if (rows < fieldSize - 1 && cols >= 1 && mines[rows+1][cols-1] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check bottom right
			if (rows < fieldSize - 1 && cols < fieldSize -1 && mines[rows+1][cols+1] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check above left
			if (rows >= 1 && cols >= 1 && mines[rows - 1][cols - 1] == true)
				counts[rows][cols] = counts[rows][cols]+1;
			//Check above right
			if (rows >= 1 && cols < fieldSize - 1 && mines[rows-1][cols+1] == true)
				counts[rows][cols] = counts[rows][cols]+1;
		}	
	}
}

//Outputs the minefield mines shown with a X in respective cells.
//Portions of output are handled through calls to other fxs. 
void displayMineLocations(const vector < vector<bool> >& mines)
{
	//Outer loop to iterate through rows
	for (unsigned rows = 0; rows < fieldSize; rows++)
	{
		//Prints row separator and row padding
		printRowLine();
		printRowSpace();
		cout << "|";

		//Loops through each cell in row and outputs mine if present
		for (unsigned cols = 0; cols < fieldSize; cols++)
		{
			if (mines[rows][cols] == true)
			{
				cout << setw(2) << left << "" << "X" << setw(3) << right <<"|";
			}
			else
			{
				cout << setw(3) << left << "" << setw(3) << right << "|";
			}
		}
		cout << endl;
		printRowSpace();
	}
	printRowLine();
	cout << endl;
}

//Outputs the table showing the mine counts for each respective cell.
void displayMineCounts(const vector < vector<unsigned> >& counts)
{
	cout << "Mine Counts: " << endl;

	//Outer loop to iterate through rows
	for (unsigned rows = 0; rows < fieldSize; rows++)
	{
		printRowLine();
		printRowSpace();

		cout << "|";
		//Loop to print each cells count
		for (unsigned cols = 0; cols < fieldSize; cols++)
		{
			cout << setw(2) << left << "" << counts[rows][cols] << setw(3) << right << "|";
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
	for (unsigned cols = 0; cols < fieldSize; cols++)
	{
		cout << setw(6) << right << "|";
	}
	cout << endl;
}

//Contains equation to print each row separator according to fieldSize..
void printRowLine()
{
	cout << " " << setfill('-') << setw((fieldSize * 5)+(fieldSize-1)) << "" << endl << setfill(' ');
}

