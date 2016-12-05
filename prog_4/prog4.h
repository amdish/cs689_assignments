/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 4
Due: September 22, 2016
File: prog4.h
Purpose: Header file; contains function prototypes for file functions to open, process data and close file. Contains symbolic constants to file paths. And variables for file streams. 
*********************************/
#ifndef PROG4_H
#define PROG4_H

//System libraries
#include <iostream>
#include <fstream>

using namespace std;

//File paths
#define INPUT_PATH "/home/cs689/progs/16f/p4/prog4-in.cc"
#define OUT_PATH "prog4-out.cc" 

//Function prototypes to open file,process data,output data,and close files
void open_files(ifstream&, ofstream&);
void process_data(ifstream&, ofstream&);
void close_files(ifstream&, ofstream&);

//Variables used in driver
char ch;
ifstream inFile;
ofstream outFile;

#endif
