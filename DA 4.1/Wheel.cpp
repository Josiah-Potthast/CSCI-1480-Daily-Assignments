#include "Wheel.h"

Wheel::Wheel() : Mover()
{

}

Wheel::Wheel(double mph)
{
	setMPH(mph);
}

string Wheel::move()
{
	return  "rolls over the ground " + Mover::move();
}