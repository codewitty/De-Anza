/* This is our Linked List template Class */
#pragma once
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//*************************************************************************//
// template class List - This is the template class for our queue.   // 
//*************************************************************************//
template <class T>
class Queue : private List<T> {
private:
	List<T> list;

public:
	Queue();
	virtual ~Queue();
	bool enqueue(const T& newItem);
	bool dequeue();
	bool isEmpty();
	T front();
	T rear();
	void print();
};
//**********************************************************************//
// This is our function to enqueue.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template <typename T>
inline bool Queue<T>::enqueue(const T& newItem)
{
	bool retVal = list.addTail(newItem);
	return retVal;
}
//**********************************************************************//
// This is our function to dequeue.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template<class T>
inline bool Queue<T>::dequeue()
{
	return list.removeFront();
}

//**********************************************************************//
// This is our isEmpty function.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template <typename T>
inline bool Queue<T>::isEmpty()
{
	return list.isEmpty();
}

//**********************************************************************//
// This is our function for front.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template <typename T>
inline T Queue<T>::front()
{
	return list.getHead();
}

//**********************************************************************//
// This is our function to push.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template<class T>
inline T Queue<T>::rear()
{
	return list.getTail();
}

//**********************************************************************//
// This is our function to push.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template<class T>
inline void Queue<T>::print()
{
	list.print();
}

//**********************************************************************//
// This is our function to push.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template <typename T>
Queue<T>::Queue()
{
}

//**********************************************************************//
// This is our function to push.									    //
// pre:  Existing queue or empty queue									//
// post: queue with added node.											//
//**********************************************************************//
template <typename T>
Queue<T>::~Queue()
{
}

