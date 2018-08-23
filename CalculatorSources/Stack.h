#ifndef STACK_H
#define STACK_H
#include"Double_list.h"

template<typename T=int>
class Stack
{
public:
	void push(const T & value);
	T pop();
	T popReturn();
	bool isEmpty();
	T getSize();
private:
	CDoubleList<T> list;
};

template<typename T>
void Stack<T>::push(const T& value)
{
	list.addToEnd(value);
}

template<typename T>
T Stack<T>::pop()
{
	T buffer = list[list.getSize()-1];
	list.removeFromEnd();
	return buffer;
}
template<typename T>
T Stack<T>::popReturn()
{
	return  list[list.getSize() - 1];
}
template<typename T>
bool Stack<T>::isEmpty()
{
	if (list.getSize() == 0)return true;
	return false;
}
template<typename T>
T Stack<T>::getSize()
{
	return list.getSize();
}
#endif;
