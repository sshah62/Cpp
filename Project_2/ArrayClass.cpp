// ArrayClass methods

#include "ArrayClass.h"

//Empty constructor
template <class DataType>
ArrayClass<DataType>::ArrayClass()
{
	_size = 0; // default in case allocation fails
	paObject = new DataType[1];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = 1;
}

//Constructor with int argument
template <class DataType>
ArrayClass<DataType>::ArrayClass(int n)
{
	_size = 0; // default in case allocation fails
	paObject = new DataType[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
}

//Constructor
template<class DataType>
ArrayClass<DataType>::ArrayClass(int n, const DataType& val)
{
	_size = 0; // default in case allocation fails
	paObject = new DataType[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
	for (int i = 0; i < n; i++) paObject[i] = val;
}



//Copy constructor
template <class DataType>
ArrayClass<DataType>::copy(const ArrayClass<DataType>& ac)
{
	_size = 0; // default in case allocation fails
	paObject = new DataType[ac._size];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = ac._size;
	for (int i = 0; i < _size; i++) paObject[i] = ac.paObject[i];
}

//Copy constructor :
template <class DataType>
ArrayClass<DataType>::ArrayClass(const ArrayClass<DataType>& ac)
{
	copy(ac);
}

//Destructor
template <class DataType>
ArrayClass <DataType> :: ~ArrayClass()
{
	if (paObject != NULL) delete[] paObject;
	paObject = NULL;
	_size = 0;
}

//Size method :
template <class DataType>
int ArrayClass<DataType>::size() const
{
	return _size;
}

//Overloaded [] operator
template <class DataType>
DataType& ArrayClass<DataType>::operator [] (int k)
{
	if ((k < 0) || (k >= size())) throw ArrayBoundsException();
	return paObject[k];
}

//Overloaded Assignment Operator
template <class DataType>
void ArrayClass<DataType>::operator= (const ArrayClass<DataType>& ac)
{
	if (paObject != NULL) delete[] paObject;
	copy(ac);
}

//Overloaded << operator
template <class DataType>
ostream& operator << (ostream& s, AbstractArrayClass<DataType>& ac)
{
	s << "[";
	for (int i = 0; i < ac.size(); i++)
	{
		if (i > 0) s << ',';
		s << ac[i];
	}
	s << "]";
	return s;
}
