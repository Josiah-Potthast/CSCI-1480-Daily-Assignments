#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include <iostream>
using namespace std;

class ParkedCar;
class ParkingMeter;
class ParkingTicket;

class PoliceOfficer
{
private:
	string name;
	string badge;
public:
	PoliceOfficer();
	PoliceOfficer(string n, string b);

	string getName() const;
	string getBadge() const;

	void setName(string n);
	void setBadge(string b);

	ParkingTicket inspectCar(ParkedCar car, ParkingMeter meter);
};

#endif