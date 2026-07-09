#pragma once
#include "Die.h"
#include <iostream>

class DiceConsole
{
public:
	void displayDie(Die* die);
	void displayDice(Die* dice, int size);
	int getUserChoice(string menu);
};

