//Matrix Class Methods
#include "Matrix.h"

//Default Constructor
template<class DataType>
Matrix<DataType>::Matrix()
{
	theRows = new ArrayClass<ArrayClass<DataType>*>(1, NULL);
	if (theRows == NULL)
	{
		throw ArrayMemoryException();
	}
	(*theRows)[0] = new ArrayClass<DataType>();
	if ((*theRows)[0] == NULL)
	{
		throw ArrayMemoryException();
	}
}

//n x m constructor: 
template<class DataType>
Matrix<DataType>::Matrix(int n, int m)
{
	theRows = new ArrayClass<ArrayClass<DataType>*>(n, NULL);
	if (theRows == NULL)
	{
		throw ArrayMemoryException();
	}
	
	for (int i = 0; i < n; ++i)
	{
		(*theRows)[i] = new ArrayClass<DataType>(m);

		if ((*theRows)[i] == NULL)
		{
			throw ArrayMemoryException();
		}
	}
}

//n x m constructor with initial values
template<class DataType>
Matrix<DataType>::Matrix(int n, int m, DataType v)
{
	theRows = new ArrayClass<ArrayClass<DataType>*>(n, NULL);
	if (theRows == NULL)
	{
		throw ArrayMemoryException();
	}

	for (int i = 0; i < n; ++i)
	{
		(*theRows)[i] = new ArrayClass<DataType>(m, v);

		if ((*theRows)[i] == NULL)
		{
			throw ArrayMemoryException();
		}
	}
}

//destructor
template <class DataType>
Matrix<DataType>::~Matrix()
{
	deletRows();
}

//define deletRows()
template <class DataType>
void Matrix<DataType>::deleteRows()
{
	if (theRows != NULL)
	{
		for (int i = 0; i < theRows->size(); ++i)
		{
			if ((*theRows)[i] != NULL)
			{
				delete (*theRows)[i];
				(*theRows)[i] = NULL;
			}
		}
		delete theRows;
	}
	theRows = Null;
}

//Copy constructor
template<class DataType>
void Matrix<DataType>::copy(Matrix<DataType>& m)
{
	deleteRows();
	theRows = new ArrayClass<ArrayClass<DataType>*>(m.size(), NULL);

	if (theRows == NULL)
	{
		throw ArrayMemoryException();
	}

	for (int i = 0; i < m.size(); ++i)
	{
		(*theRows)[i] = new ArrayClass<DataType>(m[i]);
		
		if (((*theRows)[i] == NULL)
		{
			throw ArrayMemoryException();
		}
	}
}

//constructor using "Copy" constructor
template <class DataType>
Matrix<DataType>::Matrix(Matrix<DataType>& m)
{
	theRows = NULL;
	copy(m);
}

//Assignment Operator using "copy" constructor
template<class DataType>
Matrix<DataType>::operator= (Matrix<DataType>& m)
{
	copy(m);
}

//Getter (accessor) method using [] overloaded operator
template <class DataType>
ArrayClass<DataType>& Matrix<DataType>:: operator[] (int index)
{
	return (*(*theRows)[index]);
	//Now we can use m[i] as any other instance of ArrayClass
}

//Overide the Size() method of AbstractArrayClass
template <class DataType>
int Matrix <DataType>::size() const
{
	return theRows->size();
}

//Rows Method (same as size)
template <class DataType>
int Matrix <DataType>::rows()
{
	return theRows->size();
}

//Column method
template <class DataType>
int Matrix <DataType>::columns()
{
	return (*this)[0].size();
}
