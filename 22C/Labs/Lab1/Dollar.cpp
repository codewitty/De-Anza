#include "Dollar.h"

// Dollar Constructor
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
	Dollar temp; // Temp working Dollar var.

	// Prompt the user for the dollar amount
	std::cout << "   Enter dollars ( Between 0 and 10000) : "
			  << std::endl << "   ";
	
	strm >> temp.wholePart;
	// Validate Dollar amount.
	while (temp.wholePart < 0 && temp.wholePart > 10000)
	{
		std::cout << "please re-enter dollars and cents. Dollars must be"
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

	// Update Dollar Object.
	obj = temp;

	// Normalize the values.
	obj.normalize();

	return strm;
}
