#include "Car.h"

Car::Car() : Car("Mini", "Cooper", 2014)
{

}

Car::Car(string ma, string mo, int yr)
{
	make = ma;
	model = mo;
	year = yr;
	speed = 0;
}

string Car::getMake()
{
	return make;
}

string Car::getModel()
{
	return model;
}

int Car::getYear()
{
	return year;
}

int Car::getSpeedInMPH()
{
	return speed;
}

double Car::getSpeedInKPH()
{
	return speed * MPH_TO_KPH;
}

void Car::setMake(string ma)
{
	make = ma;
}

void Car::setModel(string mo)
{
	model = mo;
}

void Car::setYear(int yr)
{
	year = yr;
}

void Car::accelerate()
{
	speed += ACCELERATION_AMOUNT;
}

void Car::brake()
{
	if (speed >= ACCELERATION_AMOUNT)
		speed -= ACCELERATION_AMOUNT;
	else
		speed = 0;
}