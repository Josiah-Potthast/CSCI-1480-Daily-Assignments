// Josiah Potthast
// Daily Assignment 3.2

#include "Term.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;

void polyDriver();

int main()
{
	polyDriver();
}

void polyDriver()
{
	Polynomial poly;
	poly.addTerm(Term(2, 'x', 1));
	poly.addTerm(Term(2, 'x', 2));
	poly.addTerm(Term(2, 'x', 3));

	Polynomial otherPoly;
	otherPoly.addTerm(Term(4, 'x', 4));
	otherPoly.addTerm(Term(4, 'x', 2));
	otherPoly.addTerm(Term(4, 'x', 0));

	poly.simplify();
	otherPoly.simplify();

	cout << "poly: " << poly << endl;
	cout << "otherPoly: " << otherPoly << endl;
	cout << "Polynomial Addition: " << poly + otherPoly << endl;
	cout << "Polynomial Subtraction: " << poly - otherPoly << endl;
	cout << "Polynomial Multiplication: " << poly * otherPoly << endl;

	if (poly == otherPoly)
		cout << poly << " is equal to " << otherPoly << endl;
	else
		cout << poly << " is not equal to " << otherPoly << endl;
}