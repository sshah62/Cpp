//LinkedList class Methods

#include "LinkedList.h"

//Default constructor
template <class DataType>
LinkedList<DataType>::LinkedList()
{
	_info = NULL;
	_next = NULL;
}

//Constructor
template <class DataType>
LinkedList<DataType>::LinkedList(const DataType& info)
{
	_info = new DataType(info);
	if (_info == NULL) throw LinkedListMemory();
	_next = NULL;
}

//Destructor
template <class DataType>
LinkedList<DataType>::~LinkedList()
{
	if (_info != NULL)
	{
		delete _info;
		_info = NULL;
	}
	if (_next != NULL)
	{
		delete _next; // this produces recursive call to destructor
		_next = NULL;
	}
}

//Constructor using ll object
template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& ll)
{
	if (ll._info == NULL)
	{
		_info = NULL;
	}
	else {
		_info = new DataType(*(ll._info));
		if (_info == NULL) throw LinkedListMemory();
	}
	if (ll._next == NULL)
	{
		_next = NULL;
	}
	else
	{
		_next = new LinkedList<DataType>(*(ll._next));
		if (_next == NULL) throw LinkedListMemory();
	}
}

//constructor using *next pointer
template <class DataType>
LinkedList<DataType>::LinkedList(DataType&info, LinkedList<DataType>* next)
{
	_info = new DataType(info);
	if (_info == NULL)
	{
		throw LinkedListMemory();
	}
	_next = next;
}

//
template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& ll)
{
	copy(ll);
}

//Copy Constructor
template <class DataType>
void LinkedList<DataType>::copy(const LinkedList<DataType>& ll)
{
	if (ll._info == NULL)
	{
		_info = NULL;
	}
	else
	{
		_info = new DataType(*(ll._info));
		if (_info == NULL)
		{
			throw LinkedListMemory();
		}
	}
	if (ll._next == NULL)
	{
		_next = NULL;
	}
	else
	{
		_next = new LinkedList<DataType>(*(ll._next));
		if (_next == NULL)
		{
			throw LinkedListMemory();
		}
	}
}

//overloaded assignment operator
template <DataType>
void LinkedList<DataType>::operator= (const LinkedList<DataType>& ll)
{
	if (_info != NULL) delete _info;
	if (_next != NULL) delete _next;
	copy(ll);
}

//Method: isEmpty
template <class DataType>
bool LinkedList<DataType>::isEmpty()
{
	return (_info == NULL);
}

//Method: info()
template <class DataType>
DataType& LinkedList<DataType>::info()
{
	if (isEmpty())
	{
		throw LinkedListBounds();
	}
	return *_info;
}

//Add method
template <class DataType>
void LinkedList<DataType>::add(DataType& object)
{
	if (_info == NULL) { _info = new DataType(object); }
	else
	{
		LinkedList<DataType>* newList = new LinkedList<DataType>(*_info, _next);
		if (newList == NULL)
		{
			throw LinkedListMemory();
		}
		*_info = object;
		_next = newList;
	}
}

//find method
template <class DataType>
DataType& LinkedList<DataType>::find(DataType& key)
{
	if (isEmpty())
	{
		throw LinkedListNotFound();
	}
	if (key == *_info) 
	{
		return *_info; 
	}
	if (_next == NULL)
	{
		throw LinkedListBounds();
	}
	return _next->find(key);
}

//next method
template <class DataType>
AbstractLinkedList<DataType>* LinkedList<DataType>::next()
{
	return _next;
}

//size method
template <class DataType>
int LinkedList<DataType>::size()
{
	if (_next == NULL)
	{
		if (_info == NULL)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else return 1 + _next->size();
}

//infoat method
template <class DataType>
DataType& LinkedList<DataType>::infoAt(int position)
{
	if (isEmpty())
	{
		throw LinkedListBounds();
	}
	if (position == 0) 
	{ 
		return *_info; 
	}
	if (_next == NULL)
	{
		throw LinkedListBounds();
	}
	return _next->infoAt(position - 1);
}

//insertAt method
template <class DataType>
void LinkedList<DataType>::insertAt(DataType& newObj, int position)
{
	if (position == 0)
	{
		add(newObj);
	}
	else
	{
		if (_next == NULL)
		{
			_next = new LinkedList(newObj);
			if (_next == NULL) throw LinkedListMemory();
		}
		else
		{
			_next->insertAt(newObj, position - 1);
		}
	}
}

//remove method
template <class DataType>
DataType LinkedList<DataType>::remove()
{
	if (isEmpty())
	{
		throw LinkedListBounds();
	}
	DataType temp = *_info;
	delete _info;
	if (_next == NULL) 
	{
		_info = NULL; 
	}
	else
	{
		LinkedList<DataType>* oldnext = _next;
		_info = _next->_info;
		_next = _next->_next;
		
		// the purpose of the two lines below is to remove any stray pointers into the linked list
		oldnext->_info = NULL;
		oldnext->_next = NULL;
	}
	return temp;
}

//Method: removeAt
template <class DataType>
DataType LinkedList<DataType>::removeAt(int position)
{
	if (isEmpty())
	{
		throw LinkedListBounds();
	}
	if (position == 0) 
	{ 
		return remove(); 
	}
	if (_next == NULL)
	{
		throw LinkedListBounds();
	}
	return _next->removeAt(position - 1);
}
