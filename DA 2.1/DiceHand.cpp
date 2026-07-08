#include "DiceHand.h"

int DiceHand::getHandSize() const
{
	return handSize;
}

Die* DiceHand::getDie(int dieNum) const
{
	return (dice + dieNum - 1);
}

void DiceHand::setHandSize(int s)
{
	if (s > 0)
		handSize = s;
}

void DiceHand::setDie(Die d, int dieNum)
{
	dice[dieNum - 1] = d;
}

string DiceHand::displayDieHand()
{
	string handDescription;
	for (int i = 0; i < handSize - 1; i++)
	{
		handDescription += dice[i].dieDescription() += ", ";
	}

	handDescription += "and ";
	handDescription += dice[handSize - 1].dieDescription();

	return handDescription;
}

void DiceHand::rollDie(int dieNum)
{
	dice[dieNum - 1].roll();
}

void DiceHand::rollAllDice()
{
	for (int i = 0; i < handSize; i++)
		dice[i].roll();
}