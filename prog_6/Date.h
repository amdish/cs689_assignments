/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 6
Due: October 10, 2016
File: Date.h
Purpose: Header file; contains setter and getter methods for data members representing a date(month, day, and year). Contains other methods to convert a string to an int and vice versa. The insertion and extraction operators are also overloaded to improve code readibility.  
*********************************/
#ifndef Date_H
#define Date_H

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define MONTH "January"
#define DAY 1
#define YEAR 2000

class Date {

public:

	const vector <string> months { "January", "February", "March", "April", 
								"May", "June", "July", "August", "September", 
								"October", "November", "December" } ;

	//Parameterized Constructor  
	Date(const string& m = MONTH, const int& d = DAY, const int& y = YEAR) : month(m), day(d), year(y) 
	{ 
		Month(); 
	}

	//Set methods
	void setMonth(const string& m);
	void setDay(const int& d);
	void setYear(const int& y);
	
	//Accessor methods
	string getMonth() const;
	int getDay() const;
	int getYear() const;

	//Other class methods
	void Month();
	bool isValidDate() const;
	string toString() const;

	//Overloaded extraction and insertion operators
	friend istream& operator>>(istream& is, Date& d);
	friend ostream& operator<<(ostream& os, const Date& d);

private:
	
	//Methods for validating date
	bool isValidMonth() const;
	bool isLeapYear() const;
	int daysInMonth(const string& m) const;	

	//Data members
	string 
		month;
	int
		day,
		year;
};
	//Non-member functions
	string intToString(const int& n);
	int strToInt(const string& s);

#endif
