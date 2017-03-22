//OCCCPerson.cpp
#include "OCCCDate.h"
#include "Person.h"
#include "OCCCPerson.h"
#include <iostream>
#include <string>

using namespace std;
OCCCPerson::OCCCPerson(string firstName, string lastName, OCCCDate dob, string studentID):Person(firstName, lastName, dob)
{
	this -> studentID = studentID;
}
OCCCPerson::OCCCPerson(Person newPerson, string studentID)
{
	this-> studentID = studentID;
}

string OCCCPerson::getStudentID()
{
	return studentID;
}

bool OCCCPerson::equals(OCCCPerson p)
{
	Person tempPerson = Person(Person::getFirstName(), Person::getLastName(), Person::getDate());
	Person comparePerson = Person(p.getFirstName(), p.getLastName(), p.getDate());
			if(tempPerson.equals(comparePerson) && getStudentID() == p.getStudentID())
	{
		return true;
	}
	else
	{
		return false;
	}
}

string OCCCPerson::toString()
{
	string OCCCPersonString = this-> Person::toString();
	return OCCCPersonString + "," + getStudentID();
}
