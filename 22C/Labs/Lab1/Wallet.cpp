#include "Wallet.h"

Wallet::Wallet()
{
   	cPtr[DOLLAR] = new Dollar;
   
	cPtr[POUND] = new Pound;
  
   	cPtr[RUPEE] = new Rupee;

   	cPtr[YEN] = new Yen;

   	cPtr[YUAN] = new Yuan;

}

Wallet::~Wallet()
{
   delete cPtr;
}

 Stupid::operator[] (std::string index)
{
	std::cout << index;
}
int Wallet::numOfCurrencies() const
{
   unsigned currencyCount = 0;
  
   for (int i = 0; i < 6; i++)
   {
       if (!cPtr[i]->isZero())
           currencyCount++;
   }

   return currencyCount;
}

bool Wallet::checkExisting(Wallet::currencyType flag)
{
   if (cPtr[flag]->isZero())
       return true;
   else
       return false;

}
void Wallet::addMoney(Wallet::currencyType cType, const int wpart, const int fpart)
{
   int fractionalPart, wholePart;

   switch(cType) 
	{
	case DOLLAR:
		

   // Whole part

   // Fractional part
   cPtr[flag]->setFractVal(cPtr[flag]->getFractVal() + static_cast<unsigned>(fractionalPart));

   // Update currency values
   cPtr[flag]->updateCurrencyVal();
}
void Wallet::removeMoney(Wallet::currencyType flag, const int x)
{
   int fractionalPart, wholePart;

   // Whole part
   cPtr[flag]->setWholeVal(cPtr[flag]->getWholeVal() - static_cast<unsigned>(wholePart));

   // Fractional part
   cPtr[flag]->setFractVal(cPtr[flag]->getFractVal() - static_cast<unsigned>(fractionalPart));

   // Update currency values
   cPtr[flag]->updateCurrencyVal();
}

int Wallet::getMoney(Wallet::currencyType flag)
{
   int currencyValue = cPtr[flag]->getWholeVal() + (cPtr[flag]->getFractVal() / 100);
   return currencyValue;
}

void Wallet::emptyWallet()
{
   for (int i = 0; i < 6; i++)
   {
       cPtr[i]->setZero();
   }
}
bool Wallet::checkIfEmpty()
{
   bool empty = true;

   int i = 0;
   while (i < 6 && empty)
   {
       if (!cPtr[i]->isZero())
           empty = false;
   }
  
   return empty;
}
