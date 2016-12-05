/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 2
Due: September 06, 2016
File: prog2.cc
Purpose: Determines perfect numbers in the range of 1 to 9999 and prints its divisors.
Input: Nothing
Output: Perfect numbers and their divisors.
**********************************/
#include "prog2.h"

//Main function, calls predicate fx and prints string of divisors for perfect nums.
int main ()
{
	//Loops through numbers to test
	while (numToTest <= UPPER_LIMIT)
	{
		//Prints number and its divisors if perfect
		if (isPerfect (numToTest))
			std::cout << divisors(numToTest) << std::endl;
		
		numToTest++;	//Next number to test
	}	
	return 0;
}

//*******Function Definitions*****
/*********************************
Method: bool isPerfect(unsigned int);
Use: Determines if a number is a perfect number
Parameters: unsigned int, representing the number to test.
Returns: True if parameter is a perfect number or else false
**********************************/
bool isPerfect(unsigned int newNumToTest)
{
	unsigned int sum = 0;	//Stores sum of divisors

	//Loop to generate sum of divisors of a specific number
	for (unsigned int count = 1; count < newNumToTest; count++)
	{
		//Adds count to sum if it is a divisor of test number
		if (newNumToTest % count == 0)
			sum += count;
	}
	if (sum == numToTest)	//Checks if parameter is perfect number
		return true;		//parameter is perfect number
	else
		return false;		//parameter is NOT perfect number
}

/*********************************
Method: string divisors(unsigned int); 
Use: Generates a string of a perfect number and its divisors
Parameters: None
Returns: A string, representing a specific perfect number and its divisors
**********************************/
string divisors(unsigned int perfectNumber)
{
	//Declare and initialize string
	string perfNumDivisors = std::to_string(perfectNumber) + " = ";

	//Concatenates divisors to string
	for (unsigned int count = 1; count < perfectNumber; count++)
	{
		//Concatenates valid divisors to string
		if (perfectNumber % count == 0)
		{
			perfNumDivisors += std::to_string(count) + " + ";
		}
	}
	
	//Removes trailing '+'
	perfNumDivisors.resize(perfNumDivisors.size() - 3);

	return perfNumDivisors; //Returns generated string
}
