// Josiah Potthast
// Daily Assignment 3.2

#include "Term.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
	Polynomial poly;
	poly.addTerm(Term(2, 'x', 1));
	poly.addTerm(Term(2, 'x', 2));
	poly.addTerm(Term(2, 'x', 3));

	Polynomial otherPoly = poly;

	poly.simplify();
	otherPoly.simplify();

	cout << poly << endl;
	cout << otherPoly << endl;

	cout << poly * otherPoly << endl;
}