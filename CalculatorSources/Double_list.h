#ifndef DOUBLE_LIST
#define DOUBLE_LIST
#include <iostream>
#include"Node.h"
#include"Iterator.h"
using namespace std;

template<typename T=int>
class CDoubleList
{
public:
	CDoubleList();
	CDoubleList(const CDoubleList & object);
	CDoubleList(CDoubleList && obj);
	CDoubleList& operator=(const CDoubleList& object);
	CDoubleList & operator=(CDoubleList && obj);
	T & operator[](size_t index);
	~CDoubleList();
public:
	unsigned int getSize();
	void addToStart(const T & v);
	void addToEnd(const T & v);
	void addToIndex(size_t index, const T & v);
	void removeFromIndex(size_t index);
	void removeAll();
	void removeFromStart();
	void removeFromEnd();
	CIterator<T> getBegin() { return CIterator<T>(start); }
	CIterator<T> getEnd() { return CIterator<T>(nullptr); }
private:
	
	List::Node<T>* start;
	List::Node<T>* end;
	unsigned int count;
private:
	List::Node<T>* getNode(unsigned int index)
	{
		if (index >= count)
			exit(1);
		List::Node<T> * node;
		if (index < count / 2)
		{
			node = start;
			for (size_t i = 0; i < index; i++)
			{
				node = node->next;
			}
		}
		else
		{
			node = end;
			for (size_t i = count - 1; i > index; i--)
			{
				node = node->previous;
			}
		}
		return node;
	}
};

template<typename T>
CDoubleList<T>::CDoubleList()
{
	//cout << "Default constr"<<endl;
	start = end = nullptr;
	count = 0;
}

template<typename T>
CDoubleList<T>::CDoubleList(CDoubleList&& obj)
{
	//cout << "Move constr"<<endl;
	this->start = obj.start;
	this->end = obj.end;
	this->count = obj.count;
	obj.start = nullptr;
}
template<typename T>
CDoubleList<T>::CDoubleList(const CDoubleList& object):CDoubleList()
{
	//cout << "Copy constr" << endl;
	List::Node<T> * node = object.start;
	while (node)
	{
		this->addToEnd(node->value);
		node = node->next;
	}
}

template<typename T>
T& CDoubleList<T>::operator[](size_t index)
{
	return getNode(index)->value;
}

template<typename T>
CDoubleList<T>& CDoubleList<T>::operator=(const CDoubleList& object)
{
	//cout << "operator= copy" << endl;
	if (this == &object)
		return *this;
	this->removeAll();
	List::Node<T> * node = object.start;
	while (node)
	{
		this->addToEnd(node->value);
		node = node->next;
	}
	return *this;
}

template<typename T>
CDoubleList<T> & CDoubleList<T>::operator=(CDoubleList && obj)
{
	//cout << "operator= move" << endl;
	if (this == &obj)
		return *this;
	this->removeAll();

	this->start = obj.start;
	this->end = obj.end;
	this->count = obj.count;
	obj.start = nullptr;

	return *this;
}

template<typename T >
CDoubleList<T>::~CDoubleList()
{
	//cout << "Destroy" << endl;
	this->removeAll();
}



template<typename T>
unsigned int CDoubleList<T>::getSize()
{
	return count;
}

template<typename T>
void CDoubleList<T>::addToEnd(const T & v)
{
	List::Node<T>* node =new List::Node<T>(v);
	if (count == 0)
		start = node;
	else
		end->next = node;
	node->previous = end;
	end = node;
	count++;
}
template<typename T>
void CDoubleList<T>::addToStart(const T & v)
{
	if (count == 0)
	{
		this->addToEnd(v);
		return;
	}
	List::Node<T> * node = new List::Node<T>(v);
	node->next = start;
	start->previous = node;
	start = node;
	count++;
}


template<typename T>
void CDoubleList<T>::addToIndex(size_t index, const T & v)//����� ���������� �� �������
{
	if (count == 0 || index == 0)
	{
		this->addToStart(v);
		return;
	}
	if (index == count || index>count)
	{
		this->addToEnd(v);
		return;
	}
	List::Node<T> * node = start;
	count = NULL;
	start = end = nullptr;

	for (size_t i = 0;i <= index;i++)
	{
		if (i < index)
		{
			addToEnd(node->value);
			node = node->next;
		}
		if (i == index)
		{
			addToEnd(v);
			while (node)
			{
				addToEnd(node->value);
				node = node->next;
			}
			return;
		}
	}
}

template<typename T>
void CDoubleList<T>::removeFromIndex(size_t index)
{
	if (index == 0)
	{
		removeFromStart();
		return;
	}
	if (index == count || index > count)
	{
		removeFromEnd();
		return;
	}
	List::Node<T> * node = start;
	count = NULL;
	start = end = nullptr;
	for (size_t i = 0;i <= index;i++)
	{
		if (i < index)
		{
			addToEnd(node->value);
			node = node->next;
		}
		if (i == index)
		{
			node = node->next;
			while (node)
			{
				addToEnd(node->value);
				node = node->next;
			}
			return;
		}
	}
}

template<typename T>
void CDoubleList<T>::removeFromEnd()
{
	if (count == 0)
		return;
	else if (count == 1)
	{
		delete start;
		start = end = nullptr;
		count = 0;
	}
	else
	{
		List::Node<T> * beforeEnd = end->previous;
		beforeEnd->next = nullptr;
		delete end;
		end = beforeEnd;
		count--;
	}
}

template<typename T>
void CDoubleList<T>::removeFromStart()
{
	if (count == 0)
		return;
	else if (count == 1)
	{
		delete start;
		start = end = nullptr;
		count = 0;
	}
	else
	{
		List::Node<T> * p = start->next;
		delete start;
		start = p;
		start->previous = nullptr;
		count--;
	}
}

template<typename T>
void CDoubleList<T>::removeAll()
{
	List::Node<T> * node = start;
	while (node)
	{
		List::Node<T> * p = node;
		node = node->next;
		delete p;
	}
	start = end = nullptr;
	count = 0;
}
#endif

