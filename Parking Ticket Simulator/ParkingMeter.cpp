#include "ParkingMeter.h"

ParkingMeter::ParkingMeter() : ParkingMeter(0)
{

}

ParkingMeter::ParkingMeter(int mins)
{
	minsBought = mins;
}

int ParkingMeter::getMinsBought() const
{
	return minsBought;
}

void ParkingMeter::setMinsBought(int mins)
{
	minsBought = mins;
}