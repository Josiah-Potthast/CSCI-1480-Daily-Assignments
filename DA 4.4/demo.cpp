// Josiah Potthast
// Daily Assignment 4.4

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

int main()
{
    int size = 2;

    Shape* s1 = new Circle(size);

    Shape* s2 = new Rectangle(size, size);

    Shape* s3 = new Triangle(size, size);

    s1->draw(cout);

    cout << endl;

    s2->draw(cout);

    cout << endl;

    s3->draw(cout);

    cout << endl;

	Triangle tri(10, 10);
	tri.draw(cout);

	Rectangle rect(10, 10);
	rect.draw(cout);

	Circle cir(5);
	cir.draw(cout);
}