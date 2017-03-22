//file SIS_HW5.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <time.h>
#include "OCCCPerson.h"

using namespace std;
	
	string newFn;
	string newLn, revisedLn, studentID;
	int newDay, newMonth, newYear, todayYear, todayMonth, todayDay;

int main()
{
	//Crate an instance of OCCCDate d1, using the current time
	OCCCDate d1 = OCCCDate();

	// Display the date d1 using d1.toString()
	cout <<"Current Date is: " << d1.toString() << endl;

	// create a new person object from user inputs
	
	cout<< "Enter person's first name" << endl;
	cin >> newFn;
	cin.ignore();
	
	cout<< "Enter person's last name" << endl;
	cin >> newLn;
	cin.ignore();
	
	cout << "Enter person's birth year" << endl;
	cin >> newYear;
	cin.ignore();
	
	cout << "Enter person's birth month" << endl;
	cin >> newMonth;
	cin.ignore();

	cout << "Enter person's birth day of the month" << endl;
	cin >> newDay;
	cin.ignore();

	OCCCDate d2 = OCCCDate(newDay, newMonth, newYear);

	// Display d2
	cout << "Implementation of d2 using toString() method: " << endl;
	cout << "The date entered is: "<< d2.toString() << endl;

	//input for today's date
	cout << "Enter today's year" << endl;
	cin >> todayYear;
	cin.ignore();
	
	cout << "Enter today's month" << endl;
	cin >> todayMonth;
	cin.ignore();

	cout << "Enter today's day of the month" << endl;
	cin >> todayDay;
	cin.ignore();

	OCCCDate d3 = OCCCDate(todayDay, todayMonth, todayYear);

	//Display result of d1.equals(d3)
	cout << "Dates d1 and d3 are same (true/false) : " << d1.equals(d3) << endl;

	// Create Persons p1, p2 and p3
	Person p1 = Person (newFn, newLn);
	Person p2 = Person (newFn, newLn, d2);
	Person p3 = Person(newFn, newLn, d3);

	//Display the first name, last name and age of p2
	cout << "Displaying First Name, Last Name and Age of person p2; " << endl;
	cout << "Name of the person p2 is: " << p2.getFirstName() << "," << p2.getLastName() << ", Age: " << p2.getAgeInYears() << endl;

	// Display results of p1.equals(p2)
	cout <<"Displaying results of p1.equals(p2) (true/false): " << endl;
	cout << p1.equals(p2) << endl;

	// Display results of p1.equals(p3)
	cout <<"Displaying results of p1.equals(p3) (true/false): " << endl;
	cout << p1.equals(p3) << endl;

	//Change Last name of p3
	cout << "Enter a new last name: " << endl;
	cin >> revisedLn;
	p3.setLastName(revisedLn);

	//Display new name for p3
	cout << "Displaying First Name and Last Name of revised person p3; " << endl;
	cout << "Name of the person p3 is: " << p3.toString() << endl;

	// Assign a student ID
	cout << "Enter a student ID for person p3 :" << endl;
	cin >> studentID;
	cin.ignore();

	//Create person p4
	OCCCPerson p4 = OCCCPerson(p3, studentID);

	//Create person p5
	
	OCCCPerson p5 = OCCCPerson(p3.getFirstName(), p3.getLastName(), d3, studentID);
	

	// Display results of p4.equals(p5)
	cout << "Person p4 and Person p5 are the same person (true/false): " << p4.equals(p5) << endl;

	// Create p6
	OCCCPerson p6 = OCCCPerson(p5);

	// Display results of p5.equals(p6)
	cout << "Person p5 and Person p6 are the same person (true/false): " << p5.equals(p6) << endl;

	//Change Last name of 6
	cout << "Enter a new last name: " << endl;
	cin >> revisedLn;
	p6.setLastName(revisedLn);

	//Display status of p5 and p6
	cout << "Person p5 is: " << p5.toString() << endl;
	cout << "Person p6 is: " << p6.toString() << endl;

	// Create p7 using p6 using a copy constructor
	OCCCPerson p7(p6);

	//Display resutls  result of p6.equals(p7)
	cout << "Results of p6.equals(p7): " << p6.equals(p7) <<endl;

	//Change Last name of 6
	cout << "Enter a new last name: " << endl;
	cin >> revisedLn;
	p6.setLastName(revisedLn);

	//Display the state of p6 and p7
	cout << "Person p6 is: " << p6.toString() << endl;
	cout << "Person p7 is: " << p7.toString() << endl;

	return EXIT_SUCCESS;
	
}

