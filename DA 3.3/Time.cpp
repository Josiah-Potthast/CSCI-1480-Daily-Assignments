#include "Time.h"

Time::Time() : Time(0, 0, 0, 0)
{

}

Time::Time(int d, int h, int m, int s)
{
	days = d;
	hours = h;
	minutes = m;
	seconds = s;
	military = true;
}

Time::Time(int h, int m, int s) : Time(0, h, m, s)
{

}

Time::Time(int h, int m) : Time(0, h, m, 0)
{

}

Time::Time(const Time& obj)
{
	days = obj.days;
	hours = obj.hours;
	minutes = obj.minutes;
	seconds = obj.seconds;
	military = obj.military;
}

int Time::getDays() const
{
	return days;
}

int Time::getHours() const
{
	return hours;
}

int Time::getMinutes() const
{
	return minutes;
}

int Time::getSeconds() const
{
	return seconds;
}

bool Time::getMilitary() const
{
	return military;
}

void Time::setDays(int d)
{
	days = d;
}

void Time::setHours(int h)
{
	if (h >= 0 && h < 24)
		hours = h;
}

void Time::setMinutes(int m)
{
	if (m >= 0 && m < 60)
		minutes = m;
}

void Time::setSeconds(int s)
{
	if (s >= 0 && s < 60)
		seconds = s;
}

void Time::setMilitary(bool m)
{
	military = m;
}

void Time::toggleMilitary()
{
	military = !military;
}

void Time::simplify()
{
	while (seconds < 0)
	{
		minutes--;
		seconds += 60;
	}
	while (seconds >= 60)
	{
		seconds -= 60;
		minutes++;
	}

	while (minutes < 0)
	{
		hours--;
		minutes += 60;
	}
	while (minutes >= 60)
	{
		minutes -= 60;
		hours++;
	}

	while (hours < 0)
	{
		days--;
		hours += 24;
	}
	while (hours >= 24)
	{
		hours -= 24;
		days++;
	}
}

void Time::stopwatch(Time runtime)
{
	Time timer;
	while (timer <= runtime)
	{
		cout << timer++ << endl;
		this_thread::sleep_for(1000ms);
	}
}

Time Time::operator++()
{
	seconds++;
	this->simplify();
	return *this;
}

Time Time::operator++(int)
{
	Time temp = *this;
	seconds++;
	this->simplify();
	return temp;
}

Time& Time::operator=(const Time& right)
{
	if (this != &right)
	{
		days = right.days;
		hours = right.hours;
		minutes = right.minutes;
		seconds = right.seconds;
		military = right.military;
	}
	return *this;
}

Time Time::operator+(const Time& right) const
{
	Time result(*this);
	result.days += right.days;
	result.hours += right.hours;
	result.minutes += right.minutes;
	result.seconds += right.seconds;
	result.simplify();
	return result;
}

Time Time::operator-(const Time& right) const
{
	Time result(*this);
	result.days -= right.days;
	result.hours -= right.hours;
	result.minutes -= right.minutes;
	result.seconds -= right.seconds;
	result.simplify();
	return result;
}

bool Time::operator<(const Time& right) const
{
	Time lcopy(*this);
	Time rcopy(right);
	lcopy.simplify();
	rcopy.simplify();
	if (lcopy.days < rcopy.days)
		return true;
	else if (lcopy.days > rcopy.days)
		return false;
	else if (lcopy.hours < rcopy.hours)
		return true;
	else if (lcopy.hours > rcopy.hours)
		return false;
	else if (lcopy.minutes < rcopy.minutes)
		return true;
	else if (lcopy.minutes > rcopy.minutes)
		return false;
	else if (lcopy.seconds < rcopy.seconds)
		return true;
	else
		return false;
}

bool Time::operator>(const Time& right) const
{
	Time lcopy(*this);
	Time rcopy(right);
	lcopy.simplify();
	rcopy.simplify();
	if (days > right.days)
		return true;
	else if (days < right.days)
		return false;
	else if (hours > right.hours)
		return true;
	else if (hours < right.hours)
		return false;
	else if (minutes > right.minutes)
		return true;
	else if (minutes < right.minutes)
		return false;
	else if (seconds > right.seconds)
		return true;
	else
		return false;
}

bool Time::operator<=(const Time& right) const
{
	if (*this < right || *this == right)
		return true;
	else
		return false;
}

bool Time::operator>=(const Time& right) const
{
	if (*this > right || *this == right)
		return true;
	else
		return false;
}

bool Time::operator==(const Time& right) const
{
	Time lcopy(*this);
	Time rcopy(right);
	lcopy.simplify();
	rcopy.simplify();
	if (lcopy.days == rcopy.days
		&& lcopy.hours == rcopy.hours
		&& lcopy.minutes == rcopy.minutes
		&& lcopy.seconds == rcopy.seconds)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& strm, const Time& obj)
{
	bool pm = false;
	strm << obj.days << ":";
	if (!obj.military && obj.hours > 12)
	{
		strm << obj.hours - 12 << ":";
		pm = true;
	}
	else
		strm << obj.hours << ":";
	strm << obj.minutes << ":" << obj.seconds;
	if (pm)
		strm << " PM";
	return strm;
}

Time::operator int()
{
	long long inSeconds = seconds;
	inSeconds += minutes * 60;
	inSeconds += hours * 60 * 60;
	inSeconds += days * 60 * 60 * 24;
	return inSeconds;
}