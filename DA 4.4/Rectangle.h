#ifndef RECTANGLE
#define RECTANGLE
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape {
private:
	int length;
	int width;
public:
	Rectangle();
	Rectangle(int l, int w);
	Rectangle(Rectangle& otherRectangle);  // *
	int getLength();
	int getWidth();
	void setLength(int l);
	void setWidth(int w);
	double getArea();
	Rectangle& operator=(Rectangle& otherRect);
	friend std::ostream& operator<<(std::ostream& strm, Rectangle& rect);

	ostream& draw(ostream& strm);
};


#endif