#include "BankAccount.h"

BankAccount::BankAccount() : BankAccount(0, 0)
{

}

BankAccount::BankAccount(double balance, double annualInterestRate)
{
	this->balance = balance;
	monthlyDeposits = 0;
	monthlyWithdraws = 0;
	this->annualInterestRate = annualInterestRate;
	monthlyServiceCharges = 0;
}

double BankAccount::getBalance() const
{
	return balance;
}

int BankAccount::getMonthlyDeposits() const
{
	return monthlyDeposits;
}

int BankAccount::getMonthlyWithdraws() const
{
	return monthlyWithdraws;
}

double BankAccount::getAnnualInterestRate() const
{
	return annualInterestRate;
}

double BankAccount::getMonthlyServiceCharges() const
{
	return monthlyServiceCharges;
}

void BankAccount::setAnnualInterestRate(double newRate)
{
	if (newRate >= 0)
		annualInterestRate = newRate;
}

void BankAccount::addServiceFee(double amount)
{
	monthlyServiceCharges += amount;
}

void BankAccount::instantServiceFee(double amount)
{
	balance -= amount;
}

void BankAccount::transfer(double amount, BankAccount& to)
{
	if (getBalance() >= amount)
	{
		withdraw(amount);
		to.deposit(amount);
	}
}

void BankAccount::deposit(double amount)
{
	balance += amount;
	monthlyDeposits++;
}

void BankAccount::withdraw(double amount)
{
	balance -= amount;
	monthlyWithdraws++;
}

void BankAccount::calcInt()
{
	if (balance > 0) // if balance is zero/negative, no interest is earned
	{
		double monthlyInterestRate = annualInterestRate / 12;
		double monthlyInterest = monthlyInterestRate * balance;
		balance += monthlyInterest;
	}
}

void BankAccount::monthlyProc()
{
	balance -= monthlyServiceCharges;
	calcInt();
	monthlyDeposits = 0;
	monthlyWithdraws = 0;
	monthlyServiceCharges = 0;
}

ostream& operator<<(ostream& strm, const BankAccount& obj)
{
	strm << fixed << showpoint << setprecision(2);
	strm << "Balance: $" << obj.balance << endl;
	strm << "Deposits this month: " << obj.monthlyDeposits << endl;
	strm << "Withdraws this month: " << obj.monthlyWithdraws << endl;
	strm << "Annual interest rate: " << static_cast<int>(obj.annualInterestRate * 100) << "%\n";
	strm << "Service charges for this month: $" << obj.monthlyServiceCharges << endl;
	strm << defaultfloat << noshowpoint << setprecision(6);
	return strm;
}