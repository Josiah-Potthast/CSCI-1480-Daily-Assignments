#include "Person.h"

Person::Person() : Person("", "", "")
{

}

Person::Person(string fN, string lN, string dOB)
{
	firstName = fN;
	lastName = lN;
	dateOfBirth = dOB;
}

string Person::getFirstName() const
{
	return firstName;
}

string Person::getLastName() const
{
	return lastName;
}

string Person::getDateOfBirth() const
{
	return dateOfBirth;
}

Person& Person::operator=(const Person& right)
{
	if (this != &right)
	{
		firstName = right.firstName;
		lastName = right.lastName;
		dateOfBirth = right.dateOfBirth;
	}
	return *this;
}

ostream& operator<<(ostream& strm, const Person& obj)
{
	strm << obj.firstName << " " << obj.lastName;
	return strm;
}