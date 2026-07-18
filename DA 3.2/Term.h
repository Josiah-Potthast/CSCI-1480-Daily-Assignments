#ifndef TERM_H
#define TERM_H
#include "Polynomial.h"
#include <iostream>
using namespace std;

class Polynomial;

class Term
{
private:
	double coefficient;
	char variable;
	int exponent;
public:
	// constructors
	Term(); 
	Term(double c, char v, int e); 
	Term(const Term& obj); 

	// accessors
	double getCoefficient() const; 
	char getVariable() const; 
	int getExponent() const; 

	// mutators
	void setCoefficient(double c);
	void setVariable(char v);
	void setExponent(int e);

	// term-to-polynomial conversion
	operator Polynomial();

	// overloaded operator functions
	Polynomial operator+(const Term& right) const; // working
	Polynomial operator-(const Term& right) const; // working
	Term operator*(const Term& right) const; // working
	const Term& operator=(const Term& right); // working
	bool operator==(const Term& right) const; // working
	friend ostream& operator<<(ostream& strm, const Term& right); // working
};

#endif