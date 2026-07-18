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

// adds the term passed in to the end of the terms dynamic array
void Polynomial::addTerm(Term term)
{
	numberOfTerms++;
	Term* tempTerms = new Term[numberOfTerms];
	for (int i = 0; i < numberOfTerms - 1; i++)
		tempTerms[i] = terms[i];
	tempTerms[numberOfTerms - 1] = term;
	delete[] terms;
	terms = tempTerms;
	tempTerms = nullptr;
}

// replaces the unwanted value with the last value in the array, then re-allocates
// it to be one size smaller
void Polynomial::removeTerm(int index)
{
	numberOfTerms--;
	terms[index] = terms[numberOfTerms]; 
	Term* tempTerms = new Term[numberOfTerms];
	for (int i = 0; i < numberOfTerms; i++)
		tempTerms[i] = terms[i];
	delete[] terms;
	terms = tempTerms;
	tempTerms = nullptr;
}

// exchanges the values of two elements in the terms array
void Polynomial::swapTerms(int firstIndex, int secondIndex)
{
	Term temp = terms[firstIndex];
	terms[firstIndex] = terms[secondIndex];
	terms[secondIndex] = temp;
}

// combines like terms (same exponent) and removes terms with a zero coefficient,
// then sorts the terms
void Polynomial::simplify()
{
	for (int i = 0; i < numberOfTerms; i++)
	{
		for (int j = i + 1; j < numberOfTerms; j++)
		{
			if (terms[i].getExponent() == terms[j].getExponent())
			{
				terms[i] = terms[i] + terms[j];
				this->removeTerm(j);
				j--; // because sub j will now be a different term, see removeTerm()
			}
		}
	}
	for (int i = 0; i < numberOfTerms; i++)
	{
		if (terms[i].getCoefficient() == 0)
		{
			this->removeTerm(i);
			i--; 
		}
	}
	this->sort();
}

// sorts terms from highest power to lowest
void Polynomial::sort()
{
	bool sorted = true;
	do
	{
		sorted = true;
		for (int i = 0; i < numberOfTerms - 1; i++)
		{
			if (terms[i].getExponent() < terms[i + 1].getExponent())
			{
				this->swapTerms(i, i + 1);
				sorted = false;
			}
		}
	} while (!sorted);
}

Polynomial::operator Term()
{
	if (numberOfTerms == 1)
		return *terms;
}

Polynomial Polynomial::operator+(const Polynomial& right) const
{
	Polynomial resultPoly(*this);
	for (int i = 0; i < right.numberOfTerms; i++)
		resultPoly.addTerm(right.terms[i]);
	
	resultPoly.simplify();
	return resultPoly;
}

Polynomial Polynomial::operator-(const Polynomial& right) const
{
	Polynomial resultPoly(*this);
	Polynomial tempPoly = right;

	for (int i = 0; i < tempPoly.numberOfTerms; i++)
	{
		tempPoly.terms[i].setCoefficient(tempPoly.terms[i].getCoefficient() * -1);
		resultPoly.addTerm(tempPoly.terms[i]);
	}
	
	resultPoly.simplify();
	return resultPoly;
}

Polynomial Polynomial::operator*(const Polynomial& right) const
{
	Polynomial resultPoly;
	for (int i = 0; i < numberOfTerms; i++)
		for (int j = 0; j < right.numberOfTerms; j++)
			resultPoly.addTerm(terms[i] * right.terms[j]);
	resultPoly.simplify();
	return resultPoly;
}

const Polynomial& Polynomial::operator=(const Polynomial& right)
{
	if (*this != right)
	{
		delete[] terms;
		terms = nullptr;
		numberOfTerms = right.numberOfTerms;
		terms = new Term[numberOfTerms];
		for (int i = 0; i < numberOfTerms; i++)
			terms[i] = right.terms[i];
	}
	return *this;
}

bool Polynomial::operator==(const Polynomial& right) const
{
	bool equality = true;
	Polynomial leftCopy(*this);
	Polynomial rightCopy(right);
	leftCopy.simplify();
	rightCopy.simplify();
	if (leftCopy.numberOfTerms != rightCopy.numberOfTerms)
		equality = false;
	else
	{
		for (int i = 0; i < leftCopy.numberOfTerms; i++)
			if (leftCopy.terms[i] != rightCopy.terms[i])
				equality = false;
	}
	return equality;
}

ostream& operator<<(ostream& strm, const Polynomial& right)
{
	Polynomial copy(right);
	for (int i = 0; i < copy.numberOfTerms; i++)
	{
		if (i > 0 && copy.terms[i].getCoefficient() > 0)
			strm << " + ";
		else if (copy.terms[i].getCoefficient() < 0)
		{
			copy.terms[i].setCoefficient(copy.terms[i].getCoefficient() * -1);
			strm << " - ";
		}
		strm << copy.terms[i];
	}
	return strm;
}