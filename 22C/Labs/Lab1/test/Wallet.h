#pragma once

#include "Currency.h"
#include "Dollar.h"
#include "Rupee.h"
#include "Yen.h"
#include "Yuan.h"
#include "Pound.h"


class Wallet; // Forward Declaration
const int WALLET_SIZE(5);  // 5 types....

class Wallet
{
public:

	// Currency Pointer for each currency type   
	Currency *wallet[WALLET_SIZE];

	//enumerator to hold currency types
	enum currencyType
	{
		DOLLAR,
		POUND,
		YEN,
		RUPEE,
		YUAN
	};

	Wallet();
	~Wallet();

	// Array of curencies...
	Currency &operator [] (const int &);
};
