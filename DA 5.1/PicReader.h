#ifndef PICREADER_H
#define PICREADER_H
#include "Pixel.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Pixel;

class PicReader
{
private:
public:
    class CoordinateOutOfRangeException
    {
    private:
        int coordValue;
    public:
        CoordinateOutOfRangeException(int val)
        {
            coordValue = val;
        };
        int getCoordValue() const
        {
            return coordValue;
        };
    };

    class ColorVectorOutOfRangeException
    {
    private:
        int coordValue;
    public:
        ColorVectorOutOfRangeException(int val)
        {
            coordValue = val;
        };
        int getCoordValue() const
        {
            return coordValue;
        };
    };

    static vector<Pixel> readPic(string fileName);
};

#endif