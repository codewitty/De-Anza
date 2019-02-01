// Program name: Lab2a
//
// Description: This program capitalises the first letter of  
// 		each sentence by iterating through a given
// 		char array using a pointer.
//
// What's on your mind about this lab? 
// This exercise helps me understand how to use C library functions
// to manipulate char arrays and also how to pass pointers to 
// functions and use them to iterate through a C string.
//
// Author: Joshua Nelson Gomes 
//
// Date: 01/28/2019
//
// IDE Used: Vim/Terminal
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function prototypes
struct Sale{
	string itemName;
	int quantity;
	double unitPrice;
	double salePrice;
};

int const SALES_SIZE = 5;

void	printData(Sale salesData [], int sizeOfSale);
double	processData(Sale salesData [], int sizeOfSale); 
void	loadData(Sale & , int sizeOfSale);

int main() {
	
	//Define an int constant named SALES_SIZE and initialize it to 5
	
	Sale salesData[SALES_SIZE];
	
	loadData(salesData&, SALES_SIZE);

	printData(salesData, SALES_SIZE);

	return 0;

}

//************************************************************************
//* Function name: sentenceCapitalizer 
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

void	loadData(Sale &salesData , int sizeOfSale)
{
	for (int ctr = 0; ctr < sizeOfSale; ++ctr){
		Sale salesData[ctr] = {
				{ "Milk", 1, 5.85 },
				{ "Whole Wheat Bread", 3, 3.75},
				{ "Napkin", 3, 2.35},
				{ "Paper Towel", 3, 2.95},
				{ "Soap", 1, 1.95}
			};

	}
}

//************************************************************************
//* Function name: sentenceCapitalizer 
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

double	processData(Sale salesData[], int sizeOfSale) {
	int totalPrice;
	for (int ctr = 0; ctr < sizeOfSale; ++ctr) {
		salesData[ctr].salePrice = salesData[ctr].quantity * salesData[ctr].unitPrice;
		totalPrice += salesData[ctr].salePrice;
	}
	return totalPrice;
}


//************************************************************************
//* Function name: sentenceCapitalizer 
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

void	printData(Sale salesData[], int sizeOfSale){
	double totalPrice = processData(salesData, sizeOfSale);

	cout 	<< "Sales" << endl;

	cout 	<< "Item" << setw(10) << "Qty" << setw (5) << "Unit"
		<< setw (5) << "Amt" << endl;
	cout	<< "================================================\n";

	for (int ctr = 0; ctr < sizeOfSale; ++ctr) {
		cout	<< salesData[ctr].itemName << setw (15)
			<< salesData[ctr].quantity << setw (5)
			<< salesData[ctr].unitPrice << setw (5)
			<< salesData[ctr].salePrice << setw (5) << endl;
	}
	
	cout << endl << "Total" << setw (25) << totalPrice;
}
/*
 Copy output of this program below this line.
 --------------------------------------------

no, not tonight.  it's a very popular place and you have to make reservations
in advance. besides,it's expensive, and I don't have any money.
No, not tonight.  It's a very popular place and you have to make reservations
in advance. Besides,it's expensive, and I don't have any money.

*/
