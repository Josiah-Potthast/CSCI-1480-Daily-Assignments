#include "PicReader.h"

vector<Pixel> PicReader::readPic(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	vector<Pixel> pixels;
	int x;
	int y;
	int red;
	int green;
	int blue;


	
	while (inFile >> x >> y >> red >> green >> blue)
	{
		try
		{
			if (x < 0)
			{
				throw CoordinateOutOfRangeException(x);
			}
			if (y < 0)
			{
				throw CoordinateOutOfRangeException(y);
			}
		}
		catch (CoordinateOutOfRangeException coord)
		{
			cout << coord.getCoordValue() << " is not a valid coordinate\n";
			continue;
		}

		try
		{
			if (red < 0)
			{
				throw ColorVectorOutOfRangeException(red);
				red = 0;
			}
			if (green < 0)
			{
				throw ColorVectorOutOfRangeException(green);
				green = 0;
			}
			if (blue < 0)
			{
				throw ColorVectorOutOfRangeException(blue);
				blue = 0;
			}
			if (red > 255)
			{
				throw ColorVectorOutOfRangeException(red);
				red = 255;
			}
			if (green > 255)
			{
				throw ColorVectorOutOfRangeException(green);
				green = 255;
			}
			if (blue > 255)
			{
				throw ColorVectorOutOfRangeException(blue);
				blue = 255;
			}
		}
		catch (ColorVectorOutOfRangeException coord)
		{
			cout << coord.getCoordValue() << " is not a valid color value\n";
		}

		pixels.push_back(Pixel(x, y, red, green, blue));
	}

	inFile.close();

	return pixels;
}