#include <iostream>
#include <string>
#include "ArrayTemplateClass.h"
#include "Dollar.h"
#include "SelectionSort.h"
using namespace std;

int main()
{
	const int     SORT_MAX_SIZE = 16;
	Array<int>    aIntArray(SORT_MAX_SIZE);
	Array<string> aStringArray(SORT_MAX_SIZE);
	Array<Dollar> aDollarArray(SORT_MAX_SIZE);
	
	bool loop = true;

	while (loop)
	{
	int choice = 0;

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
					 /*
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aIntArray[i] << " "; 
					 }
					 cout << endl << "   ";
					 */
					 recurSelectionSort(aIntArray, user_size);
					 /*
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aIntArray[i] << " "; 
					 }
					 cout << "   " << endl;
					 */
				break;
    		case 2: // Process a string array 
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
					 cout << endl << "   ";
					 recurSelectionSort(aStringArray, user_size);
					 /*
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aStringArray[i] << " "; 
					 }
					 cout << "   " << endl;
					 */
				//string template;
				break;
			case 3: // Process a dollar array
				cout << "   Please enter the dollars you would like to sort" << endl
					 << "   One word strings only!" << endl
					 << "   Hit enter after each dollar " << endl
					 << "   (1-16 dollars max)" << endl << "   ";
					 for (int i = 0; i < user_size; i++)
					 {
						 cin >> aDollarArray[i];
						 cout << "   ";
						 //aStringArray[i] = user_input_str;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << aDollarArray[i] << " "; 
					 }
					 cout << endl;
				break;
    		case 4: // We are done. Exiting now.
				cout << "   Exiting Program" << endl << endl;
				loop = false;
				break;
			default: // We re-prompt the user to input a correnct menu option.
				cout 	<< "   Please enter a valid choice between"
						<< "   1-3" << endl;
				break;
		}
	}
	return 0; // Program Finished
}

/*
	// Initialize the arrays...
	for (int nCount = 0; nCount < RANDSEQSIZE; nCount++)
	{
//		Dollar workDollar;
//		workDollar.setWholePart(fakeSequence[nCount] + 1);
//		workDollar.setFractionalPart(fakeSequence[nCount] + 2);

		aIntArray[nCount] = fakeSequence[nCount];
//		aStringArray[nCount] = "String" + std::to_string(fakeSequence[nCount]);
//		aDollarArray[nCount] = workDollar;
	}

	// dump the arrays
	for (int nCount = RANDSEQSIZE-1; nCount >= 0; nCount--) {
		cout << aIntArray[nCount] << "\t" << aStringArray[nCount] << endl;
//		cout << "Dollar : " << aDollarArray[nCount] << endl;
	}

	recurSelectionSort(aIntArray, RANDSEQSIZE);
//	recurSelectionSort(aDollarArray, RANDSEQSIZE);

	for (int nCount = RANDSEQSIZE-1; nCount >= 0; nCount--) {
		cout << aIntArray[nCount] << endl;
	}

//	for (int nCount = RANDSEQSIZE-1; nCount >= 0; nCount--) {
//		cout << aDollarArray[nCount] << endl;
//	}

//	system("pause");

	cout << "Hello World!" << endl;
	return 0;
}
*/
