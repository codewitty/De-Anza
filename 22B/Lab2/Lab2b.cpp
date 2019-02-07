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

//struct definition
struct NutritionData{
	char foodName[40];
	double servingSize;
    double calFromCarb;
    double calFromFat;
    double calFromProtein;
    double totalCalories;
};

//Function prototypes
void	printData(Sale salesData [], int sizeOfSale);
double	processData(Sale salesData [], int sizeOfSale); 
void	loadData(Sale s[], int size);

int main() {
	
	//Define an int constant named SALES_SIZE and initialize it to 5
	string const FILE_NAME = "nutri.dat";
	
	fstream file;
	file.open(FILE_NAME, ios::in);
	
	if (file.fail()) {
	    file.open(FILE_NAME, ios::out);
	}
	else {
	    file.close();
	    cout    <<  "The file nutri.dat is an existing file. You can either 
	            <<  "delete the file or move it to another location and then run the program again.\n";
	    return 0;
	}
	
	NutritionData data[] = { {Apples raw, 110, 50.6, 1.2, 1.0},
	                       {Bananas, 225, 186, 6.2, 8.2},
	                       {Bread pita whole wheat, 64, 134, 14, 22.6},
	                       {Broccoli raw, 91, 21.9, 2.8, 6.3},
	                       {Carrots raw, 128, 46.6, 2.6, 3.3},
	};
	//define an array of struct of type Sale with constant size variable
	Sale salesData[SALES_SIZE]; 
	
	//Call loadData to pass values to the struct
	loadData(salesData, SALES_SIZE);
	
	//Call printData to calculate total sale price and print the output
	printData(salesData, SALES_SIZE);

	return 0;

}

//************************************************************************
//* Function name: loadData
//*
//* This function loads data into the struct array passed as a parameter
//* 
//*
//* Parameters:
//*	Sale sale[] - The array of structs of type Sale.
//	int size - the size of the struct array.
//* Returns:
//*	There is no returned value.
//*
//*
//************************************************************************

void loadData(Sale sale[], int size) {

	//use arrays to store the data to be passed to the struct
	string itemname[] = {"Milk", "Whole Wheat Bread", "Napkin", 
				"Paper Towel", "Soap"};
	int nos[] = {1, 2, 3, 3, 1};
	double price[] = {5.85, 3.75, 2.35, 2.95, 1.95};

	//use a loop to iterate through the struct array
	//and pass values from the above arrays to the
	//struct members.
	for (int index = 0; index < size; ++index) {
		sale->itemName = itemname[index];
		sale->quantity = nos[index];
		sale->unitPrice = price[index];
		++sale;
	}
}



//************************************************************************
//* Function name: processData 
//*
//*	This function iterates through the struct parameter using a counter
//* 	index. It then calculates and fills in the sales price 
//	field of the struct by multiplying quantity and unit price 
//*
//* Parameters:
//*	Sale sale[] - The array of structs of type Sale.
//	int sizeOfSale - the size of the struct array.

//ptr  -  This is a pointer of type char which points to the 
//		array that needs to be modified.
//* Returns:
//*	totalPrice - 	A double variable that holds the calculated total
//			sale value	
//*
//*
//************************************************************************

double	processData(Sale sale[], int sizeOfSale) {
	double totalPrice;
	
	//Calculate totalPrice using quantity and unitPrice
	for (int ctr = 0; ctr < sizeOfSale; ++ctr) {
		sale[ctr].salePrice = sale[ctr].quantity * sale[ctr].unitPrice;
		totalPrice += sale[ctr].salePrice;
	}
	return totalPrice;
}


//************************************************************************
//* Function name: printData
//*
//* 	Prints out the data contained in the struct parameter
//	
//*
//* Parameters:
//*	Sale salesData[] - The array of structs of type Sale.
//	int sizeOfSale - the size of the struct array.
// 
//* Returns:
//*	There is no returned value.
//*
//*
//************************************************************************

void	printData(Sale salesData[], int sizeOfSale){
	double totalPrice = processData(salesData, sizeOfSale);

	cout 	<< "Sales" << endl;

	cout 	<< "Item" << setw(20) << "Qty" << setw (10) << "Unit"
		<< setw (10) << "Amt" << endl;
	cout	<< "============================================\n";

	for (int ctr = 0; ctr < sizeOfSale; ++ctr) {
		cout	<< fixed << showpoint << setprecision(2)
			<< setw (20) << left 
			<< salesData[ctr].itemName 
			<< setw (10) << left 
			<< salesData[ctr].quantity
			<< setw (10) << left 
			<< salesData[ctr].unitPrice
			<< setw (10) << left 
			<< salesData[ctr].salePrice << endl;
	}
	
	cout 	<< endl << setw(39) << left << "Total" 
		<< left << setw (10) << totalPrice << endl;
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
