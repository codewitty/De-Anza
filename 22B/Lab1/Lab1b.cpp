// Program name: Lab1b
//
// Description: This program prints the expense report
// 		to the screen.
//
// What's on your mind about this lab? 
// This exercise helps me to continut to understand 
// the basic concepts of using 2D arrays, how to initialise them, 
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


int main() {
	const int NUM_EXPENSES = 7;
	double sum = 0;
	double average;
	double expenses[NUM_EXPENSES] = {
		45.25, 49.38, 12.75, 123.50, 8.25, 19.95,
		145.70};
	double *ptr = nullptr;

	for (int i = 0; i < NUM_EXPENSES; i++) {
		sum += expenses[i];
	}

	average = sum / NUM_EXPENSES;


	//print report
	cout << " #              Amount" << endl;
    	cout << "----------------------" << endl;

	for (int i = 1; i <= NUM_EXPENSES; i++) {
		cout	<< " " << i << setw(20) << right << fixed << setprecision(2)
			<< expenses[i - 1] << endl;
	}

	cout	<< "Total" << setw(17) << right
		<< fixed << setprecision(2) << sum << endl
		<< "Average" << setw(15) << right
		<< fixed << setprecision(2) << average << endl;
	return 0;
}
