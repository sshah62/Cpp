template <class DataType>
class AbstractVector :virtual public AbstractArrayClass<DataType>
{
public:
	//insert a new object at a position index in the vector
	virtual void insert(const DataType& item, int index) = NULL;

	//remove the object at a position index of the vector
	virtual void remove(int index) = NULL;

	//Add item at the end of the Vector
	virtual void add(const DataType& item) = NULL;

};