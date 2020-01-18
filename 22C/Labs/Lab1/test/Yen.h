#pragma once
#include "Currency.h"

class Yen; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, const Yen &);
std::istream &operator >> (std::istream &, Yen &);

class Yen :
	public Currency
{
public:
	Yen(int wPart = 0, int fPart = 0);
	~Yen();

	// istream and ostream overloading
	// Friends them..
	friend std::ostream &operator << (std::ostream &, const Yen &);
	friend std::istream &operator >> (std::istream &, Yen &);
};
