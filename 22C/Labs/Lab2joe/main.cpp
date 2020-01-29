/* 
Lab2
Names: Joseph Saunders and Joshua N Gomes
Class: CIS 22C MW 1800 - 1950 hrs
*/

#include <iostream>
#include "Currency.h"
#include "Dollar.h"
#include "ArrayTemplateClass.h"
#include <string>

using namespace std;

int SORT_MAX_SIZE = 16;
int arr_int[16];
string arr_s[16];
Dollar arr_d[16];

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
		cin >> SORT_MAX_SIZE;
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
						 arr_int[i] = user_input;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << arr_int[i] << " "; 
					 }
					 cout << endl;
				break;
    		case 2: // Process a string array 
				cout << "   Please enter the strings you would like to sort" << endl
					 << "   One word strings only!" << endl
					 << "   Hit enter after each string " << endl
					 << "   (1-16 strings max)" << endl << "   ";
					 for (int i = 0; i < user_size; i++)
					 {
						 cin >> arr_d[i];
						 cout << "   ";
						 //arr_s[i] = user_input_str;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << arr_d[i] << " "; 
					 }
					 cout << endl;
				//string template;
				break;
			case 3: // Process a dollar array
				cout << "   Please enter the dollars you would like to sort" << endl
					 << "   One word strings only!" << endl
					 << "   Hit enter after each dollar " << endl
					 << "   (1-16 dollars max)" << endl << "   ";
					 for (int i = 0; i < user_size; i++)
					 {
						 cin >> arr_s[i];
						 cout << "   ";
						 //arr_s[i] = user_input_str;
					 }
					 for (int i = 0; i < user_size; i++)
					 {
						 cout << arr_s[i] << " "; 
					 }
					 cout << endl;
				//Dollar templ;
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
