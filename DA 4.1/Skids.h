#ifndef SKIDS_H
#define SKIDS_H
#include "Mover.h"
#include <iostream>
using namespace std;

class Skids : public Mover
{
public:
	Skids();
	Skids(double mph);

	string move();
};

#endif