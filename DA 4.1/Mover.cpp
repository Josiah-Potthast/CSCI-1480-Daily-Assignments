#include "Mover.h"

Mover::Mover() : Mover(0)
{

}

Mover::Mover(double mph)
{
	this->mph = mph;
}

string Mover::move()
{
	string temp = to_string(mph); // includes zeros
	int i = temp.length() - 1; // last char in the string
	while (temp[i] == '0') // for each useless zero...
		i--; // ...reduce string size by one
	string speed(temp, 0, i + 1); // new string copies up through last significant digit
	if (speed[speed.length() - 1] == '.') // if no non-zero fraction...
		speed += '0'; // add zero after the decimal point
	return "at " + speed + " MPH";
}

double Mover::getMPH()
{
	return mph;
}

void Mover::setMPH(double mph)
{
	this->mph = mph;
}