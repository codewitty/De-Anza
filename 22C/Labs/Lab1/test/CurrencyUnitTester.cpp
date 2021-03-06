#include <iostream>
#include "Currency.h"
#include "Wallet.h"
using namespace std;

int main()
{
	// ----- Dollar class stuff -----
	Dollar firstDollar(12, 99), secondDollar(2, 75);  // Define two objects.
	Pound firstPound(24, 59), secondPound(1, 75);  // Define two objects.
	Yuan firstYuan(175, 25), secondYuan(1024, 16);  // Define two objects.
	Yen firstYen(3, 49), secondYen(2, 0);  // Define two objects.
	Rupee firstRupee(2400, 66), secondRupee(1234, 75);  // Define two objects.

	// Display the values in the objects.
	cout << "The dollavalues you entered are:\n";
	cout << firstDollar << " and " << secondDollar << endl;

	// Display the values in the objects.
	cout << "The dollavalues you entered are:\n";
	cout << firstPound << " and " << secondPound << endl;

	// Display the values in the objects.
	cout << "The dollavalues you entered are:\n";
	cout << firstYuan << " and " << secondYuan << endl;

	// Display the values in the objects.
	cout << "The dollavalues you entered are:\n";
	cout << firstYen << " and " << secondYen << endl;

	// Display the values in the objects.
	cout << "The dollavalues you entered are:\n";
	cout << firstRupee << " and " << secondRupee << endl;

	Wallet myWallet;

	myWallet.wallet[myWallet.DOLLAR] = &firstDollar;
	myWallet.wallet[myWallet.YEN]    = &firstYen;
	myWallet.wallet[myWallet.YUAN] = &firstYuan;
	myWallet.wallet[myWallet.POUND] = &firstPound;
	myWallet.wallet[myWallet.RUPEE] = &firstRupee;

	Currency temp = myWallet[myWallet.DOLLAR];

	cout << "OK : " << static_cast <Dollar&>(temp) << endl;

	// Here is the rub... let say I try and use Operator Overloading of +
	// The code looks like this
	//myWallet.wallet[myWallet.DOLLAR] = &(*myWallet.wallet[myWallet.DOLLAR] + firstDollar);

	// we would rather it looked like this: (commented out becasue [] overload is not right.
	
	// myWallet.wallet[myWallet.DOLLAR] = myWallet.wallet[myWallet.DOLLAR] + firstDollar;



	return 0;
}
