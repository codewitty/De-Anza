#include "Yen.h"

Yen::Yen(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

Yen::~Yen()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Yen objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Yen &obj)
{
	strm << obj.wholePart << " yen, " << obj.fractionalPart << " cents :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Yen objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Yen &obj)
{
	int whole;
	// Prompt the user for the feet.
	std::cout << "Enter yens: ";
	strm >> obj.wholePart;

	// Prompt the user for the inches.
	std::cout << "Enter cents: ";
	strm >> obj.fractionalPart;

	// Normalize the values.
	obj.normalize();

	return strm;
}
