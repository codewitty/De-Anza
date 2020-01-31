/* 
Lab2
Names: Joseph Saunders and Joshua N Gomes
Class: CIS 22C MW 1800 - 1950 hrs
*/

#include <iostream>
//#include "Currency.h"
//#include "Dollar.h"
#include "ArrayTemplateClass.h"
#include <string>

using namespace std;

template<typename T>
bool pred(T &Lhs, T &Rhs) {
	return Lhs < Rhs;
}

/*
bool pred(Dollar &Lhs, Dollar &Rhs) {
	if (Lhs < Rhs)
		return true;
	return false;
}
*/

template<typename T>
void swapit(T &L, T &R) {
	T tmp = L;
	L = R;
	R = tmp;
}


template<typename T>
void recurSelectionSort(Array<T> &ArrayToSort, int ArraySize, int PartitionIndex = 0) {
	if (PartitionIndex >= ArraySize)
		return; // Should be sorted.
	  // Find min element
	T MinElem = ArrayToSort[PartitionIndex];

	int MinElemIdx = PartitionIndex;
	for (int ndx = PartitionIndex; ndx < ArraySize; ++ndx)
		if (pred(ArrayToSort[ndx], MinElem)) {
			MinElem = ArrayToSort[ndx];
			MinElemIdx = ndx;
		}
	// Found the minimum element. It's in MinElemIdx
	swapit(ArrayToSort[PartitionIndex], ArrayToSort[MinElemIdx]);
	// Now everything until PartitionIndex is sorted. recurse on beyond the PartitionIndex
	recurSelectionSort(ArrayToSort, ArraySize, PartitionIndex + 1);
}

const int SORT_MAX_SIZE = 16;
Array<int> aIntArray[16];
//Array<string> aStringArray[16];
//Array<Dollar> aDollarArray[16];

int main()
{
	int user_size;

	cout << "   How many elements would you like to sort today (1-16)"
		 << endl << "   ";
	cin >> user_size;
	while (user_size < 1 || user_size > SORT_MAX_SIZE)
	{
		cout << "   Please enter a valid value between 1 and 16"
			 << endl << "   ";
		cin >> user_size;
	}

	int choice;

	cout << "   What type of data would you like to enter?" << endl;
    cout << "   1: Integer(int)" << endl;
    cout << "   2: String" << endl;
    cout << "   3: Dollar" << endl;
    cout << "   4: Exit" << endl;
    cout << "   Your Choice: ";

	// User response recorded
    cin >> choice;
    cout << endl << endl;

		// This switch will execute all actions from the menu
    	switch (choice)
    	{
    		case 1: // Process an Integer array
				int user_input;
				cout << "   Please enter the integers you would like to sort" << endl
					 << "   Hit enter after each integer " << endl
					 << "   (1-16 integers max)" << endl << "   ";
					 for (int i = 0; i < user_size; i++)
					 {
						 cin >> user_input;
						 cout << "   ";
						 aIntArray[i] = user_input;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aIntArray[i] << " "; 
					 }
					 cout << endl;
					 recurSelectionSort(aIntArray, user_size);
				break;
    		case 2: // Process a string array 
			/*
				cout << "   Please enter the strings you would like to sort" << endl
					 << "   One word strings only!" << endl
					 << "   Hit enter after each string " << endl
					 << "   (1-16 strings max)" << endl << "   ";
					 for (int i = 0; i < user_size; i++)
					 {
						 cin >> aStringArray[i];
						 cout << "   ";
						 //aStringArray[i] = user_input_str;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aStringArray[i] << " "; 
					 }
					 cout << endl;
				//string template;
				*/
				break;
			case 3: // Process a dollar array
				/*
				cout << "   Please enter the dollars you would like to sort" << endl
					 << "   One word strings only!" << endl
					 << "   Hit enter after each dollar " << endl
					 << "   (1-16 dollars max)" << endl << "   ";
					 for (int i = 0; i < user_size; i++)
					 {
						 cin >> aStringArray[i];
						 cout << "   ";
						 //aStringArray[i] = user_input_str;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aStringArray[i] << " "; 
					 }
					 cout << endl;
				//Dollar templ;
				*/
				break;
    		case 4: // We are done. Exiting now.
				cout << "   Exiting your Wallet" << endl << endl;
				choice = false;
				break;
			default: // We re-prompt the user to input a correnct menu option.
				cout 	<< "   Please enter a valid choice between"
						<< "   1-3" << endl;
				break;
		}
	return 0; // Program Finished
}
