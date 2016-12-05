/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 1
Due: August 29, 2016
File: prog1.h
Purpose: Declaration and definition of the oddNumCalculator class including data members and associated methods
for getting user input and calculating the sum.
*********************************/

#ifndef PROG1_H
#define PROG1_H

#include <iostream>

//Using declarations
using std::cout;
using std::cin;
using std::endl;
	
class oddNumCalculator
{
	public:
		oddNumCalculator();		//Default constructor
		~oddNumCalculator();	//Destructor

		void askNumDigits();		//Gets input from user
		int getNumDigits() const;	//Accessor method
		int calcSum();				//Calculates sum of odd nums 

	private:
		int sum,		//Holds running sum
			numDigits,	//Number of digits to sum
			oddNum;		//Holds odd num to add. 
};

//Default constructor of oddNumCalculator class
oddNumCalculator::oddNumCalculator()
{
    sum = 0;	//Set sum to zero
	oddNum = 1; //First odd num
}

//Default destructor of oddNumCalculator class
oddNumCalculator::~oddNumCalculator(){}

/*********************************
Method: void askNumDigits();
Use: Asks user for input and stores value in a private data member numDigits
Parameters: None
Returns: Nothing
**********************************/
void oddNumCalculator::askNumDigits()
{
	//Prompt user and store input.
    cout << "Enter a value that represents the number of odd digits to sum: ";
    cin >> numDigits;
}

/*********************************
Method: int getNumDigits() const;
Use: Provides access to private data member numDigits
Parameters: None
Returns: User input, representing the number of digits to sum
**********************************/
int oddNumCalculator::getNumDigits() const
{
    return numDigits;
}

/*********************************
Method: int calcSum() const;
Use: Calculates the sum of specified number of odd numbers starting from one.
Parameters: None
Returns: Sum of specified number of odd digits starting from 1
**********************************/
int oddNumCalculator::calcSum() 
{
	//Calculates sum of specified number of odd digits from 1
    for (int count = 0; count < numDigits; count++)
    {
        sum += oddNum;	//Running sum
		oddNum += 2; 	//Increase to next odd num
    }
    return sum;		//Returns total sum
}
#endif
