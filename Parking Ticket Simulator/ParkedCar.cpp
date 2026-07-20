#include "ParkedCar.h"

ParkedCar::ParkedCar() : ParkedCar("", "", "", "", 0)
{

}

ParkedCar::ParkedCar(string ma, string mo, string co, string pl, int mins)
{
	make = ma;
	model = mo;
	color = co;
	plate = pl;
	minsParked = mins;
}

string ParkedCar::getMake() const
{
	return make;
}

string ParkedCar::getModel() const
{
	return model;
}

string ParkedCar::getColor() const
{
	return color;
}

string ParkedCar::getPlate() const
{
	return plate;
}

int ParkedCar::getMinsParked() const
{
	return minsParked;
}

void ParkedCar::setMake(string ma)
{
	make = ma;
}

void ParkedCar::setModel(string mo)
{
	model = mo;
}

void ParkedCar::setColor(string co)
{
	color = co;
}

void ParkedCar::setPlate(string pl)
{
	plate = pl;
}

void ParkedCar::setMinsParked(int mins)
{
	minsParked = mins;
}