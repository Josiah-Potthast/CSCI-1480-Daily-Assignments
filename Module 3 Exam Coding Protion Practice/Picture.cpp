#include "Picture.h"

Picture::Picture() : Picture(vector<vector<Color>>())
{

}

Picture::Picture(int width, int hight, string defaultANSI)
{
	for (int row = 0; row < hight; row++)
	{
		this->pixels.push_back(vector<Color>());
		for (int column = 0; column < width; column++)
		{
			this->pixels[row].push_back(WHITE);
		}
	}

	this->defaultANSI = defaultANSI;
}

Picture::Picture(vector<vector<Color>> pixels, string defaultANSI)
{
	for (int row = 0; row < pixels.size(); row++)
	{
		this->pixels.push_back(vector<Color>());
		for (int column = 0; column < pixels[row].size(); column++)
		{
			this->pixels[row].push_back(pixels[row][column]);
		}
	}

	this->defaultANSI = defaultANSI;
}

Picture::Picture(const Picture& obj)
{
	for (int row = 0; row < obj.pixels.size(); row++)
	{
		pixels.push_back(vector<Color>());
		for (int column = 0; column < obj.pixels[row].size(); column++)
		{
			pixels[row].push_back(obj.pixels[row][column]);
		}
	}

	defaultANSI = obj.defaultANSI;
}

Picture::~Picture()
{
	for (int row = 0; row < pixels.size(); row++)
	{
		for (int column = 0; column < pixels[row].size(); column++)
		{
			pixels[row].pop_back();
		}
		pixels.pop_back();
	}
}

int Picture::getWidth() const
{
	return pixels[0].size();
}

int Picture::getHight() const
{
	return pixels.size();
}

Color Picture::getPixel(int x, int y)
{
	return pixels[y][x];
}

void Picture::setPixel(int x, int y, Color c)
{
	pixels[y][x] = c;
}

// validates the incoming ANSI code, then sets it as the default for operator<< to use
void Picture::setDefaultANSI(string code)
{
	bool valid = false;
	vector<string> validCodes
	{ 
		"\033[0m", 
		"\033[40m", "\033[41m", "\033[42m", "\033[43m",
		"\033[44m", "\033[45m", "\033[46m", "\033[47m", 
		"\033[100m", "\033[101m", "\033[102m", "\033[103m", 
		"\033[104m", "\033[105m", "\033[106m", "\033[107m",
	};
	for (int i = 0; i < validCodes.size(); i++)
		if (code == validCodes[i])
			valid = true;
	if (valid)
		defaultANSI = code;
}

Picture& Picture::operator=(const Picture& right)
{
	if (this != &right)
	{
		for (int row = 0; row < pixels.size(); row++)
		{
			for (int column = 0; column < pixels[row].size(); column++)
			{
				pixels[row].pop_back();
			}
			pixels.pop_back();
		}

		for (int row = 0; row < right.pixels.size(); row++)
		{
			pixels.push_back(vector<Color>());
			for (int column = 0; column < right.pixels[row].size(); column++)
			{
				pixels[row].push_back(right.pixels[row][column]);
			}
		}
	}
	return *this;
}

ostream& operator<<(ostream& strm, const Picture& obj)
{
	for (int row = 0; row < obj.pixels.size(); row++)
	{
		for (int column = 0; column < obj.pixels[row].size(); column++)
			strm << obj.pixels[row][column] << obj.defaultANSI << " " << "\033[0m"; 
											// add colored space, then reset the color
		strm << endl;
	}
	return strm;
}