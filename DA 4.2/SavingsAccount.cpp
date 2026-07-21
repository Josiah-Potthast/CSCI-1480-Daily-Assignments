#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : SavingsAccount(0, 0)
{

}

SavingsAccount::SavingsAccount(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate)
{
	if (balance >= 25)
		active = true;
	else
		active = false;
}

void SavingsAccount::transfer(double amount, BankAccount& to)
{
	if (active)
		BankAccount::transfer(amount, to);
}

void SavingsAccount::deposit(double amount)
{
	if (getBalance() + amount >= 25)
		active = true;
	BankAccount::deposit(amount);
}

void SavingsAccount::withdraw(double amount)
{
	if (active && getBalance() >= amount)
	{
		BankAccount::withdraw(amount);
		if (getMonthlyWithdraws() > 4)
			addServiceFee(1);
		if (getBalance() < 25)
			active = false;
	}
}

void SavingsAccount::monthlyProc()
{
	BankAccount::monthlyProc();
	if (getBalance() < 25)
		active = false;
}

ostream& operator<<(ostream& strm, const SavingsAccount& obj)
{
	if (obj.active)
		strm << "Active ";
	else
		strm << "Inactive ";
	strm << "savings account\n";
	strm << static_cast<BankAccount>(obj);
	return strm;
}