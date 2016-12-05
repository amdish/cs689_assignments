/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 11
Due: November 28, 2016
File: Shape2.cc
Purpose: Provides class definitions of base and derived classes of various shapes
**********************************/

#include "/home/cs689/progs/16f/p11/Shape2.h"

/*****RECTANGLE CLASS DEFINITIONS*****/
//Class default constructor
Rectangle::Rectangle(const double& l, const double& w)
{
	length = l;
	width = w;
}
//Destructor
Rectangle::~Rectangle ()
{
	width = length = 0;
}

//Class copy constructor
Rectangle::Rectangle(const Rectangle& r)
{
	this->length = r.length;
	this->width = r.width;
}

//Class overloaded assignment operator
Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (this != &r)
	{
		this->length = r.length;
		this->width = r.width;
	}
	return *this;
}

//Class overloaded append operator
Rectangle& Rectangle::operator+=(const Rectangle& r)
{
	this->length = this->length + r.length;
	this->width = this->width + r.width;
	return *this;
}

//Returns calculated perimeter of rectangle
double Rectangle::perimeter() const
{
	return 2*(length + width);
}

//Returns calculated area of rectangle
double Rectangle::area() const
{
	return (length*width);
}

//Prints dimensions of rectangle
void Rectangle::print() const
{
	cout << "length = " << length << " : width = " << width;
}

/*****SQUARE CLASS DEFINITIONS*****/
//Class default constructor
Square::Square(const double& l)
{
	length = width = l;
}

//Destructor
Square::~Square ()
{
	length = 0;
};

//Class copy constructor
Square::Square(const Square& s) : Rectangle(s)
{
	this->length = s.length;
}

//Class overloaded assignment operator
Square& Square::operator=(const Square& s)
{
	if (this != &s)
	{
		this->length = s.length;
	}
	return *this;
}

//Class overloaded append operator
Square& Square::operator+=(const Square& s)
{
	this->length = this->length + s.length;
	return *this;
}

//Prints dimensions of rectangle
void Square::print() const
{
	cout << "length = " << length;
}

/*****CIRCLE CLASS DEFINITIONS*****/
//Class constructor
Circle::Circle(const double& r)
{
	radius = r;
}

//Destructor
Circle::~Circle ()
{
	radius = 0;
}

//Class copy constructor
Circle::Circle(const Circle& c)
{
	this->radius = c.radius;
}

//Class overloaded assignment operator
Circle& Circle::operator=(const Circle& c)
{
	if (this != &c)
	{
		this->radius = c.radius;	
	}
	return *this;
}

//Class overloaded append operator
Circle& Circle::operator+=(const Circle& c)
{
	this->radius = this->radius + c.radius;
	return *this;
}

//Returns calculated perimeter of circle
double Circle::perimeter() const
{
	return (2*PI*radius);
}

//Returns calculated area of circle
double Circle::area() const
{
	return (PI*(radius*radius));
}

//Prints dimensions of circle
void Circle::print() const
{
	cout << "radius = " << radius;
}

/*****TRIANGLE CLASS DEFINITIONS*****/
//Class constructor
Triangle::Triangle(const double& a, const double& b, const double& c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

//Destructor
Triangle::~Triangle ()
{
	a = b = c = 0;
}

//Class copy constructor
Triangle::Triangle(const Triangle& t)
{
	this->a = t.a;
	this->b = t.b;
	this->c = t.c;
}

//Class overloaded assignment operator
Triangle& Triangle::operator=(const Triangle& t)
{
	if (this != &t)
	{
		this->a = t.a;
		this->b = t.b;
		this->c = t.c;
	}
	return *this;
}

//Class overloaded append operator
Triangle& Triangle::operator+=(const Triangle& t)
{
	this->a = this->a + t.a;
	this->b = this->b + t.b;
	this->c = this->c + t.c;
	return *this;
}

//Returns calculated perimeter of triangle
double Triangle::perimeter() const
{
	return (a+b+c);
}

//Returns calculated area of triangle
double Triangle::area() const
{
	double k = perimeter()/2;
	return sqrt(k*((k-a)*(k-b)*(k-c)));
}

//Prints dimensions of triangle
void Triangle::print() const
{
	cout << "a = " << a << " : b = " << b << " : c = " << c;
}

/*****RIGHT TRIANGLE CLASS DEFINITIONS*****/
//Class constructor
rightTriangle::rightTriangle(const double& a, const double& b)
{
	this->a = a;
	this->b = b;
	this->c = sqrt((a*a)+(b*b));
}

//Destructor
rightTriangle::~rightTriangle() 
{
	a = b = c = 0;
}

//Class copy constructor
rightTriangle::rightTriangle(const rightTriangle& t) : Triangle(t)
{
	this->a = t.a;
	this->b = t.b;
	this->c = t.c;
}

//Class overloaded assignment operator
rightTriangle& rightTriangle::operator=(const rightTriangle& t)
{
	if (this != &t)
	{	
		this->a = t.a;
		this->b = t.b;
		this->c = t.c;
	}
	return *this;
}

//Class overloaded append operator
rightTriangle& rightTriangle::operator+=(const rightTriangle& t)
{
	this->a = this->a + t.a;
	this->b = this->b + t.b;
	return *this;
}

//Prints dimensions of right triangle 
void rightTriangle::print() const
{
	cout << "length = " << a << " : height = " << b;
}

/*****EQUILATERAL TRIANGLE CLASS DEFINITIONS*****/
//Class constructor
equTriangle::equTriangle(const double& a)
{
	this->a = a;
	this->b = a;
	this->c = a;
}

//Destructor
equTriangle::~equTriangle() {}

//Class copy constructor
equTriangle::equTriangle(const equTriangle& t) : Triangle(t)
{
	this->a = t.a;
	this->b = t.b;
	this->c = t.c;
}

//Class overloaded assignment operator
equTriangle& equTriangle::operator=(const equTriangle& t)
{
	if (this != &t)
	{
		this->a = t.a;
		this->b = t.b;
		this->c = t.c;
	}
	return *this;
}

//Class overloaded append operator
equTriangle& equTriangle::operator+=(const equTriangle& t)
{
	this-> a = this->a + t.a;
	this->b = this->c = a;
	return *this;
}

//Prints dimensions of right triangle 
void equTriangle::print() const
{
	cout << "length = " << a;
}
