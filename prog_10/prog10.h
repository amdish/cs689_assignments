/********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 10
Due: November 15, 2016
File: prog10.h
Purpose: Header file; contains function prototypes for simple calculator functions. 
*********************************/
#ifndef PROG10_H
#define PROG10_H

#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
#include <sstream>

using namespace std;

//Function prototypes involved in processing token
void process_token(const string& token, stack<double>& S);
bool unarySign(const char& c, const string& token, const unsigned& i);
bool isValidOperator(const char& c);

//Function prototypes to perform arithmetic, outputting, and stack management
double operation(const char& c, const double& x, const double& y);
void printResult(const stack <double>& S);
double stringToDouble(const string& token);
void emptyStack(stack <double>& S);

stack <double> calcStack;

#endif
