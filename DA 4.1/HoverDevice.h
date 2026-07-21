#ifndef HOVERDEVICE_H
#define HOVERDEVICE_H
#include "Mover.h"
#include <iostream>
using namespace std;

class HoverDevice : public Mover
{
public:
	HoverDevice();
	HoverDevice(double mph);

	string move();
};

#endif