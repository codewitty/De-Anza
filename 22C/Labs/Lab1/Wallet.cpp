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
   //delete wallet;
}

Currency & Wallet::operator[](const int &ndx)
{
	return *(wallet[ndx]);
}

/* needs isZero()

int Wallet::numOfCurrencies() const
{
   unsigned walletCount = 0;
  
   for (int i = 0; i < 6; i++)
   {
       if (!wallet[i]->isZero())
           walletCount++;
   }

   return walletCount;
}

bool Wallet::checkExisting(Wallet::walletType flag)
{
   if (wallet[flag]->isZero())
       return true;
   else
       return false;

}
*/


void Wallet::addMoney(Wallet::walletType cType, const int wpart, const int fpart)
{
   int fractionalPart, wholePart;

}

/*
void Wallet::removeMoney(Wallet::walletType flag, const int x)
{
   int fractionalPart, wholePart;

   // Whole part
  // wallet[flag]->setWholeVal(wallet[flag]->getWholeVal() - static_cast<unsigned>(wholePart));

   // Fractional part
   //wallet[flag]->setFractVal(wallet[flag]->getFractVal() - static_cast<unsigned>(fractionalPart));

   // Update wallet values
   //wallet[flag]->updateCurrencyVal();
}

int Wallet::getMoney(Wallet::walletType flag)
{
   int walletValue = wallet[flag]->getWholeVal() + (wallet[flag]->getFractVal() / 100);
   return walletValue;
}

void Wallet::emptyWallet()
{
   for (int i = 0; i < 6; i++)
   {
       wallet[i]->setZero();
   }
}

bool Wallet::checkIfEmpty()
{
   bool empty = true;

   int i = 0;
   while (i < 6 && empty)
   {
       if (!wallet[i]->isZero())
           empty = false;
   }
  
   return empty;
}
*/
