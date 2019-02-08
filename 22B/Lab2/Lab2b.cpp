// Program name: Lab2b
//
// Description: This program uses an array of structs to  
// 		store data of varoius types and then
// 		print the stored data to the screen
//
// What's on your mind about this lab? 
// This exercise helps me understand what are structs and
// how to use them to store data. I also learned how to 
// pass structs to functions. 
//
// Author: Joshua Nelson Gomes 
//
// Date: 02/06/2019
//
// IDE Used: Vim/g++
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int NAME_SIZE = 40;
const int DATA_SIZE = 5;

//struct definition
struct NutritionData{
	char foodName[NAME_SIZE];
	double servingSize;
    double calFromCarb;
    double calFromFat;
    double calFromProtein;
    double totalCalories;
};

//Function prototypes
//void	loadData(Sale s[], int size);

int main() {
	
	//Define an int constant named SALES_SIZE and initialize it to 5
	string const FILE_NAME = "nutri.dat";
	
	fstream file;
	file.open(FILE_NAME, ios::in);
	
	if (file.fail()) {
	    file.open(FILE_NAME, ios::out | ios::binary);
	}
	else {
	    file.close();
	    cout    <<  "The file nutri.dat is an existing file. You can either " 
	            <<  "delete the file or move it to another location and then run the program again.\n";
	    return 0;
	}

/*	
	NutritionData data[DATA_SIZE] = { {"Apples raw", 110, 50.6, 1.2, 1.0},
	                       {"Bananas", 225, 186, 6.2, 8.2},
	                       {"Bread pita whole wheat", 64, 134, 14, 22.6},
	                       {"Broccoli raw", 91, 21.9, 2.8, 6.3},
	                       {"Carrots raw", 128, 46.6, 2.6, 3.3},
	};
	
	*/
	for(int ctr = 0; ctr < DATA_SIZE; ++ctr) {
		file.write(reinterpret_cast<char >(data[ctr]), sizeof(data));
	}

	file.close();


	file.open("nutri.dat", ios::in | ios::binary);

	if (!file) {
		cout << "Error opening file. Program aborting.\n";
		return 0;
	}

	cout << "Now reading\n";

	file.read(reinterpret_cast<char *>(&data), sizeof(data));

	while (!file.eof()) {

		cout << "Food Name: ";
		cout << data.foodName << endl;
		cout << "Serving Size: ";
		cout << data.servingSize << endl;
		cout << "Calories Per Serving:\n ";
		//cout << data.totalCalories << endl;
		cout << "Calories From Carb: ";
		cout << data.calFromCarb << endl;
		cout << "Calories From Fat: ";
		cout << data.calFromFat << endl;
		cout << "Calories From Protein: ";
		cout << data.calFromProtein << endl;

		
		file.read(reinterpret_cast<char *>(&data), sizeof(data));
	}



	file.close();
	
	return 0;
}

/*
 Copy output of this program below this line.
 --------------------------------------------
Sales
Item                 Qty      Unit       Amt
============================================
Milk                1         5.85      5.85      
Whole Wheat Bread   2         3.75      7.50      
Napkin              3         2.35      7.05      
Paper Towel         3         2.95      8.85      
Soap                1         1.95      1.95      
Total                                  31.20 
*/
