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
int	*allocIntArray(int nbr_values);


int main() {
	//Define and initialize pointers named ptr1 and ptr2,
	//for pointing to an int value.
	int *ptr1 = nullptr;
	int *ptr2 = nullptr;

	ptr1 = allocIntArray(SIZE_1);
	cout << "checkflag2\n";
	//Store odd numbers in the array
	int counter = 1;
	for (int i = 0; i < SIZE_1; i++) {
		ptr1[i] = counter;
		counter += 2;
	}

	counter = 2;
	ptr2 = allocIntArray(SIZE_2);
	//Store even numbers in the array
	for (int i = 0; i < SIZE_2; i++) {
		ptr2[i] = counter;
		counter += 2;
	}
	//print partial arrays
	cout 	<< *ptr1 << " " << *(ptr1 +1) << " " << *(ptr1 + 2)
		<< "..." << *(ptr1 + 97) << " " << *(ptr1 + 98) << " " << *(ptr1 + 99) << endl;
	cout	<< *ptr2 << " " << *(ptr2 +1) << " " << *(ptr2 + 2)
		<< "..." << *(ptr2 + 997) << " " << *(ptr2 + 998) << " " << *(ptr2 + 999) << endl;

	delete [] ptr1;
	delete [] ptr2;
	
	
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

int	*allocIntArray(int nbr_values) {
	int *ptr_temp = new int[nbr_values];
	return ptr_temp;
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
