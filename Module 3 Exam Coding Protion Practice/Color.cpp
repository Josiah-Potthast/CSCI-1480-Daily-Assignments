#include "Color.h"

Color::Color() : Color(WHITE)
{

}

Color::Color(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::Color(const Color& obj)
{
	red = obj.red;
	green = obj.green;
	blue = obj.blue;
}

Color& Color::operator=(const Color& right)
{
	if (this != &right)
	{
		red = right.red;
		green = right.green;
		blue = right.blue;
	}
	return *this;
}

// added some ANSI code escape sequences for better visuals
ostream& operator<<(ostream& strm, const Color& obj)
{
	char letter = 'Z'; // an error, should never show up
	
	if (obj.red > obj.green && obj.red > obj.blue)
	{
		strm << "\033[41m";
		letter = 'R'; // red
	}
	else if (obj.green > obj.red && obj.green > obj.blue)
	{
		strm << "\033[42m";
		letter = 'V'; // green
	}
	else if (obj.blue > obj.red && obj.blue > obj.green)
	{
		strm << "\033[44m";
		letter = 'B'; // blue
	}
	else if (obj.red == obj.green && obj.red > obj.blue)
	{
		strm << "\033[43m";
		letter = 'Y'; // yellow
	}
	else if (obj.red == obj.blue && obj.red > obj.green)
	{
		strm << "\033[45m";
		letter = 'P'; // purple
	}
	else if (obj.green == obj.blue && obj.green > obj.red)
	{
		strm << "\033[46m";
		letter = 'T'; // teal
	}
	else if (obj.red == obj.green && obj.red == obj.blue)
	{
		if (obj.red < 50)
		{
			strm << "\033[40m";
			letter = 'D'; // black
		}
		else if (obj.red > 250)
		{
			strm << "\033[47m" << "\033[30m";
			letter = 'W'; // white
		}
		else
		{
			strm << "\033[100m";
			letter = 'G'; // grey
		}
	}
	else
		letter = 'X'; // an error, should never show up

	strm << letter;
	strm << "\033[0m";
	return strm;
}