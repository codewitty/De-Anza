/* This is our Linked List template Class */
#pragma once
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//*************************************************************************//
// template class Stack - This is the template class for our Stack.		   // 
//*************************************************************************//
template <class T>
class Stack : private LinkedList<T> {
private:
	LinkedList<T> list;

public:
	Stack();
	virtual ~Stack();
	bool    push(const T& newItem);
	bool    pop();
	bool    isEmpty();
	T       peek();
	void    print();
};
//**********************************************************************//
// This is our function to push.									    //
// pre:  Existing stack or empty stack									//
// post: Stack with added node.											//
//**********************************************************************//
template <typename T>
inline bool Stack<T>::push(const T& newItem)
{
	bool retVal = list.insert(newItem);
	return retVal;
}

//**********************************************************************//
// This is our function to pop			.							    //
// pre:  Existing stack													//
// post: Stack with top item popped.									//
//**********************************************************************//
template<class T>
inline bool Stack<T>::pop()
{
	return list.removeFront();
}

//**********************************************************************//
// This is our function to check for empty list.					    //
// pre:  Existing Stack.												//
// return: true if empty list											//
//**********************************************************************//
template <typename T>
inline bool Stack<T>::isEmpty()
{
	return list.isEmpty();
}

//**********************************************************************//
// This is our function to peek.									    //
// return:  Item at top of stack										//
//**********************************************************************//
template <typename T>
inline T Stack<T>::peek()
{
	return list.getHead();
}

//**********************************************************************//
// This is our function to print the stack.							    //
// return: print the stack, no return.									//
//**********************************************************************//
template<class T>
inline void Stack<T>::print()
{
	list.print();
}

//**********************************************************************//
// This is our stack constructor									    //
//**********************************************************************//
template <typename T>
Stack<T>::Stack()
{
}

//**********************************************************************//
// This is our stack destructor											//
//**********************************************************************//
template <typename T>
Stack<T>::~Stack()
{
}

