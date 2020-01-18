#include <iostream>
#include "Wallet.h"

using namespace std;

//forward declarations
void	addMoney(Wallet &); 
void	removeMoney(Wallet &); 
//void	viewWallet(Wallet &); 
//void	emptyWallet(Wallet &); 

int main()
{
	
   Wallet myWallet;   

   bool loop = false;

   while (!loop)
   {
	int choice = 0;

	cout 	<< endl 
		<< "What would you like to do with your Wallet today?" << endl;
       	cout 	<< "   1: Add Money" << endl;
       	cout 	<< "   2: Remove Money" << endl;
	cout 	<< "   3: View Wallet" << endl;
	cout 	<< "   4: Empty Wallet" << endl;
       	cout 	<< "   5: EXIT" << endl << endl;
	cout 	<< "   Your Choice: ";

	cin >> choice;
	cout << endl << endl;
      

       switch (choice)
       {
       case 1:
		addMoney(myWallet);
           break;

       case 2:
		removeMoney(myWallet);
           break;

       case 3:
           cout << "case 2";
           break;

       case 4:
           cout << "case 2";
           break;

       case 5:
           loop = true;
           break;

       default:
           cout << "\t\t**Please enter a valid choice**\n" << endl; //error message when choice is not from the menu
           break;

       }

   }
  
   return 0;
}


void	addMoney(Wallet &)
{
	bool loop = false;
	
	while(loop == false)
	{
		int choice = 0;
		int w_currency = 0;
		int p_currency = 0;
		
		cout 	<< "What currency would you like to add today?"
			<< endl
			<< "1: Dollars" << endl
       			<< "2: Pounds" << endl
       			<< "3: Yen" << endl
       			<< "4: Rupee" << endl
			<< "5: Yuan" << endl
       			<< "6: EXIT" << endl
       			<< "Enter your Selection" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout	<< "How many dollars would you like to add?"
					<< endl;
				cin 	>> w_currency;
				while (w_currency < 0 && w_currency > 2147483647)
				{
					cout	<< "please enter a valid value"
						<< " greater than 0" << endl;
					cin >> w_currency;
				}
				cout	<< "How many cents would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value "
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				myWallet.addMoney(Wallet::DOLLAR, w_currency, p_currency);
           			break;
			case 2:
				cout	<< "How many pounds would you like to add?"
					<< endl;
				cin 	>> w_currency;
				while (w_currency < 0)
				{
					cout	<< "please enter a valid value"
						<< " greater than 0" << endl;
					cin >> w_currency;
				}
				cout	<< "How many pence would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value "
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				//myWallet.addMoney(Wallet::POUND, w_currency, p_currency);
           			break;
			case 3:
				cout	<< "How many yen would you like to add?"
					<< endl;
				cin 	>> w_currency;
				while (w_currency < 0)
				{
					cout	<< "please enter a valid value"
						<< " greater than 0" << endl;
					cin >> w_currency;
				}
				cout	<< "How many sen would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value "
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				//myWallet.addMoney(Wallet::YEN, w_currency, p_currency);
           			break;
			case 4:
				cout	<< "How many rupees would you like to add?"
					<< endl;
				cin 	>> w_currency;
				while (w_currency < 0)
				{
					cout	<< "please enter a valid value"
						<< " greater than 0" << endl;
					cin >> w_currency;
				}
				cout	<< "How many paise would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value "
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				//myWallet.addMoney(Wallet::RUPEE, w_currency, p_currency);
           			break;
			case 5:
				cout	<< "How many yuan would you like to add?"
					<< endl;
				cin 	>> w_currency;
				while (w_currency < 0)
				{
					cout	<< "please enter a valid value"
						<< " greater than 0" << endl;
					cin >> w_currency;
				}
				cout	<< "How many fen would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value "
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				//myWallet.addMoney(Wallet::YUAN, w_currency, p_currency);
           			break;
			case 6:
				loop = true;
				break;

			default:
				cout 	<< "Please enter a valid choice between"
					<< " 1-6" << endl;
				break;
		}
	}
}

void	removeMoney(Wallet &myWallet)
{
	bool loop = true;
	
	while(loop)
	{
		int choice = 0;
		int w_currency = 0;
		int p_currency = 0;
		
		cout 	<< "What currency would you like to remove today?"
			<< endl
			<< "1: Dollars" << endl
       			<< "2: Pounds" << endl
       			<< "3: Yen" << endl
       			<< "4: Rupee" << endl
			<< "5: Yuan" << endl
       			<< "6: EXIT" << endl
       			<< "Enter your Selection" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout	<< "How many dollars would you like to remove?"
					<< endl;
				cin 	>> w_currency;	 
				cout	<< "How many cents would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::DOLLAR, w_currency, p_currency);
           			break;
			case 2:
				cout	<< "How many pounds would you like to remove?"
					<< endl;
				cin 	>> w_currency;	 
				cout	<< "How many pence would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::POUND, w_currency,p_currency);
           			break;
			case 3:
				cout	<< "How many Yen would you like to remove?"
					<< endl;
				cin 	>> w_currency;	 
				cout	<< "How many sen would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::YEN, w_currency,p_currency);
           			break;
		
			case 4:
				cout	<< "How many Rupees would you like to remove?"
					<< endl;
				cin 	>> w_currency;	 
				cout	<< "How many paise would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::RUPEE, w_currency,p_currency);
           			break;

			case 5:
				cout	<< "How many Yuan would you like to remove?"
					<< endl;
				cin 	>> w_currency;	 
				cout	<< "How many fen would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::YUAN, w_currency, p_currency);
           			break;
	
			case 6:
				loop = false;
				break;

			default:
				cout 	<< "Please enter a valid choice between"
					<< " 1-6" << endl;
				break;
		}
	}
}

/*Get values from wallet class and display them on screen
void viewWallet(Wallet &myWallet)
{
	cout << endl << "Your Wallet contains: " << endl << endl
       << "---> Dollars: " <<  myWallet.getMoney(Wallet::DOLLAR) << "\n"
       << "---> Pound: "<< myWallet.getMoney(Wallet::POUND) << "\n"
       << "---> Yen: "<< myWallet.getMoney(Wallet::YEN) << "\n"
       << "---> Rupees: "<<  myWallet.getMoney(Wallet::RUPEE) << "\n"
       << "---> Yuan: "<< myWallet.getMoney(Wallet::YUAN) << "\n"
       << endl << endl;

   system("pause");
}

//Calls function from wallet class to set all values to zero
void emptyWallet(Wallet &)
{
   cout << endl << "   ***Emptying Wallet...***" << endl;
  
   myWallet.emptyWallet();
  
   cout << endl << "   ***Wallet Emptied***" << endl;

   system("pause");
}
*/
