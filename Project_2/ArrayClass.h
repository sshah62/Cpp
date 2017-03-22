#ifndef _ARRAYCLASS_H
#define _ArrayCLASS_H

#include "AbstractArray.h"

template <class DataType> class ArrayClass: virtual public AbstractArrayClass<DataType>
{
protected:
	// An array of type Object will be created and paObject will be the address of the array.
	DataType* paObject;
	int _size;
	void copy(const ArrayClass<DataType>& ac);

public:
	ArrayClass();
	ArrayClass(int n);
	ArrayClass(int n, const DataType& val);
	ArrayClass(const ArrayClass<DataType>& ac);
	virtual ~ArrayClass();
	virtual int size() const;
	virtual copy(const ArrayClass<DataType>& ac)
	virtual DataType & operator [] (int k);
	void operator= (const ArrayClass<DataType>& ac);
	//void Ostream& operator<< (ostream& s, AbstractArrayClass<DataType> & ac);
};
#endif //!_ARRAYCLASS_H

