#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <string>
using namespace std;

enum COLOR;

class Pixel
{
private:
	int x;
	int y;
	int red;
	int green;
	int blue;
	COLOR color;
public:
	Pixel();
	Pixel(int x, int y, int red, int green, int blue);

	int getX() const;
	int getY() const;
	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	COLOR getColor() const;

	void setX();
	void setY();
	void setRed();
	void setGreen();
	void setBlue();

	friend ostream& operator<<(ostream& strm, const Pixel& obj);

	static string getCode(COLOR color, bool background = true, bool bright = false);
};

enum COLOR
{
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	GRAY = 100,
	RESET = 0
};

#endif