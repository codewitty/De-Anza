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

class Wallet
{
private:
   // Currency Pointer for each currency type   

Currency *currency[5];
  
public:

   //enumerator to hold currency type
   enum currencyType
   {
       DOLLAR,
       POUND,
       YEN,
       RUPEE,
       YUAN
   };
static currencyType x;
   //default constructor
   Wallet();

   //default destructor
   ~Wallet();

	Wallet * operator[] (std::string flag);
   	int numOfCurrencies() const;
   	bool checkExisting(currencyType);
   	void addMoney(currencyType, const int, const int);
   	void removeMoney(currencyType, const int, const int);
   	int getMoney(currencyType);
   	void emptyWallet();
   	bool checkIfEmpty();

};

#endif
