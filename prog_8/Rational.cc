/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 8
Due: October 27, 2016
File: Rational.cc
Purpose: Implementation of arithmetic, comparision between two Rational objects. Overloaded operators for incre/decre, and i/o streams. 
Input: Data from driver program prog8.cc
Output: Based on request made from prog8.cc
**********************************/
#include "Rational.h"

//Constructors and overloaded assignment operator
Rational::Rational(const int& n, const int& d)
{
	num = n;
	den = d;
	
	if (den != 0)
		reduce(); //Used to call gcd and simplify code	
	else
		cerr << "Error: division by zero" << endl;
}
Rational::Rational(const Rational& r)
{
	this->num = r.num;
	this->den = r.den;
}
Rational& Rational::operator=(const Rational& r)
{
	if (this != &r)
	{
		this->num = r.num;
		this->den = r.den;
	}
	return *this;
}

/****Overloaded arithmetic operators****/
Rational operator+(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}
Rational operator-(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}
Rational operator*(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num * r2.num, r1.den * r2.den);
}
Rational operator/(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num * r2.den, r1.den * r2.num);
}
Rational& Rational::operator+=(const Rational& r)
{
	this->num = this->num * r.den + r.num * this->den;
	this->den = this->den * r.den;
	this->reduce();
	return *this;
}
Rational& Rational::operator-=(const Rational& r)
{
	this->num = this->num * r.den - r.num * this->den;
	this->den = this->den * r.den;
	this->reduce();
	return *this;
}
Rational& Rational::operator*=(const Rational& r)
{
	this->num = this->num * r.num;
	this->den = this->den * r.den;
	this->reduce();
	return *this;
}
Rational& Rational::operator/=(const Rational& r)
{
	this->num = this->num * r.den;
	this->den = this->den * r.num;
	this->reduce();
	return *this;
}

/****Overloaded pre/post incre/decre operators****/
Rational& Rational::operator++()
{
	this->num += this->den;
	return *this;
}
Rational& Rational::operator--()
{
	this->num -= this->den;
	return *this;
}
Rational Rational::operator++(int unused)
{
	unused++; //To silent warning
	Rational temp = *this;
	this->num += this->den;
	return temp;
}
Rational Rational::operator--(int unused)
{
	unused++; //To silent warning
	Rational temp = *this;
	this->num -= this->den;
	return temp;
}

/****Overloaded comparision operators****/
bool operator==(const Rational& r1, const Rational& r2)
{
	return (r1.num == r2.num && r1.den == r2.den);
}
bool operator!=(const Rational& r1, const Rational& r2)
{
	return !(r1 == r2);
}
bool operator<(const Rational& r1, const Rational& r2)
{
	return ((double)r1.num/r1.den < (double)r2.num/r2.den);	
}
bool operator<=(const Rational& r1, const Rational& r2)
{
	return ((double)r1.num/r1.den <= (double)r2.num/r2.den);
}
bool operator>(const Rational& r1, const Rational& r2)
{
	return !(r1 < r2);
}
bool operator>=(const Rational& r1, const Rational& r2)
{
	return !(r1 <= r2);
}

/****Overloaded extraction and insertion****/
ostream& operator<<(ostream& os, const Rational& r)
{
	//Checks for shortend rational form
	if (r.num == 0)
		os << 0;
	else if (r.den == 1) 
		os << r.num;
	else 
	{
		//Checks if "-" is needed
		if ((r.num < 0 && r.den > 0) || (r.num > 0 && r.den < 0))
			os << "-";
		os << abs(r.num);
		os << "/";
		os << abs(r.den);
	}
	return os;
}
istream& operator>>(istream& is, Rational& r)
{
	string temp;
	char ch;	
	int tmpNum;

	//Reads in line and assigns to a sstream	
	getline(is, temp);
	istringstream str1(temp);
	
	//Read and assign numerator
	str1 >> tmpNum;
	if (str1.fail())
		cerr << "Error: line \"" << temp << "\" contains invalid number" <<  endl;
	else
		r.num = tmpNum;

	//Check for '/' btwn digits	
	str1 >> ch;
	if (ch != '/')
	{
		cerr << "Error: line \"" << temp << "\" contains invalid number" <<  endl;
		return is;
	}
	else if (str1.eof())
	{
		r.den = 1;
		return is;
	}
	
	//Read and assign denominator
	str1 >> tmpNum;
	r.den = tmpNum;

	//Check remainder line for "emptiness"
	while(str1.get(ch))
	{
		if (ch != ' ')
		{
			cerr << "Error: line \"" << temp << "\" contains invalid number" <<  endl;
			return is;
		}
	}
	return is;
}

//Method to find gcd: From book
int Rational::gcd (int x, int y)
{
	int r = x % y;
	while (r != 0)
	{
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}
//Method to reduce num and den
void Rational::reduce()
{
	int gcD = gcd (num, den);
	num /= gcD;
	den /= gcD;
}
//Std string to int non-mem fx
int strToInt (const string& s)
{
	istringstream is(s); int x;
	is >> x;
	return x;
}
