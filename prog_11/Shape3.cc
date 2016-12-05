/**********************************
Name: Amol Shah
zID: z1723133
Assignment: Program 11
Due: November 28, 2016
File: Shape3.cc
Purpose: Provides class definitions of base and derived classes of various 3 Dimensional shapes
**********************************/
#include "/home/cs689/progs/16f/p11/Shape3.h"

/*****BOX CLASS DEFINITIONS*****/
//Class default constructor
Box::Box(const double& a, const double&b, const double& c)
{
	length = a;
	width = b;
	height = c;
}
//Class destructor
Box::~Box(){}

//Class copy constructor
Box::Box(const Box& b) : Rectangle(b)
{
	this->length = b.length;
	this->width = b.width;
	this->height = b.height;
}

//Class overloaded assignment operator
Box& Box::operator=(const Box& b)
{
	if (this != &b)
	{
		this->length = b.length;
		this->width = b.width;
		this->height = b.height;
	}
	return *this;
}

//Class overloaded append operator
Box& Box::operator+=(const Box& b)
{
	this->length = this->length + b.length;
	this->width = this->width + b.width;
	this->height = this->height + b.height;
	return *this;
}

//Returns calculated perimeter
double Box::perimeter() const
{
	return 0;
}

//Returns calcualted area 
double Box::area() const
{
	return (2*(length*width) + (height*(2*(length+width))));	
}

//Returns calculated volume
double Box::volume() const
{
	return height*length*width;
}

//Prints dimensions
void Box::print() const
{
	cout << "length = " << length << " : width = " << width << " : height = " << height;
}

/*****CUBE CLASS DEFINITIONS*****/
//Class default constructor
Cube::Cube(const double& a)
{
	width = length = a;
}
//Class destructor
Cube::~Cube(){}

//Class copy constructor
Cube::Cube(const Cube& c) : Square(c)
{
	this->length = c.length;
	this->width = c.width;
}

//Class overloaded assignment operator
Cube& Cube::operator=(const Cube& c)
{
	if (this != &c)
	{
		this->length = c.length;
		this->width = c.width;
	}
	return *this;
}

//Class overloaded append operator
Cube& Cube::operator+=(const Cube& c)
{
	this->length = this->length + c.length;
	this->width = this->length;
	return *this;
}

//Returns calculated perimeter
double Cube::perimeter() const
{
	return 0;
}

//Returns calcualted area 
double Cube::area() const
{
	return 6*(length*length);
}

//Returns calculated volume
double Cube::volume() const
{
	return (length*length*length);
}

//Prints dimensions
void Cube::print() const
{
	cout << "length = " << length;
}

/*****CYLINDER CLASS DEFINITIONS*****/
//Class default constructor
Cylinder::Cylinder(const double& a, const double& b)
{
	radius = a;
	height = b;
}
//Class destructor
Cylinder::~Cylinder(){}

//Class copy constructor
Cylinder::Cylinder(const Cylinder& c) : Circle(c)
{
	this->radius = c.radius;
	this->height = c.height;
}

//Class overloaded assignment operator
Cylinder& Cylinder::operator=(const Cylinder& c)
{
	if (this != &c)
	{
		this->radius = c.radius;
		this->height = c.height;
	}
	return *this;
}

//Class overloaded append operator
Cylinder& Cylinder::operator+=(const Cylinder& c)
{
	this->radius = this->radius + c.radius;
	this->height = this->height + c.height;
	return *this;
}

//Returns calculated perimeter
double Cylinder::perimeter() const
{
	return 0;
}

//Returns calcualted area 
double Cylinder::area() const
{
	return 2*(PI*(radius*radius) + (height*PI*radius));
}

//Returns calculated volume
double Cylinder::volume() const
{
	return height*(PI*(radius*radius));
}

//Prints dimensions
void Cylinder::print() const
{
	cout << "radius = " << radius << " : height = " << height;
}

/*****CONE CLASS DEFINITIONS*****/
//Class default constructor
Cone::Cone(const double& a, const double& b)
{
	this-> radius = a;
	this-> height = b;
}
//Class destructor
Cone::~Cone()
{
	radius = height = 0;
}

//Class copy constructor
Cone::Cone(const Cone& c) : Circle(c)
{
	this->radius = c.radius;
	this->height = c.height;
}

//Class overloaded assignment operator
Cone& Cone::operator=(const Cone& c)
{
	if (this != &c)
	{
		this->radius = c.radius;
		this->height = c.height;
	}
	return *this;
}

//Class overloaded append operator
Cone& Cone::operator+=(const Cone& c)
{
	this->radius = this->radius + c.radius;
	this->height = this-> height + c.height;
	return *this;
}

//Returns calculated perimeter
double Cone::perimeter() const
{
	return 0;
}

//Returns calcualted area 
double Cone::area() const
{
	return PI*(radius*radius)+0.5*(sqrt((radius*radius)+(height*height)))*(2*PI*radius);
}

//Returns calculated volume
double Cone::volume() const
{
	return (height*(PI*(radius*radius)))/3;
}

//Prints dimensions
void Cone::print() const
{
	cout << "radius = " << radius << " : height = " << height;
}

/*****SPHERE CLASS DEFINITIONS*****/
//Class default constructor
Sphere::Sphere(const double& a)
{
	radius = a;
}
//Class destructor
Sphere::~Sphere(){}

//Class copy constructor
Sphere::Sphere(const Sphere& s) : Circle(s)
{
	radius = s.radius;
}

//Class overloaded assignment operator
Sphere& Sphere::operator=(const Sphere& s)
{
	if (this != &s)
	{
		this->radius = s.radius;
	}
	return *this;
}

//Class overloaded append operator
Sphere& Sphere::operator+=(const Sphere& s)
{
	this->radius = this->radius + s.radius;
	return *this;
}

//Returns calcualted area 
double Sphere::area() const
{

	return 4*(PI*(radius*radius));
}

//Returns calculated volume
double Sphere::volume() const
{
	return (4*(radius*(PI*(radius*radius))))/3;
}

/*****TETRAHEDRON CLASS DEFINITIONS*****/
//Class default constructor
Tetrahedron::Tetrahedron(const double& a)
{
	this->a = a;
}
//Class destructor
Tetrahedron::~Tetrahedron(){}

//Class copy constructor
Tetrahedron::Tetrahedron(const Tetrahedron& t) : equTriangle(t)
{
	this->a = t.a;
}

//Class overloaded assignment operator
Tetrahedron& Tetrahedron::operator=(const Tetrahedron& t)
{
	if (this != &t)
	{
		this->a = t.a;
	}
	return *this;
}

//Class overloaded append operator
Tetrahedron& Tetrahedron::operator+=(const Tetrahedron& t)
{
	this->a = this->a + t.a;
	return *this;
}

//Returns calculated perimeter
double Tetrahedron::perimeter() const
{
	return 0;
}

//Returns calcualted area 
double Tetrahedron::area() const
{
	return 4*((a*sqrt((a*a)-((a/2)*(a/2))))/2);
}

//Returns calculated volume
double Tetrahedron::volume() const
{
	return (a*a*a)/(6*sqrt(2));
}
