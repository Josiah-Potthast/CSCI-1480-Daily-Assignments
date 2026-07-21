#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <iostream>
using namespace std;

class SavingsAccount : public BankAccount
{
private:
	bool active;
public:
	SavingsAccount();
	SavingsAccount(double balance, double annualInterestRate);

	void transfer(double amount, BankAccount& to) override;
	void deposit(double amount) override;
	void withdraw(double amount) override;
	void monthlyProc() override;

	friend ostream& operator<<(ostream& strm, const SavingsAccount& obj);
};

#endif