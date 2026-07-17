#include "Polynomial.h"

Polynomial::Polynomial() : Polynomial(nullptr, 0)
{

}

Polynomial::Polynomial(Term* termArray, int size)
{
	numberOfTerms = size;
	terms = new Term[numberOfTerms];
	for (int i = 0; i < numberOfTerms; i++)
		terms[i] = termArray[i];
}

Polynomial::Polynomial(const Polynomial& obj)
{
	numberOfTerms = obj.numberOfTerms;
	terms = new Term[numberOfTerms];
	for (int i = 0; i < numberOfTerms; i++)
		terms[i] = obj.terms[i];
}

Polynomial::~Polynomial()
{
	delete[] terms;
	terms = nullptr;
}

Term* Polynomial::getTerms() const
{
	return terms;
}

int Polynomial::getNumberOfTerms() const
{
	return numberOfTerms;
}

Term Polynomial::getTerm(int index) const
{
	return terms[index];
}

void Polynomial::setTerms(Term* newTerms, int size)
{
	if(terms != newTerms)
	{
		delete[] terms;
		terms = nullptr;
		numberOfTerms = size;
		terms = new Term[numberOfTerms];
		for (int i = 0; i < numberOfTerms; i++)
			terms[i] = newTerms[i];
	}
}

void Polynomial::setTerm(int index, Term newTerm)
{
	terms[index] = newTerm;
}

Polynomial Polynomial::operator+(const Polynomial& right)
{

}

Polynomial Polynomial::operator-(const Polynomial& right)
{

}

Polynomial Polynomial::operator*(const Polynomial& right)
{

}

bool Polynomial::operator==(const Polynomial& right)
{

}

ostream& operator<<(ostream& strm, const Polynomial& right)
{
	
}