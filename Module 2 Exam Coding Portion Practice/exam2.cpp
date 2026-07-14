#include <iostream>
#include "Date.h"
#include "Car.h"
using namespace std;

void demonstrateDate();
void demonstrateCar();

int main()
{
	demonstrateDate();
	demonstrateCar();
}

void demonstrateDate()
{
	Date date1;
	Date date2(2015, 10, 21);

	date1.printNumeric();
	date1.printFormal();
	date1.printEuro();

	cout << endl;

	date2.printNumeric();
	date2.printFormal();
	date2.printEuro();

	cout << endl;
}

void demonstrateCar()
{
	Car car;

	cout << "Speed of car in MPH: " << car.getSpeedInMPH() << endl;
	cout << "Speed of car in KPH: " << car.getSpeedInKPH() << endl;

	cout << "Speeding up..." << endl;
	car.accelerate();

	cout << "Speed of car in MPH: " << car.getSpeedInMPH() << endl;
	cout << "Speed of car in KPH: " << car.getSpeedInKPH() << endl;
	
	cout << "Speeding up..." << endl;
	car.accelerate();

	cout << "Speed of car in MPH: " << car.getSpeedInMPH() << endl;
	cout << "Speed of car in KPH: " << car.getSpeedInKPH() << endl;

	cout << "Slowing down..." << endl;
	car.brake();

	cout << "Speed of car in MPH: " << car.getSpeedInMPH() << endl;
	cout << "Speed of car in KPH: " << car.getSpeedInKPH() << endl;

	cout << "Slowing down..." << endl;
	car.brake();

	cout << "Speed of car in MPH: " << car.getSpeedInMPH() << endl;
	cout << "Speed of car in KPH: " << car.getSpeedInKPH() << endl;
}