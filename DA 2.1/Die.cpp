#include "Die.h"
#include <iostream>
#include <string>
using namespace std;

Die::Die(int n, int v)
{
	numberOfSides = n;
	faceValue = v;
}

int Die::getNumberOfSides() const
{
	return numberOfSides;
}

int Die::getFaceValue() const
{
	return faceValue;
}

void Die::setNumberOfSides(int sides)
{
	if (sides > 0)
		numberOfSides = sides;
}

void Die::setFaceValue(int value)
{
	if (value < numberOfSides)
		faceValue = value;
}

void Die::roll()
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(time(0));
		seeded = true;
	}

	faceValue = rand() % numberOfSides + 1;
}

string Die::dieDescription()
{
	return "a " + to_string(faceValue);
}