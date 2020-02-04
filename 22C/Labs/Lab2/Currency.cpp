#include <cstdlib>
#include "Currency.h"


//************************************************************
// Definition of member function normalize. This function    *
// checks for values in the inches member greater than       *
// 10 or less than 0. If such a value is found, the numbers  *
// in wholePart and fractionalPart are adjusted to conform   *
// to our whole to part ratio of 1 whole is 100 parts.       *
//                                                           *
// For example:                                              *
// 2 wholePart's and 140 fractionaPart's would be adjusted   *
// to 3 wholePart's and 40 fractionalPart's.                 *
//************************************************************

void Currency::normalize()
{
	if (fractionalPart >= 100)
	{
		wholePart += (fractionalPart / 100);
		fractionalPart = fractionalPart % 100;
	}
	else if (fractionalPart < 0)
	{
		wholePart -= ((abs(fractionalPart) / 100) + 1);
		fractionalPart = 100 - (abs(fractionalPart) % 100);
	}
}

Currency Currency::operator+(const Currency &right)
{
	Currency temp;

	temp.fractionalPart = fractionalPart + right.fractionalPart;
	temp.wholePart = wholePart + right.wholePart;
	temp.normalize();
	return temp;
}

Currency Currency::operator-(const Currency &right)
{
	Currency temp;

	temp.fractionalPart = fractionalPart - right.fractionalPart;
	temp.wholePart = wholePart - right.wholePart;
	temp.normalize();
	return temp;
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************

bool Currency::operator > (const Currency &right)
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

//************************************************************
// Overloaded < operator. Returns true if the current object *
// is set to a value less than that of right.                *
//************************************************************

bool Currency::operator < (const Currency &right)
{
	bool status;

	if (wholePart < right.wholePart)
		status = true;
	else if (wholePart == right.wholePart && fractionalPart < right.fractionalPart)
		status = true;
	else
		status = false;

	return status;
}

//*************************************************************
// Overloaded == operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool Currency::operator == (const Currency &right)
{
	bool status;

	if (wholePart == right.wholePart && fractionalPart == right.fractionalPart)
		status = true;
	else
		status = false;

	return status;
}

//*************************************************************
// Overloaded = operator. Assigns the value of the operand on *
// the left of the "=" to the right.						  *
// Returns a pointer to the updated object.					  *
//*************************************************************
Currency& Currency::operator=(const Currency &right)
{
	if (this != &right) {
		this->wholePart = right.wholePart;
		this->fractionalPart = right.fractionalPart;
	}
	return *this;
}
