// Josiah Potthast
// Daily Assignment 2.4: CoinFlipper

#include <iostream>
#include "Coin.h"
#include "CoinGame.h"
using namespace std;

void coinDriver(int flips = 20);

int main()
{
	CoinGame game;
	game.playGame();
}

void coinDriver(int flips)
{
	Coin penny;
	int headsTally = 0, tailsTally = 0;

	for (int i = 0; i < flips; i++)
	{
		penny.flip();
		cout << penny.getSideUp() << endl;
		if (penny.isItHeads())
			headsTally++;
		else
			tailsTally++;
	}

	cout << "\nTotals:" << endl;
	cout << "Heads: " << headsTally << endl;
	cout << "Tails: " << tailsTally << endl;
}