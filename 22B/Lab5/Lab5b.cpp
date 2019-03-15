// Program name: Lab5b 
//
// Description: 
//		The program instantiates and uses instances 
//		of a derived class with default and non-default constructors.	
// 	
//
// What's on your mind about this lab? 
// This exercise helps understand how to use classes and inheritance to  
// process data
//
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


//This program processes data using a derived class 
int main() {

// Apartment variable
NumberList myList;



myList.appendNode(38.45);
myList.appendNode(45.83);
myList.appendNode(75.2);
myList.appendNode(106.94);
myList.appendNode(108.3);
myList.appendNode(163.52);
myList.appendNode(173.45);

cout << "Displaying list after inserting numbers" << endl;
myList.displayList();

myList.deleteNode(45.83);
myList.deleteNode(173.45);

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
