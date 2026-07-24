#include "Car.h"

Car::Car() : Vehicle() 
{
	passengerCapacity = 0;

}

Car::Car(string make, string model, int year, Mover* mover, int passengerCapacity) :
	Vehicle(make, model, year, mover), passengerCapacity(passengerCapacity) 
{

}

Car::Car(const Car& otherCar) : Vehicle(otherCar), passengerCapacity(otherCar.passengerCapacity) 
{

}

int Car::getPassengerCapacity() const 
{
	return passengerCapacity;
}

void Car::setPassengerCapacity(int passengerCapacity) 
{
	this->passengerCapacity = passengerCapacity;
}

string Car::move()
{
	string moving;
	moving += "A " + to_string(getYear());
	moving += " " + getMake();
	moving += " " + getModel();
	moving += " with " + to_string(getPassengerCapacity());
	moving += " passenger capacity ";
	moving += this->getMover()->move();
	return moving;
}

Car& Car::operator=(const Car& otherCar)
{
	if (this != &otherCar) 
	{
		delete this->getMover();
		this->setMake(otherCar.getMake());
		this->setModel(otherCar.getModel());
		this->setYear(otherCar.getYear());
		this->setMover(otherCar.getMover());
		this->passengerCapacity = otherCar.passengerCapacity;
	}
	return *this;
}

ostream& operator<<(ostream& strm, const Car& car)
{
	strm << "A " << car.getYear() << " "
		<< car.getMake() << " "
		<< car.getModel() << " " << car.getPassengerCapacity();
	return strm;
}