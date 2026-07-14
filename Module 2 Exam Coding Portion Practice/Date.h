#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	const string MONTH_NAMES[12] = { "January", "February", "March", "April",
	"May", "June", "July", "August", "September", "October", "November", "December" };
public:
	Date();
	Date(int y, int m, int d);
	~Date();
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void printNumeric(char delim = '/');
	void printFormal();
	void printEuro();
};

