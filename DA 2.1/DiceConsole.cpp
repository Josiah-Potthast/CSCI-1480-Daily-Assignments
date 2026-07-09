#include "DiceConsole.h"

void DiceConsole::displayDie(Die* die)
{
	cout << "* * * *\n";
	cout << "*     *\n";
	cout << "*  " << die->getFaceValue() << "  *\n";
	cout << "*     *\n";
	cout << "* * * *\n";
}

void DiceConsole::displayDice(Die* dice, int size)
{
	for (int r = 1; r <= 5; r++)
	{
		for (int i = 0; i < size; i++)
		{
			switch (r)
			{
			case 1:
			case 5:
				cout << "* * * *\t\t";
				break;
			case 2:
			case 4:
				cout << "*     *\t\t";
				break;
			case 3:
				cout << "*  " << dice[i].getFaceValue() << "  *\t\t";
				break;
			}

			//displayDie(dice + i);
			//cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

int DiceConsole::getUserChoice(string menu)
{
	int choice;
	cout << menu;
	cin >> choice;
	return choice;
}