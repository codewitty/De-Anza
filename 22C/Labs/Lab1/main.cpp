/* 
Lab1
Names: Joseph Saunders and Joshua N Gomes
Class: CIS 22C MW 1800 - 1950 hrs
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "Currency.h"
#include "Wallet.h"
using namespace std;

// forward declarations
void addMoney(Wallet&);
void removeMoney(Wallet&);
void viewWallet(Wallet&);
void emptyWallet(Wallet&);
bool validate_input(string);

//****************************************************************************
// int main() - Main declares defines a wallet that is capable of holding and 
// managing 5 currency types. The currencies supported are Dollars, Pounds,
// Yen, Rupee and Yuan.
// 
// You can add money to the wallet, remove money from the wallet, check the 
//	amount of money in the wallet and empty the wallet.
// 
// PSEUCODE: 
// 
// While not done
//	  select action from list of wallet methods
//	  executes action from method list 
//	  ask if done
//	  	  exit
//	  else continue
//	  
//***************************************************************************

int main()
{
	// This is our Wallet instance. All the code is written to create this
	// virtual Wallet.
	Wallet myWallet;

	bool loop = true;

	// Loop until done
	while (loop)
	{
		string valid;
		int choice = 0;

		// Output User Menu
		cout << endl 
	     	 << "   What would you like to do with your Wallet today?" << endl;
     	cout << "   1: Add Money" << endl;
     	cout << "   2: Remove Money" << endl;
     	cout << "   3: View Wallet" << endl;
     	cout << "   4: Empty Wallet " << endl;
     	cout << "   5: EXIT" << endl << endl;
     	cout << "   Your Choice: ";

		// User response recorded
     	getline(cin, valid);

		// User response validation
		while (!validate_input(valid)){
			cout << "Error!! Invalid input detected. Enter a positive number please: ";
			getline(cin, valid);
		}
		// Convert string to int for switch menu
		choice = atoi(valid.c_str());
     	cout << endl;

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
			
			default: // We re-prompt the user to input a correnct menu option.
				cout 	<< "   Please enter a valid choice between"
						<< "   1-5" << endl;

				break;
		}
	}
	return 0; // Program Finished
}

//**********************************************************************
// void addMoney(Wallet &mWallet) is our Add Money to wallet action.
//
// Pre: An existing Wallet.
// Post: An existing Wallet with one currency updated.
// Return: Nothing 
//**********************************************************************

void addMoney(Wallet &mWallet)
{
	bool loop = true;

	// Loop until done.
	while (loop)
	{
		int choice = 0; 	// Currency Choice
		int w_currency = 0; // Currency Whole Units
		int p_currency = 0; // Currency Fractional Units
		string valid;
	
		// Present the User Menu of Currency types
		cout << "   What currency would you like to add today?"
			 << endl
			 << "   1: Dollars" << endl
			 << "   2: Pounds" << endl
			 << "   3: Yen" << endl
			 << "   4: Rupee" << endl
			 << "   5: Yuan" << endl
       		 << "   6: EXIT TO MAIN MENU" << endl
       		 << "   Enter your Selection: ";

		// User response recorded
     	getline(cin, valid);

		// User response validation
		while (!validate_input(valid)){
			cout << "Error!! Invalid input detected. Enter a positive number please: ";
			getline(cin, valid);
		}
		// Convert string to int for switch menu
		choice = atoi(valid.c_str());
     	cout << endl;

		switch (choice)
		{
			case 1: // Process Dollars added to Wallet
			{
				Dollar temp(w_currency, p_currency);
				cin >> temp;
				// There are 3 operators overloaded to make this code lean and elegant
				mWallet[mWallet.DOLLAR] = mWallet[mWallet.DOLLAR] + static_cast<Currency>(temp); 
				break;
			}

			case 2: // Process Pounds added to Wallet
			{
				Pound temp(w_currency, p_currency);
				cin >> temp;
				// There are 3 operators overloaded to make this code lean and elegant
				mWallet[mWallet.POUND] = mWallet[mWallet.POUND] + static_cast<Currency>(temp); 
				break;
			}

			case 3: // Process Yen added to Wallet
			{
				Yen temp(w_currency, p_currency);
				cin >> temp;
				// There are 3 operators overloaded to make this code lean and elegant
				mWallet[mWallet.YEN] = mWallet[mWallet.YEN] + static_cast<Currency>(temp); 
				break;
			}

			case 4: // Process Rupee added to Wallet
			{
				Rupee temp(w_currency, p_currency);
				cin >> temp;
				// There are 3 operators overloaded to make this code lean and elegant
				mWallet[mWallet.RUPEE] = mWallet[mWallet.RUPEE] + static_cast<Currency>(temp); 
				break;
			}
			
			case 5: // Process Yuan added to Wallet
			{
				Yuan temp(w_currency, p_currency);
				cin >> temp;
				// There are 3 operators overloaded to make this code lean and elegant
				mWallet[mWallet.YUAN] = mWallet[mWallet.YUAN] + static_cast<Currency>(temp); 
				break;
			}

			// This is our exit process, break loop and return to main menu
			// for further user processing.
			case 6:
				loop = false;

				break;

			default: // We re-prompt the user to input a correnct menu option.
				cout 	<< "   Please enter a valid choice between"
					<< "   1-6" << endl;

				break;
		}
	}
}

//*************************************************************************
// void removeMoney(Wallet &mWallet) is our Remove Money from wallet action.
//
// Pre: An existing Wallet.
// Post: An existing Wallet with one currency updated.
// Return: Nothing 
//*************************************************************************
void removeMoney(Wallet &mWallet)
{
	bool loop = true;

	// Loop until done.
	while (loop)
	{
		int choice = 0; 	// Currency Choice
		int w_currency = 0; // Currency Whole Units
		int p_currency = 0; // Currency Fractional Units
		string valid;
	
		// Present the User Menu of Currency types
		cout << "   What currency would you like to remove today?"
			 << endl
			 << "   1: Dollars" << endl
			 << "   2: Pounds" << endl
			 << "   3: Yen" << endl
			 << "   4: Rupee" << endl
			 << "   5: Yuan" << endl
       		 << "   6: EXIT TO MAIN MENU" << endl
       		 << "   Enter your Selection: ";

		// User response recorded
     	getline(cin, valid);

		// User response validation
		while (!validate_input(valid)){
			cout << "Error!! Invalid input detected. Enter a positive number please: ";
			getline(cin, valid);
		}
		// Convert string to int for switch menu
		choice = atoi(valid.c_str());
     	cout << endl;

		switch (choice)
		{
			case 1: // Process Dollars removed from Wallet
			{
				// The code below validates user input and records it.
				int dollars = (mWallet[mWallet.DOLLAR]).getWholePart();
				int cents 	= (mWallet[mWallet.DOLLAR]).getFractionalPart();

				cout << "   Your Wallet currently has: "
					 << dollars << " dollars and " << cents << " cents."
					 << endl
					 << "   How many dollars would you like to remove?"
					 << endl
					 << "   ";
				cin  >> w_currency;
				
				while (w_currency < 0 || (w_currency > dollars))
				{
					cout << "   !!! Please enter a valid value"
						 << " greater than 0 and less than "
						 << (dollars + 1)
						 << " !!!"
						 << endl
						 << "   ";
					cin  >> w_currency;
				}

				if (dollars > 0) 
				{
					cout << "   How many cents would you like to remove?"
						 << " (Between 1- " << (cents + 1) << ")" << endl
					 	 << "   ";
					cin	 >> p_currency;
					while (p_currency < 0 || p_currency > 99)
					{
						cout << "   !!! Please enter a valid value "
							 << "between 1-99 !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				else if (dollars == 0 && cents != 0)
				{
					cout << "   How many cents would you like to remove?"
						 << " (Between 1-99)" << endl
						 << "   ";
					cin	 >> p_currency;
					while (p_currency > cents)
					{
						cout << "   !!! Please enter a valid value "
							 << " less than " << (cents + 1) << " !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				// This is where we remove dollars from the wallet
				// There are 3 operators overloaded to make this code lean and elegant
				Dollar temp(w_currency, p_currency);
				mWallet[mWallet.DOLLAR] = mWallet[mWallet.DOLLAR] - static_cast<Currency>(temp); 

           		break;
			}
			
			case 2: // Process Pounds removed from Wallet
			{
				// The code below validates user input and records it.
				int dollars = (mWallet[mWallet.POUND]).getWholePart();
				int cents 	= (mWallet[mWallet.POUND]).getFractionalPart();

				cout << "   Your Wallet currently has: "
					 << dollars << " pounds and " << cents << " pence."
					 << endl
					 << "   How many pounds would you like to remove?"
					 << endl
					 << "   ";
				cin  >> w_currency;
				
				while (w_currency < 0 || (w_currency > dollars))
				{
					cout << "   !!! Please enter a valid value"
						 << " greater than 0 and less than "
						 << (dollars + 1)
						 << " !!!"
						 << endl
						 << "   ";
					cin  >> w_currency;
				}

				if (dollars > 0) 
				{
					cout << "   How many pence would you like to remove?"
						 << " (Between 1- " << cents << ")" << endl
					 	 << "   ";
					cin	 >> p_currency;
					while (p_currency < 0 || p_currency > 99)
					{
						cout << "   !!! Please enter a valid value "
							 << "between 1-99 !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				else if (dollars == 0 && cents != 0)
				{
					cout << "   How many pence would you like to remove?"
						 << " (Between 1-99)" << endl
						 << "   ";
					cin	 >> p_currency;
					while (p_currency > cents)
					{
						cout << "   !!! Please enter a valid value "
							 << " less than " << (cents + 1) << " !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				// This is where we remove pounds from the wallet
				// There are 3 operators overloaded to make this code lean and elegant
				Pound temp(w_currency, p_currency);
				mWallet[mWallet.POUND] = mWallet[mWallet.POUND] - static_cast<Currency>(temp); 

           		break;
			}
			
			case 3: // Process Yen removed from Wallet
			{
				// The code below validates user input and records it.
				int dollars = (mWallet[mWallet.YEN]).getWholePart();
				int cents 	= (mWallet[mWallet.YEN]).getFractionalPart();

				cout << "   Your Wallet currently has: "
					 << dollars << " yen and " << cents << " sen."
					 << endl
					 << "   How many yen would you like to remove?"
					 << endl
					 << "   ";
				cin  >> w_currency;
				
				while (w_currency < 0 || (w_currency > dollars))
				{
					cout << "   !!! Please enter a valid value"
						 << " greater than 0 and less than "
						 << (dollars + 1)
						 << " !!!"
						 << endl
						 << "   ";
					cin  >> w_currency;
				}

				if (dollars > 0) 
				{
					cout << "   How many sen would you like to remove?"
						 << " (Between 1- " << cents << ")" << endl
					 	 << "   ";
					cin	 >> p_currency;
					while (p_currency < 0 || p_currency > 99)
					{
						cout << "   !!! Please enter a valid value "
							 << "between 1-99 !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				else if (dollars == 0 && cents != 0)
				{
					cout << "   How many sen would you like to remove?"
						 << " (Between 1-99)" << endl
						 << "   ";
					cin	 >> p_currency;
					while (p_currency > cents)
					{
						cout << "   !!! Please enter a valid value "
							 << " less than " << (cents + 1) << " !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				// This is where we remove yen from the wallet
				// There are 3 operators overloaded to make this code lean and elegant
				Yen temp(w_currency, p_currency);
				mWallet[mWallet.YEN] = mWallet[mWallet.YEN] - static_cast<Currency>(temp); 

           		break;
			}

			case 4: // Process Rupees removed from Wallet
			{
				// The code below validates user input and records it.
				int dollars = (mWallet[mWallet.RUPEE]).getWholePart();
				int cents 	= (mWallet[mWallet.RUPEE]).getFractionalPart();

				cout << "   Your Wallet currently has: "
					 << dollars << " rupees and " << cents << " paise."
					 << endl
					 << "   How many rupees would you like to remove?"
					 << endl
					 << "   ";
				cin  >> w_currency;
				
				while (w_currency < 0 || (w_currency > dollars))
				{
					cout << "   !!! Please enter a valid value"
						 << " greater than 0 and less than "
						 << (dollars + 1)
						 << " !!!"
						 << endl
						 << "   ";
					cin  >> w_currency;
				}
				
				if (dollars > 0) 
				{
					cout << "   How many paise would you like to remove?"
						 << " (Between 1- " << cents << ")" << endl
					 	 << "   ";
					cin	 >> p_currency;
					while (p_currency < 0 || p_currency > 99)
					{
						cout << "   !!! Please enter a valid value "
							 << "between 1-99 !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				else if (dollars == 0 && cents != 0)
				{
					cout << "   How many paise would you like to remove?"
						 << " (Between 1-99)" << endl
						 << "   ";
					cin	 >> p_currency;
					while (p_currency > cents)
					{
						cout << "   !!! Please enter a valid value "
							 << " less than " << (cents + 1) << " !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				// This is where we remove rupees from the wallet
				// There are 3 operators overloaded to make this code lean and elegant
				Rupee temp(w_currency, p_currency);
				mWallet[mWallet.RUPEE] = mWallet[mWallet.RUPEE] - static_cast<Currency>(temp); 

           		break;
			}
			
			case 5: // Process Yuan removed from Wallet
			{
				// The code below validates user input and records it.
				int dollars = (mWallet[mWallet.YUAN]).getWholePart();
				int cents 	= (mWallet[mWallet.YUAN]).getFractionalPart();

				cout << "   Your Wallet currently has: "
					 << dollars << " yuan and " << cents << " fen."
					 << endl
					 << "   How many yuan would you like to remove?"
					 << endl
					 << "   ";
				cin  >> w_currency;
				
				while (w_currency < 0 || (w_currency > dollars))
				{
					cout << "   !!! Please enter a valid value"
						 << " greater than 0 and less than "
						 << (dollars + 1)
						 << " !!!"
						 << endl
						 << "   ";
					cin  >> w_currency;
				}
				if (dollars > 0) 
				{
					cout << "   How many fen would you like to remove?"
						 << " (Between 1- " << cents << ")" << endl
					 	 << "   ";
					cin	 >> p_currency;
					while (p_currency < 0 || p_currency > 99)
					{
						cout << "   !!! Please enter a valid value "
							 << "between 1-99 !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				else if (dollars == 0 && cents != 0)
				{
					cout << "   How many fen would you like to remove?"
						 << " (Between 1-99)" << endl
						 << "   ";
					cin	 >> p_currency;
					while (p_currency > cents)
					{
						cout << "   !!! Please enter a valid value "
							 << " less than " << (cents + 1) << " !!!" << endl
							 << "   ";
						cin  >> p_currency;
					}
				}
				// This is where we remove Yuan from the wallet
				// There are 3 operators overloaded to make this code lean and elegant
				Yuan temp(w_currency, p_currency);
				mWallet[mWallet.YUAN] = mWallet[mWallet.YUAN] - static_cast<Currency>(temp); 

           		break;
			}
			// This is our exit process, break loop and return to main menu
			// for further user processing.
			case 6:
				loop = false;

				break;

			default: // We re-prompt the user to input a correnct menu option.
				cout 	<< "   !!! Please enter a valid choice between"
					<< " 1-6 !!!" << endl << endl;

				break;
		}
	}
}

void viewWallet(Wallet& mWallet)
{
	cout << "   Your wallet contains " << endl
		 << "  ***   "
		 << (mWallet[mWallet.DOLLAR]).getWholePart()
		 << " dollars and "
		 << (mWallet[mWallet.DOLLAR]).getFractionalPart()
		 << " cents"
		 << "   ***" << endl
		 << "  ***   "
		 << (mWallet[mWallet.POUND]).getWholePart()
		 << " pounds and "
		 << (mWallet[mWallet.POUND]).getFractionalPart()
		 << " pence"
		 << "   ***" << endl
		 << "  ***   "
		 << (mWallet[mWallet.YEN]).getWholePart()
		 << " yen and "
		 << (mWallet[mWallet.YEN]).getFractionalPart()
		 << " sen"
		 << "   ***" << endl
		 << "  ***   "
		 << (mWallet[mWallet.RUPEE]).getWholePart()
		 << " rupees and "
		 << (mWallet[mWallet.RUPEE]).getFractionalPart()
		 << " paise"
		 << "   ***" << endl
		 << "  ***   "
		 << (mWallet[mWallet.YUAN]).getWholePart()
		 << " yuan and "
		 << (mWallet[mWallet.YUAN]).getFractionalPart()
		 << " fen"
		 << "   ***" << endl;
}

void emptyWallet(Wallet& mWallet)
{
	for (int index = 0; index < WALLET_SIZE; index++)
	{
		mWallet[index].setWholePart(0);
		mWallet[index].setFractionalPart(0);
	}

	cout << "Your wallet is now empty" << endl << endl;
}

bool validate_input(string str) {
		// Check user input for non-numeric values
		if (str.end() != find_if_not(str.begin(), str.end(), ::isdigit)) {
			return false;
		}
		// Check for empty string
		else if (str.empty())
			return false;
		else
			return true;
}

