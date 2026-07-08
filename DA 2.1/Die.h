#pragma once
#include <iostream>
using namespace std;

class Die
{
private:
	int numberOfSides;
	int faceValue;
public:
	int getNumberOfSides() const;
	int getFaceValue() const;
	void setNumberOfSides(int sides);
	void setFaceValue(int value);
	void roll();
	string dieDescription();
};