#include "Coin.h"

Coin::Coin() : Coin(1)
{}

Coin::Coin(int value) : centValue(value)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(time(0));
		seeded = true;
	}
	flip();
}

void Coin::flip()
{
	isHeads = rand() % 2;
}

bool Coin::isItHeads() const
{
	if (isHeads)
		return true;
	else
		return false;
}

string Coin::getSideUp() const
{
	if (isHeads)
		return "Heads";
	else
		return "Tails";
}

int Coin::getCentValue() const
{
	return centValue;
}