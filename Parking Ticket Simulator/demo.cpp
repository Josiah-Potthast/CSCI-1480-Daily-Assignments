// Josiah Potthast
// Class Coding Practice: Parking Ticket Simulator

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
using namespace std;

int main()
{
	ParkedCar cars[] =
	{
		{"Mini", "Cooper", "Green", "ABC 123", 45},
		{"Toyota", "Sienna", "Red", "ABC 456", 75},
		{"Jeep", "Wrangler", "Grey", "ABC 789", 120}
	};

	ParkingMeter meters[] = { 60, 60, 0 };

	PoliceOfficer officer("John Doe", "1234");

	for (int i = 0; i < 3; i++)
		cout << officer.inspectCar(cars[i], meters[i]) << endl << endl;
}