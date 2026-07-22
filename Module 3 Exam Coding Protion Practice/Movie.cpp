#include "Movie.h"

Movie::Movie() : Movie("", Person(), vector<Person>(), 0)
{

}

Movie::Movie(string title, Person director, vector<Person> cast, int runtime)
{
	this->title = title;
	this->director = director;
	this->cast = cast;
	this->runtime = runtime;
}

Movie::Movie(const Movie& obj)
{
	title = obj.title;
	director = obj.director;
	cast = obj.cast;
	runtime = obj.runtime;
}

Movie::~Movie()
{

}

string Movie::getTitle() const
{
	return title;
}

Person Movie::getDirector() const
{
	return director;
}

vector<Person> Movie::getCast() const
{
	return cast;
}

Person Movie::getCastMember(int index) const
{
	if (index >= 0 && index < cast.size())
		return cast[index];
}

int Movie::getRuntime() const
{
	return runtime;
}

void Movie::setTitle(string title)
{
	this->title = title;
}

void Movie::setDirector(Person director)
{
	this->director = director;
}

void Movie::setCast(vector<Person> cast)
{
	this->cast = cast;
}

void Movie::setCastMember(int index, Person member)
{
	if (index >= 0 && index < cast.size())
		cast[index] = member;
}

void Movie::setRuntime(int runtime)
{
	this->runtime = runtime;
}


Movie& Movie::operator=(const Movie& right)
{
	if (this != &right)
	{
		title = right.title;
		director = right.director;
		cast = right.cast;
		runtime = right.runtime;
	}
	return *this;
}

ostream& operator<<(ostream& strm, const Movie& obj)
{
	strm << "Title: " << obj.title << endl;
	strm << "Director: " << obj.director << endl;
	strm << "Cast: \n";
	for (int i = 0; i < obj.cast.size(); i++)
		strm << "  " << obj.cast[i] << endl;
	strm << "Runtime: " << obj.runtime << endl;
	return strm;
}

bool Movie::isLongMovie(int mins)
{
	return mins > LONG_TIME;
}