#pragma once
#include "Die.h"

class DiceHand
{
private:
	int handSize = 5;
	Die* dice = new Die[handSize];
public:
	int getHandSize() const;
	Die* getDie(int dieNum) const;
	void setHandSize(int s);
	void setDie(Die d, int dieNum);
	string displayDieHand();
	void rollDie(int dieNum);
	void rollAllDice();
};