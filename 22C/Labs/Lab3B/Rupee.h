#pragma once

#include "Currency.h"

class Rupee; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Rupee &);
std::istream &operator >> (std::istream &, Rupee &);

//**********************************************************************//
// class Rupee - This is the derived Rupee container.                 //
//**********************************************************************//
class Rupee :
	public Currency
{
public:
	Rupee(int wPart = 0, int fPart = 0);
	~Rupee();

	//**********************************************************************//
	// Rupee operator >                                                  //
	// pre:  currency objects we want to compare.                           //
	// return: result of comparing the operands (>)                         //
	//**********************************************************************//
	bool operator > (const Rupee &);		// Overloaded >

	// istream and ostream overloading
	// Friends them..
	//**********************************************************************//
	// Rupee output stream operator <<                                     //
	// pre:  A Rupee object we want to display                             //
	// return: formatted display data                                       //
	//**********************************************************************//
	friend std::ostream &operator << (std::ostream &, const Rupee &);

	//**********************************************************************//
	// Rupee input stream operator >>                                      //
	// pre:  a Rupee object we wan to initialize with user input           //
	// return: properly initialized Rupee object                           //
	//**********************************************************************//
	friend std::istream &operator >> (std::istream &, Rupee &);
};
