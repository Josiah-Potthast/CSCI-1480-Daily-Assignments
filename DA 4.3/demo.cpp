// Josiah Potthast
// Daily Assignment 4.3

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include <iostream>
using namespace std;

int main()
{
	Wheel wheel(35);
	Car car("Toyota", "Corola", 2011, &wheel, 5);
	cout << car.move() << endl;

	HoverDevice hover(75);
	Truck truck("Dodge", "Ram", 2062, &hover, 2000);
	cout << truck.move() << endl;

	Rocket rocket(150);
	Motorcycle motorcycle("Yamaha", "Rocket Bike", 2055, &rocket, 5000);
	cout << motorcycle.move() << endl;
}