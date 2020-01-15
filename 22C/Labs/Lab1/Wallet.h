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

Currency *cPtr[5];
  
public:

   //enumerator to hold currency types
   enum currencyFlag
   {
       DOLLAR,
       POUND,
       YEN,
       RUPEE,
       YUAN
   };
static currencyFlag x;
   //default constructor
   Wallet();

   //default destructor
   ~Wallet();

   int numOfCurrencies() const;
   bool checkExisting(currencyFlag);
   void addMoney(currencyFlag, const int, const int);
   void removeMoney(currencyFlag, const int, const int);
   int getMoney(currencyFlag);
   void emptyWallet();
   bool checkIfEmpty();

};

#endif
