#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle(), engineCC(0.0) {}

Motorcycle::Motorcycle(string make, string model, int year, Mover* mover, double engineCC)
    : Vehicle(make, model, year, mover), engineCC(engineCC)
{

}

Motorcycle::Motorcycle(const Motorcycle& otherMotorcycle) : Vehicle(otherMotorcycle), engineCC(otherMotorcycle.engineCC)
{
    
}

double Motorcycle::getEngineCC() const
{
    return engineCC;
}

void Motorcycle::setEngineCC(double engineCC)
{
    this->engineCC = engineCC;
}

string Motorcycle::move()
{
    string moving;
    moving += "A " + to_string(getYear());
    moving += " " + getMake();
    moving += " " + getModel();
    moving += " with " + stringZeroKiller(getEngineCC());
    moving += " engine CC ";
    moving += this->getMover()->move();
    return moving;
}

Motorcycle& Motorcycle::operator=(const Motorcycle& otherMotorcycle)
{
    if (this != &otherMotorcycle)
    {
        delete this->getMover();
        this->setMake(otherMotorcycle.getMake());
        this->setModel(otherMotorcycle.getModel());
        this->setYear(otherMotorcycle.getYear());
        this->setMover(otherMotorcycle.getMover());
        this->engineCC = otherMotorcycle.engineCC;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& strm, const Motorcycle& motorcycle)
{
    strm << "Make: " << motorcycle.getMake()
        << ", Model: " << motorcycle.getModel()
        << ", Year: " << motorcycle.getYear()
        << ", Engine CC: " << motorcycle.engineCC;
    return strm;
}