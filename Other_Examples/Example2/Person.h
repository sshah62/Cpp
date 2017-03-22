//Person.h

#ifndef Person_H
#define Person_H

#include <iostream>
#include <string>
#include "OCCCDate.h"

using namespace std;
class Person
{
private: 
	string firstName;
	string lastName;
	OCCCDate dob;

public:
	//default contstructor
	Person();   
	
	//consturctor with first and last name
	Person(string, string); 
	
	//consturctor with first name, last name and date of birth
	Person (string, string, OCCCDate);
	
	//get first name
	string getFirstName();

	//get last name
	string getLastName();

	//set first name
	void setFirstName(string);

	//set lastname
	void setLastName(string);

	//get dob of a person
	OCCCDate getDate();

	//get age 
	int getAgeInYears();

	//compares two person objects
	bool equals(Person);

	//output “Lastname, Firstname (dob)”
	string toString();
} ;
#endif