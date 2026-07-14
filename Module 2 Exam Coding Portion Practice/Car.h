#pragma once
#include <iostream>
using namespace std;

class Car
{
private:
	string make;
	string model;
	int year;
	int speed;
	const double MPH_TO_KPH = 1.60934;
	const int ACCELERATION_AMOUNT = 5;
public:
	Car();
	Car(string ma, string mo, int yr);
	string getMake();
	string getModel();
	int getYear();
	int getSpeedInMPH();
	double getSpeedInKPH();
	void setMake(string ma);
	void setModel(string mo);
	void setYear(int yr);
	void accelerate();
	void brake();
};

