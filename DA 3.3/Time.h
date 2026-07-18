#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time
{
private:
	int days;
	int hours;
	int minutes;
	int seconds;
	bool military; 
public:
	Time();
	Time(int d, int h, int m, int s);
	Time(int h, int m, int s);
	Time(int h, int m);
	Time(const Time& obj);

	int getDays() const;
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	bool getMilitary() const;

	void setDays(int d);
	void setHours(int h);
	void setMinutes(int m);
	void setSeconds(int s);
	void setMilitary(bool m);
	void toggleMilitary();

	void simplify();

	Time& operator=(const Time& right);
	Time operator+(const Time& right) const;
	Time operator-(const Time& right) const;
	bool operator<(const Time& right) const;
	bool operator>(const Time& right) const;
	bool operator<=(const Time& right) const;
	bool operator>=(const Time& right) const;
	bool operator==(const Time& right) const;
	friend ostream& operator<<(ostream& strm, const Time& obj);

	operator int();
};

#endif