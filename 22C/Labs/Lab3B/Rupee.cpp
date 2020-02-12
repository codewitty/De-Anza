#include "Rupee.h"
#include "Currency.h"

// Constructor
Rupee::Rupee(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

// Destructor
Rupee::~Rupee()
{
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************
bool Rupee::operator>(const Rupee &right)
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
// directly display Rupee objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Rupee &obj)
{
	std::string stp(".");
	std::string decp0(".0");
	if (obj.fractionalPart < 10)
		stp = ".0";

	strm << obj.wholePart << stp.c_str() << obj.fractionalPart << " ";

	//strm << obj.wholePart << "." << obj.fractionalPart << " ";
	//strm << obj.wholePart << " rupees and " << obj.fractionalPart
	//	<< " paise. ($" << obj.wholePart << "." << obj.fractionalPart << ")" << std::endl;

	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Rupee objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Rupee &obj)
{
	// Prompt the user for the feet.
	std::cout << "   Enter rupees: ";
	strm >> obj.wholePart;

	// Prompt the user for the inches.
	std::cout << "   Enter paise: ";
	strm >> obj.fractionalPart;

	// Normalize the values.
	obj.normalize();

	return strm;
}
