/* This is our Linked List template Class */
#pragma once
#include "Node.h"
using namespace std;

// Enumerator class for sorting types
enum Sorting {
	UNORDERED,
	ASCENDING,
	DESCENDING
} sortOrder;

//*************************************************************************//
// template class List - This is the template class for our linked list.   // 
//*************************************************************************//
template <typename T>
class List {
private:
	// Our member variables are the list head pointer, the list tail pointer,
	// the list item count and the enumerator value for the list sort.
	Node<T>* head;
	Node<T>* tail;
	int itemCount;
	Sorting listOrder;  // UNORDERED = 0, ASCENDING = 1, DECENDING = 2

	// Utility function to find target data node
	Node<T>* findItemNode(const T& target) const;

	// Sorting functions for target sortings
	bool addUnordered(const T& newItem);	// Enum is UNORDERED
	bool addAscending(const T& newItem);	// Enum is ASCENDING
	bool addDescending(const T& newItem);	// Enum is DESCENDING
public:
	// Constructors
	List(Sorting ordering);
	List();
	List(const List<T>& list);
	// Destructor
	virtual ~List();

	// Accessor
	int getSize() const;
	T getHead() const;
	T getTail() const;

	// Mutators
	void setHead(T& newPtr);
	void setTail(T& newPtr);
	void setItemCount(int count);
	// Our Public List utility functions
	// - isEmpty() returns true if list is empty else false
	// - add() add item to list
	// - remove() remove item from list
	// - clear() clears list completely
	// - contains() returns true if list contains a specified data item
	// - getFrequencyOf() returns the frequency of a specified data item
	// - print() prints the formatted data values from the list
	bool isEmpty() const;
	bool add(const T& newItem);
	bool addTail(const T& newItem);
	bool remove(const T& anItem);
	bool removeFront();
	void clear();
	bool contains(const T& anEntry);
	int  getFrequencyOf(const T& anEntry) const;
	void print();
};

//**********************************************************************//
// This is a private utility member function used to find a target node // 
// pre: User provides the item to be found.								//
// post: N/A.															//
// return: Returns the address of the target item node.					//
//**********************************************************************//
template<typename T>
inline Node<T>* List<T>::findItemNode(const T & target) const
{
	bool found(false);
	Node<T>* currPtr = head;
	while (!found && (currPtr != nullptr))
	{
		if (target == currPtr->getItem())
			found = true;
		else
			currPtr = currPtr->getNext();
	}
	return currPtr;
}

//**********************************************************************//
// List Constructor 													// 
// pre:  User provided sorting type.									//
// post: A list that deploys sorting at add time. Head and tail are		//
//		 set to nullptr and itemCount is set to zero.					//
//**********************************************************************//
template<typename T>
inline List<T>::List(Sorting ordering)
{
	listOrder = ordering;
	head = nullptr;
	tail = nullptr;
	itemCount = 0;
}

template<typename T>
inline List<T>::List()
{
	listOrder = UNORDERED;
	head = nullptr;
	tail = nullptr;
	itemCount = 0;
}

//**********************************************************************//
// List Copy Constructor												// 
//**********************************************************************//
template<typename T>
inline List<T>::List(const List<T>& list)
{
}


//**********************************************************************//
// List Destructor.														// 
// See clear below.														//
// Pre: A linked list with items.										//
// Post: An empty List.													//
//**********************************************************************//
template<typename T>
inline List<T>::~List()
{
	clear();
}

//**********************************************************************//
// This is the get size accessor.										//
// return: Returns the count for the number of items in the list.		//
//**********************************************************************//
template<typename T>
inline int List<T>::getSize() const
{
	return itemCount;
}

template<typename T>
inline T List<T>::getHead() const
{
	return head->getItem();
}

template<typename T>
inline T List<T>::getTail() const
{
	return tail->getItem();
}

template<typename T>
inline void List<T>::setHead(T & newPtr)
{
	head = newPtr;
}

template<typename T>
inline void List<T>::setTail(T & newPtr)
{
	tail = newPtr;
}

template<typename T>
inline void List<T>::setItemCount(int count)
{
	itemCount = count;
}

//**********************************************************************//
// This is the utility function to check for an empty list.				//
// return: Returns true if the list is empty, else false.				//
//**********************************************************************//
template<typename T>
inline bool List<T>::isEmpty() const
{
	return (itemCount == 0);
}

//**********************************************************************//
// This is a private utility function to add items to the list in an    //
// unordered manner. The covering function for add will call this if	//
// the list is instantiated with the unordered enumeration.				// 
// pre:  User provides item data to add to list.						//
// post: List now contains items.										//
// return: return true if successful, else false.						//
//**********************************************************************//
template<typename T>
inline bool List<T>::addUnordered(const T & newItem)
{
	Node<T>* curr(nullptr);
	Node<T>* newNode = new Node<T>(newItem);

	curr = head;
	head = newNode;
	newNode->setNext(curr);
	itemCount++;
	return true;
}
//**********************************************************************//
// This is the public function for add. After the user instantiates		//
// a list of one of 3 types(ascending, descending and unordered),		//
// this function selects the correct insertion function for add.		//
// This is a covering function.											//
// pre:  User provides item data to add to list.						//
// post: List now contains items inserted in the order specified at		//
// list instantiation time(UNORDERED, ASCENDING, DESCENDING.			//
// return: return true if successful, else false.						//
//**********************************************************************//
template<typename T>
inline bool List<T>::add(const T & newItem)
{
	bool retVal(false);
	if (listOrder == UNORDERED)
		retVal = addUnordered(newItem);
	else if (listOrder == ASCENDING)
		retVal = addAscending(newItem);
	else if (listOrder == DESCENDING)
		retVal = addDescending(newItem);
	return retVal;
}

