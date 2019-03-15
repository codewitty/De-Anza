// Program name: Lab5b 
//
// Description: 
//		The program instantiates and uses instances 
//		of a derived class with default and non-default constructors.	
// 	
//
// What's on your mind about this lab? 
// This exercise helps understand how to use classes and inheritance to  
// process data
//
// Author: Joshua N  Gomes 
//
// Date: 03/13/2019
//
// IDE Used: Vim/g++
//

#include <iostream>
#include <iomanip>
#include <string>
#include "NumberList.h"

using namespace std;


	streetAddress = address;
	squareFootage =	sqFtg;
	taxes = tax;
}

//Defining member functions
// The mutator function sets the value of the setStreetAddress variable
void	RealProperty::setStreetAddress(string name) {
    streetAddress = name;
}

// The mutator function sets the value of the setSquareFootage variable
void	RealProperty::setSquareFootage(int sqft) {
    squareFootage = sqft;
}

// The mutator function sets the value of the setTaxes variable
void	RealProperty::setTaxes(double taxx) {	
	double taxes = taxx; 
}


// This accessor function gets the value of getStreetAddress variable
string	RealProperty::getStreetAddress() const{
    return streetAddress;
}

// This accessor function gets the value of getSquareFootage variable
int 	RealProperty::getSquareFootage() const{
    return squareFootage;
}

// This accessor function gets the value of getTaxes  variable
double 	RealProperty::getTaxes() const{
    return taxes;
}

// Derived class
class Apartment : public RealProperty {
	private:
		// Variable to hold monthly rent	
		double monthlyRent;
	public:
		// Default Constructor;
		Apartment();		
		
		// Other Constructor which accepts parameters	
		Apartment(string, int, double, double); 
		
		// mutator functions
		void	setMonthlyRent(double);
		// accessor functions
		double	getMonthlyRent() const;

};

// Defining the default constructor and initializing it to given values
Apartment::Apartment() : RealProperty() {
			monthlyRent = 0.0;
		}

// Defining the other constructor that accepts data
Apartment::Apartment(string address, int sqFtg, double tax, double rent)
		 : RealProperty(address, sqFtg, tax) {
	monthlyRent = rent;
}
//Defining member functions
// The mutator function sets the value of the monthly rent variable
void	Apartment::setMonthlyRent(double rent) {
    monthlyRent = rent;
}

// This accessor function gets the value of monthly rentvariable
double	Apartment::getMonthlyRent() const{
    return monthlyRent;
}

// Function to display Property Information
void	displayPropertyInfo(RealProperty &);

// Function to display Property Information
void	displayApartmentInfo(Apartment &);


//This program processes data using a derived class 
int main() {

// Apartment variable
Apartment myApartment("Cupertino", 1200, 200, 2550.0);

displayPropertyInfo(myApartment);

displayApartmentInfo(myApartment);

return 0;
}

//************************************************************************
//* Function name: displayPropertyInfo 
//*
//* This function uses accessor functions from the base class 
//* to display data to the screen 
//*
//* Parameters:
//*	ptr  -  This is a reference variable of type RealProperty 
//		that contains the data to be displayed
//* Returns:
//*	There is no returned value.
//*
//*
//************************************************************************

void	displayPropertyInfo(RealProperty &property) {

	cout	<< "Property is located at: " << property.getStreetAddress()
		<< endl;
	cout	<< "Square footage: " << property.getSquareFootage() << endl;
	cout	<< "Taxes: " << property.getTaxes() << endl << endl;
}


//************************************************************************
//* Function name: displayApartmentInfo 
//*
//* 
//* This function uses accessor functions from the derived class 
//* to display data to the screen 
//*
//* Parameters:
//*	  Apartment &property - This is a reference variable of type Apartment
//				that contains the data to be displayed
//* Returns:
//*	There is no returned value.
//*
//*
//************************************************************************

void	displayApartmentInfo(Apartment &property) {

	cout	<< "Apartment is located at: " << property.getStreetAddress()
		<< endl;
	cout	<< "Square footage: " << property.getSquareFootage() << endl;
	cout 	<< "Taxes: " << property.getTaxes() << endl;
	cout	<< "Monthly rent: " << showpoint << fixed << setprecision(2) 
		<< property.getMonthlyRent() << endl;
}


/*
Copy output of this program below this line.

Property is located at: Cupertino
Square footage: 1200
Taxes: 200

Apartment is located at: Cupertino
Square footage: 1200
Taxes: 200
Monthly rent: 2550.00
*/
