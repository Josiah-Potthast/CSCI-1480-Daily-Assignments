#include "Truck.h"

Truck::Truck() : Vehicle(), cargoCapacity(0.0) {}

Truck::Truck(string make, string  model, int year, Mover* mover, double  cargoCapacity) :
	Vehicle(make, model, year, mover), cargoCapacity(cargoCapacity)
{

}

Truck::Truck(const Truck& otherTruck) : Vehicle(otherTruck), cargoCapacity(otherTruck.cargoCapacity) {}

double Truck::getCargoCapacity() const
{
	return cargoCapacity;
}

void Truck::setCargoCapacity(double cargoCapacity)
{
	this->cargoCapacity = cargoCapacity;
}

string Truck::move()
{
	string moving;
	moving += "A " + to_string(getYear());
	moving += " " + getMake();
	moving += " " + getModel();
	moving += " with " + stringZeroKiller(getCargoCapacity());
	moving += " cargo capacity ";
	moving += this->getMover()->move();
	return moving;
}

Truck& Truck::operator=(const Truck& otherTruck)
{
	if (this != &otherTruck) 
	{
		Vehicle::operator=(otherTruck);
		cargoCapacity = otherTruck.cargoCapacity;
	}
	return *this;
}

ostream& operator<<(ostream& strm, const Truck& truck)
{
	strm << " A " << truck.getMake() << " " << truck.getModel() << " "
		<< truck.getYear() << " " << truck.getCargoCapacity();
	return strm;
}