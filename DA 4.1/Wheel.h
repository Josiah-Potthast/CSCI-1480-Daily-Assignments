#ifndef WHEEL_H
#define WHEEL_H
#include "Mover.h"
#include <iostream>
using namespace std;

class Wheel : public Mover
{
public:
	Wheel();
	Wheel(double mph);

	string move();
};

#endif