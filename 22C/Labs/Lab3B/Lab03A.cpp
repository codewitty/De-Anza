/*
Lab03A
Names : Joseph Saunders and Joshua Gomes
Class : CIS22C61Y
*/
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
#include "Rupee.h"
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
//	1.  Print header
//	2.  Declare 3 lists (Integer, String and Rupee Lists)
//	3A. Insert integers in the descending order
//	3B. Print resulting integer list
//	4A. Insert strings in the ascending order
//	4B. Print resulting string list
//	5A. Insert rupee objects unordered 
//	5B. Print resulting rupee object list
//******************************************************************************
int main()
{
	// 1.  Print Header
	cout << "\n\nLab03A\n"
		 << "Names : Joseph Saunders and Joshua Gomes\n"
		 << "Class : CIS22C61Y"
		 << endl;

	// 2.  Instantiate list of items
	List<int> myListDescending(DESCENDING);
	List<string> myListAscending(ASCENDING);
	List<Rupee> myListUnordered(UNORDERED);
	Stack<int> myList;
	List<int> newList;

	// 3A. Add integers to descending ordered list
	myListDescending.add(454);
	myListDescending.add(2323);
	myListDescending.add(344);
	myListDescending.add(2989);
	myListDescending.add(93);
	myListDescending.add(78);
	myListDescending.add(536);
	myListDescending.add(32);
	myListDescending.add(4225);
	myListDescending.add(425);

	// 3B. Print the resulting integer list
	cout << "\nIntegers list in descending order" << endl;
	cout << "---------------------------------" << endl;
	myListDescending.print();
	cout << endl;

	// 4A. Add strings to ascending ordered list
	myListAscending.add("Edward");
	myListAscending.add("Gail");
	myListAscending.add("Josh");
	myListAscending.add("Isaac");
	myListAscending.add("Harry");
	myListAscending.add("Frank");
	myListAscending.add("Adam");
	myListAscending.add("Drake");
	myListAscending.add("Charlotte");
	myListAscending.add("Bill");

	// 4B. Print the resulting string list
	cout << "\nStrings list in ascending order" << endl;
	cout << "---------------------------------" << endl;
	myListAscending.print();
	cout << endl;

	// 5A. Add rupee objects to unordered list
	
	// Fixed random sequence arrays of rupee.paise amounts.
	// These are parallel arrays.
	int rupee_value[] = { 45, 232, 34, 298, 9, 7, 53, 3, 422, 42 };
	int paise_value[] = { 40, 30, 40, 90, 30, 80, 60, 20, 45, 25 };

	// loop for 10 rupee values : 
	//		instantiate random rupee object
	//		insert into unordered list
	// end loop.
	for (int ndx = 0; ndx < 10; ndx++) {
		Rupee anItem(rupee_value[ndx], paise_value[ndx]);
		myListUnordered.add(anItem);
	} //end for loop

	cout << "\nRupee list in unsorted order" << endl;
	cout << "---------------------------------" << endl;

	// 5B. Print the resulting rupee object list
	myListUnordered.print();
	cout << endl;

	//myList.push(25);
	newList.addVanilla(33);
	newList.addVanilla(433);
	newList.addVanilla(333);
	newList.print();
	cout << endl;

	/*
	myList.push(44);
	myList.print();
	cout << endl;
	*/
	return 0;
}
