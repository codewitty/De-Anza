// Program name: Lab3b 
//
// Description: This program instantiates and uses instances of a class 
//		with non-default constructors. 
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
class NutritionData{
	private:
		// Variable to store Food Name	
		string foodName;
		// Variable to store Serving Size	
		int servingSize;
		// Variable to store Calories from Carbohydrates	
		double calFromCarb;
		// Variable to store Calories from Fat
		double calFromFat;
   		// Variable to store Calories from Protein 
		double calFromProtein;
   		// Variable to store Total Calories 
		double totalCalories;
	public:
		// Default Constructor
		NutritionData();
		// Constructor that accepts data
		NutritionData(string, int, double, double, double);	
		
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

// Defining the other constructor that accepts data

NutritionData::NutritionData(string food, int size, double carb, double fat,
				double protein) {

	foodName = food;
	servingSize = size;
	calFromCarb = carb;
	calFromFat = fat;
	calFromProtein = protein;
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
	// Variable to hold initial value of calFromCarb
	double initialValueCarb = calFromCarb; 
	calFromCarb = carb;
	// Set the value of totalCalories	
	totalCalories = (totalCalories - initialValueCarb) + calFromCarb;
}

// The mutator function sets the value of the setCalFromFat variable
void	NutritionData::setCalFromFat(double fat) {
 // Variable to hold initial value of calFromFat
	double initialValueFat = calFromFat; 
	calFromFat = fat;
	// Set the value of totalCalories
	totalCalories = (totalCalories - initialValueFat) + calFromFat;
}
  
// The mutator function  sets the value of the setCalFromProtein variable
void	NutritionData::setCalFromProtein(double protein) {
 // Variable to hold initial value of calFromFat
	double initialValueProtein = calFromProtein; 
	calFromProtein = protein;
	// Set the value of totalCalories
	totalCalories = (totalCalories - initialValueProtein) + calFromProtein;
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

// This accessor function gets the total value of calories from all calorie
// variables
 
double	NutritionData::getTotalCalories() const{
    return (calFromCarb + calFromFat + calFromProtein);
}
//This program processes data with a class
int main() {
	// Define and initialize an array named nutritionData using given data	
	NutritionData nutritionData [] = {
	NutritionData ("Apples raw", 110, 50.6, 1.2, 1.0),
	NutritionData ("Bananas", 225, 186, 6.2, 8.2),
	NutritionData ("Bread pita whole wheat", 64, 134, 14, 22.6),
	NutritionData ("Broccoli raw", 91, 21.9, 2.8, 6.3),
	NutritionData ("Carrots raw", 128, 46.6, 2.6, 3.3)
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
