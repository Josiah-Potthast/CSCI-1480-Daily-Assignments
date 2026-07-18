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

	void addTerm(Term term); // working
	void removeTerm(int index); // working
	void swapTerms(int firstIndex, int secondIndex); // working
	void simplify(); // working
	void sort(); // working

	operator Term();

	Polynomial operator+(const Polynomial& right) const; // working
	Polynomial operator-(const Polynomial& right) const; // working
	Polynomial operator*(const Polynomial& right) const; // working
	const Polynomial& operator=(const Polynomial& right); // working
	bool operator==(const Polynomial& right) const; // working
	friend ostream& operator<<(ostream& strm, const Polynomial& right); // working
};

#endif