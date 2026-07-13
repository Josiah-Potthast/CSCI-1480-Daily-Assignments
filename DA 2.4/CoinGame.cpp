#include "CoinGame.h"

void CoinGame::printFlipResults() const
{
	for (int i = 0; i < numberOfCoins; i++)
	{
		switch (i)
		{
		case 0:
			cout << "Nickel landed on ";
			break;
		case 1:
			cout << "Dime landed on ";
			break;
		case 2:
			cout << "Quarter landed on ";
			break;
		default:
			cout << "Error! CoinGame cannot handle more than three coins" << endl;
		}
		cout << coins[i].getSideUp();
		if (coins[i].isItHeads())
			cout << " (+$" << coins[i].getCentValue() * 0.01 << ")" << endl;
		else
			cout << endl;
	}
}

void CoinGame::flipCoins()
{
	for (int i = 0; i < numberOfCoins; i++)
	{
		coins[i].flip();
	}
}

void CoinGame::printScore() const
{
	cout << "Your current score is $" << totalScore * 0.01 << endl;
}

int CoinGame::getRounds() const
{
	return rounds;
}

int CoinGame::getScore() const
{
	int score = 0;
	for (int i = 0; i < numberOfCoins; i++)
	{
		if (coins[i].isItHeads())
			score += coins[i].getCentValue();
	}
	return score;
}

CoinGame::CoinGame() : CoinGame(1.00)
{}

CoinGame::CoinGame(double target)
{
	numberOfCoins = 3;
	coins = new Coin[numberOfCoins]{ Coin(5), Coin(10), Coin(25) };
	targetBalance = target;
	totalScore = 0;
	rounds = 0;
}

CoinGame::~CoinGame()
{
	delete[] coins;
	coins = nullptr;
}

void CoinGame::playGame()
{
	cout << fixed << setprecision(2);
	cout << "Welcome to CoinFlipper!" << endl;
	cout << "Every round you flip three coins, and those that land\n"
		<< "on heads have their value added to your score." << endl;
	cout << "Your goal is to get exactly $" << targetBalance
		<< " no more, no less." << endl;

	while (totalScore < targetBalance * 100)
	{
		printScore();
		cout << "Press enter to flip coins." << endl;
		cin.get();
		cin.ignore(1000, '\n');
		cin.unget();
		cout << "Flipping a nickel, a dime, and a quarter..." << endl;
		flipCoins();
		rounds++;
		printFlipResults();
		totalScore += getScore();
	}

	if (totalScore == targetBalance * 100)
	{
		cout << "You win! You got exactly $" << targetBalance 
			<< " in " << rounds << " rounds!" << endl;
	}
	else if (totalScore > targetBalance * 100)
	{
		cout << "Too bad, you overshot the target score of $" << targetBalance << endl;
		cout << "Final Score: $" << totalScore * 0.01 << endl;
		cout << "Rounds Played: " << rounds << endl;
	}
}