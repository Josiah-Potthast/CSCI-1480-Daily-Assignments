// Josiah Potthast
// Daily Assignment 4.2: Bank Account

#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
using namespace std;

void accountDriver();

int main()
{
	double input;
	int menuChoice;

	cout << "How much money do you want to deposit into your new savings account?\n";
	cin >> input;
	SavingsAccount savings(input, 0.05);
	cout << "How much money do you want to deposit into your new checking account?\n";
	cin >> input;
	CheckingAccount checking(input, 0.01);

	cout << endl;
	cout << "Savings at the start of the month\n";
	cout << savings << endl;
	cout << "Checking at the start of the month\n";
	cout << checking << endl;

	do
	{
		cout << "1. Deposit into savings\n";
		cout << "2. Deposit into checking\n";
		cout << "3. Withdraw from savings\n";
		cout << "4. Withdraw from checking\n";
		cout << "5. Transfer from savings to checking\n";
		cout << "6. Transfer from checking to savings\n";
		cout << "7. Display savings\n";
		cout << "8. Display checking\n";
		cout << "9. End month\n";
		cout << "Choice: ";
		cin >> menuChoice;
		cin.ignore(1000, '\n');

		if (menuChoice >= 1 && menuChoice <= 6)
		{
			cout << "How much? ";
			cin >> input;
		}

		switch (menuChoice)
		{
		case 1:
			savings.deposit(input);
			break;
		case 2:
			checking.deposit(input);
			break;
		case 3:
			savings.withdraw(input);
			break;
		case 4:
			checking.withdraw(input);
			break;
		case 5:
			savings.transfer(input, checking);
			break;
		case 6:
			checking.transfer(input, savings);
			break;
		case 7:
			cout << endl << savings << endl;
			break;
		case 8:
			cout << endl << checking << endl;
			break;
		case 9:
			break;
		default:
			cout << "Choice invalid\n";
		}

	} while (menuChoice != 9);

	cout << "Savings at the end of the month (before monthlyProc)\n";
	cout << savings << endl;
	cout << "Checking at the end of the month (before monthlyProc)\n";
	cout << checking << endl;
	savings.monthlyProc();
	checking.monthlyProc();
	cout << "Savings at the end of the month (after monthlyProc)\n";
	cout << savings << endl;
	cout << "Checking at the end of the month (after monthlyProc)\n";
	cout << checking << endl;
}

void accountDriver()
{
	CheckingAccount checking(500, 0.02);
	SavingsAccount savings(10000, 0.05);
	const double SALARY = 40000;
	const double REDUCED_SPENDING = 200;

	for (int month = 1; month <= 12; month++)
	{
		savings.deposit(SALARY / 12);

		cout << "======================================\n";
		cout << "Savings at the start of month " << month << endl;
		cout << savings << endl;
		cout << "Checking at the start of month " << month << endl;
		cout << checking;

		double weeklySpending = 1000;
		for (int week = 1; week <= 4; week++)
		{
			savings.transfer(weeklySpending, checking);

			if (checking.getBalance() >= weeklySpending)
				checking.withdraw(weeklySpending);
			else if (savings.getBalance() >= weeklySpending)
			{
				savings.transfer(weeklySpending, checking);
				checking.withdraw(weeklySpending);
			}
			else
			{
				weeklySpending = REDUCED_SPENDING;
				if (checking.getBalance() >= REDUCED_SPENDING)
					checking.withdraw(REDUCED_SPENDING);
				else
				{
					savings.transfer(REDUCED_SPENDING, checking);
					checking.withdraw(REDUCED_SPENDING);
				}
			}

			if (weeklySpending != REDUCED_SPENDING)
			{
				for (int day = 1; day <= 7; day++)
				{
					savings.transfer(weeklySpending / 100, checking);
					checking.withdraw(weeklySpending / 100);
				}
			}
		}

		cout << "--------------------------------------\n";
		cout << "Savings at the end of month " << month << endl;
		cout << savings << endl;
		cout << "Checking at the end of month " << month << endl;
		cout << checking;
		cout << "======================================\n\n\n";

		savings.monthlyProc();
		checking.monthlyProc();
	}
}