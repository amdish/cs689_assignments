/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 5
Due: September 30, 2016
File: prog5.h
Purpose: Header file; contains function prototypes to build field (select mine locations), calculate mine counts, and output minefield and counts field.  
*********************************/
#ifndef PROG5_H
#define PROG5_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SEEDval = 1;

//Fx prototypes to build field, count mines, and output fields showing mines and counts
void buildMineField (vector < vector<bool> >&, const double&);
void fixCounts (const vector < vector<bool> >&, vector < vector<unsigned> >&);
void displayMineLocations (const vector < vector<bool> >&);
void displayMineCounts (const vector < vector<unsigned> >&);

//Additional fx prototypes for output spacing
void printRowSpace();
void printRowLine();

//Mine field metrics
unsigned fieldSize;
double diffProb;

#endif 
