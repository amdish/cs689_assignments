/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 3
Due: September 14, 2016
File: prog3.h
Purpose: Header file for caeser cipher function prototypes and constants. 
*********************************/
#ifndef PROG3_H
#define PROG3_H

//System libraries
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <cctype>

using namespace std;

//Constants used in driver 
const int NUM_LETTERS = 26;
const string DATA_FILE_PATH = "/home/cs689/progs/16f/p3/prog3.d2";

//Functions to open, read, and encode text from data file. 
void process_infile(int);		
string encodeCaesarCipher(string, int);
int new_position(char, int);

#endif
