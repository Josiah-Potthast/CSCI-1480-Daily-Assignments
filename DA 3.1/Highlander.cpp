#include "Highlander.h"

Highlander::Highlander()
{
	name = "Nameless Highlander";
	count++;
}

Highlander::Highlander(string n)
{
	name = n;
	count++;
}

Highlander::Highlander(const Highlander& obj)
{
	name = obj.name;
	count++;
}

Highlander::~Highlander()
{
	count--;
}

string Highlander::getName() const
{
	return name;
}

void Highlander::setName(string n)
{
	name = n;
}

string Highlander::speak()
{
	return "There can be only one. But now there are " + to_string(count);
}

string Highlander::status() const
{
	string status;
	if (count == 1)
		status = "Immortal";
	if (count > 1)
		status = "Murderous";
	if (count < 1)
		status = "Confused";
	return status;
}

int Highlander::count = 0;