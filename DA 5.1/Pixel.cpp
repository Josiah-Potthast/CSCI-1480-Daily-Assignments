#include "Pixel.h"

Pixel::Pixel() : Pixel(0, 0, 255, 255, 255)
{

}

Pixel::Pixel(int x, int y, int red, int green, int blue)
{
	this->x = x;
	this->y = y;
	this->red = red;
	this->green = green;
	this->blue = blue;

}

int Pixel::getX() const
{
	return x;
}

int Pixel::getY() const
{
	return y;
}

int Pixel::getRed() const
{
	return red;
}

int Pixel::getGreen() const
{
	return green;
}

int Pixel::getBlue() const
{
	return blue;
}

COLOR Pixel::getColor() const
{
	int colorInt;
	if (red > green && red > blue)
		colorInt = RED;
	else if (green > red && green > blue)
		colorInt = GREEN;
	else if (blue > red && blue > green)
		colorInt = BLUE;
	else if (red == green && red > blue)
		colorInt = YELLOW;
	else if (red == blue && red > green)
		colorInt = MAGENTA;
	else if (green == blue && green > red)
		colorInt = CYAN;
	else if (red == green && red == blue && red < 50)
		colorInt = BLACK;
	else if (red == green && red == blue && red > 250)
		colorInt = WHITE;
	else if (red == green && red == blue)
		colorInt = GRAY;
	else
		throw "color does not exsist";
	return static_cast<COLOR>(colorInt);
}

void Pixel::setX()
{
	this->x = x;
}

void Pixel::setY()
{
	this->y = y;
}

void Pixel::setRed()
{
	this->red = red;
}

void Pixel::setGreen()
{
	this->green = green;
}

void Pixel::setBlue()
{
	this->blue = blue;
}

ostream& operator<<(ostream& strm, const Pixel& obj)
{
	strm << Pixel::getCode(obj.getColor());
	strm << "  " << Pixel::getCode(RESET);
	return strm;
}

string Pixel::getCode(COLOR color, bool background, bool bright)
{
	if (color == GRAY)
		return "\033[100m"; // technically bright black background, added for convenience
	if (color == RESET)
		return "\033[0m";

	string code = "\033[";
	int num = 0;

	if (background)
		num += 10;
	if (bright)
		num += 60;

	num += color;
	code += to_string(num);
	code += "m";

	return code;
}