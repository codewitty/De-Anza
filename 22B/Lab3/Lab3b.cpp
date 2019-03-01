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

// Definig the other constructor that accepts data

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

// This accessor function gets the value of getCalFromProtein variable
double	NutritionData::getTotalCalories() const{
    return (calFromCarb + calFromFat + calFromProtein);
}
//This program processes data with a class
int main() {
	// Define and initialize an array named nutritionData using given data	
	NutritionData nutritionData[5] = {
	{"Apples raw", 110, 50.6, 1.2, 1.0},
	{"Bananas", 225, 186, 6.2, 8.2},
	{"Bread pita whole wheat", 64, 134, 14, 22.6},
	{"Broccoli raw", 91, 21.9, 2.8, 6.3},
	{"Carrots raw", 128, 46.6, 2.6, 3.3}
};
	// Use a range-based for loop to print the nutrition data for all
	// foods to the screen using the accessor functions.

	

	cout << showpoint << fixed << setprecision(1);
	cout << "Food Name: ";
	cout << nutritionData.getFoodName() << endl;
	cout << "Serving Size: ";
	cout << nutritionData.getServingSize() << " grams" << endl;
	cout << "Calories Per Serving: ";
	cout << nutritionData.getTotalCalories() << endl;
	cout << "Calories From Carb: ";
	cout << nutritionData.getCalFromCarb() << endl;
	cout << "Calories From Fat: ";
	cout << nutritionData.getCalFromFat() << endl;
	cout << "Calories From Protein: ";
	cout << nutritionData.getCalFromProtein() << endl;

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
