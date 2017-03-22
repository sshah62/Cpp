//file SIS_HW2.cpp

#include <iostream>
#include <ctime>
#include <string>
#include "OCCCDate.h"
#include "Person.h"


using namespace std;

int main()
{
	//Create 2 date objects
	OCCCDate d1 = OCCCDate();
	OCCCDate d2 (03,23,1962);

	//Create Person Objects
	Person p1 = Person();
	Person p2 = Person("John", "Smith");
	Person p3 = Person ("jane", "Smith", d2);

	//test default person constructor and toString function
	cout << "Implementation of person created with default constructor - Person(), " << endl;
	cout << "default OCCCDate constructor - OCCCDate() and Person.toString() functions" <<endl;
	cout << p1.toString() << endl;
	
	cout << "Implementation of Person(string, string) constructor and Person.toString() functions:" << endl;
	cout << p2.toString() << endl;
	
	cout << "Implementation of Person(string, string, OCCCDate) constructor and Person.toString() functions:" << endl;
	cout << p3.toString() << endl;

	//test OCCCDate toString function
	cout << "OCCCDate.toString function:" << endl;
	cout << d1.toString() << endl;

	//test setDateFormat and toString function
	cout << "Implementation of OCCCDate.setDateFormat() and OCCCDate.toString() functions:" << endl;
	d1.setDateFormat(true);
	cout << d1.toString() << endl;

	//Test getters
	cout << "Implementation of Person.getFirstName() function: " << endl;
	cout << "Jane's First Name is " << p3.getFirstName() << endl;
	
	cout << "Implementation of Person.getLastName function: " << endl;
	cout << "Jane's Last Name is " << p3.getLastName() << endl;
	
	cout << "Implementation of Person.getAgeInYears() function: " <<endl;
	cout << "Jane's age is " << p3.getAgeInYears() << endl;

	//Test Person.equals() function
	cout << "Implementation of person.equals() function:" << endl;
	if (p1.equals(p2))
	{
		cout << "Person already in the system.  Use existing person?" << endl;
	}
	else
		cout << "Person not in the system.  Continue" << endl;

	//Test OCCCDate.equals() function
	cout << "Implementation of OCCCDate.equals() function:" << endl;
	if (d1.equals(d2))
	{
		cout << "p1 and p2 have the same birthday." << endl;
	}
	else
	{
		cout << p2.getFirstName() <<" and " << p3.getFirstName() << "do not have the same birthday" << endl;
	}

	// create a new person object
	string newFn;
	string newLn;
	int newDay;
	int newMonth;
	int newYear;
	Person newPerson;

	cout << "Implementation of Person.setFirstName() function:" << endl;
	cout<< "Enter person's first name" << endl;
	cin >> newFn;
	cin.ignore();
	newPerson.setFirstName(newFn);

	cout << "Implementation of Person.setLastName() function:" << endl;
	cout<< "Enter person's last name" << endl;
	cin >> newLn;
	cin.ignore();
	newPerson.setLastName(newLn);

	cout << "Implementation of OCCCDate(day, month, year) constructor" << endl;
	cout << "Enter person's birth year" << endl;
	cin >> newYear;
	cin.ignore();
	
	cout << "Enter person's birth month" << endl;
	cin >> newMonth;
	cin.ignore();

	cout << "Enter person's birth day of the month" << endl;
	cin >> newDay;
	cin.ignore();

	OCCCDate newDate = OCCCDate(newMonth, newDay, newYear);
	newPerson = Person (newFn, newLn, newDate);

	cout << "Implementation of Person(newFn, newLn, newDate) and OCCCDate(newMonth, newDay, newYear) constructors" << endl;
	cout << "You have entered following person to the list: " << newPerson.toString() << endl;

	return EXIT_SUCCESS;
}