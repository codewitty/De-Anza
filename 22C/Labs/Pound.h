//Pound.h

#ifndef POUND_H
#define POUND_H

#include "Currency.h"

//Pound class inherited form currency class
class Pound : public Currency
{
private:


public:

   //Constructors

	Pound(int wPart, int fPart);


   friend std::ostream& operator << (std::ostream &, const Pound &);
   friend std::istream& operator >> (std::istream &, Pound &);
};

#endif

