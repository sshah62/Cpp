#include "String.h"
#include "ArrayClass.h"

String::String() : ArrayClass<char>(1, '\0')
{
}

String::String(int n) : ArrayClass<char>(n, '\0')
{
}

String::String(char* s) : ArrayClass<char>(strlen(s) + 1)
{
	strcpy(paObject, s);
}

// Copy Constructor
String::String(const String& str) : ArrayClass<char>(str)
{
}

//Destructor
String::~String() { }

//Assignment Operator
void String::operator= (const String& str)
{
	int max = str.length(); // not constructed by default
	bool overflow = false; 
	if (size() == 0) // constructed by default
	{
		ArrayClass<char>::operator= (str);
		// call parent operator
		return;
	}
		
	if (_size - 1 < max)
	{
		overflow = true;
		max = _size - 1;
		// note, we should replace _size-1 with size()
		// as soon as we implement size()
	}
	strncpy(paObject, str.paObject, max);
	paObject[max] = '\0'; // always null terminate!
	if (overflow) throw StringSizeException();
}

//Size method
int String::size() const
{
	return ArrayClass<char>::size() - 1;
}

//length()
int String::length() const
{
	return strlen(paObject);
}

//Overloaded == Operator
bool String::operator== (const String& str) const
{
	return (strcmp(paObject, str.paObject) == 0);
}

//Overloaded < Operator
bool String::operator < (const String& str) const
{
	return (strcmp(paObject, str.paObject) < 0);
}

//String Comparison (ingoring case)
bool String::equalsIgnoreCase(const String& str)
{
	return (stricmp(paObject, str.paObject));
}


void String::concatenate(const String& str)
{
	int len = length(); // store length() for efficiency’s sake
	int max = str.length();
	bool overflow = false;
	if (size() < max + len)
	{
		overflow = true;
		max = size() - len;
	}
	strncpy(paObject + len, str.paObject, max);
	paObject[max + len] = '\0'; // always null terminate!
	if (overflow) throw StringSizeException();
}

//Concatenate
void String::concatenate(const String& str)
{
	int len = length(); // store length() for efficiency
	int max = str.length();
	bool overflow = false;
	if (size() < max + len)
	{
		overflow = true;
		max = size() - len;
	}
	strncpy(paObject + len, str.paObject, max);
	paObject[max + len] = '\0'; // always null terminate!
	if (overflow) throw StringSizeException();
}

//Overloaded + operator
String :: operator+ (const String& str)
{
	String temp (length() + str.length());
	temp = (*this);
	temp.concatenate(str);
	return temp;
}

//Index of a particular character
int String::index(char c, int start) const
{
	// if start is past the end, obviously c isn’t present
	if (start >= length())
	{
		return -1;
	}
		
	char* pc = strchr(paObject + start, c);
	
	if (pc == NULL)
	{
		return –1;
	}
	return (pc - paObject);
}

//Substring function
String String::substring(int left, int len) const
{
	// a negative index is illegal
	if (left < 0)
	{
		throw ArrayBoundsException();
	}
	// no need to throw exception if left is at least
	// legal, if not actually in bounds

	String sub(len);
	if (left > length())
	{
		return sub;
	}
	int max = len;
	if (max + left > length())
	{
		max = length() - left;
		strncpy(sub.paObject, &paObject[left], max);
		sub.paObject[max] = '\0'; // always null terminate!
		return sub;
	}
	
}


//Overloaded ostream operator
ostream& operator<< (ostream& s, const String& str)
{
	s << str.paObject;
	return s;
}

//Index
int String::index(char c) const
{
	return index(c, 0);
}


