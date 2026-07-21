#ifndef ROCKET_H
#define ROCKET_H
#include "Mover.h"
#include <iostream>
using namespace std;

class Rocket : public Mover
{
public:
	Rocket();
	Rocket(double mph);

	string move();
};

#endif