/*
Lab02
Names : Joseph Saunders and Joshua Gomes
Class : CIS22C61Y
*/


#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <string>
#include "ArrayTemplateClass.h"
#include "Dollar.h"
#include "SelectionSort.h"

using namespace std;


//*********************************************************************************
// int main() - Main declares defines 3 arrays of max size 16, int, string, dollar
// asks the user for the size of the array and the type of array.
// A menu is used to record the user input
// The user can use the menu to sort the arrays in the descending order
// 
// PSEUDOCODE:
// 
// While not done
//	  enter the number of items to process
//	  enter the type of items to process
//	  enter each item upto the prev specified number.
//	  sort items in descending order and provide+log output.
//	  ask if done
//	  	  exit
//	  else restart
//	  
//********************************************************************************
int main()
{
	const int     SORT_MAX_SIZE = 16;
	Array<int>    aIntArray(SORT_MAX_SIZE);		// An array of type int using Array Template
	Array<string> aStringArray(SORT_MAX_SIZE);	// An array of type String using Array Template
	Array<Dollar> aDollarArray(SORT_MAX_SIZE);	// An array of type Dollar using Array Template

	// handle logging file setup
	// in the initial case we just creat the file and then close it
	ofstream exelog;
	exelog.open("Lab02_Log.txt");
	exelog << "Lab   : 02\n";
	exelog << "Names : Joseph Saunders and Joshua Gomes\n";
	exelog << "Class : CIS22C61Y\n";
	exelog.close();

	bool loop = true;	// Exit condition

	while (loop)
	{
		int choice = 0;

		int user_size;

		// User input for size of array
		cout << "   How many elements would you like to sort today (1-16)"
			<< endl << "   ";
		cin >> user_size;

		//Validate user input
		while (user_size < 1 || user_size > SORT_MAX_SIZE)
		{
			cout << "   Please enter a valid value between 1 and 16"
				<< endl << "   ";
			cin >> user_size;
		}

		// Menu for array type
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
			cout << "   Please enter the integers you would like to sort" << endl
				<< "   Hit enter after each integer " << endl
				<< "   (1-16 integers max)" << endl << "   ";
			for (int i = 0; i < user_size; i++)
			{
				cin >> aIntArray[i];
				cout << "   ";
			}
			exelog.open("Lab02_Log.txt", ios::app);
			exelog << "\n   +++++++++++++++" << endl;
			cout << "\n   +++++++++++++++" << endl;
			exelog.close();
			recurSelectionSort(aIntArray, user_size);
			exelog.open("Lab02_Log.txt", ios::app);
			cout << "   ===============" << endl << endl;
			exelog << "   ===============" << endl << endl;
			exelog.close();
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
			}
			exelog.open("Lab02_Log.txt", ios::app);
			exelog << "\n   +++++++++++++++" << endl;
			cout << "\n   +++++++++++++++" << endl;
			exelog.close();
			recurSelectionSort(aStringArray, user_size);
			cout << "   ===============" << endl << endl;
			exelog << "   ===============" << endl << endl;
			exelog.close();
			break;
		case 3: // Process a dollar array

			cout << "   Please enter the dollar and cent amounts you would like to sort" << endl
				<< "   Hit enter after each dollar and cent amount " << endl;
			for (int i = 0; i < user_size; i++)
			{
				cin >> aDollarArray[i];
			}
			exelog.open("Lab02_Log.txt", ios::app);
			exelog << "\n   +++++++++++++++" << endl;
			cout << "\n   +++++++++++++++" << endl;
			recurSelectionSort(aDollarArray, user_size);
			cout << "   ===============" << endl << endl;
			exelog << "   ===============" << endl << endl;
			exelog.close();
			break;
		case 4: // We are done. Exiting now.
			cout << "   Exiting Program" << endl << endl;
			loop = false;
			break;
		default: // We re-prompt the user to input a correnct menu option.
			cout << "   Please enter a valid choice between"
				<< "   1-3" << endl;
			break;
		}
	}
	return 0; // Program Finished
}
