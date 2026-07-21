#include "Skids.h"

Skids::Skids() : Mover()
{

}

Skids::Skids(double mph)
{
	setMPH(mph);
}

string Skids::move()
{
	return "skids across the water " + Mover::move();
}