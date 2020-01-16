#pragma once
#include "Currency.h"

class Rupee; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Rupee &);
std::istream &operator >> (std::istream &, Rupee &);

class Rupee :
	public Currency
{
public:
	Rupee();
	~Rupee();

	// istream and ostream overloading
	// Friends them..
	friend std::ostream &operator << (std::ostream &, const Rupee &);
	friend std::istream &operator >> (std::istream &, Rupee &);
};
