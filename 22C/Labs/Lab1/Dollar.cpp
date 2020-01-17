#include "Dollar.h"

Dollar::Dollar(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

Dollar::~Dollar()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Dollar objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Dollar &obj)
{
	strm << obj.wholePart << " dollars, " << obj.fractionalPart << " cents :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Dollar objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Dollar &obj)
{
	int whole;
	// Prompt the user for the feet.
	std::cout << "Enter dollars: ";
	strm >> obj.wholePart;

	// Prompt the user for the inches.
	std::cout << "Enter cents: ";
	strm >> obj.fractionalPart;

	// Normalize the values.
	obj.normalize();

	return strm;
}
