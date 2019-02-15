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





};

//This program processes data with a class
int main() {
	
	//Define an string constant for file name
	string const FILE_NAME = "nutri.dat";
	
	//open file to read and write
	fstream file;

	//check if file already exists
	file.open(FILE_NAME, ios::in);
	
	//if file does not exist open to write data
	//else display error messages and exit program
 
	if (file.fail()) {
	    file.open(FILE_NAME, ios::out | ios::binary);
	}
	else {
	    file.close();
	    cout    	<<  "The file nutri.dat is an existing file. You can either " 
			<<  "delete the file or move it to another "
			<<  "location and then run the program again.\n";
	    return 0;
	}
	
	//create 5 records to store data
	NutritionData data1 =	{"Apples raw", 110, 50.6, 1.2, 1.0};
	NutritionData data2 =	{"Bananas", 225, 186, 6.2, 8.2};
	NutritionData data3 =	{"Bread pita whole wheat", 64, 134, 14, 22.6};
	NutritionData data4 =	{"Broccoli raw", 91, 21.9, 2.8, 6.3};
	NutritionData data5 =	{"Carrots raw", 128, 46.6, 2.6, 3.3};


	//write records to file
	file.write(reinterpret_cast<char *> (&data1), sizeof(data1));
	file.write(reinterpret_cast<char *> (&data2), sizeof(data2));
	file.write(reinterpret_cast<char *> (&data3), sizeof(data3));
	file.write(reinterpret_cast<char *> (&data4), sizeof(data4));
	file.write(reinterpret_cast<char *> (&data5), sizeof(data5));


	file.close();

	//open file to read data
	file.open (FILE_NAME, ios::in | ios::binary);

	//test to check file opens correctly
	if (!file) {
		cout << "Error opening file. Program aborting.\n";
	}
	
	//create a struct to read data from file into it
	NutritionData dataOut;

	//use seekg function to read tht 3rd record from file
	file.seekg (sizeof(NutritionData) * 2, ios::beg);

	//read the data into the struct
	file.read((char *) &dataOut, sizeof(dataOut));

	//Calculate the totalCalories field using the data
	dataOut.totalCalories = dataOut.calFromCarb + dataOut.calFromFat 
				+ dataOut.calFromProtein;

	//Print data from the 3rd record onto the screen
	cout << showpoint << fixed << setprecision(1);
	cout << "Food Name: ";
	cout << dataOut.foodName << endl;
	cout << "Serving Size: ";
	cout << dataOut.servingSize << " grams" << endl;
	cout << "Calories Per Serving: ";
	cout << dataOut.totalCalories << endl;
	cout << "Calories From Carb: ";
	cout << dataOut.calFromCarb << endl;
	cout << "Calories From Fat: ";
	cout << dataOut.calFromFat << endl;
	cout << "Calories From Protein: ";
	cout << dataOut.calFromProtein << endl;

	file.close();
	
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
