/* This is our Linked List template Class */
#pragma once
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//*************************************************************************//
// template class List - This is the template class for our linked list.   // 
//*************************************************************************//
template <typename T>
class Stack:private List<T> {
private:

public:

	Stack();
	virtual ~Stack();
	bool push(const T& newItem);
};

template <typename T>
bool push(const T& newItem)
{
	List<T>::addVanilla(newItem);
}

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::~Stack()
{
}
