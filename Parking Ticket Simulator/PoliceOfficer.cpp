#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer() : PoliceOfficer("", "")
{

}

PoliceOfficer::PoliceOfficer(string n, string b)
{
	name = n;
	badge = b;
}

string PoliceOfficer::getName() const
{
	return name;
}

string PoliceOfficer::getBadge() const
{
	return badge;
}

void PoliceOfficer::setName(string n)
{
	name = n;
}

void PoliceOfficer::setBadge(string b)
{
	badge = b;
}

ParkingTicket PoliceOfficer::inspectCar(ParkedCar car, ParkingMeter meter)
{
	int minsOver = car.getMinsParked() - meter.getMinsBought();
	if (car.getMinsParked() > meter.getMinsBought())
		return ParkingTicket(*this, car, minsOver);
	return ParkingTicket(PoliceOfficer(), ParkedCar(), 0);
}