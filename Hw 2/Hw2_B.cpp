/**
   Constants, variables and arithmetic operators

   This program will output the circumference and area
   of the circle with a given radius.

   	NAME: JOSHUA NELSON GOMES
	IDE: vim / g++
	DATE: 10/03/2019 
*/
#include <iostream>

using namespace std;

const  double PI = 3.14;

int main()
{
	double	circumference;                // definition of circumference
    double	radius = 5.4;                 // definition and initialization of the radius
    double	area;                        // definition of area of circle
    
    // Calculations Section
    circumference = 2 * PI * radius;    // computes circumference

    area = PI * radius * radius;                       // computes area

    // Display Results Section
    // Fill in the code for the cout statement that will output (with description)
    // the radius
    cout << "The radius of the circle is : " << radius << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the circumference
    cout << "The circumference of the circle is : " << circumference << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the area of the circle
    cout << "The area of the circle is : " << area << endl;


   return 0;
}
/*********************************************************************************
The radius of the circle is : 5.4
The circumference of the circle is : 33.912
The area of the circle is : 91.5624
 
*/
