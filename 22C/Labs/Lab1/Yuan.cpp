#include "Yuan.h"

Yuan::Yuan()
{
}


Yuan::~Yuan()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Yuan objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Yuan &obj)
{
	strm << obj.wholePart << " yuans, " << obj.fractionalPart << " cents :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Yuan objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Yuan &obj)
{
	int whole;
	// Prompt the user for the feet.
	std::cout << "Enter yuans: ";
	strm >> obj.wholePart;

	// Prompt the user for the inches.
	std::cout << "Enter cents: ";
	strm >> obj.fractionalPart;

	// Normalize the values.
	obj.normalize();

	return strm;
}
