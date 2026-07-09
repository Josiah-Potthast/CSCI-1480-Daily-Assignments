#pragma once
#include "Die.h"

class DiceHand
{
private:
	int handSize;
	Die* dice;
public:
	DiceHand(int s = 5);
	DiceHand(Die* d, int s);
	~DiceHand();
	int getHandSize() const;
	Die* getDie(int dieNum = 1) const;
	void setHandSize(int s);
	//string displayDieHand();
	void rollDie(int dieNum);
	void rollAllDice();
};