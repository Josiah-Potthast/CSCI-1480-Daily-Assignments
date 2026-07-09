#include "DiceConsole.h"

void DiceConsole::displayDie(Die* die)
{
	cout << "* * * *\n"
		<< "*     *\n"
		<< "*  " << die->getFaceValue() << "  *\n"
		<< "*     *\n"
		<< "* * * *\n";
}

void DiceConsole::displayDice(Die* dice, int size)
{
	for (int i = 0; i < size; i++)
	{
		displayDie(dice + i);
		cout << endl;
	}
}

int DiceConsole::getUserChoice(string menu)
{
	int choice;
	cout << menu;
	cin >> choice;
	return choice;
}