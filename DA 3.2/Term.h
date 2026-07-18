#ifndef TERM_H
#define TERM_H
#include "Polynomial.h"
#include <iostream>
#include <math.h>
using namespace std;

class Polynomial;

class Term
{
private:
	double coefficient;
	char variable;
	int exponent;
public:
	Term(); 
	Term(double c, char v, int e); 
	Term(const Term& obj); 

	double getCoefficient() const; 
	char getVariable() const; 
	int getExponent() const; 

	void setCoefficient(double c);
	void setVariable(char v);
	void setExponent(int e);

	operator Polynomial();

	Polynomial operator+(const Term& right) const; // working
	Polynomial operator-(const Term& right) const; // working
	Term operator*(const Term& right) const; // working
	const Term& operator=(const Term& right); // working
	bool operator==(const Term& right) const; // working
	friend ostream& operator<<(ostream& strm, const Term& right); // working
};

#endif