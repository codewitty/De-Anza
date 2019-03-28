// Program name: Lab5b 
//
// Description: 
// 		The program uses a linked list to manipulate a 
//		sequence of numbers.	
//
// What's on your mind about this lab? 
// This exercise helps me understand how to use linked lists to 
// process data
// Author: Joshua N  Gomes 
//
// Date: 03/13/2019
//
// IDE Used: Vim/g++
//

#include <iostream>
#include <iomanip>
#include <string>
#include "NumberList.h"

using namespace std;


//This program processes data using a linked list 
int main() {

// instance variable of NumberList
NumberList myList;

// Inserting numbers into list

myList.insertNode(75.2);
myList.insertNode(108.3);
myList.insertNode(38.45);
myList.insertNode(45.83);
myList.insertNode(173.45);
myList.insertNode(163.52);
myList.insertNode(106.94);

// Displaying list
cout << "Displaying list after inserting numbers" << endl;
myList.displayList();

// Deleting numbers from list
myList.deleteNode(45.83);
myList.deleteNode(173.45);

// Displaying list after deleting numbers
cout << "Displaying list after deleting numbers" << endl;
myList.displayList();

return 0;
}


/*
Copy output of this program below this line.

Displaying list after inserting numbers
38.45
45.83
75.2
106.94
108.3
163.52
173.45
Displaying list after deleting numbers
38.45
75.2
106.94
108.3
163.52

*/
