#pragma once
#include "Currency.h"

class Yuan; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Yuan &);
std::istream &operator >> (std::istream &, Yuan &);

class Yuan :
	public Currency
{
public:
	Yuan();
	~Yuan();

	// istream and ostream overloading
	// Friends them..
	friend std::ostream &operator << (std::ostream &, const Yuan &);
	friend std::istream &operator >> (std::istream &, Yuan &);
};
