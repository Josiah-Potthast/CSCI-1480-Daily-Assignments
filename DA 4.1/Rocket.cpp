#include "Rocket.h"

Rocket::Rocket() : Mover()
{

}

Rocket::Rocket(double mph)
{
	setMPH(mph);
}

string Rocket::move()
{
	return "shoots through the air " + Mover::move();
}