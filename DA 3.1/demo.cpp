// Josiah Potthast
// Daily Assignment 3.1

#include <iostream>
#include <vector>
#include "Highlander.h"
#include "SuperIntArray.h"
using namespace std;

void highlanderDriver();
void superIntArrayDriver();
void arrayDisplayHelper(SuperIntArray nums);

int main()
{
	highlanderDriver();
	superIntArrayDriver();
}

void highlanderDriver()
{
	cout << Highlander::speak() << endl;

	vector<Highlander> highlanders = { Highlander("Connor MacLeod"), Highlander("The Kurgan") };
	cout << "Highlanders have appeared!" << endl;

	cout << Highlander::speak() << endl;

	do
	{
		for (int i = 0; i < highlanders.size(); i++)
			cout << highlanders[i].getName() << " is " << highlanders[i].status() << endl;
		cout << highlanders[highlanders.size() - 1].getName() << " has died" << endl;
		highlanders.pop_back();
		cout << Highlander::speak() << endl;
	} while (highlanders.size() > 1);
	cout << highlanders[0].getName() << " is " << highlanders[0].status() << endl << endl;
}

void superIntArrayDriver()
{	
	cout << "Creating SuperIntArray nums\n";
	SuperIntArray nums;
	for (int i = 0; i < 10; i++)
		nums.add(i * 2);
	cout << "nums:\n";
	arrayDisplayHelper(nums);

	cout << "Creating SuperIntArray copyNums by copying nums\n";
	SuperIntArray copyNums = nums;
	cout << "copyNums:\n";
	arrayDisplayHelper(copyNums);

	cout << "Adding 7 to the end of copyNums\n";
	copyNums.add(7);
	cout << "copyNums:\n";
	arrayDisplayHelper(copyNums);

	cout << "Which does not change nums\n";
	cout << "nums:\n";
	arrayDisplayHelper(nums);

	cout << "Setting index 9 of copyNums to 7\n";
	copyNums.change(9, 7);
	cout << "copyNums:\n";
	arrayDisplayHelper(copyNums);

	cout << "Still does not modify nums\n";
	cout << "nums:\n";
	arrayDisplayHelper(nums);
}

void arrayDisplayHelper(SuperIntArray nums)
{
	cout << "|------------------------------\n";
	for (int i = 0; i < nums.getNumberOfNums(); i++)
		cout << "|Index " << i << ": " << nums.get(i) << endl;
	cout << "|------------------------------\n";
	cout << "|Array max: " << SuperIntArray::getMax(nums.getNums(), nums.getNumberOfNums()) << endl;
	cout << "|Array min: " << SuperIntArray::getMin(nums.getNums(), nums.getNumberOfNums()) << endl;
	cout << "|Array average: " << SuperIntArray::getMean(nums.getNums(), nums.getNumberOfNums()) << endl;
	cout << "|------------------------------\n\n\n";
}