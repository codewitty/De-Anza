/*
Lab03A
Names : Joseph Saunders and Joshua Gomes
Class : CIS22C61Y
*/
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

//******************************************************************************
// int main() - Main declares defines 3 arrays of 10 elements each. 
// An int, string and dollar.
//
// Our list template allows us to sort whatever type is passed in ascending
// and descending order or unsorted. For our case to demonstrate the template
// support for list in descending order we print integers, to demonstrate 
// support for ascending order we print strings and to demonstrate unordered
// insertion we print rupee objects.
// 
// PSEUDOCODE:
// 
//	1.  Print Header
//	2.  Demonstrate Stack implementation of Linked List
//	3.	Demonstrate Queue implementation of Linked List
//******************************************************************************
int main()
{
	// 1.  Print Header
	cout << "\n\nLab03B\n"
		<< "Names : Joseph Saunders and Joshua Gomes\n"
		<< "Class : CIS22C61Y"
		<< endl;

	// 2.  Instantiate stack
	Stack<int> myStack;
	myStack.push(33);
	myStack.push(433);
	myStack.push(333);

	cout << "All items pushed as follows: \n";
	myStack.print();

	
	int topOfList = myStack.peek();
	cout << topOfList << endl;

	myStack.pop();
	cout << "Pop one printing stack: \n";
	myStack.print();
	myStack.pop();



	// 3. Instantiate and demonstrate Queue
	Queue<int> myQueue;
	myQueue.enqueue(23); 
	myQueue.enqueue(454);
	myQueue.enqueue(567);
	myQueue.enqueue(5654);
	myQueue.enqueue(222);


	// Printing the Queue
	cout << "All items queued as follows: \n";
	myQueue.print();

	myQueue.dequeue();
	myQueue.dequeue();

	cout << myQueue.front() << endl;
	cout << "Printing rear of queue: \n";
	cout << myQueue.rear() << endl;

	myQueue.dequeue();
	myQueue.isEmpty();
	myQueue.dequeue();
	myQueue.dequeue();

	myQueue.isEmpty();

	return 0;
}
