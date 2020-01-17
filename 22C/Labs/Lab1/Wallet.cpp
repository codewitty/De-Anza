#include "Wallet.h"

Wallet::Wallet()
{
   	currency[DOLLAR] = new Dollar;
   
	currency[POUND] = new Pound;
  
   	currency[RUPEE] = new Rupee;

   	currency[YEN] = new Yen;

   	currency[YUAN] = new Yuan;

}

Wallet::~Wallet()
{
   //delete currency;
}

Currency & Wallet::operator[](const int &ndx)
{
	return *(wallet[ndx]);
}

/* needs isZero()

int Wallet::numOfCurrencies() const
{
   unsigned currencyCount = 0;
  
   for (int i = 0; i < 6; i++)
   {
       if (!currency[i]->isZero())
           currencyCount++;
   }

   return currencyCount;
}

bool Wallet::checkExisting(Wallet::currencyType flag)
{
   if (currency[flag]->isZero())
       return true;
   else
       return false;

}
*/


void Wallet::addMoney(Wallet::currencyType cType, const int wpart, const int fpart)
{
   int fractionalPart, wholePart;

}

/*
void Wallet::removeMoney(Wallet::currencyType flag, const int x)
{
   int fractionalPart, wholePart;

   // Whole part
  // currency[flag]->setWholeVal(currency[flag]->getWholeVal() - static_cast<unsigned>(wholePart));

   // Fractional part
   //currency[flag]->setFractVal(currency[flag]->getFractVal() - static_cast<unsigned>(fractionalPart));

   // Update currency values
   //currency[flag]->updateCurrencyVal();
}

int Wallet::getMoney(Wallet::currencyType flag)
{
   int currencyValue = currency[flag]->getWholeVal() + (currency[flag]->getFractVal() / 100);
   return currencyValue;
}

void Wallet::emptyWallet()
{
   for (int i = 0; i < 6; i++)
   {
       currency[i]->setZero();
   }
}

bool Wallet::checkIfEmpty()
{
   bool empty = true;

   int i = 0;
   while (i < 6 && empty)
   {
       if (!currency[i]->isZero())
           empty = false;
   }
  
   return empty;
}
*/
