#pragma once
#include <iostream>
using namespace std;

class Shape
{
private:
public:
	virtual double getArea();
	virtual ostream& draw(ostream& strm) = 0;
};