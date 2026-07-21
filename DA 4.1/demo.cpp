// Josiah Potthast
// Daily Assignment 4.1

#include "Mover.h"
#include "HoverDevice.h"
#include "Wheel.h"
#include "Skids.h"
#include "Rocket.h"
#include <iomanip>
#include <iostream>
using namespace std;

void moverDriver();

int main()
{
	moverDriver();
}

void moverDriver()
{
	HoverDevice hoverboard(25.1);
	Wheel tire(45.45);
	Skids seaplane(33.3333);
	Rocket jet(100);

	cout << "Hoverboard " << hoverboard.move() << endl;
	cout << "Tire " << tire.move() << endl;
	cout << "Seaplane " << seaplane.move() << endl;
	cout << "Jet " << jet.move() << endl;
}