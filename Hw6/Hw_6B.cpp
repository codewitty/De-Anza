/**~*~*~*~*~*~
   Project 6B:
 
   Defining and using functions in a C++ program

   This program will output the perimeter and area
   of several rectangles. 
 
   The program reads data from "rectangles.txt"
   Create the input file using the follwing data:
10 20
10 5
2 100
30 50
9 7
2 3
9 9

   Find and fix the errors, then run the program and save its output.
 
   NAME:
 
*~**/

#include <iostream>
#include <fstream>

using namespace std;

const  double PI = 3.14;

void welcome(void);
void farewell(void);
void displayRectangle(double length, double width, double area, double perim);
void calculateRectangle(double length, double width, double area, double perim);
bool getRectangle(ifstream &inFile, double &length, double &width);

int main()
{
    ifstream inFile;
    double length, width;
	double area, perim;

    welcome();
    //inFile.open("rectngles.txt"); // <== incorect file name!
    inFile.open("rectangles.txt");
    if(!inFile)
    {
        cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        return 1; // or you could use exit(1);
    }
    while (getRectangle(inFile, length, width))
    {
        calculateRectangle(length, width, perim, area);
        displayRectangle(length, width, area, perim);
    }
    inFile.close();
    farewell();

    return 0;
}

/**~*~*
 This function displays general information
 about the program
*~**/
void welcome(void)
{
    cout << "WELCOME to the RECTANGLE calculator!\n\n"
         << "This program will output the\n"
         << "\tperimeter and\n"
         << "\tarea\n"
         << "of several rectangles.\n\n";
    return;
}

/**~*~*
 This function displays the end-of-the-program
 message
*~**/
void farewell(void)
{
    cout << "\n\n"
         << "\t ~~*~~ The END ~~*~~ \n\n"
         << "\t        ~~*~~ \n"
         << "\t      Thank you\n\tfor using my program!\n";
    return;
}

/**~*~*
 This function displays the length and the width of a rectangle
 and its area and perimeter
*~**/
void displayRectangle(double length, double width, double area, double perim)
{
    cout << "\nRESULTS: ";
    cout << "\tLength = " << length;
    cout << ", Width  = " << width  << endl;
    cout << "\t\tPerimeter = " << perim << endl;
    cout << "\t\t     Area = " << area << endl;
    return;
}

/**~*~*
 This function reads the length and the width of a rectangle
 from a file. It returns true in case of success, false otherwise.
*~**/
bool getRectangle(ifstream &inFile, double &length, double &width)
{
    return inFile  >> length >> width;
}

/**~*~*
 This function calcualtes 
 the area and the perimeter of a rectangle
 *~**/
void displayRectangle(double length, double width,
                      double area, double perim)
{
    perim = 2 * (length + width);
    area  = length * width;
    return;
}
/**
OUTPUT:

*/
