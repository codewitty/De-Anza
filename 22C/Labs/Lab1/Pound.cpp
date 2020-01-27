#include "Pound.h"

// Constructor
Pound::Pound(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

// Destructor
Pound::~Pound()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Pound objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Pound &obj)
{
	strm << obj.wholePart << " pounds, " << obj.fractionalPart << " pence :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Pound objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Pound &obj)
{
	Pound temp; // Temp working Pound var.

	// Prompt the user for the dollar amount
	std::cout << "   Enter pounds ( Between 0 and 10000) : "
			  << std::endl << "   ";
	
	strm >> temp.wholePart;
	// Validate Pound amount.
	while (temp.wholePart < 0 && temp.wholePart > 10000)
	{
		std::cout << "   Please re-enter pounds. Pounds must be"
			 << " greater than 0 and less than 10000" << std::endl << "   ";
		strm  >> temp.wholePart; 
	}

	// Prompt the user for the pence amount
	
	std:: cout << "   Enter pence"
			  << std::endl << "   ";

	strm >> temp.fractionalPart;
	// Validate Pence.
	while (temp.fractionalPart < 0 || temp.fractionalPart > 99)
	{
		std::cout << "   Please re-enter pence. Pence must be"
				  << " between 1-99" << std::endl << "   ";
		strm >> temp.fractionalPart; 
	}

	// Update Pound Object.
	obj = temp;

	// Normalize the values.
	obj.normalize();

	return strm;
}
