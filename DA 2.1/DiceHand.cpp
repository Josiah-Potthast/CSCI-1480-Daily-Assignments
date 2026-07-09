#include "DiceHand.h"

DiceHand::DiceHand(int size) : DiceHand(dice, size)
{

}

DiceHand::DiceHand(Die* d, int s)
{
	handSize = s;
	dice = new Die[s];
}

DiceHand::~DiceHand()
{
	delete[] dice;
	dice = nullptr;
}

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

//string DiceHand::displayDieHand()
//{
//	string handDescription;
//	for (int i = 0; i < handSize - 1; i++)
//	{
//		handDescription += dice[i].dieDescription() += ", ";
//	}
//
//	handDescription += "and ";
//	handDescription += dice[handSize - 1].dieDescription();
//
//	return handDescription;
//}

void DiceHand::rollDie(int dieNum)
{
	dice[dieNum - 1].roll();
}

void DiceHand::rollAllDice()
{
	for (int i = 0; i < handSize; i++)
		dice[i].roll();
}