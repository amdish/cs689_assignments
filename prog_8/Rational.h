/*********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 8
Due: October 27, 2016
File: Rational.h
Purpose: Provides class prototypes for various methods to work with rational numbers; for arithmetic operations between two Rational objects, increment, decrement, and overloadeds stream operators..  
*********************************/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>

using namespace std;

class Rational 
{
	//Overloaded arithmetic operators	
	friend Rational operator+(const Rational& r1, const Rational& r2);
	friend Rational operator-(const Rational& r1, const Rational& r2);
	friend Rational operator*(const Rational& r1, const Rational& r2);
	friend Rational operator/(const Rational& r1, const Rational& r2);

	//Overloaded compare operators
	friend bool operator==(const Rational& r1, const Rational& r2);
	friend bool operator!=(const Rational& r1, const Rational& r2);
	friend bool operator<(const Rational& r1, const Rational& r2);
	friend bool operator<=(const Rational& r1, const Rational& r2);
	friend bool operator>(const Rational& r1, const Rational& r2);
	friend bool operator>=(const Rational& r1, const Rational& r2);

	//Overloaded streams
	friend ostream& operator<<(ostream& os, const Rational& r);
	friend istream& operator>>(istream& is, Rational& r);

public:
	
	//Constructors
	Rational(const int& n = 0, const int& d = 1);
	Rational(const Rational& r);

	//Overloaded operators
	Rational& operator=(const Rational& r);
	Rational& operator+=(const Rational& r);
	Rational& operator-=(const Rational& r);
	Rational& operator*=(const Rational& r);
	Rational& operator/=(const Rational& r);
	Rational& operator++();
	Rational& operator--();
	Rational operator++(int unused);
	Rational operator--(int unused);
	
private:
	
	int gcd(int, int);
	void reduce();	//Helps reduce clutter in imple
	int num, 
		den;
};

int strToInt(const string&);

#endif
