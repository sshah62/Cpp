// file OCCCDate.cpp
#include "OCCCDate.h"
#include <string>
#include <iostream>
#include <time.h>
#include <sstream>

using namespace std;

time_t timeObject;
struct tm *timeNow;

//OCCCDate Object: default constructor
//Code from class notes and internet
OCCCDate:: OCCCDate()
{
	time(&timeObject);
	timeNow = localtime(&timeObject);
	dayOfMonth = timeNow ->tm_mday;
	monthOfYear = timeNow ->tm_mon + 1;
	year = timeNow ->tm_year + 1900;
}
//OCCCDate constructor with 3 parameters for day, month and year
OCCCDate::OCCCDate(int day, int month, int year){
	this -> dayOfMonth = day;
	this -> monthOfYear = month;
	this -> year = year;
}
//Getter for day of month from OCCCDate object
int OCCCDate::getDayofMonth()
{
	return dayOfMonth;
}

//Getter for month from OCCCDate object
int OCCCDate::getMonth()
{
	return monthOfYear;
}

//Getter for month name from OCCCDate object
string OCCCDate::getNameofMonth()
{
	switch(OCCCDate().getMonth())
	{
		case 1: "January"; 
				break;
		case 2: "Februay"; 
				break;
		case 3: "March"; 
				break;
		case 4: "April"; 
				break;
		case 5: "May"; 
				break;
		case 6: "June"; 
				break;
		case 7: "July"; 
				break;
		case 8: "August"; 
				break;
		case 9: "September"; 
				break;
		case 10: "October"; 
				break;
		case 11: "November"; 
				break;
		case 12: "December"; 
				break;
		default: 
			return "Error";
	}
}
//Getter for year from OCCCDate object
int OCCCDate::getYear()
{
	return year;
}

//Caculate elapsed time in years
int OCCCDate::getDifference(OCCCDate d1)
{
	OCCCDate rightnow;
	return abs (d1.getYear() + ((d1.getMonth() - 1)/12) + (d1.getDayofMonth()/365)) - (rightnow.getYear() +((rightnow.getMonth() - 1)/12) + (rightnow.getDayofMonth()/365));
	
}
//Calculate elapsed time in years from current time
int OCCCDate::getDifference()
{
	OCCCDate rightnow;
	return abs (rightnow.getYear() +((rightnow.getMonth()-1)/12) + (rightnow.getDayofMonth()/365)) - (getYear() + ((getMonth()-1)/12) + (getDayofMonth()/365));
}

//Set Date Format
void OCCCDate::setDateFormat(bool df)
{
	if (df)
	{
		dateFormat = false;
	}
	
}

//Compare dates (year, month and day)
bool OCCCDate::equals(OCCCDate d)
{
	if (d.getDayofMonth() == dayOfMonth && d.getMonth() == monthOfYear && d.getYear() == year)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Output formatted date string as mm/dd/YYYY or dd/mm/yyyy depending on value of dateFormat
//use stringstream
string OCCCDate::toString()
{
	string dMonth;
	string dYear;
	string dDay;
	stringstream sDay;
	stringstream sMonth;
	stringstream sYear;
	sDay << dayOfMonth;
	sDay >> dDay;
	sMonth << monthOfYear;
	sMonth >> dMonth;
	sYear << year;
	sYear >> dYear;
	if (dateFormat) 
	{
		//return the strings in american format
		return (dMonth + "/" + dDay + "/" + dYear);
	}
	else
	{
		// return the strings in European format
		return (dDay + "/" + dMonth + "/" + dYear);
	}
}