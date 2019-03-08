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
		void	setStreetaddress(string);
		void	setSquarefootage(int);
		void	setTaxes(double);
		// accessor functions
		string	getStreetaddress() const;
		int 	getSquarefootage() const;
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
		Apartment();
		Apartment(double rent); 
		// mutator functions
		void	setMonthlyRent(string);
		// accessor functions
		string	getMonthlyRent() const;


void	displayPropertyInfo(RealProperty &);

void	displayApartmentInfo(Apartment &);


//This program processes data with a class
int main() {
	// Define and initialize an array named nutritionData using given data	
	RealProperty nutritionData [] = {
	RealProperty ("Apples raw", 110, 50.6, 1.2, 1.0),
	RealProperty ("Bananas", 225, 186, 6.2, 8.2),
	RealProperty ("Bread pita whole wheat", 64, 134, 14, 22.6),
	RealProperty ("Broccoli raw", 91, 21.9, 2.8, 6.3),
	RealProperty ("Carrots raw", 128, 46.6, 2.6, 3.3)
};

// Use a range-based for loop to print the nutrition data for all
// foods to the screen using the accessor functions.

for (const auto nutrition : nutritionData) {
	cout << "Food Name: ";
	cout << nutrition.getFoodName() << endl;
	cout << "Serving Size: ";
	cout << nutrition.getServingSize() << " g" << endl;
	cout << "Calories Per Serving: ";
	cout << nutrition.getTotalCalories() << endl;
	cout << "Calories From Carb: ";
	cout << nutrition.getCalFromCarb() << endl;
	cout << "Calories From Fat: ";
	cout << nutrition.getCalFromFat() << endl;
	cout << "Calories From Protein: ";
	cout << nutrition.getCalFromProtein() << endl << endl;
}
	return 0;
}

/*
Copy output of this program below this line.

Food Name: Apples raw
Serving Size: 110 g
Calories Per Serving: 52.8
Calories From Carb: 50.6
Calories From Fat: 1.2
Calories From Protein: 1

Food Name: Bananas
Serving Size: 225 g
Calories Per Serving: 200.4
Calories From Carb: 186
Calories From Fat: 6.2
Calories From Protein: 8.2

Food Name: Bread pita whole wheat
Serving Size: 64 g
Calories Per Serving: 170.6
Calories From Carb: 134
Calories From Fat: 14
Calories From Protein: 22.6

Food Name: Broccoli raw
Serving Size: 91 g
Calories Per Serving: 31
Calories From Carb: 21.9
Calories From Fat: 2.8
Calories From Protein: 6.3

Food Name: Carrots raw
Serving Size: 128 g
Calories Per Serving: 52.5
Calories From Carb: 46.6
Calories From Fat: 2.6
Calories From Protein: 3.3

*/
