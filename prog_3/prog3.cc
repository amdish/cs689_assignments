/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 3
Due: September 14, 2016
File: prog3.cc
Purpose: Applies the caeser cipher encryption based on shift value. 
Input: Various shift values. D1 file is assumed to be filled with ints and only ints and no error checking.  
Output: Encoded output of text in data file.
**********************************/
#include "prog3.h"

int main ()
{
	int shiftVal;
	
	//Loops through values from stdin
  	while (cin >> shiftVal)
	{
		process_infile(shiftVal);        
    } 
	
	return 0;
}

//Opens data file reads  and outputs encoded text. 
void process_infile(int shift)
{
	string inString;
	ifstream dataFile;

	//Opens data file and or displays error.
	dataFile.open(DATA_FILE_PATH.c_str());
	if (!dataFile)
	{
		cerr << "Error opening file" << endl;		
		exit(EXIT_FAILURE);
	}

	//Encoding for each shift value.
	cout << "shift = " << shift << endl;
	while (getline(dataFile, inString))
	{
		cout << encodeCaesarCipher(inString, shift) << endl;
	}
	cout << endl;

	dataFile.close();
}

//Iterates through charecters in string and passes to new positon function.
string encodeCaesarCipher(string str, int shift)
{
	for (unsigned count = 0; count < str.length(); count++)
	{
		str[count] = new_position(str[count], shift);		
	}
	return str;
}

//Performs caesar cipher on charecter
//Charecter arithmetic, to simplify code returns new charecter instead of ASCII position as int. 
int new_position(char c, int shift)
{
	//For shifting to the right
	if (shift > 0)
	{
		if (islower(c))
		{
			return ('a' + ((c - 'a' + shift) % NUM_LETTERS));
		}
		else if (isupper(c))
		{
			return ('A' + ((c - 'A' + shift) % NUM_LETTERS));
		}
		else 
			return c;
	}
	//For shifting to the left
	else if (shift < 0)
	{
		if (islower(c))
		{
			return ('z' + ((c - 'z' + shift) % NUM_LETTERS));
		}
		else if (isupper(c))
		{
			return ('Z' + ((c - 'Z' + shift) % NUM_LETTERS));
		}	
		else return c;
	}
	else return c;
}
