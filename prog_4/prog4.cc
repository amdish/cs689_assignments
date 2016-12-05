/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 4
Due: September 22, 2016
File: prog4.cc
Purpose: Driver and function definitions that open a C++ source code file, removes comments, and output data to a new file.  
Input: Source code file with comments
Output: Source code file without comments
**********************************/
#include "prog4.h"

int main()
{
	//Function calls to accomplish purpose outlined in doc box.
	open_files(inFile, outFile);
	process_data(inFile, outFile);
	close_files(inFile, outFile);

	return 0;
}

//Opens file stream to input source code file (with comments) and opens file stream to output file. 
void open_files(ifstream& is, ofstream& os)
{
	//For input file
	is.open(INPUT_PATH);
	if (is.fail())
	{
		cerr << "Error opening file" << endl;
		exit(EXIT_FAILURE);
	}
	//For output file
	os.open(OUT_PATH);
	if (os.fail())
	{
		cerr << "Error opening file" << endl;
		exit(EXIT_FAILURE);
	}
}

//Reads in data from input file, parses out comments, and outputs data (without comments) to output file stream.
void process_data(ifstream& is, ofstream& os)
{
	//Iterates through each charecter in input file, outputs all except comments.
	while (is.get(ch))
	{
		//Ignores checking for comments in string literals
		if (ch == '"')
		{
			while(true)
			{
				os.put(ch);
				is.get(ch);
				if (ch == '"')
				{
					os.put(ch);
					break;
				}
			}
		}
		else if (ch == '/')
		{
			is.get(ch);
			//Skips text in comment block
        	if (ch == '*')
			{   
            	while(true)
                {   
                	is.get(ch);
                	if (ch == '*')
                    {   
                    	is.get(ch);
                    	if (ch == '/')
							break;
						else
							is.unget();
                    }   
                }   
            }   
			//Skips remaining text after line comment
			else if (ch == '/')
			{
				while (true)
				{
					is.get(ch);
					if (ch == '\n')
					{
						is.unget();	//Preserves newline char for output stream.
						break;
					}
				}
			}
			//Moves file cursor back and writes char to out file stream
			else
			{
				is.unget();		
				os.put(ch);	
			}
		}
		else
			os.put(ch);
	}
}

//Closes both input and output file streams
void close_files(ifstream& is, ofstream& os)
{
	is.close();
	os.close();
}
