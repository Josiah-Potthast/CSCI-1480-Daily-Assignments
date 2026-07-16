#ifndef SUPERINTARRAY_H
#define SUPERINTARRAY_H
#include <iostream>
#include <vector>
using namespace std;

class SuperIntArray
{
private:
	int* nums;
	int numberOfNums;
public:
	SuperIntArray();
	SuperIntArray(int numArray[], int size);
	SuperIntArray(int num);
	SuperIntArray(vector<int> numVect);
	SuperIntArray(const SuperIntArray& obj);
	~SuperIntArray();

	int* getNums() const;
	int getNumberOfNums() const;
	void setNums(int* newNums, int newSize);

	void add(int num);
	int get(int index) const;
	void change(int index, int newNum);

	static int getMax(int numArray[], int size);
	static int getMin(int numArray[], int size);
	static double getMean(int numArray[], int size);
};

#endif