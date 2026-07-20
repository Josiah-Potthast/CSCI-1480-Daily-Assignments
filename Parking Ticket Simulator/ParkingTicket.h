#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H
#include "ParkedCar.h"
#include "PoliceOfficer.h"
#include <iostream>
#include <iomanip>
using namespace std;

class ParkedCar;
class PoliceOfficer;

class ParkingTicket
{
private:
	string carMake;
	string carModel;
	string carColor;
	string carPlate;
	string officerName;
	string officerBadge;
	int illegalMins;
	double fine;
public:
	ParkingTicket(PoliceOfficer officer, ParkedCar car, int minsOver);

	string getCarInfo() const;
	string getOfficerInfo() const;

	friend ostream& operator<<(ostream& strm, const ParkingTicket ticket);

	static double calcFine(int minsOver);
};

#endif