#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() : CheckingAccount(0, 0)
{

}

CheckingAccount::CheckingAccount(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate)
{
	addServiceFee(5);
}

void CheckingAccount::transfer(double amount, BankAccount& to)
{
	if (getBalance() >= amount)
	{
		BankAccount::transfer(amount, to);
	}
	else
		instantServiceFee(15);
}

void CheckingAccount::withdraw(double amount)
{
	if (getBalance() > amount)
	{
		BankAccount::withdraw(amount);
		addServiceFee(0.10);
	}
	else
		instantServiceFee(15);
}

void CheckingAccount::monthlyProc()
{
	BankAccount::monthlyProc();
	addServiceFee(5);
}