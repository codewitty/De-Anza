#pragma once
#include <iostream>


class Currency 
{
protected:
	int wholePart;        // To hold a number of feet
	int fractionalPart;   // To hold a number of inches
	void normalize();      // Defined in FeetInches.cpp
public:
	// Constructor
	Currency(int wPart = 0, int fPart = 0)
	{
		wholePart = wPart;
		fractionalPart = fPart;
		normalize();
	}

	// Mutator functions
	void setWholePart(int wPart)
	{
		wholePart = wPart;
	}

	void setFractionalPart(int fPart)
	{
		fractionalPart = fPart;
		normalize();
	}

	// Accessor functions
	int getWholePart() const
	{
		return wholePart;
	}

	int getFractionalPart() const
	{
		return fractionalPart;
	}

	// Overloaded operator functions
	Currency operator + (const Currency &); // Overloaded +
	Currency operator - (const Currency &); // Overloaded -
	bool operator > (const Currency &);		// Overloaded >
	bool operator < (const Currency &);		// Overloaded <
	bool operator == (const Currency &);	// Overloaded ==
	Currency& operator = (const Currency &);  // overloaded =

};
