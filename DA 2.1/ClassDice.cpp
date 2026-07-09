// Josiah Potthast
// Daily Assignment 2.1: Classes

#include <iostream>
#include "Die.h"
#include "DiceHand.h"
#include "DiceConsole.h"
using namespace std;

const int DICE = 3;
const int SIDES = 6;
const int STARTING_SIDE = 1;

int main()
{
	const int HAND_SIZE = 2;

	DiceHand hand(HAND_SIZE);

	DiceConsole console;

	cout << "Here are your dice:\n\n";

	console.displayDice(hand.getDie(), HAND_SIZE);

	bool done = false;
	int rollNum = 1;
	do
	{
		cout << "You have rolled the dice " << rollNum << " time";
		if (rollNum != 1)
			cout << "s";
		
		cout << "\nWould you like to re-roll or stay?\n";

		switch (console.getUserChoice("1. Re-roll\n2. Stay\n"))
		{
		case 1:
			hand.rollAllDice();
			rollNum++;
			cout << "\nHere are your new dice:\n\n";
			console.displayDice(hand.getDie(), HAND_SIZE);
			break;
		case 2:
			cout << "\nHere was your final roll:\n\n";
			console.displayDice(hand.getDie(), HAND_SIZE);
			done = true;
			break;
		default:
			cout << "That is not a valid choice, please enter 1 or 2\n";
		}
	} while (!done);
}