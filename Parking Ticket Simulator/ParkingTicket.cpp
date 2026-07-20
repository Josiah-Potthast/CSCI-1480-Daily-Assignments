#include "ParkingTicket.h"

ParkingTicket::ParkingTicket(PoliceOfficer officer, ParkedCar car, int minsOver)
{
	carMake = car.getMake();
	carModel = car.getModel();
	carColor = car.getColor();
	carPlate = car.getPlate();
	officerName = officer.getName();
	officerBadge = officer.getBadge();
	illegalMins = minsOver;
	fine = calcFine(minsOver);
}

string ParkingTicket::getCarInfo() const
{
	string carInfo;
	carInfo += "Make: " + carMake + "\n";
	carInfo += "Model: " + carModel + "\n";
	carInfo += "Color: " + carColor + "\n";
	carInfo += "Licence: " + carPlate + "\n";
	return carInfo;
}

string ParkingTicket::getOfficerInfo() const
{
	string officerInfo;
	officerInfo += "Officer Name: " + officerName + "\n";
	officerInfo += "Officer Badge: " + officerBadge + "\n";
	return officerInfo;
}

ostream& operator<<(ostream& strm, const ParkingTicket ticket)
{
	strm << ticket.getCarInfo() << ticket.getOfficerInfo();
	strm << "Time Illegally Parked: 0 " << ticket.illegalMins / 60;
	strm << ":" << ticket.illegalMins % 60 << " 0\n";
	strm << fixed << setprecision(2);
	strm << "Fine: $" << ticket.calcFine(ticket.illegalMins);
	strm << defaultfloat << setprecision(6);
	return strm;
}

double ParkingTicket::calcFine(int minsOver)
{
	if (minsOver > 0)
		return 25 + (10 * ((minsOver - 1) / 60));
	return 0;
}