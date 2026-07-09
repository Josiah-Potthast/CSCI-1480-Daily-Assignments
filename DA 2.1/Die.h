#pragma once
#include <iostream>
using namespace std;

class Die
{
private:
	const int numberOfSides;
	int faceValue;
public:
	Die(int sides = 6);
	int getNumberOfSides() const;
	int getFaceValue() const;
	void setFaceValue(int value);
	void roll();
	//string dieDescription();
};