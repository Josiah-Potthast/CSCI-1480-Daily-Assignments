#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Triangle : public Shape
{
private:
	int base;
	int height;
public:
	// Constructors: default, one with base and height, and copy
	Triangle();
	Triangle(int base, int height);
	Triangle(Triangle& otherTriangle);

	// Getters and setters for base and height and area
	int getBase();
	int getHeight();
	double getArea();
	void setBase(int base);
	void setHeight(int height);

	// equals and << overload
	Triangle& operator=(Triangle& otherTriangle);
	friend ostream& operator<<(ostream& strm, Triangle& triangle);

	ostream& draw(ostream& strm);
};