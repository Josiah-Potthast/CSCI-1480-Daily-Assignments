#include "Picture.h"

Picture::Picture() : Picture(vector<vector<Color>>())
{

}

Picture::Picture(int width, int hight)
{
	for (int row = 0; row < hight; row++)
	{
		this->pixels.push_back(vector<Color>());
		for (int column = 0; column < width; column++)
		{
			this->pixels[row].push_back(WHITE);
		}
	}
}

Picture::Picture(vector<vector<Color>> pixels)
{
	for (int row = 0; row < pixels.size(); row++)
	{
		this->pixels.push_back(vector<Color>());
		for (int column = 0; column < pixels[row].size(); column++)
		{
			this->pixels[row].push_back(pixels[row][column]);
		}
	}
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
			strm << obj.pixels[row][column]; 
		strm << endl;
	}
	return strm;
}