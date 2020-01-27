#include "Rupee.h"

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

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display Rupee objects.                      *
//********************************************************
std::ostream & operator<<(std::ostream &strm, const Rupee &obj)
{
	strm << obj.wholePart << " rupees, " << obj.fractionalPart << " paise :";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into Rupee objects.        *
//********************************************************
std::istream & operator>>(std::istream &strm, Rupee &obj)
{
	Rupee temp; // Temp working Rupee var.

	// Prompt the user for the rupee amount
	std::cout << "   Enter rupees ( Between 0 and 10000) : "
			  << std::endl << "   ";
	
	strm >> temp.wholePart;
	// Validate Rupee amount.
	while (temp.wholePart < 0 && temp.wholePart > 10000)
	{
		std::cout << "please re-enter rupees. Rupees must be"
			 << " greater than 0 and less than 10000" << std::endl << "   ";
		strm  >> temp.wholePart; 
	}

	// Prompt the user for the paises amount
	
	std:: cout << "   Enter paise"
			  << std::endl << "   ";

	strm >> temp.fractionalPart;
	// Validate Paise.
	while (temp.fractionalPart < 0 || temp.fractionalPart > 99)
	{
		std::cout << "   Please re-enter paise. Paise must be"
				  << " between 1-99" << std::endl << "   ";
		strm >> temp.fractionalPart; 
	}

	// Update Rupee Object.
	obj = temp;

	// Normalize the values.
	obj.normalize();

	return strm;
}
