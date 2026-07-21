#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iomanip>
#include <iostream>
using namespace std;

class BankAccount
{
private:
	double balance;
	int monthlyDeposits;
	int monthlyWithdraws;
	double annualInterestRate;
	double monthlyServiceCharges;
public:
	BankAccount();
	BankAccount(double balance, double annualInterestRate);

	double getBalance() const;
	int getMonthlyDeposits() const;
	int getMonthlyWithdraws() const;
	double getAnnualInterestRate() const;
	double getMonthlyServiceCharges() const;

	void setAnnualInterestRate(double newRate);
	void addServiceFee(double amount);
	void instantServiceFee(double amount);

	virtual void transfer(double amount, BankAccount& to);
	virtual void deposit(double amount);
	virtual void withdraw(double amount);
	virtual void calcInt();
	virtual void monthlyProc();

	friend ostream& operator<<(ostream& strm, const BankAccount& obj);
};

#endif