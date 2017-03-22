#ifndef OCCCPerson_H
#define OCCCPerson_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;
class OCCCPerson: public Person
{
protected:
	string studentID;
	

public:
	//default contstructor
	OCCCPerson();   
	
	//consturctor with first and last name
	OCCCPerson(string, string); 
	
	//consturctor with first name, last name, date of birth and student ID
	OCCCPerson (string , string , OCCCDate, string);

	//Constructor with Person and student id
	OCCCPerson(Person, string);
	
	string getStudentID();
	bool equals(OCCCPerson);
	string toString();
} ;
#endif