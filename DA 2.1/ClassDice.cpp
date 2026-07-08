// Josiah Potthast
// Daily Assignment 2.1: Classes

#include <iostream>
#include "Die.h"
using namespace std;

const int DICE = 3;
const int SIDES = 6;
const int STARTING_SIDE = 1;

int main()
{
	// Declare the array of dice
	Die dice[DICE];

	// Set the state of the dice
	for (int i = 0; i < DICE; i++)
	{
		dice[i].setNumberOfSides(SIDES);
		dice[i].setFaceValue(STARTING_SIDE);
	}

	for (int i = 0; i < DICE; i++)
	{
		dice[i].roll();
	}

	cout << "You rolled ";

	for (int i = 0; i < DICE - 1; i++)
	{
		cout << dice[i].dieDescription() << ", ";
	}

	cout << "and " << dice[DICE - 1].dieDescription() << endl;
}