#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "AbstractLinkedList.h"

template <class DataType>
class LinkedList : public AbstractLinkedList <DataType>
{
protected:
	DataType* _info;
	LinkedList <DataType>* _next;
public:
	LinkedList();
	LinkedList(const DataType& info);
	LinkedList(const DataType& info, LinkedList<DataType>* next);
	~LinkedList();
	void copy(const LinkedList<DataType>& ll);
	LinkedList(const LinkedList<DataType>& ll);
	bool isEmpty();
	DataType& info();
	int size();
	DataType& find(DataType& key);
	DataType& infoAt(int position);
	void add(DataType& object);
	void insertAt(DataType& newObj, int position);
	DataType remove();
	DataType removeAt(int position);
	void operator=(const LinkedList<DataType>& ll);
	virtual LinkedList<DataType>*next();
};
#endif // !_LINKEDLIST_H
