//Vector Methods
//Empty constructor
#include "Vector.h"

template <class DataType>
Vector<DataType>::Vector() : ArrayClass<DataType>()
{
	_currSize = 0;
	_incFactor = 5;
}

//Constructor Vector(int)
template <class DataType>
Vector <DataType> :: Vector(int n) : ArrayClass<DataType>(n)
{
	_currSize = 0;
	_incFactor = (n + 1) / 2;
}

//constructor Vector(int n, DataType)
template <class DataType>
Vector<DataType>::Vector(int n, DataType& val) : ArrayClass<DataType>(n, val)
{
	_currSize = 0;
	_incFactor = n / 2;
}

//destructor
template <class DataType>
Vector <DataType>::~Vector()
{

}

//Constructor
template <class DataType>
Vector<DataType>::Vector(const Vector<DataType>& v) : ArrayClass <DataType> (v)
{
	_currSize = v._currSize;
	_incFactor = v.incFactor();
}

//Constructor
template <class DataType>
Vector<DataType>::Vector(const ArrayClass <DataType>& ac) : ArrayClass <DataType> (ac)
{
	_currSize = ac.size();
	_incFactor = (_currSize + 1) / 2;
}

//constructor using overloaded assignment operator
template <class DataType>
void Vector<DataType>::operator= (const Vector<DataType>& v)
{
	ArrayClass<DataType>::copy(v);
	_currSize = v._currSize;
	_incFactor = v.incFactor();
}

//constructor for overloading assignment operator for ArrayClass objects
template <class DataType>
void Vector<DataType>::operator= (const ArrayClass<DataType>& ac)
{
	ArrayClass<DataType>::copy(ac);
	_currSize = ac.size();
	_incFactor = (_currSize + 1) / 2;
}

//Size method
template <class DataType>
int Vector<DataType>::size() const
{
	return _currSize;
}

//Capacity Method
template <class DataType>
int Vector <DataType> ::capacity() const
{
	return _size();
}

//find current increment factor
template <class DataType>
int Vector <DataType> ::incFactor() const
{
	return _incFactor;
}

//set increment factor
template <class DataType>
void Vector<DataType>::setIncFactor(int f)
{
	if (f >= 0)
	{
		_incFactor = f;
	}
}

//set capacity
template <class DataType>
void Vector <DataType>::setCapacity(int c)
{
	int len = _currSize;
	if (len > c)
	{
		len = c;
	}
	DataType* paNew = new DataType[c];
	if (paNew == NULL)
	{
		throw ArrayMemoryException();
	}
	for (int i = 0; i < len; ++i)
	{
		paNew[i] = paObject[i];
	}
	if (paObject != NULL)
	{
		delete[] paObject;
	}
	paObject = paNew;
	_size = c;
	if (_currSize > len)
	{
		_currSize = len;
	}
}

//insert method (for increas the _currSize)
template <class DataType>
void Vector <DataType> ::insert(const DataType& item, int index)
{
	if ((index < 0) || (index > _currSize))
	{
		throw ArrayBoundsException();
	}
	if (_currSize + 1 == _size)
	{
		setCapacity(_size + _incFactor);
	}
	_currSize++;
	
	for (int i = _currSize + 1; i > index; i--)
	{
		(*this)[i] = (*this)[i - 1];
	}
	(*this)[index] = item;
}

//add at the end of current vector i.e at position _currSize
template <class DataType>
void Vector <DataType> ::add(const DataType& item)
{
	insert(item, _currSize);
}

//Remove method.  
template <class DataType>
void Vector<DataType> ::remove(int index)
{
	if ((index < 0) || (index >= _currSize))
	{
		throw ArrayBoundsException
	}
	if (_currSize <= _size - _incFactor)
	{
		setCapacity(_size - _incFactor);
	}
	for (int i = index; i < _currSize - 1; i++)
	{
		(*this)[i] = (*this)[i + 1];
	}
	_currSize--;
}
