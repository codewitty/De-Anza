//Wallet.h

#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <iostream>

#include "Currency.h"
#include "Dollar.h"
#include "Rupee.h"
#include "Yen.h"
#include "Yuan.h"
#include "Pound.h"

class Wallet;
const int WALLET_SIZE(5);

class Wallet
{
public:
   // Currency Pointer for each currency types

Currency *wallet[WALLET_SIZE];
  
   //enumerator to hold currency type
   enum currencyType
   {
       DOLLAR,
       POUND,
       YEN,
       RUPEE,
       YUAN
   };
   //default constructor
   Wallet();

   //default destructor
   ~Wallet();

	Currency & operator[] (const int &);
   	int numOfCurrencies() const;
   	bool checkExisting(currencyType);
   	void addMoney(currencyType, const int, const int);
   	void removeMoney(currencyType, const int, const int);
   	int getMoney(currencyType);
   	void emptyWallet();
   	bool checkIfEmpty();

};

#endif
