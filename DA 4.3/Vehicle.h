#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include "../DA 4.1/Mover.h"
#include "../DA 4.1/HoverDevice.h"
#include "../DA 4.1/Wheel.h"
#include "../DA 4.1/Skids.h"
#include "../DA 4.1/Rocket.h"

using namespace std;

class Mover;
class HoverDevice;
class Wheel;
class Skids;
class Rocket;

class Vehicle
{
private:
	string make;
	string model;
	int year;
	Mover* mover;
public:
	Vehicle();
	Vehicle(string make, string model, int year, Mover* mover);
	Vehicle(const Vehicle& otherVehicle);
	Vehicle(Mover* mover);
	virtual ~Vehicle();

	string getMake() const;
	string getModel() const;
	int getYear() const;
	Mover* getMover() const;

	void setMake(string make);
	void setModel(string model);
	void setYear(int year);
	void setMover(Mover* mover);

	virtual string move() = 0;

	Vehicle& operator=(const Vehicle& otherVehicle);

	friend ostream& operator<<(ostream& strm, const Vehicle& vehicle);


	static string stringZeroKiller(double num);
};

#endif