#ifndef PICTURE_H
#define PICTURE_H
#include "Color.h"
#include <vector>
#include <iostream>
using namespace std;

class Color;

class Picture
{
private:
	vector<vector<Color>> pixels;
public:
	Picture();
	Picture(int width, int hight);
	Picture(vector<vector<Color>> pixels);
	Picture(const Picture& obj);
	~Picture();

	int getWidth() const;
	int getHight() const;
	Color getPixel(int x, int y);
	void setPixel(int x, int y, Color c);

	Picture& operator=(const Picture& right);
	friend ostream& operator<<(ostream& strm, const Picture& obj);
};

static const Picture CREEPER
{
	vector<vector<Color>>
	{
	vector<Color>{GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
	vector<Color>{GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
	vector<Color>{GREEN, BLACK, BLACK, GREEN, GREEN, BLACK, BLACK, GREEN},
	vector<Color>{GREEN, BLACK, BLACK, GREEN, GREEN, BLACK, BLACK, GREEN},
	vector<Color>{GREEN, GREEN, GREEN, BLACK, BLACK, GREEN, GREEN, GREEN},
	vector<Color>{GREEN, GREEN, BLACK, BLACK, BLACK, BLACK, GREEN, GREEN},
	vector<Color>{GREEN, GREEN, BLACK, BLACK, BLACK, BLACK, GREEN, GREEN},
	vector<Color>{GREEN, GREEN, BLACK, GREEN, GREEN, BLACK, GREEN, GREEN},
	}
};

#endif