#include "Vehicle.h"

Vehicle::Vehicle() : Vehicle("unknown", "unknown", 0, nullptr)
{
	
}

Vehicle::Vehicle(string make, string model, int year, Mover* mover)
{
	this->make = make;
	this->model = model;
	this->year = year;

	this->setMover(mover);
}

Vehicle::Vehicle(const Vehicle& otherVehicle) : 
	Vehicle(otherVehicle.getMake(), otherVehicle.getModel(), otherVehicle.getYear(), otherVehicle.getMover())
{
	
}

Vehicle::Vehicle(Mover* mover) : Vehicle("unknown", "unknown", 0, mover)
{

}

Vehicle::~Vehicle()
{
	delete mover;
	mover = nullptr;
}

string Vehicle::getMake() const
{
	return make;
}

string Vehicle::getModel() const
{
	return model;
}

int Vehicle::getYear() const
{
	return year;
}

Mover* Vehicle::getMover() const
{
	return mover;
}

void Vehicle::setMake(string make)
{
	this->make = make;
}

void Vehicle::setModel(string model)
{
	this->model = model;
}

void Vehicle::setYear(int year)
{
	this->year = year;
}

void Vehicle::setMover(Mover* mover)
{
	delete this->mover;
	
	if (this->mover = dynamic_cast<HoverDevice*>(mover))
		this->mover = new HoverDevice(mover->getMPH());
	else if (this->mover = dynamic_cast<Wheel*>(mover))
		this->mover = new Wheel(mover->getMPH());
	else if (this->mover = dynamic_cast<Skids*>(mover))
		this->mover = new Skids(mover->getMPH());
	else if (this->mover = dynamic_cast<Rocket*>(mover))
		this->mover = new Rocket(mover->getMPH());
	else if (mover == nullptr)
		this->mover = nullptr;
	else throw "Mover type does not exist";
}

Vehicle& Vehicle::operator=(const Vehicle& otherVehicle)
{
	if (this != &otherVehicle)
	{
		this->make = otherVehicle.make;
		this->model = otherVehicle.model;
		this->year = otherVehicle.year;
		this->setMover(otherVehicle.getMover());
	}
	return *this;
}

std::ostream& operator<<(std::ostream& strm, const Vehicle& vehicle)
{
	strm << "A " << vehicle.getYear() << " "
		<< vehicle.getMake() << " "
		<< vehicle.getModel();
	return strm;
}

string Vehicle::stringZeroKiller(double num)
{
	string temp = to_string(num); // includes zeros
	int i = temp.length() - 1; // last char in the string
	while (temp[i] == '0') // for each useless zero...
		i--; // ...reduce string size by one
	string result(temp, 0, i + 1); // new string copies up through last significant digit
	if (result[result.length() - 1] == '.') // if no non-zero fraction...
		result += '0'; // add zero after the decimal point
	return result;
}