#pragma once
#include "Die.h"

class DiceHand
{
private:
	int handSize;
	Die* dice = nullptr;
public:
	DiceHand(int s = 5);
	~DiceHand();
	int getHandSize() const;
	Die* getDie(int dieNum) const;
	void setHandSize(int s);
	void setDie(Die d, int dieNum);
	string displayDieHand();
	void rollDie(int dieNum);
	void rollAllDice();
};