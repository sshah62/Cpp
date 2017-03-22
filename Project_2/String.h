#ifndef _STRING_H
#define _STRING_H
#include "ArrayClass.h"
class StringSizeException : public ArrayException
{
};
class String : virtual public ArrayClass<char>
{
	friend ostream& operator<< (ostream& s, const String& str);
public:
	String();
	String(int n);
	String(const String& str);
	String(char* s);
	virtual ~String();
	void operator= (const String& str);
	virtual int length() const;
	virtual int size() const;
	bool operator== (const String& str) const;
	bool operator < (const String&str) const;
	void concatenate(const String& str);
	int index(char c, int start) const;
	int index(char c) const;
	//int lastIndex(char c, int start) const;
	//int lastIndex(char c) const;
	String substring(int left, int len) const;
	String operator+ (const String& str);
	bool equalsIgnoreCase(const String& str);
};
#endif //!_STRING_H