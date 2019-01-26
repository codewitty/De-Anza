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
	char userString [] = "no, not tonight.  it's a very popular place \
and you have to make reservations in advance. besides,\
it's expensive, and I don't have any money.";

	//Print unmodified string
	cout << userString << "\n";
	char *ptr1 = nullptr;

	ptr1 = userString;
	
	sentenceCapitalizer(ptr1);
	
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
	if (*ptr >= 97 || *ptr <= 122) {
			*ptr -= 32;
		}
	while (*ptr) {
		if (*ptr == '.') {
			flag = true;
		}
		if (((*ptr >= 97 && * ptr <= 122) || (*ptr >= 65 && *ptr <= 90)) && (flag == true)) {
			if ( *ptr >= 97 && *ptr <= 122) {
				*ptr -= 32;
			}
			flag = false;
		}
		ptr++;
	}

	
	
	
}



/*
 Copy output of this program below this line.
 --------------------------------------------

1 3 5 ... 195 197 199
2 4 6 ... 1996 1998 2000

*/
