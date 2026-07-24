#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Motorcycle : public Vehicle
{
private:
	double engineCC;
public:
	Motorcycle();
	Motorcycle(string make, string model, int year, Mover* mover, double engineCC);
	Motorcycle(const Motorcycle& otherMotorcycle);

	double getEngineCC() const;
	void setEngineCC(double engineCC);

	string move() override;

	Motorcycle& operator=(const Motorcycle& otherMotorcycle);

	friend std::ostream& operator<<(std::ostream& strm, const Motorcycle& motorcycle);
};

#endif