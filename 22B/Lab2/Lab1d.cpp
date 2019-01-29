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

void	sentenceCapitalizer(char *ptr)
{
	//initialise a bool flag to check for characters
	bool flag = false;

	//capitalise the first letter of the sentence
	if (islower(*ptr)) {
		*ptr = toupper(*ptr);
		}
	
	//iterate through the string until a period is found
	while (*ptr) {
		if (*ptr == '.') {
			flag = true;	//set the flag to true and check for
					//characters
		}
		//when the first character after a period is found, 
		//check case and then capitalise if needed
		if (((islower(*ptr)) || (isupper(*ptr))) && (flag == true)) {
			if ( islower(*ptr)) {
				*ptr = toupper(*ptr);
			}
			flag = false;	//reset flag to false to continue
					//iteration.
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
