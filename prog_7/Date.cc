/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 7
Due: October 18, 2016
File: Date.cc
Purpose: Builds upon program 6 with implementations for the copy constructor, assignment operator, shifting the data n days, months, years. Date index, num days from 01.01.01 to input date and diff between two dates. 
Input: Dates and method calls to use above mentioned methods.
Output: Appropriate output based on request made from driver.
**********************************/
#include "Date.h"

//Class copy constructor
Date::Date(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

//Class assignment operator
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
	}
	return *this;
}

//Shifts date n number of days
Date& Date::addDay(const int& n)
{
	int dayShift = n;
	bool direction;
	
	//Holds direction to shift date
	if (n > 0)
		direction = 1;
	else if (n < 0)
		direction = 0;
	
	//Shifts date forward n number of days
	if (direction == 1)
	{
		while (dayShift > (this->daysInMonth(this->month) - day))
		{
			dayShift -= (this->daysInMonth(this->month) - (day-1));
			this->addMonth(1);
			day = 1;
		}
		day += dayShift;
	}
	
	//Shifts date backwards n number of days
	if (direction == 0)
	{
		while (dayShift <= -(daysInMonth(this->month)))
		{
			dayShift += daysInMonth(this->month);
			this->addMonth(-1);
		}
		//Move back one month and adjust days	
		if ((day + dayShift) <= 0)
		{
			dayShift += day;
			addMonth(-1);	
			day = daysInMonth(this->month) + dayShift;
		}
		else
			day += dayShift;
	}
	return *this;	
}

//Shifts date n number of months
Date& Date::addMonth(const int& n)
{
	bool direction;
	int shiftYear = 0;
	int shiftMon;	
	int newMonth = this->monthIndex() + 1;

	//Determines direction to shift date
	if (n < 0)
		direction = 0;
	else if (n > 0)
		direction = 1;

	//Normalizes number of shifts
	if (n >= 12 || n <= -12)
	{	
		shiftYear = n / 12;
		shiftMon = abs(n) % 12;
	}
	else
		shiftMon = n;	
	this->addYear(shiftYear);
	
	//Move towards future or past
	if (direction == 1)
		newMonth += shiftMon;
	else if (direction == 0)
		newMonth += shiftMon;
	
	//Adjust year when looping around
	if (newMonth <=0)
	{
		newMonth += 12;
		this->addYear(-1);
	}
	else if (newMonth > 12)
	{
		newMonth -= 12;
		this->addYear(1);
	}		
	this->month = months[newMonth - 1];
	
	//Advance month if days exceed num days in month.
	if (daysInMonth(this->month) < this->day)
    {
        addMonth(1);
        this->day = 1; 
    }
	return *this;
}

//Shifts year n number of years
Date& Date::addYear(const int& n)
{
	year += n;
	string newMonth;

	//Adjust days and month if needed
	if (daysInMonth(this->month) < this->day)
	{
		this->day -= daysInMonth(this->month);
		addMonth(1);
	}
	//Adjust if new year is 0
	else if (this->year == 0 && n > 0)
	{
		year += 1;
	}
	if (this->year == 0 && n < 0)
	{
		year -= 1;
	}
	return *this;
}

//Returns number of days from 01.01.01 to object date.
int Date::dayIndex() const
{
	int count = 0;
	//Create temp object w/ copy constructor
	Date temp(*this);

	//Counter for AD dates
	if (year > 0)
	{	
		count += temp.day;
		temp.day = 1;
		while(temp.year > 1 || (temp.monthIndex()-1) > 0)
		{
			temp.addMonth(-1);
			count += temp.daysInMonth(temp.month);
		}
		//Needed since addMonth loops 1 to 12
		if (temp.monthIndex() == 1)
			count += temp.daysInMonth("January");
	}
	//Counter for BC dates
	else if (year < 0)
	{
		count = -(temp.daysInMonth(temp.month) - temp.day) - 1;
		while (temp.year <= -1 || temp.monthIndex()-1 > 0)
		{
			temp.addMonth(1);
			count -= temp.daysInMonth(temp.month);
		}
		count += temp.daysInMonth("January");
	}
	return count;
}

//Returns index of month 
int Date::monthIndex()
{
	return find(months.begin(), months.end(), month) - months.begin();
}

//Returns the number of days between two dates.
unsigned dateDiff(const Date& d1, const Date& d2)
{
	int diff = 0;
	//Compensate for switching over year 0
	if ((d1.getYear() < 0 && d2.getYear() > 0) || (d1.getYear() > 0 && d2.getYear() < 0)){diff = 1;}
	diff += (abs(d2.dayIndex()) - abs(d1.dayIndex()));
	return diff;
}

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
	
	if (year == 0)
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
	if (abs(year) % 100 == 0)
		norm = abs(year) / 100;
	else if	 (abs(year) % 1000 == 0)
		norm = abs(year) / 1000;
	else 
		norm = abs(year);

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
