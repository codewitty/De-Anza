#pragma once
#include "Node.h"

using namespace std;

// Enumerator class for sorting types
//enum Sorting {
//	UNORDERED,
//	ASCENDING,
//	DESCENDING
//} sortOrder;

template <typename T>
class LinkedList {
private:
	// Our member variables are the list head pointer, the list tail pointer,
	// the list item count and the enumerator value for the list sort.
	Node<T>* head;       // head of list pointer
	Node<T>* tail;       // end of list pointer
	Node<T>* curr;       // working current pointer
	int      itemCount;  // number of items in the list
	//Sorting  listOrder;  // UNORDERED = 0, ASCENDING = 1, DECENDING = 2

	// Utility function to find target data node
	Node<T>* findItemNode(const T& target) const;

	// Sorting functions for target sortings
	bool addUnordered(const T& newItem);	// Enum is UNORDERED
	bool addAscending(const T& newItem);	// Enum is ASCENDING
	bool addDescending(const T& newItem);	// Enum is DESCENDING

public:
	// Constructors
	//LinkedList(Sorting ordering);
	LinkedList();
	LinkedList(const LinkedList<T>& LinkedList);
	// Destructor
	virtual ~LinkedList();

	// clear the list
	void clear();

	// Inserts an item into the list at position index
	bool insert(const T& newItem);

	// Append "it" at the end of the list
	// The client must ensure that the list's capacity is not exceeded
	bool append(const T& newItem);

	// Deletes an item from the list at a given position
	bool remove(const T& anItem);

	// Removes front of list
	bool removeFront();

	// -------------------------------------------------
	// START of 'curr' pointer related member functions
	// THESE are all related to the 'curr' pointer.
	// -------------------------------------------------
	void moveToStart();	// Set the current position to the start of the list
	void moveToEnd();	// Set the current position to the end of the list
	void prev();		// Move the current position one step left, 
						// no change if already at beginning
	void next();		// Move the current position one step right, 
						// no change if already at end
	// These two map the 'curr' pointer to a numeric index in the list
	int  currPos();		        // Return the position of the current element
	bool moveToPos(int pos);	// Set the current position to "pos"
	// -------------------------------------------------
	// END of 'curr' pointer related member functions
	// -------------------------------------------------

	int getSize() const;
	T getHead() const;
	T getTail() const;

	//Return the number of items stored in the list
	int length();

	// Return true if current position is at end of the list
	bool isAtEnd();

	// Returns true if the list is empty
	bool isEmpty() const;

	// dump the list...
	void print();

};

