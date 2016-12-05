/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 2
Due: September 6, 2016
File: prog2.h
Purpose: Contains function prototypes, declares and initializes global variables. 
for getting user input and calculating the sum.
*********************************/
#ifndef PROG2_H
#define PROG2_H

//System header files
#include <iostream>
#include <string>

using std::string;	//Using declarations

const unsigned int UPPER_LIMIT = 9999;	//Max num to test
unsigned int numToTest = 1;				//Holds number to test

int main();						//Main prototype
string divisors(unsigned int);	//Generates string for output
bool isPerfect(unsigned int);	//Determines if number is perfect

#endif
