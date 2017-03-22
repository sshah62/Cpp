//Person.cpp
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Person::Person()
{
	firstName = "None";
	lastName = "None";
	
}

//Constructor with only first and last name.  
Person::Person(string firstName, string lastName)
{
	this -> firstName = firstName;
	this -> lastName = lastName;
	
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

