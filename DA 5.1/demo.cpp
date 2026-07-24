// Josiah Potthast
// Daily Assignment 5.1

#include "Pixel.h"
#include "PicReader.h"
#include <iostream>
using namespace std;

int main()
{
	vector<Pixel> pixels = PicReader::readPic("colors.txt");

	for (Pixel& p : pixels)
		cout << p;
}