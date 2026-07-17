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
	Term();
	Term(double c, char v, int e);
	Term(const Term& obj);

	double getCoefficient() const;
	char getVariable() const;
	int getExponent() const;

	void setCoefficient(double c);
	void setVariable(char v);
	void setExponent(int e);

	Polynomial operator+(const Term& right);
	Polynomial operator-(const Term& right);
	Polynomial operator*(const Term& right);
	bool operator==(const Term& right);
};

#endif