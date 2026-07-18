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

Term::operator Polynomial()
{
	Term copy;
	copy.coefficient = coefficient;
	copy.variable = variable;
	copy.exponent = exponent;
	Polynomial poly(&copy, 1);
	return poly;
}

Polynomial Term::operator+(const Term& right) const
{
	int size; // number of terms in the resulting polynomial (1 or 2)

	if (exponent == right.exponent)
		size = 1;
	else
		size = 2;
	Term* terms = new Term[size];
	terms[0].coefficient = coefficient;
	terms[0].exponent = exponent;
	if (exponent == right.exponent)
		terms[0].coefficient += right.coefficient;
	else
		terms[1] = right;

	Polynomial result(terms, size);

	delete terms;
	terms = nullptr;

	return result;
}

Polynomial Term::operator-(const Term& right) const
{
	int size; // number of terms in the resulting polynomial (1 or 2)

	if (exponent == right.exponent)
		size = 1;
	else
		size = 2;
	Term* terms = new Term[size];
	terms[0].coefficient = coefficient;
	terms[0].exponent = exponent;
	if (exponent == right.exponent)
		terms[0].coefficient -= right.coefficient;
	else
	{
		terms[1] = right;
		terms[1].coefficient *= -1; // flip the sign of the second term
	}

	Polynomial result(terms, size);

	delete terms;
	terms = nullptr;

	return result;
}

Term Term::operator*(const Term& right) const
{
	Term product;
	product.coefficient = coefficient * right.coefficient;
	product.exponent = exponent + right.exponent;
	return product;
}

const Term& Term::operator=(const Term& right)
{
	if (*this != right)
	{
		coefficient = right.coefficient;
		variable = right.variable;
		exponent = right.exponent;
	}
	return *this;
}

bool Term::operator==(const Term& right) const
{
	bool equality = true;
	if (coefficient != right.coefficient)
		equality = false;
	if (exponent != right.exponent)
		equality = false;
	return equality;
}

ostream& operator<<(ostream& strm, const Term& right)
{
	strm << abs(right.coefficient);
	if (right.exponent != 0 && right.exponent != 1)
		strm << right.variable << '^' << right.exponent;
	else if (right.exponent != 0)
		strm << right.variable;
	return strm;
}