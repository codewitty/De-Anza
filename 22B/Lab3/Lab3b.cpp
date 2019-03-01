// Program name: Lab3b 
//
// Description: This program instantiates and uses instances of a class 
//		with non-default constructors. 
// 	
//
// What's on your mind about this lab? 
// This exercise helps understand how to create classes 
// and to use mutators and accessors to process data
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
class	NutritionData{
	private:
		//variable to store Food Name	
		string foodName;
		//variable to store Serving Size	
		int servingSize;
		double calFromCarb;
		double calFromFat;
    		double calFromProtein;
    		double totalCalories;
	public:
		// Default Constructor
		NutritionData();
		// Mutator Functions
		void	setFoodName(string);
		void	setServingSize(int);
		void	setCalFromCarb(double);
		void	setCalFromFat(double);
		void	setCalFromProtein(double);
		// Accessor Functions
		string	getFoodName() const;
		int 	getServingSize() const;
		double 	getCalFromCarb() const;
		double 	getCalFromFat() const;
    		double 	getCalFromProtein() const;
    		double 	getTotalCalories() const;

};

// Defining the default constructor and initializing it to given values
NutritionData::NutritionData() {

	foodName = "";
	servingSize = 0;
	calFromCarb = 0.0;
	calFromFat = 0.0;
	calFromProtein = 0.0;
	totalCalories = 0.0;
}

//Defining member functions
// The mutator function sets the value of the setFoodName variable
void	NutritionData::setFoodName(string name) {
    foodName = name;
}

// The mutator function sets the value of the setServingSize variable
void	NutritionData::setServingSize(int serving) {
    servingSize = serving;
}

// The mutator function sets the value of the setCalFromCarb variable
void	NutritionData::setCalFromCarb(double carb) {
    calFromCarb = carb;
}

// The mutator function sets the value of the setCalFromFat variable
void	NutritionData::setCalFromFat(double fat) {
    calFromFat = fat;
}

// The mutator function  sets the value of the setCalFromProtein variable
void	NutritionData::setCalFromProtein(double protein) {
    calFromProtein = protein;
}


// This accessor function gets the value of getFoodName variable
string	NutritionData::getFoodName() const{
    return foodName;
}

// This accessor function gets the value of getServingSize variable
int 	NutritionData::getServingSize() const{
    return servingSize;
}

// This accessor function gets the value of getCalFromCarb  variable
double 	NutritionData::getCalFromCarb() const{
    return calFromCarb;
}

// This accessor function gets the value of getCalFromFat variable
double	NutritionData::getCalFromFat() const{
    return calFromFat;
}

// This accessor function gets the value of getCalFromProtein variable
double	NutritionData::getCalFromProtein() const{
    return calFromProtein;
}


//This program processes data with a class
int main() {
	//Define an instance of the class NutritionData named pita.
	NutritionData Pita;
	//Use the mutator functions to set the nutrition data for pita. 
	Pita.setFoodName("Bread pita whole wheat");
	Pita.setServingSize(64);
	Pita.setCalFromCarb(134);
	Pita.setCalFromFat(14);
	Pita.setCalFromProtein(22.6);

	//Print the nutrition data of pita on the screen 
	//using cout and the accessor functions.	
	cout << showpoint << fixed << setprecision(1);
	cout << "Food Name: ";
	cout << Pita.getFoodName() << endl;
	cout << "Serving Size: ";
	cout << Pita.getServingSize() << " grams" << endl;
	cout << "Calories Per Serving: ";
	cout <<	(Pita.getCalFromCarb() + Pita.getCalFromFat()
		+ Pita.getCalFromProtein()) << endl;
	cout << "Calories From Carb: ";
	cout << Pita.getCalFromCarb() << endl;
	cout << "Calories From Fat: ";
	cout << Pita.getCalFromFat() << endl;
	cout << "Calories From Protein: ";
	cout << Pita.getCalFromProtein() << endl;

	return 0;
}

/*
Copy output of this program below this line.

Food Name: Bread pita whole wheat
Serving Size: 64.0 grams
Calories Per Serving: 170.6
Calories From Carb: 134.0
Calories From Fat: 14.0
Calories From Protein: 22.6

*/
