// file OCCCDate.h

#ifndef OCCCDATE_H
#define OCCCDATE_H
#include <iostream>
#include <string>

using namespace std;
class OCCCDate
{
  private:

    int dayOfMonth;
    int monthOfYear;
    int year;
    bool dateFormat;

  public:

    OCCCDate(); 
    OCCCDate(int day, int month, int year);
    int getDayofMonth(); 
    int getMonth();
    string getNameofMonth(); 
    int getYear(); 
    int getDifference(OCCCDate d1);
    int getDifference();
	void setDateFormat(bool df);
    bool equals(OCCCDate d);
    string toString();
};

#endif
