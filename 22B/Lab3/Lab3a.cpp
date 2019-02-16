// Program name: Lab3a
//
// Description: This program uses classes an array of structs to  
// 		create records. It then writes these
//		records to the specified file. Later
//		the same file is opened and the data
//		of a particular record is read and then
// 		printed to the screen 

//
// What's on your mind about this lab? 
// This exercise helps understand how to use 
// structs and file objects
// to read and write data to file
//
// Author: Joshua N  Gomes 
//
// Date: 02/14/2019
//
// IDE Used: Vim/g++
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//declare a constant size for food name
const int NAME_SIZE = 40;

//struct definition
class	NutritionData{
	private:
		string foodName;	
		int servingSize;
		double calFromCarb;
		double calFromFat;
    		double calFromProtein;
    		double totalCalories;
	public:
		NutritionData(); //Default Constructor
		void	setFoodName(string);
		void	setServingSize(int);
		void	setCalFromCarb(double);
		void	setCalFromFat(double);
		void	setCalFromProtein(double);
		string	getFoodName() const;
		int 	getServingSize() const;
		double 	getCalFromCarb() const;
		double 	getCalFromFat() const;
    		double 	getCalFromProtein() const;
    		double 	getTotalCalories() const;

};

NutritionData::NutritionData() {

	foodName = "";
	servingSize = 0;
	calFromCarb = 0.0;
	calFromFat = 0.0;
	calFromProtein = 0.0;
	totalCalories = 0.0;
}

// The mutator function setFoodName
void	NutritionData::setFoodName(string name) {
    foodName = name;
}

// The mutator function setServingSize
void	NutritionData::setServingSize(int serving) {
    servingSize = serving;
}

// The mutator function setCalFromCarb
void	NutritionData::setCalFromCarb(double carb) {
    calFromCarb = carb;
}

// The mutator function setCalFromFat
void	NutritionData::setCalFromFat(double fat) {
    calFromFat = fat;
}

// The mutator function setCalFromProtein
void	NutritionData::setCalFromProtein(double protein) {
    calFromProtein = protein;
}


// The accessor function getFoodName
string	NutritionData::getFoodName() const{
    return foodName;
}

// The accessor function getServingSize
int 	NutritionData::getServingSize() const{
    return servingSize;
}

// The accessor function getCalFromCarb
double 	NutritionData::getCalFromCarb() const{
    return calFromCarb;
}

// The accessor function getCalFromFat
double	NutritionData::getCalFromFat() const{
    return calFromFat;
}

// The accessor function getCalFromProtein
double	NutritionData::getCalFromProtein() const{
    return calFromProtein;
}

// The accessor function getTotalCalories
double	NutritionData::getTotalCalories() const{
    return totalCalories;
}

//This program processes data with a class
int main() {
	
	NutritionData Pita;
	Pita.setFoodName("Bread pita whole wheat");
	Pita.setServingSize(64);
	Pita.setCalFromCarb(134);
	Pita.setCalFromFat(14);
	Pita.setCalFromProtein(22.6);


	//Print data from onto the screen
	cout << showpoint << fixed << setprecision(1);
	cout << "Food Name: ";
	cout << Pita.getFoodName() << endl;
	cout << "Serving Size: ";
	cout << Pita.getServingSize() << " grams" << endl;
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
