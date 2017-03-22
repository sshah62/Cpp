#ifndef _VECTOR_H
#define _VECTOR_H

#include "ArrayClass.h"
#include "AbstractVector.h"

template <class DataType> 
class Vector : virtual public ArrayClass <DataType>, virtual public AbstractVector <DataType>
{
protected:
	int _currSize;
	int _incFactor;
public:
	Vector();
	Vector(int n);
	Vector(int n, DataType& val);
	Vector(const Vector<DataType>& v);
	Vector(const ArrayClass<DataType>& ac);
	virtual ~Vector();
	void operator= (const Vector<DataType>& v);
	void operator= (const ArrayClass<DataType>& ac);
	virtual void insert(const DataType& item, int index);
	virtual void remove(int index);
	virtual void add(const DataType& item);
	virtual int size() const;
	virtual int capacity() const;
	virtual int incFactor() const;
	virtual void setIncFactor(int f);
	void setCapacity(int c);

};
#endif