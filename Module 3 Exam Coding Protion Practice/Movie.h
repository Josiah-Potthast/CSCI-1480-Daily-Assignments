#ifndef MOVIE_H
#define MOVIE_H
#include "Person.h"
#include <vector>
#include <iostream>
using namespace std;

class Person;

class Movie
{
private:
	string title;
	Person director;
	vector<Person> cast;
	int runtime;
	const static int LONG_TIME = 135; // technically the longest runtime before being considered long
public:
	Movie();
	Movie(string title, Person director, vector<Person> cast, int runtime);
	Movie(const Movie& obj);
	~Movie();

	string getTitle() const;
	Person getDirector() const;
	vector<Person> getCast() const;
	Person getCastMember(int index) const;
	int getRuntime() const;

	void setTitle(string title);
	void setDirector(Person director);
	void setCast(vector<Person> cast);
	void setCastMember(int index, Person member);
	void setRuntime(int runtime);

	Movie& operator=(const Movie& right);
	friend ostream& operator<<(ostream& strm, const Movie& obj);

	static bool isLongMovie(int mins);
};

#endif