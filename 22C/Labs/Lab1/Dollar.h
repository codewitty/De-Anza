#pragma once
#include "Currency.h"

class Dollar; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Dollar &);
std::istream &operator >> (std::istream &, Dollar &);

class Dollar :
	public Currency
{
public:
	Dollar(int wPart = 0, int fPart = 0);
	~Dollar();

	// istream and ostream overloading
    // Friends them..
	friend std::ostream &operator << (std::ostream &, const Dollar &);
	friend std::istream &operator >> (std::istream &, Dollar &);
};
