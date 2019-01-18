// Program name: Lab1c
//
// Description: This program prints the Corporation Sales report
// 		to the screen.
//
// What's on your mind about this lab? 
// This exercise helps me understand the C- String variables 
// how to initialise them, 
// pass them to functions and print them to the screen.
//
// Author: Joshua Nelson Gomes 
//
// Date: 01/17/2019
//
// IDE Used: Vim/Terminal
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//global constant declaration and function prototypes
const int SIZE_1 = 100;
const int SIZE_2 = 1000;
void	printSalesData(double arr[][COLS], int rows);


int main() {
	//Define and initialize pointers named ptr1 and ptr2,
	//for pointing to an int value.
	int *ptr1 = nullptr;
	int *ptr2 = nullptr;

	double matrix[ROWS][COLS] = {
		{201.24, 150.91, 270.83, 421.51},
		{312.43, 422.14, 251.85, 732.53},
		{271.83, 321.55, 321.67, 641.69}
	};
	//print header
	cout << "Corporation Sales Report" << endl;
    	cout << " DIV"	<< "        Q1"
			<< "       Q2"
			<< "       Q3"
			<< "       Q4\n";

	//print sales data
	printSalesData(matrix, ROWS);

	return 0;
}

//************************************************************************
//* Function name: printSalesData
//*
//* This function prints the matrix portion of the report in the specified
//* format.
//*
//* Parameters:
//*	arr  -  This is a 2d Array of doubles.
//*	rows -  This is an int variable that tells us how many rows the
//*	        array is made up of.
//* Returns:
//*		Function does not return anything
//*
//*
//************************************************************************

void	allocIntArray(int nbr_values) {
	int *ptr_temp;
	for (ptr; size < ptr + nbr_values; ptr++) {
		// Print the row beginning with row number
		*ptr_temp = new int;
	}
}




/*
 Copy output of this program below this line.
 --------------------------------------------
 
Corporation Sales Report
 DIV        Q1       Q2       Q3       Q4
   0    201.24   150.91   270.83   421.51
   1    312.43   422.14   251.85   732.53
   2    271.83   321.55   321.67   641.69


 */
