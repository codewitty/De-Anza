#include "Pound.h"

Pound::Pound()
{
}


Pound::~Pound()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Pound objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Pound &obj)
{
	strm << obj.wholePart << " pounds, " << obj.fractionalPart << " cents :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Pound objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Pound &obj)
{
	int whole;
	// Prompt the user for the feet.
	std::cout << "Enter pounds: ";
	strm >> obj.wholePart;

	// Prompt the user for the inches.
	std::cout << "Enter cents: ";
	strm >> obj.fractionalPart;

	// Normalize the values.
	obj.normalize();

	return strm;
}



