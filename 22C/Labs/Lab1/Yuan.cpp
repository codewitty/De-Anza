#include "Yuan.h"

// Constructor
Yuan::Yuan(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

// Destructor
Yuan::~Yuan()
{
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Yuan objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Yuan &obj)
{
	strm << obj.wholePart << " yuans, " << obj.fractionalPart << " fens :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Yuan objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Yuan &obj)
{
	Yuan temp; // Temp working Yuan var.

	// Prompt the user for the yuan amount
	std::cout << "   Enter yuan ( Between 0 and 10000) : "
			  << std::endl << "   ";
	
	strm >> temp.wholePart;
	// Validate Yuan amount.
	while (temp.wholePart < 0 && temp.wholePart > 10000)
	{
		std::cout << "   Please re-enter yuan. Yuan must be"
			 << " greater than 0 and less than 10000" << std::endl << "   ";
		strm  >> temp.wholePart; 
	}

	// Prompt the user for the fens amount
	
	std:: cout << "   Enter fen"
			  << std::endl << "   ";

	strm >> temp.fractionalPart;
	// Validate Cents.
	while (temp.fractionalPart < 0 || temp.fractionalPart > 99)
	{
		std::cout << "   Please re-enter fen. Fen must be"
				  << " between 1-99" << std::endl << "   ";
		strm >> temp.fractionalPart; 
	}

	// Update Yuan Object.
	obj = temp;

	// Normalize the values.
	obj.normalize();

	return strm;
}
