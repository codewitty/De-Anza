#include "Wallet.h"

Wallet::Wallet()
{
   std::random_device rd;

   cPtr[DOLLAR] = new Dollar;
   cPtr[DOLLAR]->setFractVal(rd() % 100);
   cPtr[DOLLAR]->setWholeVal(rd() % 100);
  
   cPtr[RUPEE] = new Rupee;
   cPtr[RUPEE]->setFractVal(rd() % 100);
   cPtr[RUPEE]->setWholeVal(rd() % 100);

   cPtr[YEN] = new Yen;
   cPtr[YEN]->setFractVal(rd() % 100);
   cPtr[YEN]->setWholeVal(rd() % 100);

   cPtr[YUAN] = new Yuan;
   cPtr[YUAN]->setFractVal(rd() % 100);
   cPtr[YUAN]->setWholeVal(rd() % 100);

   cPtr[POUND] = new Pound;
   cPtr[POUND]->setFractVal(rd() % 100);
   cPtr[POUND]->setWholeVal(rd() % 100);
}

Wallet::~Wallet()
{
   delete cPtr;
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

bool Wallet::checkExisting(Wallet::currencyFlag flag)
{
   if (cPtr[flag]->isZero())
       return true;
   else
       return false;

}
void Wallet::addMoney(Wallet::currencyFlag flag, const double x)
{
   double fract, whole;

   // Whole part
   cPtr[flag]->setWholeVal(cPtr[flag]->getWholeVal() + static_cast<unsigned>(whole));

   // Fractional part
   cPtr[flag]->setFractVal(cPtr[flag]->getFractVal() + static_cast<unsigned>(fract));

   // Update currency values
   cPtr[flag]->updateCurrencyVal();
}
void Wallet::removeMoney(Wallet::currencyFlag flag, const double x)
{
   double fract, whole;

   // Extract whole and fractional parts
   fract = modf(x, &whole);
   fract *= 100;
   fract = round(fract);

   // Whole part
   cPtr[flag]->setWholeVal(cPtr[flag]->getWholeVal() - static_cast<unsigned>(whole));

   // Fractional part
   cPtr[flag]->setFractVal(cPtr[flag]->getFractVal() - static_cast<unsigned>(fract));

   // Update currency values
   cPtr[flag]->updateCurrencyVal();
}

double Wallet::getMoney(Wallet::currencyFlag flag)
{
   double currencyValue = cPtr[flag]->getWholeVal() + (cPtr[flag]->getFractVal() / 100);
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
