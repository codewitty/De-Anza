#pragma once

#include "Currency.h"
#include "Dollar.h"

class Dollar; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Dollar &);
std::istream &operator >> (std::istream &, Dollar &);

//**********************************************************************//
// class Dollar - This is the derived Dollar container.                 //
//**********************************************************************//
class Dollar :
	public Currency
{
public:
	Dollar(int wPart = 0, int fPart = 0);
	~Dollar();

	//**********************************************************************//
	// Dollar operator >                                                  //
	// pre:  currency objects we want to compare.                           //
	// return: result of comparing the operands (>)                         //
	//**********************************************************************//
	bool operator > (const Dollar &);		// Overloaded >

	// istream and ostream overloading
	// Friends them..
	//**********************************************************************//
	// Dollar output stream operator <<                                     //
	// pre:  A Dollar object we want to display                             //
	// return: formatted display data                                       //
	//**********************************************************************//
	friend std::ostream &operator << (std::ostream &, const Dollar &);

	//**********************************************************************//
	// Dollar input stream operator >>                                      //
	// pre:  a Dollar object we wan to initialize with user input           //
	// return: properly initialized Dollar object                           //
	//**********************************************************************//
	friend std::istream &operator >> (std::istream &, Dollar &);
};
