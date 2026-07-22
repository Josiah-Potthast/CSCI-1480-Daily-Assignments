#include "Person.h"
#include "Movie.h"
#include "Color.h"
#include "Picture.h"
#include <vector>
#include <iostream>
using namespace std;

void movieDriver();
void colorDriver();

int main()
{
	movieDriver();
	colorDriver();
	cout << endl << CREEPER << endl;
}

void movieDriver()
{
	Person p1("William", "Shakespear", "long time ago");
	vector<Person> ps;
	ps.push_back(Person("John", "Cena", "not as long ago"));
	ps.push_back(Person("Dwain", "Johnson", "not as long ago"));

	Movie film("Movie: the film", p1, ps, 135);
	Movie sequal(film);
	sequal.setTitle("Movie: the sequal");
	sequal.setRuntime(140);

	cout << film << endl;
	cout << sequal << endl;

	cout << Movie::isLongMovie(film.getRuntime()) << endl;
	cout << Movie::isLongMovie(sequal.getRuntime()) << endl;

	cout << endl;
}

void colorDriver()
{
	cout << RED << endl;
	cout << YELLOW << endl;
	cout << BLUE << endl;
	cout << GREEN << endl;
	cout << PURPLE << endl;
	cout << TEAL << endl;
	cout << BLACK << endl;
	cout << WHITE << endl;
	cout << GRAY << endl;
}