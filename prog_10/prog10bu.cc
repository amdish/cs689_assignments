#include "prog10.h"

int main()
{
	string inString;
	while (getline(cin, inString))
	{
		process_token(inString, calcStack);
	}
	return 0;
}

//Processes string that was passed in from main
void process_token(const string& token, stack<double>& S){

	string tempString;	
	int decCount = 0;
	for (unsigned i = 0; i < token.length(); i++)
	{
		if (unarySign(token[i], token, i))
		{
			tempString+=token[i];
			i++;
		}
		if (isdigit(token[i]) || token[i] == '.')
		{
			while (isdigit(token[i]) || token[i] == '.')
			{
				tempString+=token[i];
				i++;
			}
			if (!isalpha(token[0]))
			{
				cout << "MADE STR: " << tempString << endl;
				double temp = stringToDouble(tempString);
				cout << "PUSHING THIS: " << temp << endl;
				S.push(temp);
				cout << token[i];
				tempString = "";
			}
		}
		if (isValidOperator(token[i]) && !unarySign(token[i], token, i))
		{
			if (S.empty()) {cout << "EMPTY STACK CANT DO SHIT" << endl;}
			cout << "THIS IS VALID: " << token[i] << endl;
			double one = S.top();
			S.pop();
			double two = S.top();
			S.pop();
			cout << "ONE: " << one << "TWO: " << two << endl;
			double result = operation(token[i], one, two);
			cout << "RESULT: " << result << endl;
			S.push(result);
			i++;
		}
		if (token[i] == 'c')
			emptyStack(S);
		if (token[i] == '=')
			printResult(S);
		if (token[i] == '-')
			i--;
		if (token[i] == '!')
			cout << "Cant have this shit" << endl;	
	}

	cout << endl;

} 
bool unarySign(const char& c, const string& token, const unsigned& i){
	
	if ((c == '-' || c == '+') && (isdigit(token[i+1]) || token[i+1] == '.'))
		return true;
	else return false;
	
} 
bool floatPoint(const char&c, const string& token, unsigned&i){

	
}
double getNumber(const char& c, const string& token, unsigned& i, const bool& floatPointFlag){
/*
	if (floatPointFlag)
		//Count decimals err if > 1
	else 
		return stringToDouble(token);
*/
}
double stringToDouble(const string& token){
	istringstream stream(token);
	double value;
	stream >> value;
	return value;
}
bool isValidOperator(const char& c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
} 
double operation(const char& c, const double& x, const double& y){
	
	if (c == '+')
		return y + x;
	else if (c == '-')
		return y - x;
	else if (c == '*')
		return y * x;
	else if (c == '/')
		return y / x;

} 
double popStack(stack<double>& S){} 
void printResult(const stack <double>& S){

	double temp = S.top();
	cout << fixed << setprecision(2) << temp << endl;
} 
void emptyStack(stack <double>& S){
	while(!S.empty())
	{
		S.pop();
	}
	cout << "STACK HAS BEEN emptied" << endl;
} 
