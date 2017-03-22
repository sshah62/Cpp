//Person.cpp
//#include "OCCCDate.h"
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Person::Person()
{
	firstName = "None";
	lastName = "None";
	dob = OCCCDate();
}

//Constructor with only first and last name.  dob will be set to default - current date
Person::Person(string firstName, string lastName)
{
	this -> firstName = firstName;
	this -> lastName = lastName;
	dob = OCCCDate();
}
//constructor with all 3 parameters
Person::Person(string firstName, string lastName, OCCCDate dob)
{
	this -> firstName = firstName;
	this -> lastName = lastName;
	this -> dob = dob;
}
//getter for firstName
string Person::getFirstName()
{
	return firstName;
}

//getter for lastName
string Person::getLastName()
{
	return lastName;
}

//setter for firstName
void Person::setFirstName(string fn)
{
	firstName = fn;
}

//setter for lastName
void Person::setLastName(string ln)
{
	lastName = ln;
}

//getter for dob
OCCCDate Person::getDate()
{
	return dob;
}

//getter for person's age
int Person::getAgeInYears()
{
	return dob.getDifference();	
}

string toUpperCase(string s1)
{
	string result = s1;
	for (int i = 0; i <result.length(); ++i)
	{
		if(islower(result[i]))
		{
			result[i] += 'A' - 'a';
		}
	}
return result;
}



//compare a person object with another person object
bool equalsIgnoresCase(string s1, string s2)
{	
	return toUpperCase(s1) == toUpperCase(s2);	
}

//Creates a string output of a person's name and dob
string Person::toString()
{
	return (getLastName() + ", " + getFirstName() + ", (" + getDate().toString() + ")" );
}

bool Person::equals(Person p) {
	if(p.getFirstName() == this->firstName &&
		p.getLastName() == this->lastName &&
		this->dob.equals(p.dob)) {
		return true;
	}
	else 
	{
		return false;
	}
}


