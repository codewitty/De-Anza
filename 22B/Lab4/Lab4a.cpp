// Program name: Lab4a 
//
// Description: 
//		The program instantiates and uses instances 
//	of a derived class with default and non-default constructors.	
// 	
//
// What's on your mind about this lab? 
// This exercise helps understand how to use an array of class objects 
// and to use a range based for loop 
//
// Author: Joshua N  Gomes 
//
// Date: 02/28/2019
//
// IDE Used: Vim/g++
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//class definition
class RealProperty{
	private:
		// Variable to store Food Name	
		string streetAddress;
		// Variable to store Serving Size	
		int squareFootage;
		// Variable to store Calories from Carbohydrate
		double taxes;
	public:
		// Default Constructor
		RealProperty();
		// Constructor that accepts data
		RealProperty(string, int, double);	
		
		// mutator functions
		void	setStreetAddress(string);
		void	setSquareFootage(int);
		void	setTaxes(double);
		// accessor functions
		string	getStreetAddress() const;
		int 	getSquareFootage() const;
		double 	getTaxes() const;

};

// Defining the default constructor and initializing it to given values
RealProperty::RealProperty() {

	streetAddress = "";
	squareFootage = 0;
	taxes = 0.0;
}

// Defining the other constructor that accepts data

RealProperty::RealProperty(string address, int sqFtg, double tax) {
	streetAddress = address;
	squareFootage =	sqFtg;
	taxes = tax;
}

//Defining member functions
// The mutator function sets the value of the setStreetAddress variable
void	RealProperty::setStreetAddress(string name) {
    streetAddress = name;
}

// The mutator function sets the value of the setServingSize variable
void	RealProperty::setSquareFootage(int sqft) {
    squareFootage = sqft;
}

// The mutator function sets the value of the setCalFromCarb variable
void	RealProperty::setTaxes(double taxx) {	
	double taxes = taxx; 
}


// This accessor function gets the value of getFoodName variable
string	RealProperty::getStreetAddress() const{
    return streetAddress;
}

// This accessor function gets the value of getServingSize variable
int 	RealProperty::getSquareFootage() const{
    return squareFootage;
}

// This accessor function gets the value of getCalFromCarb  variable
double 	RealProperty::getTaxes() const{
    return taxes;
}


class Apartment : public RealProperty {
	private:
		double monthlyRent;
	public:
		//Apartment();
		Apartment() : RealProperty() {
			monthlyRent = 0.0;
		}
		//Apartment(string, double, double, double rent); 
		Apartment(string address, int sqFtg, double tax, double rent) : RealProperty(address, sqFtg, tax) {
	monthlyRent = rent;
}

	
		// mutator functions
		void	setMonthlyRent(double);
		// accessor functions
		double	getMonthlyRent() const;

};

// Defining the default constructor and initializing it to given values


// Defining the other constructor that accepts data

//Defining member functions
// The mutator function sets the value of the setStreetAddress variable
void	Apartment::setMonthlyRent(double rent) {
    monthlyRent = rent;
}

// This accessor function gets the value of getFoodName variable
double	Apartment::getMonthlyRent() const{
    return monthlyRent;
}

void	displayPropertyInfo(RealProperty &);

void	displayApartmentInfo(Apartment &);


//This program processes data with a class
int main() {

Apartment myApartment("Cupertino", 1200, 200, 2550.0);

displayPropertyInfo(myApartment);

displayApartmentInfo(myApartment);

return 0;
}

//************************************************************************
//* Function name: displayPropertyInfo 
//*
//* This function uses a pointer to iterate through a given string
//* it then capitalises the first letter of every sentence.
//*
//* Parameters:
//*	ptr  -  This is a pointer of type char which points to the 
//		array that needs to be modified.
//* Returns:
//*	There is no returned value.
//*
//*
//************************************************************************

void	displayPropertyInfo(RealProperty &property) {

	cout << "Property is located at: " << property.getStreetAddress() << endl;
	cout << "Square footage: " << property.getSquareFootage() << endl;
	cout << "Taxes: " << property.getTaxes() << endl << endl;
}


//************************************************************************
//* Function name: displayApartmentInfo 
//*
//* This function uses a pointer to iterate through a given string
//* it then capitalises the first letter of every sentence.
//*
//* Parameters:
//*	ptr  -  This is a pointer of type char which points to the 
//		array that needs to be modified.
//* Returns:
//*	There is no returned value.
//*
//*
//************************************************************************

void	displayApartmentInfo(Apartment &property) {

	cout << "Apartment is located at: " << property.getStreetAddress() << endl;
	cout << "Square footage: " << property.getSquareFootage() << endl;
	cout << "Taxes: " << property.getTaxes() << endl;
	cout << "Monthly rent: " << property.getMonthlyRent() << endl;
}


/*
Copy output of this program below this line.


*/
