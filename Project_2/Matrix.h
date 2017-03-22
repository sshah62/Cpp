#ifndef _MATRIX_H
#define _MATRIX_H

#include "ArrayClass.h"

class MatrixIncompatibleException : public ArrayException
{
};

class MatrixIncompatibleException : public ArrayException
{
};

template <class DataType>
class Matrix : public AbstractArrayClass<ArrayClass<DataType>>
{
protected:
	ArrayClass<ArrayClass<DataType>*>* theRows;
	void copy(Matrix<DataType>& m);
	void deleteRows();
public:
	Matrix();
	Matrix(int n, int m);
	Matrix(int n, int m, DataType v);
	Matrix(Matrix& m);
	virtual ~Matrix();
	void operator= (Matrix& m);
	void operator= (const DataType* list);
	virtual int size() const;
	int columns();
	int rows();
	virtual ArrayClass<DataType>& operator[] (int index);
};
#endif