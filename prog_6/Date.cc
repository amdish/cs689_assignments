/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 6
Due: October 10, 2016
File: Date.cc
Purpose: Implementation of the date class, where the provided inputs validity is verified and reported. Converts date formart and checks for leap year. 
Input: Date in various input formats from stdin.
Output: As requested by driver, whether the date, date in string format, indicates validity. 
**********************************/
#include "Date.h"

/************************************************/
/***Setter methods to set Month, Day, and Year***/
void Date::setMonth(const string& m)
{
	month = m;
	Month();
}
void Date::setDay(const int& d)
{
	day = d;
}
void Date::setYear(const int& y)
{
	year = y;
}

/************************************************/
/***Getter methods to get Month, Day, and Year***/
string Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}
int Date::getYear() const
{
	return year;
}

//Changes first letter of month to capital and rest to lowercase
void Date::Month()
{
	if (isalpha(month[0]))
	{
		month[0] = toupper(month[0]);
	}
	for (unsigned count = 1; count < month.length(); count++)
	{
		month[count] = tolower(month[count]);
	}
}

//Converts date to format dd-Mmm-yyyy
string Date::toString() const
{
	return intToString(day) + '-' + month.substr(0,3) + '-' + intToString(year);
}

//Overloaded extraction operator to read date inputs from stdin to parameter date instance
istream & operator>>(istream& is, Date& d)
{
	string tempStr;
	char ch;

	//Checks for end of input	
	is >> tempStr;
	if (!is)
		return is;

	d.setMonth(tempStr);
	is >> tempStr;

	//Sets day, removes extra charecters
	while (!isdigit(tempStr[tempStr.length()-1]))
	{
		tempStr.erase(tempStr.length()-1);
	}
	d.setDay(strToInt(tempStr));

	//Iterates until start of year data
	while(is.get(ch))
	{
		if (isdigit(ch))
		{
			is.unget();
			break;
		}
	}
	
	is >> tempStr;
	d.setYear(strToInt(tempStr));

	return is;
}

//Overloaded insertion operator
ostream & operator<<(ostream& os, const Date& d)
{
	os << d.getMonth() << " " << d.getDay() << ", " << d.getYear();
	return os;
}

//Checks if entire date is valid
bool Date::isValidDate() const
{
	if (year < 1)
		return false;

	if(isValidMonth())
	{
		if (day <= daysInMonth(month))			
			return true;
	}
	return false;
}

//Checks if month input is correct
bool Date::isValidMonth() const
{
	for (string monthSet : months)
	{	
		if (monthSet == month)
			return true;
	}
	return false;
}

//Checks if year is a leap year
bool Date::isLeapYear() const
{
	//Normalize the year
	//Addresses the 10,000 year issue 
	//I belive normalizing the year allowed for cleaner code
	int norm;
	if (year % 100 == 0)
		norm = year / 100;
	else if	 (year % 1000 == 0)
		norm = year / 1000;
	else 
		norm = year;

	if (norm % 4 == 0)
		return true;
	else
		return false;
}

//Returns the number of days in a particular month with consideration if it is a leap year or not
int Date::daysInMonth(const string& m) const
{
	if (m == "January" || m == "March" || m == "May" || m == "July" || m == "August" || m == "October" || m == "December")
		return 31;
	else if (m == "April" || m == "June" || m == "September" || m == "November")
		return 30;
	else if (isLeapYear())
		return 29;
	else  
		return 28;
}

/************NON-MEMBER FX*****/
//Converts integer to string
string intToString(const int& n)
{
	ostringstream os;
	os << n;	
	return os.str();	
}

//Converts string to integer
int strToInt(const string& s)
{
	istringstream is(s); int x;
	is >> x;
	return x;
}
