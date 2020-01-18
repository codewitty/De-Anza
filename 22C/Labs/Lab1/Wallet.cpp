#include "Wallet.h"

// Constructor
Wallet::Wallet()
{
	wallet[DOLLAR] = new Dollar;
	wallet[POUND] = new Pound;
	wallet[RUPEE] = new Rupee;
	wallet[YEN] = new Yen;
	wallet[YUAN] = new Yuan;

}

// Destructor
Wallet::~Wallet()
{
	for (int ndx = 0; ndx < WALLET_SIZE; ndx++) {
		delete wallet[ndx];
	}
}


// Our subscript operator
Currency& Wallet::operator[](const int &ndx)
{
	return * (wallet[ndx]);
}
