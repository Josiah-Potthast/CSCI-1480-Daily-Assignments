// Josiah Potthast
// Daily Assignment 3.3: Time

#include "Time.h"
#include <iostream>
using namespace std;

void testTimeAddition();
void testTimeSubtraction();
void testTimeRelationalOperators();
void testTimeOutStreamOperator();
void testTimeIntegerConversion();

int main()
{
	testTimeAddition();
	testTimeSubtraction();
	testTimeRelationalOperators();
	testTimeOutStreamOperator();
	testTimeIntegerConversion();
	Time::stopwatch(Time(0, 0, 1, 30));
}

void testTimeAddition()
{
	cout << "Time Addition\n";
	cout << "-------------\n";

	Time time1(14, 45);
	Time time2(8, 30, 15);
	cout << time1 << endl;
	cout << time2 << endl;
	cout << time1 + time2 << endl;

	cout << "-------------\n";
	cout << endl;
}

void testTimeSubtraction()
{
	cout << "Time Subtraction\n";
	cout << "----------------\n";

	Time time1(12, 15);
	Time time2(5, 20, 30);
	cout << time1 << endl;
	cout << time2 << endl;
	cout << time1 - time2 << endl;

	cout << "----------------\n";
	cout << endl;
}

void testTimeRelationalOperators()
{
	cout << "Time Comparison\n";
	cout << "---------------\n";

	Time time1(6, 0);
	Time time2(8, 30);
	Time time3(8, 30, 0);
	Time time4(13, 0);

	cout << time1;
	if (time1 < time2)
		cout << " is less than ";
	else
		cout << " is not less than ";
	cout << time2 << endl;

	cout << time2;
	if (time2 == time3)
		cout << " is equal to ";
	else
		cout << " is not equal to ";
	cout << time3 << endl;

	cout << time3;
	if (time3 > time4)
		cout << " is greater than ";
	else
		cout << " is not greater than ";
	cout << time4 << endl;

	cout << time4;
	if (time4 <= time3)
		cout << " is less than or equal to ";
	else
		cout << " is not less than or equal to ";
	cout << time3 << endl;

	cout << time4;
	if (time4 >= time1)
		cout << " is greater than or equal to ";
	else
		cout << " is greater than or not equal to ";
	cout << time1 << endl;

	cout << "---------------\n";
	cout << endl;
}

void testTimeOutStreamOperator()
{
	cout << "Time Output\n";
	cout << "-----------\n";

	Time times[5];
	for (int i = 0; i < 5; i++)
	{
		times[i].setHours(i + 6);
		times[i].setMinutes((i % 4) * 15);
		cout << times[i] << endl;
	}

	cout << "-----------\n";
	cout << endl;
}

void testTimeIntegerConversion()
{
	cout << "Time Conversion\n";
	cout << "---------------\n";

	Time time(0, 5);
	int num = time;

	cout << time << " as time" << endl;
	cout << "is converted to" << endl;
	cout << num << " as int" << endl;

	cout << "---------------\n";
	cout << endl;
}