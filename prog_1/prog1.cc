/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 1
Due: August 29, 2016
File: prog.cc
Purpose: This program requests input from the user in the form of an integer (no error checking) 
and calculates the sum of odd numbers starting at 1 and including subsequent odd numbers until 
the number of odd digits summed equals the value entered by the user. 
Input: An integer greater than or equal to 1
Output: Sum of N odd numbers starting from 1, N specified by input. 
**********************************/

//Include header file, which includes class declaration and definitions of the oddNumCalculator class
#include "prog1.h"

int main()
{
	//Creates a new object of the oddNumCalculator class
	oddNumCalculator session_1;

	//Gets user input
	session_1.askNumDigits();

	//Output results of summation
	cout << "Summing the first " << session_1.getNumDigits() << " odd numbers starting from 1 equals: " << session_1.calcSum() << endl;	

	return 0;
}

