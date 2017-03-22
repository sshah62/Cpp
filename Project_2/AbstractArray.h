#ifndef _ABSTRACTARRAY_H
#define _ABSTRACTARRAY_H

#include <iostream>
#include "Exception.h"



class ArrayException : public Exception
{
};

class ArrayMemoryException : public ArrayException
{
};

class ArrayBoundsException : public ArrayException
{
};

template <class DataType>
class AbstractArrayClass
{
	
public:
	virtual int size () const = 0;
	virtual DataType& operator[] (int k) = 0;
	
};
#endif // !_ABSTRACTARRAY_H
