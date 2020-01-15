#include <iostream>

using namespace std;

int main() {

	Wallet myWallet;
	
	bool select = true;
	
	while (select){
		int choice;
			
		cout 	<< "What would you like to do with your wallet today?"
			<< endl
			<< "1: Add Money" << endl;
       			<< "2: Remove Money" << endl;
       			<< "3: View Wallet" << endl;
       			<< "4: Empty Wallet" << endl;
       			<< "5: EXIT" << endl << endl;
       			<< "Enter your Selection" << endl;
		cin << choice;

		switch (choice) {
			case 1:
				addMoney(myWallet);
				break;
			case 2:
           			removeMoney(myWallet);
           			break;

       			case 3:
           			viewWallet(myWallet);
           			break;

       			case 4:
           			emptyWallet(myWallet);
           			break;

       			case 5:
           			select = false;
           			break;

       			default:
           			cout << "Please enter a valid choice from 1-5" << endl; 
           			break;
		}

		return 0;
}

void	addMoney(Wallet &myWallet)
{
	bool loop = true;
	
	while(loop)
	{
		int choice = 0;
		int wcurrency = 0;
		int p_currency = 0;
		
		cout 	<< "What currency would you like to add today?"
			<< endl
			<< "1: Dollars" << endl;
       			<< "2: Pounds" << endl;
       			<< "3: Yen" << endl;
       			<< "4: Rupee" << endl;
			<< "5: Yuan" << endl;
       			<< "6: EXIT" << endl;
       			<< "Enter your Selection" << endl;
		cin << choice;
		switch (choice)
		{
			case 1:
				cout	<< "How many dollars would you like to add?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many cents would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.addMoney(Wallet::DOLLAR, currency);
           			break;
			case 2:
				cout	<< "How many pounds would you like to add?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many pence would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.addMoney(Wallet::POUND, currency);
           			break;
			case 3:
				cout	<< "How many Yen would you like to add?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many sen would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.addMoney(Wallet::YEN, currency);
           			break;
		
			case 4:
				cout	<< "How many Rupees would you like to add?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many paise would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.addMoney(Wallet::RUPEE, currency);
           			break;

			case 5:
				cout	<< "How many Yuan would you like to add?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many fen would you like to add?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.addMoney(Wallet::YUAN, currency);
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

void	removeMoney(Wallet &myWallet)
{
	bool loop = true;
	
	while(loop)
	{
		int choice = 0;
		int wcurrency = 0;
		int p_currency = 0;
		
		cout 	<< "What currency would you like to remove today?"
			<< endl
			<< "1: Dollars" << endl;
       			<< "2: Pounds" << endl;
       			<< "3: Yen" << endl;
       			<< "4: Rupee" << endl;
			<< "5: Yuan" << endl;
       			<< "6: EXIT" << endl;
       			<< "Enter your Selection" << endl;
		cin << choice;
		switch (choice)
		{
			case 1:
				cout	<< "How many dollars would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many cents would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::DOLLAR, currency);
           			break;
			case 2:
				cout	<< "How many pounds would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many pence would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::POUND, currency);
           			break;
			case 3:
				cout	<< "How many Yen would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many sen would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::YEN, currency);
           			break;
		
			case 4:
				cout	<< "How many Rupees would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many paise would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::RUPEE, currency);
           			break;

			case 5:
				cout	<< "How many Yuan would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many fen would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::YUAN, currency);
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

//Get values from wallet class and display them on screen
void viewWallet(Wallet &myWallet)
{
	cout << endl << "Your Wallet contains: " << endl << endl
       << "---> Dollars: " << fixed << setprecision(2) << myWallet.getMoney(Wallet::DOLLAR) << "\n"
       << "---> Pound: "<< fixed << setprecision(2) << myWallet.getMoney(Wallet::POUND) << "\n"
       << "---> Yen: "<< fixed << setprecision(2) << myWallet.getMoney(Wallet::YEN) << "\n"
       << "---> Rupees: "<< fixed << setprecision(2) << myWallet.getMoney(Wallet::RUPEE) << "\n"
       << "---> Yuan: "<< fixed << setprecision(2) << myWallet.getMoney(Wallet::YUAN) << "\n"
       << endl << endl;

   system("pause");
}

//Calls function from wallet class to set all values to zero
void emptyWallet(Wallet &myWallet)
{
   cout << endl << "   ***Emptying Wallet...***" << endl;
  
   myWallet.emptyWallet();
  
   cout << endl << "   ***Wallet Emptied***" << endl;

   system("pause");
}
