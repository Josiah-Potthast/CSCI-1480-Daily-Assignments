#include "Term.h"

Term::Term() : Term(1, 'x', 1)
{

}

Term::Term(double c, char v, int e)
{
	coefficient = c;
	variable = v;
	exponent = e;
}

Term::Term(const Term& obj)
{
	coefficient = obj.coefficient;
	variable = obj.variable;
	exponent = obj.exponent;
}

double Term::getCoefficient() const
{
	return coefficient;
}

char Term::getVariable() const
{
	return variable;
}

int Term::getExponent() const
{
	return exponent;
}

void Term::setCoefficient(double c)
{
	coefficient = c;
}

void Term::setVariable(char v)
{
	variable = v;
}

void Term::setExponent(int e)
{
	exponent = e;
}

Polynomial Term::operator+(const Term& right)
{

}

Polynomial Term::operator-(const Term& right)
{

}

Polynomial Term::operator*(const Term& right)
{

}

bool Term::operator==(const Term& right)
{

}