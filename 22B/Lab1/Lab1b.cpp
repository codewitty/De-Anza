// Program name: Lab1b
//
// Description: This program prints the expense report
// 		to the screen.
//
// What's on your mind about this lab? 
// This exercise helps me to understand how pointers are used
// how to initialise them, pass them to functions 
// and use loops to print them to the screen.
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


int main() {
	//define int constant
	const int NUM_EXPENSES = 7;
	//define and initialise variables, pointer and array
	double sum = 0;
	double average;
	double expenses[NUM_EXPENSES] = {
		45.25, 49.38, 12.75, 123.50, 8.25, 19.95,
		145.70};
	double *ptr = expenses;

	/*iterate through the array using ptr to calculate the total 
	 *of the expenses.*/
	for (ptr; ptr < &expenses[NUM_EXPENSES]; ptr++) {
		sum += *ptr;
	}

	//use the total to find the average of the expenses
	average = sum / NUM_EXPENSES;
	cout << sum << endl << average << endl << endl; 
	ptr = expenses;
	/* This block of code prints the report header first. It then uses 
	 * the pointer variable to iterate through the expenses array to 
	 * print the expenses. Finally it prints the total and the average.
	*/

	//print header
	cout << " #              Amount" << endl;
    	cout << "----------------------" << endl;
	
	//loop through array and print it along with total and average
	for (int i = 1; i <= NUM_EXPENSES; i++) {
		cout	<< " " << i << setw(20) << right << fixed 
			<< setprecision(2) << ptr[i - 1] << endl;
	}

	cout	<< "Total" << setw(17) << right
		<< fixed << setprecision(2) << sum << endl
		<< "Average" << setw(15) << right
		<< fixed << setprecision(2) << average << endl;
	return 0;
}
