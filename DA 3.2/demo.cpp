// Josiah Potthast
// Daily Assignment 3.2

#include "Term.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;

void termDriver();
void polyDriver();

int main()
{
	termDriver();
	polyDriver();
}

void termDriver()
{
	Term term(3, 'x', 1);
	Term otherTerm(1, 'x', 3);
	cout << "term: " << term << endl;
	cout << "otherTerm: " << otherTerm << endl;
	cout << "Term Addition: " << term + otherTerm << endl;
	cout << "Term Subtraction: " << term - otherTerm << endl;
	cout << "Term Multiplication: " << term * otherTerm << endl;

	if (term == otherTerm)
		cout << term << " is equal to " << otherTerm << endl;
	else
		cout << term << " is not equal to " << otherTerm << endl;

	otherTerm = term;

	if (term == otherTerm)
		cout << term << " is equal to " << otherTerm << endl;
	else
		cout << term << " is not equal to " << otherTerm << endl;

	cout << endl;
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

	otherPoly = poly;

	if (poly == otherPoly)
		cout << poly << " is equal to " << otherPoly << endl;
	else
		cout << poly << " is not equal to " << otherPoly << endl;

	cout << endl;
}