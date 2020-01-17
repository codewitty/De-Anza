#pragma once
#include "Currency.h"

class Pound; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Pound &);
std::istream &operator >> (std::istream &, Pound &);

class Pound :
	public Currency
{
public:
	Pound(int wPart = 0, int fPart = 0);
	~Pound();

	// istream and ostream overloading
	// Friends them..
	friend std::ostream &operator << (std::ostream &, const Pound &);
	friend std::istream &operator >> (std::istream &, Pound &);
};

