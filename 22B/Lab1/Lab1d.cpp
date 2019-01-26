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

//Function prototypes
void	sentenceCapitalizer(char *pointer);


int main() {
	//Define and initialize a char array named userString
	//with the given string literal
	char userString [] = "no, not tonight.  it's a very popular place \
and you have to make reservations in advance. besides,\
it's expensive, and I don't have any money.";

	//Print unmodified string
	cout << userString << "\n";
	//intialise a pointer
	char *ptr1 = nullptr;

	//set the pointer to point to the array
	ptr1 = userString;
	
	//use the function to capitalise the sentence
	sentenceCapitalizer(ptr1);
	
	//Print the modified string
	cout << userString << endl;

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

void	sentenceCapitalizer(char *ptr)
{
	bool flag = false;
	if (islower(*ptr)) {
		isupper(*ptr);
		}
	while (*ptr) {
		if (*ptr == '.') {
			flag = true;
		}
		if (((islower(*ptr)) || (isupper(*ptr))) && (flag == true)) {
			if ( islower(*ptr)) {
				*ptr = isupper(*ptr);
			}
			flag = false;
		}
		ptr++;
	}
}



/*
 Copy output of this program below this line.
 --------------------------------------------

no, not tonight.  it's a very popular place and you have to make reservations
in advance. besides,it's expensive, and I don't have any money.
No, not tonight.  It's a very popular place and you have to make reservations
in advance. Besides,it's expensive, and I don't have any money.

*/
