#ifndef ITERATOR_H
#define ITERATOR_H
#include"Node.h"
template<typename T>
class CIterator
{
public:
	CIterator(List::Node<T>* current);
public:
	T & operator*();
	CIterator & operator++();
	CIterator & operator--();
	bool operator!=(CIterator & obj);
	bool hasNext();
	bool hasPrevious();
private:
	List::Node<T> * current;
};
template<typename T>
T &CIterator<T>::operator*()
{ 
	return current->value; 
}

template<typename T>
CIterator<T>::CIterator(List::Node<T>* current)
{ 
	this->current = current;
}

template<typename T>
CIterator<T>& CIterator<T>:: operator++()
{
	current = current->next;
	return *this;
}

template<typename T>
CIterator<T> &CIterator<T>:: operator--()
{
	current = current->prev;
	return *this;
}

template<typename T>
bool CIterator<T>:: operator!=(CIterator & obj)
{
	return current != obj.current;
}

template<class T>
bool CIterator<T>::hasNext() 
{
	return (current->next() != nullptr ? true : false);
}

template<class T>
bool CIterator<T>::hasPrevious() 
{
	return (current->previous() != nullptr ? true : false);
}
#endif;
