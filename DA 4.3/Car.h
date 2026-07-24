#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle
{
private:
	int passengerCapacity;
public:
	Car();
	Car(string make, string model, int year, Mover* mover, int passengerCapacity);
	Car(const Car& otherCar);

	int getPassengerCapacity() const;
	void setPassengerCapacity(int passengerCapacity);

	string move() override;

	Car& operator=(const Car& otherCar);

	friend ostream& operator<<(ostream& strm, const Car& car);
};

#endif