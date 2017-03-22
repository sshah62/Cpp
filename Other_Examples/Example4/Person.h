//Person.h

#ifndef Person_H
#define Person_H

#include <iostream>
#include <string>


using namespace std;
class Person
{
private: 
	string firstName;
	string lastName;


public:
	//default contstructor
	Person();   
	
	//consturctor with first and last name
	Person(string, string); 
	
	
	//get first name
	string getFirstName();

	//get last name
	string getLastName();

	//set first name
	void setFirstName(string);

	//set lastname
	void setLastName(string);


} ;
#endif