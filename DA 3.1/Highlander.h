#ifndef HIGHLANDER_H
#define HIGHLANDER_H

#include <iostream>
#include <string>
using namespace std;

class Highlander
{
private:
	string name;
	static int count;
public:
	Highlander();
	Highlander(string n);
	Highlander(const Highlander& obj);
	~Highlander();
	string getName() const;
	void setName(string n);
	static string speak();
	string status() const;
};

#endif