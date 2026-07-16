#include "SuperIntArray.h"

SuperIntArray::SuperIntArray() : SuperIntArray(nullptr, 0)
{}

SuperIntArray::SuperIntArray(int numArray[], int size)
{
	if (size > 0)
	{
		numberOfNums = size;
		nums = new int[numberOfNums];
		for (int i = 0; i < numberOfNums; i++)
			nums[i] = numArray[i];
	}
	else
	{
		numberOfNums = 0;
		nums = nullptr;
	}
}

SuperIntArray::SuperIntArray(int num) : SuperIntArray(new int(num), 1)
{}

SuperIntArray::SuperIntArray(vector<int> numVect)
{
	numberOfNums = numVect.size();
	nums = new int[numberOfNums];
	for (int i = 0; i < numberOfNums; i++)
		nums[i] = numVect[i];
}

SuperIntArray::SuperIntArray(const SuperIntArray& obj)
{
	numberOfNums = obj.numberOfNums;
	nums = new int[obj.numberOfNums];
	for (int i = 0; i < numberOfNums; i++)
		nums[i] = obj.nums[i];
}

SuperIntArray::~SuperIntArray()
{
	delete[] nums;
	nums = nullptr;
}

int* SuperIntArray::getNums() const
{
	return nums;
}

int SuperIntArray::getNumberOfNums() const
{
	return numberOfNums;
}

void SuperIntArray::setNums(int* newNums, int newSize)
{
	delete[] nums;
	nums = nullptr;
	numberOfNums = newSize;
	nums = new int[numberOfNums];
	for (int i = 0; i < numberOfNums; i++)
		nums[i] = newNums[i];
}

void SuperIntArray::add(int num)
{
	numberOfNums++;
	int* tempNums = new int[numberOfNums];
	for (int i = 0; i < numberOfNums - 1; i++)
		tempNums[i] = nums[i];
	tempNums[numberOfNums - 1] = num;
	delete[] nums;
	nums = tempNums;
	tempNums = nullptr;
}

int SuperIntArray::get(int index) const
{
	return nums[index];
}

void SuperIntArray::change(int index, int newNum)
{
	nums[index] = newNum;
}

int SuperIntArray::getMax(int numArray[], int size)
{
	int max = numArray[0];
	for (int i = 1; i < size; i++)
		if (numArray[i] > max)
			max = numArray[i];
	return max;
}

int SuperIntArray::getMin(int numArray[], int size)
{
	int min = numArray[0];
	for (int i = 1; i < size; i++)
		if (numArray[i] < min)
			min = numArray[i];
	return min;
}

double SuperIntArray::getMean(int numArray[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
		total += numArray[i];
	return total / size;
}