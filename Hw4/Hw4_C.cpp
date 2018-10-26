/**~*~*~*
   PART C
 
 Mobile Service Provider (Chapter 4, Project 25):
 
 Run the program 7 times using the following input:
 1.  A 400
 2.  A 700
 3.  B 825
 4.  B 1001
 5.  C
 6.  A -129 // error
 7.  D  // error!
 
 Display clear error messages, showing what was wrong.
 NOTE: Do not forget to define and use named constants.

Name: Joshua N Gomes.
*/

#include <iostream>

using namespace std;

double const PKG_A = 39.99;
double const PKG_B = 59.99;
double const PKG_C = 69.99;

int main()
{
	char pkg_choice;
	double gb_used;
	double extra_gb;
	double monthly_bill;

	cout << "Which package did you purchase?(A/B/C) And how many GB of data did you use?\n" ;
	cin >> pkg_choice >> gb_used;

	switch(pkg_choice)
	{
		case 'A': 	if (gb_used >= 4)
					{
						extra_gb = gb_used - 4;
						cout << "Total due : " << PKG_A + extra_gb * 10 << endl;
					}
				else if (gb_used >= 0 && gb_used < 4)
					cout << "Total due : " << PKG_A << endl;
				else
					cout << "Invalid input\n" << endl;
				break;
		case 'B': 	if (gb_used >= 8)
					{
						extra_gb = gb_used - 8;
						cout << "Total due : " << PKG_B + extra_gb * 5 << endl;
					}
				else if (gb_used >= 0 && gb_used < 8)
					cout << "Total due : " << PKG_B << endl;
				else
					cout << "Invalid input\n" << endl;
				break;
		case 'C': 	if (gb_used >= 0)
					cout << "Total due : " << PKG_C << endl;
				else
					cout << "Invalid input\n" << endl;
				break;		
		default :	cout << "Invalid input" << endl;
				break;
	}
	return (0);
}

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 1:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
A
400
Total due : 3999.99

 
 */

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 2:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
A
700
Total due : 6999.99

*/

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 3:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
B
825
Total due : 4144.99

*/

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 4:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
B   
1001
Total due : 5024.99

*/

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 5:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
C
0
Total due : 69.99

*/

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 6:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
A
-129
Invalid input

*/

/**~*~*~*~*~*~*~*~*~*
 OUTPUT 7:
Which package did you purchase?(A/B/C) And how many GB of data did you use?
D
22
Invalid input

*/
