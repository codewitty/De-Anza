#pragma once
#include <iostream>

//**********************************************************************//
// class Currency - This is the base class for our Wallet currencies.   //
//**********************************************************************//
class Currency
{
protected:
	int wholePart;        // To hold a number of feet
	int fractionalPart;   // To hold a number of inches
	void normalize();      // Defined in FeetInches.cpp
public:
	// Constructor                                                          
	//                                                                      
	// post: a Currency object with 0.0 units for the whole and fractional  
	//       parts.                                                         
	Currency(int wPart = 0, int fPart = 0)
	{
		wholePart = wPart;
		fractionalPart = fPart;
		normalize();
	}

	// currency whole units mutator
	void setWholePart(int wPart)
	{
		wholePart = wPart;
	}
	// currency fractional units mutator
	void setFractionalPart(int fPart)
	{
		fractionalPart = fPart;
		normalize();
	}

	// currency whole units accessor
	int getWholePart() const
	{
		return wholePart;
	}
	// currency whole units accessor
	int getFractionalPart() const
	{
		return fractionalPart;
	}

	// Overloaded operator functions

	//**********************************************************************//
	// Currency operator +                                                  //
	// pre:  currency object we want to add.                                //
	// return: sum of the operands                                          //
	//**********************************************************************//
	Currency operator + (const Currency &); // Overloaded +

	//**********************************************************************//
	// Currency operator -                                                  //
	// pre:  currency objects we want to subtract.                          //
	// return: result of subtration the operands                            //
	//**********************************************************************//
	Currency operator - (const Currency &); // Overloaded -

	//**********************************************************************//
	// Currency operator >                                                  //
	// pre:  currency objects we want to compare.                           //
	// return: result of comparing the operands (>)                         //
	//**********************************************************************//
	virtual bool operator > (const Currency &);		// Overloaded >

	//**********************************************************************//
	// Currency operator <                                                  //
	// pre:  currency objects we want to compare.                           //
	// return: result of comparing the operands (<)                         //
	//**********************************************************************//
	virtual bool operator < (const Currency &);		// Overloaded <

	//**********************************************************************//
	// Currency operator ==                                                 //
	// pre:  currency objects we want to compare.                           //
	// return: result of comparing the operands (==)                        //
	//**********************************************************************//
	virtual bool operator == (const Currency &);	// Overloaded ==

	//**********************************************************************//
	// Currency operator =                                                  //
	// pre:  source and target Currency opjects we want to perform a copy   //
	//       operation on.                                                  //
	// return: result of assign one operand the result of an RHS expression.//
	//**********************************************************************//
	virtual Currency& operator=(const Currency &);  // overloaded =
};
