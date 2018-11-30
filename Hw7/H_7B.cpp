/*
  Exam Statistics.
 
  NAME
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes
void	welcome(void);
bool	getScores(ifstream &inFile, string &s_id[], double &finalScores[]);

int main()
{
	string inputFile;
	ifstream inFile;
	const int SIZE = 45;		// Array maximum size
	int size;			// Array actual size
	string s_id[SIZE],		// Array of student id's
	double	finalScores[SIZE],	// Array of final exam scores
        	total,			// Total of the scores
		lowestScore,		// Lowest test score
		average;		// Average test score
	
	welcome();
	cout << "Please enter the name of the file that contains the student id's and exam scores.\n";
	cin >> inputFile;
	inFile.open(inputFile);
	if(!inFile)
    		{
        		cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        		return 1;
    		}
	while (count < SIZE && inputFile >> s_id[size] >> numbers[size])
      		size++;
	// Get the total of the test scores.
	total = getTotal(finalScores, size);
	
	// Calculate the average
	average = total / size;


	return 0;
}

//This function prints a welcome message to the screen. It also explains what the program does. 
void	welcome(void)
{
	cout	<< "This program reads the final exam scores and corresponding student id's it then displays the following results"
		<< "displays the following results: \n• The total number of students in the array \n• The class average \n"
		<< "• The lowest score in the array followed by the ids of the students with that score \n"
		<< "• The highest score in the array followed by the ids of the students with that score.\n"
		<< " The program also prompts the user to enter the name of an output file it writes all the" 
		<< " scores below the average, and the corresponding id's.\n\n";
}
 /*~*~*~*
This function checks the input file for data and reads the data line-by-line into the given variables
To accomplish this we pass by reference into the declared variables. 

bool	getScores(ifstream &inFile, string &s_id[], double &finalScores)
{
	
	return inFile >> name >> sc1 >> sc2 >> sc3 >> sc4 >> sc5;
}*/

//****************************************************
// The getTotal function accepts a double array      *
// and its size as arguments. The sum of the array's *
// elements is returned as a double.                 *
//****************************************************

double getTotal(const double array[], int size)
{
   double total = 0; // Accumulator

   // Add each element to total.
   for (int counter = 0; counter < size; counter++)
      total += array[counter];

   // Return the total.
   return total;
}

