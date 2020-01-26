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

//********************************************************
// Overloaded << operator. Gives std::cout the ability to     *
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
	int whole; // Whole part of currency
	int part;  // Fractional part of currency
	Dollar temp; // Temp working Dollar var.

	// Prompt the user for the dollar amount
	std::cout << "   Enter dollars and cents (Ex: $2.11 is 2 11) : "
			  << std::endl << "   ";

	// Validate Dollar amount.
	while (temp.wholePart < 0 && temp.wholePart > 10000)
	{
		std::cout << "please re-enter dollars and cents. Dollars must be"
			 << " greater than 0 and less than 10000" << std::endl;
		strm  >> temp; 
	}

	// Prompt the user for the cents amount

	// Validate Cents.
	while (temp.fractionalPart < 0 || temp.fractionalPart > 99)
	{
		std::cout << "please re-enter dollars and cents. Cents must be"
				  << "   between 1-99" << std::endl;
		strm >> temp; 
	}

	// Update Dollar Object.
	obj = temp;

	// Normalize the values.
	obj.normalize();

	return strm;
}
