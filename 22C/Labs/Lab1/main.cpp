#include <iostream>

using namespace std;

int main() {

	Wallet myWallet;
	
	int select == 0;
	
	while (select == 0){
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
           			loop = true;
           			break;

       			default:
           			cout << "Please enter a valid choice from 1-5" << endl; 
           			break;
		}

		return 0;
}


