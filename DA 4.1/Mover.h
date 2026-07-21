#ifndef MOVER_H
#define MOVER_H
#include <string>
#include <iostream>
using namespace std;

class Mover
{
private:
	double mph;
public:
	Mover();
	Mover(double mph);

	virtual string move() = 0;

	double getMPH();
	void setMPH(double mph);
};

#endif