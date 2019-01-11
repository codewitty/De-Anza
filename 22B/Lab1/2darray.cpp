// Program name: Lab1a
//
// Description: This program prints a greeting on the user's screen.
// 
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Joshua Nelson Gomes 
//
// Date: 01/11/2019
//
// IDE Used: Vim/Terminal
//

// Note: DO NOT remove these include statements.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Remove the following line if the definition foo is removed.
void	header(void);

const int COLS = 4;

int main() {
	//Define and initialize a 2D array
	const int ROWS = 3;
	double matrix[ROWS][COLS] = {
		{201.24, 150.91, 270.83, 421.51},
		{312.43, 422.14, 251.85, 732.53},
		{271.83, 321.55, 321.67, 641.69}
	};
	//print header
	header();
	return 0;
}

// Remove the function template below for the labs not requiring functions.
//************************************************************************
//* Function name: foo
//*
//* This function . . .
//*
//* Parameters:
//*    ptr - describe the purpose of this parameter
//*    size - describe the purpose of this parameter
//*
//* Returns:
//*
//*    Describe the return value
//*
//************************************************************************

void header(void) {
    // prints the header to the screen
    cout << "Corporation Sales Report" << endl;
    cout << "DIV" << "\t\t\t" << "Q1\t\t\tQ2\t\t\tQ3\t\t\tQ4\n";
};

/*
 Copy output of this program below this line.
 --------------------------------------------
 
 */
