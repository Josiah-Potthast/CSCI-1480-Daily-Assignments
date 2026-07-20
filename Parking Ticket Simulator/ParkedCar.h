#ifndef PARKEDCAR_H
#define PARKEDCAR_H
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
using namespace std;

class ParkingMeter;
class ParkingTicket;
class PoliceOfficer;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string plate;
	int minsParked;
public:
	ParkedCar();
	ParkedCar(string ma, string mo, string co, string pl, int mins);

	string getMake() const;
	string getModel() const;
	string getColor() const;
	string getPlate() const;
	int getMinsParked() const;

	void setMake(string ma);
	void setModel(string mo);
	void setColor(string co);
	void setPlate(string pl);
	void setMinsParked(int mins);
};

#endif