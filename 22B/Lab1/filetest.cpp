// Program name: Lab1d
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
#include <fstream>

using namespace std;

//Function prototypes
void	sentenceCapitalizer(char *pointer);


int main() {
	fstream output ("output.txt", ios::out);
	for (int i; i < 10; ++i) {
		output << i;
		if ((i + 1) % 3 == 0) {
			output << endl;
		}
		else {
			output << " ";
		}
	}
	output.close();
	return 0;
}
