#pragma once
#include <iostream>
#include <iomanip>
#include "Coin.h"
class CoinGame
{
private:
	Coin* coins;
	int numberOfCoins;
	double targetBalance;
	int totalScore;
	int rounds;

	void printFlipResults() const;
	void flipCoins();
public:
	void printScore() const;
	int getRounds() const;
	int getScore() const;
	CoinGame();
	CoinGame(double target);
	~CoinGame();
	void playGame();
};

