#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() : Rectangle(1, 1) {}

Rectangle::Rectangle(int l, int w) : length(l), width(w) {
}

Rectangle::Rectangle(Rectangle& otherRectangle) {
	if (this != &otherRectangle) {
		this->length = otherRectangle.length;
		this->width = otherRectangle.width;
	}
}

void Rectangle::setLength(int l) {
	length = l;
}

int Rectangle::getLength() {
	return length;
}
int Rectangle::getWidth() {
	return width;
}

void Rectangle::setWidth(int w) {
	width = w;
}

double Rectangle::getArea() {
	return length * width;
}

Rectangle& Rectangle::operator=(Rectangle& otherRect) {
	if (this != &otherRect) {
		this->length = otherRect.length;
		this->width = otherRect.width;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& strm, Rectangle& rect) {
	strm << "A Rectangle with length: " << rect.getLength() <<
		", width: " << rect.getWidth() <<
		" and an area of " << rect.getArea();
	return strm;
}

ostream& Rectangle::draw(ostream& strm)
{
	// print out the top of the box
	for (int w = 0; w < width; w++)
		strm << "--";
	strm << endl;
	// print out the sides of the box
	for (int l = 0; l < length; l++) {
		strm << "| ";
		for (int w2 = 1; w2 < width - 1; w2++)
			strm << "  ";
		strm << " |" << endl;
	}
	// print out the bottom of the box.
	for (int w = 0; w < width; w++)
		strm << "--";
	strm << endl;
	return strm;
}