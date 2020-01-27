/* 
Lab2
Names: Joseph Saunders and Joshua N Gomes
Class: CIS 22C MW 1800 - 1950 hrs
*/

#include <iostream>
#include "Currency.h"
#include "Wallet.h"
using namespace std;

int SORT_MAX_SIZE;

int main()
{
	
	cout << "   How many elements would you like to sort today (1-16)"
		 << endl << "   ";
	cin >> SORT_MAX_SIZE;
	while (SORT_MAX_SIZE < 1 || SORT_MAX_SIZE > 16)
	{
		cout << "   Please enter a valid value between 1 and 16;
			 << endl << "   ";
		cin >> SORT_MAX_SIZE;
	}

	int choice;

	cout << "   What type of data would you like to enter?"
    cout << "   1: Integer(int)" << endl;
    cout << "   2: String" << endl;
    cout << "   3: Dollar" << endl;
    cout << "   Your Choice: ";

	// User response recorded
    cin >> choice;
    cout << endl << endl;

		// This switch will execute all actions from the menu
    	switch (choice)
    	{
    		case 1: // Add money to the wallet.
	     		addMoney(myWallet);
				break;
    		case 2: // Remove money from the wallet.
	     		removeMoney(myWallet);
				break;
    		case 3: // View money in wallet.
	     		viewWallet(myWallet);
				break;
    		case 4: // Empty Wallet. 
	     		emptyWallet(myWallet);
				break;
    		case 5: // We are done. Exiting now.
				cout << "   Exiting your Wallet" << endl << endl;
				loop = false;
				break;
		}
	}
	return 0; // Program Finished
}

