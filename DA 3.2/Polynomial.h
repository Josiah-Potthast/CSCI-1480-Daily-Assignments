#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"
#include <iostream>
using namespace std;

class Term;

class Polynomial
{
private:
	Term* terms;
	int numberOfTerms;
public:
	Polynomial();
	Polynomial(Term* termArray, int size);
	Polynomial(const Polynomial& obj);
	~Polynomial();

	Term* getTerms() const;
	int getNumberOfTerms() const;
	Term getTerm(int index) const;

	void setTerms(Term* newTerms, int size);
	void setTerm(int index, Term newTerm);

	Polynomial operator+(const Polynomial& right);
	Polynomial operator-(const Polynomial& right);
	Polynomial operator*(const Polynomial& right);
	bool operator==(const Polynomial& right);
	friend ostream& operator<<(ostream& strm, const Polynomial& right);
};

#endif