//**********************************************************************//
// This is a private utility member function used to find a target node // 
// pre: User provides the item to be found.								//
// post: N/A.															//
// return: Returns the address of the target item node.					//
//**********************************************************************// 
template<typename T>
inline Node<T>* LinkedList<T>::findItemNode(const T & target) const
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
// This is a private utility function to add items to the list in an    //
// unordered manner. The covering function for add will call this if	//
// the list is instantiated with the unordered enumeration.				// 
// pre:  User provides item data to add to list.						//
// post: List now contains items.										//
// return: return true if successful, else false.						//
//**********************************************************************//
template<typename T>
inline bool LinkedList<T>::addUnordered(const T & newItem)
{
	Node<T>* newNode = new Node<T>(newItem);
	// if the list is empty list, set tail to the first entry.
	if (head == nullptr)
		tail = newNode;

	// curr set to the front of the list
	moveToStart();  // move 'curr' to start of list
	head = newNode;
	head->setNext(curr);
	itemCount++;
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
inline bool LinkedList<T>::addAscending(const T & newItem)
{
	Node<T>* newNode = new Node<T>(newItem);
	// First check for empty list and act accordingly
	if (head == nullptr || head->getItem() > newNode->getItem() || head->getItem() == newNode->getItem()) {
		newNode->setNext(head);
		head = newNode;
	}
	// Else list not empty handle accordingly	
	else {
		moveToStart();  // move 'curr' to start of list
		while ((curr->getNext() != nullptr) &&
			(curr->getNext()->getItem() < newNode->getItem()))
		{
			curr = curr->getNext();
		}
		newNode->setNext(curr->getNext());
		curr->setNext(newNode);
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
inline bool LinkedList<T>::addDescending(const T & newItem)
{
	Node<T>* newNode = new Node<T>(newItem);
	Node<T>* currPtr = nullptr;
	// First check for empty list and act accordingly
	if ((head == nullptr) ||
		(head->getItem() < newNode->getItem()) ||
		(head->getItem() == newNode->getItem()))
	{
		newNode->setNext(head);
		head = newNode;
	}
	// Else list not empty handle accordingly	
	else {
		moveToStart();  // move 'curr' to start of list
		while (curr->getNext() != nullptr &&
			curr->getNext()->getItem() > newNode->getItem())
		{
			curr = curr->getNext();
		}
		newNode->setNext(curr->getNext());
		curr->setNext(newNode);
	}
	itemCount++;
	return true;
}

//**********************************************************************//
// List Constructor - Instantiate the list with implied data ordering.	// 
// pre:  User provided sorting type.									//
// post: A list that deploys sorting at add time. Head and tail are		//
//		 set to nullptr and itemCount is set to zero.					//
//**********************************************************************//
//template<typename T>
//inline LinkedList<T>::LinkedList(Sorting ordering)
//{
//	listOrder = ordering;
//	head = nullptr;
//	tail = nullptr;
//	curr = nullptr;
//	itemCount = 0;
//}

//**********************************************************************//
// List Constructor - Instantiate a list that has no implied data       //
//                    ordering insertion       	     	                // 
// pre:  NA                                                             //
// post: A list that that inserts item to the front of the list         //
//       regardless of the data value.  Head and tail are		        //
//		 set to nullptr and itemCount is set to zero.					//
//**********************************************************************//
template<typename T>
inline LinkedList<T>::LinkedList()
{
	//listOrder = UNORDERED;
	head = nullptr;
	tail = nullptr;
	curr = nullptr;
	itemCount = 0;
}

//**********************************************************************//
// List Copy Constructor (currently unused)								// 
//**********************************************************************//
template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& LinkedList)
{
	// TBD need a deep copy of the list.
}

//**********************************************************************//
// List Destructor.														// 
// See clear below.														//
// Pre: A linked list with items.										//
// Post: An empty List.													//
//**********************************************************************//
template<typename T>
inline LinkedList<T>::~LinkedList()
{
	clear();
}

//**********************************************************************//
// This is our function to empty the list.							    //
// pre:  Existing list with item to be removed							//
// post: Empty list.													//
//**********************************************************************//
template<typename T>
inline void LinkedList<T>::clear()
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
// This is the public function for insert. After the user instantiates  //
// a list of one of 3 types(ascending, descending and unordered),		//
// this function selects the correct insertion function for add.		//
// This is a covering function.											//
// pre:  User provides item data to add to list.						//
// post: List now contains items inserted in the order specified at		//
// list instantiation time(UNORDERED, ASCENDING, DESCENDING.			//
// return: return true if successful, else false.						//
//**********************************************************************//
template<typename T>
inline bool LinkedList<T>::insert(const T & newItem)
{
	bool retVal(false);
	retVal = addUnordered(newItem);
	return retVal;
}

template<typename T>
inline bool LinkedList<T>::append(const T & newItem)
{
	// Instantiate and initialize a new node to append to the list.
	Node<T>* newNode = new Node<T>(newItem, nullptr);

	// 2.  If the list is empty then update list pointers...
	if (head == nullptr) {
		head = newNode;
		curr = newNode;
		tail = newNode;
	}
	// 3.  ...else set current end of list to poin to the new Node.
	else {
		tail->setNext(newNode);
		tail = tail->getNext();
	}
	// update the list itemCount after this append
	itemCount++;
	// Always returns true ... 
	// In real life probably needs to be explicitly handled.
	return true;
}

//**********************************************************************//
// This is our function to remove an item from the list.			    //
// pre:  Existing list with item to be removed							//
// post: List with specified item removed.								//
// return: return true if remove successful, else false.				//
//
// alg:
//  curr.setElement(curr.next().element()); // Pull forward the next element
//  if (curr.next() == tail) tail = curr;   // Removed last, move tail
//  curr.setNext(curr.next().next());       // Point around unneeded link

//**********************************************************************//
template<typename T>
inline bool LinkedList<T>::remove(const T & anItem)
{
	// Attempt to find the item in the list. 'itemFound' is :
	//     TRUE if the item is in the list.
	//     FALSE if the item is not in the list.
	// After this create a copy of 'curr'. This copy ('temp')is important
	// for memory management.
	bool itemFound((curr = findItemNode(anItem)) != nullptr);
	Node<T>* temp(curr);

	// if it exists, 'curr' points to the item and we can remove it
	if (itemFound)
	{
		// 2.  Call prev() which moves 'curr' pointer to previous node we want 
		//     to delete. NOTE now 'temp' will be used to delete the target node
		//     once we have managed the list pointers.
		prev();  // move list member 'curr' to one position previous.
		
		// 3.  update tail is its the next node
		if (curr->getNext() == tail)
			tail = curr;   // Since tail is removed, tail get 'prev'

		// 4.  If curr == temp after the attempting to meve it before target
		//     we are at the head of the list.
		if (temp == head) {
			head = temp->getNext();
		}
		else {
			curr->setNext(temp->getNext());
		}

		// Now mange the deletion of the target node memory.
		// We do not want any memory leaks.
		temp->setNext(nullptr);  // no dangles
		delete temp;             // deleting the 'temp' pointer free's node memory.
		itemCount--;             // update the item count
	}
	// ELSE nothing to remove, 'itemFound':w is false.

	// If the item DOES exist, return true, else false.
	return itemFound;
}

//**********************************************************************//
// This is our function to remove an item from the list.			    //
// pre:  Existing list with item to be removed							//
// post: List with specified item removed.								//
// return: return true if remove successful, else false.				//
//**********************************************************************//
template<typename T>
inline bool LinkedList<T>::removeFront()
{
	bool retval(false);

	if (head != nullptr)
		retval = remove(head->getItem());

	// itemCount is mantained by 'remove'
	return retval;
}

template<typename T>
inline void LinkedList<T>::moveToStart()
{
	curr = head;
}

template<typename T>
inline void LinkedList<T>::moveToEnd()
{
	curr = tail;
}

template<typename T>
inline void LinkedList<T>::prev()
{
	// Because we have a singly linked list we we need to iterate until
	// we are the node whos next pointer is 'curr'.  (The current pointer).
	bool currFound(false);
	Node<T>* posPtr = head;

	// FIRST take care of the case we are at the head of the list.
	// We just return if this is the case.
	if (posPtr == curr)
		return;

	while (!currFound && (posPtr != nullptr)) {
		// If our position pointer is pointing at curr then we set
		// curr to position pointer (posPtr)...
		if (posPtr->getNext() == curr) {
			curr = posPtr;
			currFound = true;  // indicate we found the node so exit.
		}
		// ...else move top the next postion
		else {
			posPtr = posPtr->getNext();
		}
	}
}

template<typename T>
inline void LinkedList<T>::next()
{
	// We only advance if the next pointer is not 'nullptr'
	if (curr->getNext())
		curr = curr->getNext();
}

template<typename T>
inline int LinkedList<T>::length()
{
	return itemCount;
}

template<typename T>
inline int LinkedList<T>::currPos()
{
	Node<T>* posPtr = head->getNext();
	int pos(0);

	for (pos = 0; curr != posPtr; pos++)
		posPtr = posPtr->next();

	return pos;
}

template<typename T>
inline bool LinkedList<T>::moveToPos(int pos)
{
	if ((pos < 0) || (pos > itemCount)) return false;
	curr = head->next();
	for (int i = 0; i < pos; i++) curr = curr->next();
	return true;
}

template<typename T>
inline int LinkedList<T>::getSize() const
{
	return itemCount;
}

template<typename T>
inline T LinkedList<T>::getHead() const
{
	return head->getItem();
}

template<typename T>
inline T LinkedList<T>::getTail() const
{
	return tail->getItem();
}

template<typename T>
inline bool LinkedList<T>::isAtEnd()
{
	return (curr == tail);
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
	return (itemCount == 0);
}

template<typename T>
inline void LinkedList<T>::print()
{
	Node<T>* index = head;

	if (index == nullptr) {
		cout << "Underflow : Empty List...\n";
	}
	while (index != nullptr) {
		cout << "Item [" << index->getItem() << "]\n";
		index = index->getNext();

	}
	cout << "\nTotal Item Count : " << itemCount << "\n";
	return;
}
