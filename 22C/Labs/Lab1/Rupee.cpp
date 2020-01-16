#include "Rupee.h"

Rupee::Rupee()
{
}


Rupee::~Rupee()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Rupee objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Rupee &obj)
{
	strm << obj.wholePart << " rupees, " << obj.fractionalPart << " cents :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Rupee objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Rupee &obj)
{
	int whole;
	// Prompt the user for the feet.
	std::cout << "Enter rupees: ";
	strm >> obj.wholePart;

	// Prompt the user for the inches.
	std::cout << "Enter cents: ";
	strm >> obj.fractionalPart;

	// Normalize the values.
	obj.normalize();

	return strm;
}
