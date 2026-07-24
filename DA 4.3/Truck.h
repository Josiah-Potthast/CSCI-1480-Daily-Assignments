#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle
{
private:
    double cargoCapacity;
public:
    Truck();
    Truck(string make, string  model, int year, Mover* mover, double  cargoCapacity);
    Truck(const Truck& otherTruck);

    double getCargoCapacity() const;
    void setCargoCapacity(double cargoCapacity);

    string move() override;

    Truck& operator=(const Truck& otherTruck);

    friend ostream& operator<<(ostream& strm, const Truck& truck);
};
#endif