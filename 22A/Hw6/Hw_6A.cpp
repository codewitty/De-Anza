/**~*~*~*~*~*~
   Project 6A: - in class exercise
 
   Defining and using functions in a C++ program:

       void welcome(void);                          // No paramaters, no return value
       void farewell(void);
       void printCircle(double, double, double);    // PASS BY VALUE
       double getRadius(void);                      // return a value which is a double
       double calcArea(double);                     // receive a value and return a value
       double calcCirc(double);
 
       double calculateCircle(double, &double, &double); // PASS BY REFERENCE
 
   This program will output the circumference and area
   of a circle with a given radius.
 
	NAME: JOSHUA N GOMES; 
*~**/

#include <iostream>

using namespace std;

const  double PI = 3.14;

void	welcome(void);
void	farewell(void);
void	printResults(double radius, double circ, double area);
double	getRadius(void);
double	calcCirc(double radius);
double	calcArea(double radius);
void	calculateCircle(double radius, double &area, double &circ);

int main()
{
	double radius;
	double area, circ;
    // Display a welcome message
	welcome();
    // Get Radius
	radius = getRadius();
   
    // Perform Calculations
	circ = calcCirc(radius);  //function to calculate circumference   
	area = calcArea(radius); //function call to calculate Area for the circle

    // Display Results
	printResults(radius, circ, area); //call to arguments (actual parameters)

	area = circ = 0;
	calculateCircle(radius, area, circ);    

	printResults(radius, circ, area); 

	farewell(); // Display an "end of the program" message
    
   return (0);
}

void	welcome() //function definition
{
	cout << "WELCOME to the CIRCLE calculator!\n\n"
         << "This program will output the\n"
         << "\tcircumference and\n"
         << "\tarea\n"
         << "of a circle with a given radius.\n\n";
}

void	farewell()
{
	cout << "\n\n"
         << "\t ~~*~~ The END ~~*~~ \n\n"
         << "\t        ~~*~~ \n"
         << "\t      Thank you\n\tfor using my program!\n";
}

void	printResults(double radius, double circ, double area)
{
	cout << "\n\nRESULTS\n";
    	cout << "\tRadius = " << radius << endl;
    	cout << "\tCircumference = " << circ << endl;
    	cout << "\tArea = " << area << endl;
}

double	getRadius(void)
{
	double r; 
	do
    {
        cout << "Enter radius (must be > 0): ";
        cin  >> r;
    } while (r <= 0);
	return (r);

}

double	calcCirc(double radius)
{
	double circ = 2.0 * PI * radius;
	return (circ);
}

double	calcArea(double radius)
{
	return  ( PI * radius * radius * 1.0);
}

void	calculateCircle(double radius, double &area, double &circ)
{

	area =	( PI * radius * radius * 1.0);
	circ = 	2.0 * PI * radius;
	return;
}

/****************************************

*************Output***********

WELCOME to the CIRCLE calculator!

This program will output the
	circumference and
	area
of a circle with a given radius.

Enter radius (must be > 0): 3


RESULTS
	Radius = 3
	Circumference = 18.84
	Area = 28.26


RESULTS
	Radius = 3
	Circumference = 18.84
	Area = 28.26


	 ~~*~~ The END ~~*~~ 

	        ~~*~~ 
	      Thank you
	for using my program!
 
*******************************************/
