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

           			cout 	<< "Added " << currency<< " in dollars to wallet\n" << endl;
           break;
