#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person
{
private:
	string firstName;
	string lastName;
	string dateOfBirth;
public:
	Person();
	Person(string fN, string lN, string dOB);

	string getFirstName() const;
	string getLastName() const;
	string getDateOfBirth() const;

	Person& operator=(const Person& right);
	friend ostream& operator<<(ostream& strm, const Person& obj);
};

#endif