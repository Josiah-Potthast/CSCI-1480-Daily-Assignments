#ifndef PARKINGMETER_H
#define PARKINGMETER_H
#include "ParkedCar.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
using namespace std;

class ParkedCar;
class ParkingTicket;
class PoliceOfficer;

class ParkingMeter
{
private:
	int minsBought;
public:
	ParkingMeter();
	ParkingMeter(int mins);
	int getMinsBought() const;
	void setMinsBought(int mins);
};

#endif