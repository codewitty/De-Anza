/**~*~*~*
 PART B - Intro to files
 
 This program writes 10 random numbers to a file.
 Then reads the numbers from the file, displays them to the screen,
 and calculates their average.
 
 Finish the program following the specifications listed below as comments.
 Run the program and save the output as a comment at the end of the source file.
 
 JOSHUA N. GOMES
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    ofstream outputFile;
    int rNum;
    
    // Open an output file.
    outputFile.open("Numbers.txt");
    
    // Write 10 random numbers to the file
    for (int i = 0; i < 10; i++)
    {
        rNum = rand() % 51 - 10;
        outputFile << rNum << " ";
    }
    
    // Close the file.
    outputFile.close();
    cout << "File with 10 random numbers created!\n";
    
    // Open the same file to read from;
    //string fileName = "Number.txt";  // <==== Try to open this file!
    ifstream inputFile;
    string fileName = "Numbers.txt";
    
    inputFile.open(fileName.c_str());  // another way of opening the input file
    if (!inputFile) // could not open the input file // <=== Always check this!
    {
        cout << "Error opening " << fileName << " for reading!\n";
    }
    else
    {
        // calculate the average of the positive numbers ( > 0 )
        // define other variables as needed
        int sum = 0;
        while (inputFile >> rNum)
        {
            cout << rNum << " ";
            sum += rNum;
            
        }
        // Close the file.
        inputFile.close();
        
        // Show average
        cout << "\n\nThe average of the random numbers is: " << sum / 10.0 << endl;
        
        // Show the average of the positive ( > 0 ) numbers
        
        
    }
    return 0;
}
/**~*~*~*~*~*~*~*~*~*
File with 10 random numbers created!
0 39 -1 24 22 27 27 38 35 9 

The average of the random numbers is: 22

 
 */
