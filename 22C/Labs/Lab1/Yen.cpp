#include "Yen.h"

// Constructor
Yen::Yen(int wPart, int fPart)
{
	wholePart = wPart;
	fractionalPart = fPart;
	normalize();
}

// Destructor
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
	Yen temp; // Temp working Yen var.

	// Prompt the user for the dollar amount
	std::cout << "   Enter dollars ( Between 0 and 10000) : "
			  << std::endl << "   ";
	
	strm >> temp.wholePart;
	// Validate Yen amount.
	while (temp.wholePart < 0 && temp.wholePart > 10000)
	{
		std::cout << "please re-enter dollars and cents. Yens must be"
			 << " greater than 0 and less than 10000" << std::endl << "   ";
		strm  >> temp.wholePart; 
	}

	// Prompt the user for the cents amount
	
	std:: cout << "   Enter cents"
			  << std::endl << "   ";

	strm >> temp.fractionalPart;
	// Validate Cents.
	while (temp.fractionalPart < 0 || temp.fractionalPart > 99)
	{
		std::cout << "   Please re-enter cents. Cents must be"
				  << " between 1-99" << std::endl << "   ";
		strm >> temp.fractionalPart; 
	}

	// Update Yen Object.
	obj = temp;

	// Normalize the values.
	obj.normalize();

	return strm;
}
