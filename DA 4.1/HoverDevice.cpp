#include "HoverDevice.h"

HoverDevice::HoverDevice() : Mover()
{

}

HoverDevice::HoverDevice(double mph) 
{
	setMPH(mph);
}

string HoverDevice::move()
{
	return "hovers over the ground " + Mover::move();
}