// Program name: Lab1a
//
// Description: This program prints the Corporation Sales report
// 		to the screen.
//
// What's on your mind about this lab? 
// This exercise helps me understand the basic concepts 
// of using 2D arrays, how to initialise them, 
// pass them to functions and print them to the screen.
//
// Author: Joshua Nelson Gomes 
//
// Date: 01/11/2019
//
// IDE Used: Vim/Terminal
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//global constant declaration and function prototypes
const int COLS = 4;
void	printSalesData(double arr[][COLS], int rows);


int main() {
	//Define and initialize a 2D array
	const int ROWS = 3;
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

void	printSalesData(double arr[][COLS], int rows) {
	for (int row = 0; row < rows; row++) {
		// Print the row beginning with row number
		cout << "   " << row << " ";
		// Print each element of the report
		for (int col = 0; col < COLS; col++) {
			cout << "   " << arr[row][col];
		}
		// Move to a new line after each row
		cout << '\n';
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
