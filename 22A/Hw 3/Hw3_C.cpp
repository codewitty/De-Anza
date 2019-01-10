/**
 PART C
 
 Write a program that will do the following steps (pseudo-code):
 1.	Display a welcome message and a title, such as “Working with random numbers and simple mathematical functions”. Then display the name of the library functions you are going to use in this program and the header files needed for each function.
 2.	Generate 3 random numbers between -5 and 13 inclusive:
     r1, r2, r3
 3.	Generate one random number between 2 and 6 inclusive, name it x
 4.	Calculate result as r3 to the power of x
 5.	Calculate the average of the 3 random numbers
 6.	Calculate the square root of the average
 7.	Calculate the geometric mean of the random numbers (the product of these numbers to the power of 1 / 3)
 8.	Display a line of “=”, such as “=================\n”
 9.	Display the following (with description):
 •	 r1, r2, r3
 •	 r3, x, and result
 •	average of the 3 numbers with 2 digits after the decimal point
 •	square root of the average with 4 digits after the decimal point
 •	geometric mean of the random numbers with 1 digit after the decimal point
 

Name : Gomes Joshua Nelson
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int r1, r2, r3, x;
	double avg;
	double square_rt;
	double g_mean;
	double result;
	double prod;


	unsigned seed = time(0);

	srand(seed);
	r1 = rand() % (9) - 5;
	r2 = rand() % (9) - 5;
	r3 = rand() % (9) - 5;

	x = rand() % (3) + 2;

	result = pow(r3, x);
	
	avg = (r1 + r2 + r3) / 3;

	square_rt = sqrt(avg);
	 
	prod = r1 * r2 * r3;
	g_mean = pow(prod, 1/3.0);

	cout << "Welcome!! Today we'll be having some fun with random numbers and simple math functions\n";

	cout << "We will be using the following library functions and their associated header files: \n";

	cout << "pow & sqrt : cmath\n";
	cout << "time : ctime\n" << "rand and srand : cstdlib\n" << "setprecision, showpoint & fixed : iomanip\n";



	cout << "==================================================\n";

	cout << "The first random number, r1 = " << r1 << "\n";
	cout << "The second random number, r2 = " << r2 << "\n";
	cout << "The third random number, r3 = " << r3 << "\n";

	cout << "r3 = " << r3 << "\nx = " << x << "\nresult = " << result << endl;

	cout << setprecision(2) << fixed << showpoint << "The Average is : " << avg << endl;
	
	cout << setprecision(4) << fixed << showpoint << "The Square Root is : " << square_rt << endl;

	cout << setprecision(1) << fixed << showpoint << "The Geometric Mean is : " << g_mean << endl;

   return 0;
}
/*********************************************************************************
Welcome!! Today we'll be having some fun with random numbers and simple math functions
We will be using the following library functions and their associated header files: 
pow & sqrt : cmath
time : ctime
rand and srand : cstdlib
setprecision, showpoint & fixed : iomanip

==================================================
The first random number, r1 = -2
The second random number, r2 = -2
The third random number, r3 = 2
r3 = 2
x = 4
result = 16
The Average is : 0.00
The Square Root is : 0.0000
The Geometric Mean is : 2.0

*/


/*********************************************************************************
Welcome!! Today we'll be having some fun with random numbers and simple math functions
We will be using the following library functions and their associated header files: 
pow & sqrt : cmath
time : ctime
rand and srand : cstdlib
setprecision, showpoint & fixed : iomanip

==================================================
The first random number, r1 = -1
The second random number, r2 = 0
The third random number, r3 = -2
r3 = -2
x = 2
result = 4
The Average is : -1.00
The Square Root is : -nan
The Geometric Mean is : 0.0

*/
