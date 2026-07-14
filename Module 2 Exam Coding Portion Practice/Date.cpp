#include "Date.h"

Date::Date() : Date(2000, 1, 1)
{

}

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

Date::~Date()
{

}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setYear(int y)
{
	year = y;
}

void Date::printNumeric(char delim)
{
	cout << month << delim << day << delim << year << endl;
}

void Date::printFormal()
{
	cout << MONTH_NAMES[month - 1] << " " << day << ", " << year << endl;
}

void Date::printEuro()
{
	cout << day << " " << MONTH_NAMES[month - 1] << " " << year << endl;
}
