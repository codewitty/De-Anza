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
void	sentenceCapitalizer(char *pointer);


int main() {
	struct Sale{
		string itemName;
		int quantity;
		double unitPrice;
		double salePrice;
	};
	
	//Define an int constant named SALES_SIZE and initialize it to 5
	int const SALES_SIZE = 5;
	
	salesData[SALES_SIZE];
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

void	loadData(char *Sale, int sizeOfSale)
{
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
