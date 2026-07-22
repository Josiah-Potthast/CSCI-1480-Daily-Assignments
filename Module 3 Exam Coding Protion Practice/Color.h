#ifndef COLOR_H
#define COLOR_H
#include <iostream>
using namespace std;

class Color
{
private:
	int red;
	int green;
	int blue;
	static bool printLetters;
public:
	Color();
	Color(int red, int green, int blue);
	Color(const Color& obj);

	Color& operator=(const Color& right);
	friend ostream& operator<<(ostream& strm, const Color& obj);

	static void setPrintLetters(bool mode);
};

static const Color
RED(255, 0, 0),
YELLOW(255, 255, 0),
BLUE(0, 0, 255),
GREEN(0, 255, 0),
PURPLE(255, 0, 255), // PURPLE(150, 0, 255) originally
TEAL(0, 255, 255), // ORANGE(255, 150, 0) originally
BLACK(0, 0, 0),
WHITE(255, 255, 255),
GRAY(150, 150, 150);

#endif