template<typename T>
inline bool List<T>::addTail(const T & newItem)
{
	Node<T>* curr(nullptr);
	Node<T>* newNode = new Node<T>(newItem);
	newNode->setItem(newItem);
	newNode->setNext(nullptr);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->setNext(newNode);
		tail = tail->getNext();
	}
	return true;
}

//**********************************************************************//
// This is a private utility function to add items to the list in an    //
// ascending manner. The covering function for add will call this if	//
// the list is instantiated with the ascending enumeration.				// 
// pre:  User provides item data to add to list.						//
// post: List now contains items in ascending order.					//
// return: return true if successful, else false.						//
//**********************************************************************//
template<typename T>
inline bool List<T>::addAscending(const T & newItem)
{
	Node<T>* newNode = new Node<T>(newItem);
	Node<T>* currPtr = nullptr;
	// First check for empty list and act accordingly
	if (head == nullptr || head->getItem() > newNode->getItem() || head->getItem() == newNode->getItem()) {
		newNode->setNext(head);
		head = newNode;
	}
	// Else list not empty handle accordingly	
	else {
		currPtr = head;
		while (currPtr->getNext() != nullptr &&
			currPtr->getNext()->getItem() < newNode->getItem())
		{
			currPtr = currPtr->getNext();
		}
		newNode->setNext(currPtr->getNext());
		currPtr->setNext(newNode);
	}
	itemCount++;
	return true;
}

//**********************************************************************//
// This is a private utility function to add items to the list in an    //
// descending manner. The covering function for add will call this if	//
// the list is instantiated with the descending enumeration.			// 
// pre:  User provides item data to add to list.						//
// post: List now contains items in descending order.					//
// return: return true if successful, else false.						//
//**********************************************************************//
template<typename T>
inline bool List<T>::addDescending(const T & newItem)
{
	Node<T>* newNode = new Node<T>(newItem);
	Node<T>* currPtr = nullptr;
	// First check for empty list and act accordingly
	if (head == nullptr || head->getItem() < newNode->getItem() || head->getItem() == newNode->getItem()) {
		newNode->setNext(head);
		head = newNode;
	}
	// Else list not empty handle accordingly	
	else {
		currPtr = head;
		while (currPtr->getNext() != nullptr &&
			currPtr->getNext()->getItem() > newNode->getItem())
		{
			currPtr = currPtr->getNext();
		}
		newNode->setNext(currPtr->getNext());
		currPtr->setNext(newNode);
	}
	itemCount++;
	return true;
}

//**********************************************************************//
// This is our function to remove an item from the list.			    //
// pre:  Existing list with item to be removed							//
// post: List with specified item removed.								//
// return: return true if remove successful, else false.				//
//**********************************************************************//
template<typename T>
inline bool List<T>::removeFront()
{
	bool canRemove(!isEmpty());
	// first validate there is a world top remove from
	if (canRemove)
	{
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
		itemCount--;
	}
	return canRemove;
}

//**********************************************************************//
// This is our function to remove an item from the list.			    //
// pre:  Existing list with item to be removed							//
// post: List with specified item removed.								//
// return: return true if remove successful, else false.				//
//**********************************************************************//
template<typename T>
inline bool List<T>::remove(const T & anItem)
{
	// first validate there is a world top remove from
	Node<T>* entryNode = findItemNode(anItem);
	bool canRemove = !isEmpty() && (entryNode != nullptr);
	if (canRemove)
	{
		/*
		entryNode->setItem(head->getItem());

		Node<T>* nodeToDelete = head;
		head = head->getNext();
		nodeToDelete->setNext(nullptr);
		delete nodeToDelete;
		*/
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
		itemCount--;
	}
	return canRemove;
}

//**********************************************************************//
// This is our function to empty the list.							    //
// pre:  Existing list with item to be removed							//
// post: Empty list.													//
//**********************************************************************//
template<typename T>
inline void List<T>::clear()
{
	Node<T>* nodeToDelete(head);

	while (head != nullptr) {
		head = head->getNext();

		nodeToDelete->setNext(nullptr);
		delete nodeToDelete;
		nodeToDelete = head;
	}
	itemCount = 0;
}

//**********************************************************************//
// This is our function to check if the list contains a specific item.  //
// pre:  Existing list with user provided item to be found.				//
// post: N/A.															//	
// return: return true if found, else false.							//
//**********************************************************************//
template<typename T>
inline bool List<T>::contains(const T & anEntry)
{
	return (findItemNode(anEntry) != nullptr);
}

//**********************************************************************//
// This is our function to find the frequency of an item in a list		//
// pre:  Existing list.													//
// post: N/A.															//	
// return: return value for frequency of specified item.				//
//**********************************************************************//
template<typename T>
inline int List<T>::getFrequencyOf(const T & anEntry) const
{
	int frequency(0);
	int counter(0);
	Node<T>* curPtr = head;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
			frequency++;

		counter++;
		curPtr = curPtr->getNext();
	}  // END while
	return frequency;
}  // END getFrequencyOf()

//**********************************************************************//
// This is our function to print the items in the list.					//
// pre:  Existing list.													//
// post: N/A.															//	
//**********************************************************************//
template<typename T>
inline void List<T>::print()
{
	Node<T>* index = head;

	if (index == nullptr) {
		cout << "Empty List wonk wonk\n";
	}
	while (index != nullptr) {
		cout << "Item [" << index->getItem() << "]\n";
		index = index->getNext();
	}
	cout << "\nTotal Item Count : " << itemCount << "\n";
	return;
}
