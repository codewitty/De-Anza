#include "Currency.h"
#include "Dollar.h"

// Constructor
Dollar::Dollar(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

// Destructor
Dollar::~Dollar()
{
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************
bool Dollar::operator>(const Dollar &right)
{
	bool status;

	if (wholePart > right.wholePart)
		status = true;
	else if (wholePart == right.wholePart && fractionalPart > right.fractionalPart)
		status = true;
	else
		status = false;

	return status;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Dollar objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Dollar &obj)
{
	strm << obj.wholePart << " dollars and " << obj.fractionalPart
		<< " cents. ($" << obj.wholePart << "." << obj.fractionalPart << ")" << std::endl;
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Dollar objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Dollar &obj)
{
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
