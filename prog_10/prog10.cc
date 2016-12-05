/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 10
Due: November 15, 2016
File: prog10.cc
Purpose: To accept input, validate input, and perform arithmetic as requested. 
Output: Triggered by "=" sign displays the value at the top of the stack.
**********************************/
#include "prog10.h"

int main()
{
	//Reads in strings and processes lines until no more from stdin 
	string inString;
	while (getline(cin, inString))
		process_token(inString, calcStack);
	
	return 0;
}

//Processes string that was passed in from main
void process_token(const string& token, stack<double>& S)
{
		//To keep track of various aspects of processing string.
		string tempString;	
		int decCount = 0;
		bool active = true;
			
		//Loop to process charecters of token
		for (unsigned i = 0; i < token.length(); i++)
		{
			if (unarySign(token[i], token, i))
			{
				tempString+=token[i];
				i++;
			}
			//Extracts valid numbers, counts decimals and pushes onto stack
			if (isdigit(token[i]) || token[i] == '.')
			{
				decCount = 0;
				while (isdigit(token[i]) || token[i] == '.')
				{//Counts decimals
					if (token[i] == '.') 
						decCount++;
					tempString+=token[i];
					i++;
				}
				if (decCount >=2) 
				{//For numerals with too many decimals
					cerr << "error: number '" << tempString << "' is invalid" << endl;
					active = false;
					tempString = "";
				}
				else 
				{//Push the number
					if (!isalpha(token[0]))
					{
						double temp = stringToDouble(tempString);
						S.push(temp);
						tempString = "";
					}
				}
			}
			//Perform specified operation combined boolean expression evaluates to true
			if (isValidOperator(token[i]) && !unarySign(token[i], token, i) && decCount < 2 && active != false)  
			{
				if (S.empty()) 
					cerr << "error: stack is empty" << endl;
				else 
				{//Popping off top two and replacing with result
					double one = S.top();
					S.pop();
					double two = S.top();
					S.pop();
					double result = operation(token[i], one, two);
					S.push(result);
					i++;
				}
			}
			//Checks for other characters
			//And performs neccessary action
			if (token[i] == 'c')
				emptyStack(S);
			if (token[i] == '=')
				printResult(S);
			if (token[i] == '-')
				i--;
			if (token[i] == '!')
				cerr << "error: character '!' is invalid" << endl;	
		}
}

//Determines if -/+ is unary sign. 
bool unarySign(const char& c, const string& token, const unsigned& i)
{	
	if ((c == '-' || c == '+') && (isdigit(token[i+1]) || token[i+1] == '.'))
		return true;
	else return false;
} 

//Converts a string to a double type
double stringToDouble(const string& token)
{	
	istringstream stream(token);
	double value;
	stream >> value;
	return value;
}

//Checks if character is valid arithmetic operator(+,-,*,/)
bool isValidOperator(const char& c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
} 

//Performs operation of argument c on two argument values
double operation(const char& c, const double& x, const double& y)
{
	if (c == '+')
		return y + x;
	else if (c == '-')
		return y - x;
	else if (c == '*')
		return y * x;
	else if (c == '/')
		return y / x;
	else return y;	
} 

//Prints the result in specific format triggered by "="
void printResult(const stack <double>& S)
{
	double temp = S.top();
	if (!S.empty())
		cout << fixed << setprecision(2) << temp << endl;
} 

//Removes all items from sstack
void emptyStack(stack <double>& S)
{
	while(!S.empty())
		S.pop();
} 
