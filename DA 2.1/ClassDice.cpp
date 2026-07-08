// Josiah Potthast
// Daily Assignment 2.1: Classes

#include <iostream>
#include "Die.h"
#include "DiceHand.h"
using namespace std;

const int DICE = 3;
const int SIDES = 6;
const int STARTING_SIDE = 1;

int main()
{
	// Declare the array of dice
	// Die dice[DICE];

	// Set the state of the dice
	/*for (int i = 0; i < DICE; i++)
	{
		dice[i].setNumberOfSides(SIDES);
		dice[i].setFaceValue(STARTING_SIDE);
	}*/

	// Roll the dice
	/*for (int i = 0; i < DICE; i++)
	{
		dice[i].roll();
	}*/

	DiceHand hand;

	cout << "You have " << hand.displayDieHand() << endl;
	cout << "Rolling all dice... " << endl;

	hand.rollAllDice();

	cout << "Now you have " << hand.displayDieHand() << endl;
	cout << "Rolling the first and last dice... " << endl;

	hand.rollDie(1);
	hand.rollDie(hand.getHandSize());

	cout << "Now you have " << hand.displayDieHand() << endl;
}