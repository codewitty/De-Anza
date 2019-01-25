// Program name: Lab1d
//
// Description: This program uses 
// 		by dynamically allocating an array of integers to
// 		the array and storing values in the array using 
// 		pointers. It then prints the partial contents of 
// 		the arrays to the screen.
//
// What's on your mind about this lab? 
// This exercise helps me understand dynamic memory allocation 
// how to use it to initialise an array,
// pass them to functions and print the contents to the screen.
//
// Author: Joshua Nelson Gomes 
//
// Date: 01/24/2019
//
// IDE Used: Vim/Terminal
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//global constant declaration and function prototypes
void	sentenceCapitalizer(char *pointer);


int main() {
	//Define and initialize pointers named ptr1 and ptr2,
	//for pointing to an int value.
	int *ptr2 = nullptr;

	//Allocate an array that can contain 100 int values 
	//by calling allocIntArray, 
	//and assign the returned pointer to ptr1
	ptr1 = allocIntArray(SIZE_1);
	
	//Store odd numbers in the array starting from 1
	int value = 1;
	for (int arrayCtr = 0; arrayCtr < SIZE_1; arrayCtr++) {
		*(ptr1 + arrayCtr) = value;
		value += 2;
	}

	//Allocate an array that can contain 1000 int values 
	//by calling allocIntArray 
	//and assign the returned pointer to ptr1
	ptr2 = allocIntArray(SIZE_2);
	
	//Store even numbers in the array starting from 2
	value = 2;
	for (int arrayCtr = 0; arrayCtr  < SIZE_2; arrayCtr++) {
		*(ptr2 + arrayCtr) = value;
		value += 2;
	}

	//print partial arrays to the screen
	for (int arrayCtr = 0; arrayCtr < 3; arrayCtr++) {
		cout << *(ptr1 + arrayCtr) << " ";
	}
	cout << "...";
	for (int arrayCtr = (SIZE_1 - 3); arrayCtr < (SIZE_1); arrayCtr++) {
		cout << " " << *(ptr1 + arrayCtr);
	}
	cout << "\n";
	for (int arrayCtr = 0; arrayCtr < 3; arrayCtr++) {
		cout << *(ptr2 + arrayCtr) << " ";
	}
	cout << "...";
	for (int arrayCtr = (SIZE_2 - 3); arrayCtr < (SIZE_2); arrayCtr++) {
		cout << " " << *(ptr2 + arrayCtr);
	}
	cout << "\n";
	
	//free allocated memory from both pointers
	delete [] ptr1;
	delete [] ptr2;
	
	
	return 0;
}

//************************************************************************
//* Function name: allocIntArray
//*
//* This function allocates memory for an int array according to
//* the size specified in the input parameter.
//*
//* Parameters:
//*	nbr_values  -  This is the size of the array to be allocated.
//* Returns:
//*		Function returns a pointer to the allocated array.
//*
//*
//************************************************************************

int	*allocIntArray(int sizeOfArray) {
	int *ptrTemp = new int[sizeOfArray];
	return ptrTemp;
}



/*
 Copy output of this program below this line.
 --------------------------------------------

1 3 5 ... 195 197 199
2 4 6 ... 1996 1998 2000

*/
