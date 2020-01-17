#include "Wallet.h"

Wallet::Wallet()
{
	wallet[DOLLAR] = new Dollar;
	wallet[POUND] = new Pound;
	wallet[RUPEE] = new Rupee;
	wallet[YEN] = new Yen;
	wallet[YUAN] = new Yuan;

}

Wallet::~Wallet()
{
//	delete wallet;
}

Currency & Wallet::operator[](const int &ndx)
{
	return *(wallet[ndx]);
}
