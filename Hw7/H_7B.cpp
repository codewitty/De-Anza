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
bool	getScores(ifstream &inFile, string &s_id, double &finalScores, int size);
double 	Lowest(const double array[], int size);
double 	get_highest(const double array[], int size);

double getTotal(const double array[], int size);

int main()
{
	string inputFile;
	string outputFile;
	ifstream inFile;
	ofstream outFile;
	const int SIZE = 45;		// Array maximum size
	int size = 0;			// Array actual size
	int y = 0;
	string s_id[SIZE];		// Array of student id's
	double	finalScores[SIZE],	// Array of final exam scores
        	total,			// Total of the scores
		lowestScore,		// Lowest test score
		highestScore,		// Highest exam score
		average;		// Average test score
		
	welcome();
	cout << "Please enter the name of the file that contains the student id's and exam scores.\n";
	cin >> inputFile;
	inFile.open("scores.txt");
	if(!inFile)
    		{
        		cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        		return 1;
    		}
	for(int i = 0; i < SIZE ; i++)
	{
		inFile << s_id[i] << finalScores[i];
		size++;
	}
		
		//while (getScores(inFile, s_id, finalScores))
      		//size++;
	// Get the total of the test scores.
	total = getTotal(finalScores, size);
	
	// Calculate the average
	average = total / size;
	
	lowestScore = Lowest(finalScores, size);
	highestScore = get_highest(finalScores, size);
	cout << "The average class score is"
        << average << " and the class strength is " << size << ".\n"
	<< "The students with the lowest score are: ";

	while (y < size)
	{
		if (finalScores[y] == lowestScore)
		{
			cout << s_id[y] << " score : " << lowestScore << endl;
		}
		y++;
	}

	cout << "The students with the highest score are: ";
	
	while (y < size)
	{
		if (finalScores[y] == highestScore)
		{
			cout << s_id[y] << " score : " << highestScore << endl;
		}
		y++;
	}
	inFile.close();
	
	cout << "Please enter the name of the file you'd like to write the results to.\n";
	cin >> outputFile;
	
	outFile.open(outputFile);
	// Write the array contents to the file.
	for (int y; y < size; y++)
	{
		if (finalScores[y] < average)
		{
			 outFile << s_id[y] << " : " << finalScores[y] << endl;
		}
		y++;
	}
	// Close the file.
	outFile.close();
	cout << "That's all folks!!! \n\n\n";

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
*/
bool	getScores(ifstream &inFile, string &s_id, double &finalScores, int size)
{
	
	return (inFile >> s_id[size] >> finalScores[size]);
}

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

//****************************************************
// The getLowest function accepts a double array and *
// its size as arguments. The lowest value in the    *
// array is returned as a double.                    *
//****************************************************


double get_highest(const double array[], int size)
{
	double high;	// To hold the highest value

	// Get the first array's first element.
	high = array[0];

	// Step through the rest of the array. When a
	// value less than lowest is found, assign it
	// to lowest. When a value more than highest is found assign it to highest.

	for (int count = 1; count < size; count++)
	{
		if (array[count] > high)
			high = array[count];
	}
	// Return the lowest value.
	return high;
}
double Lowest(const double array[], int size)
{
	double lowest;	// To hold the lowest value

	// Get the first array's first element.
	lowest = array[0];

	// Step through the rest of the array. When a
	// value less than lowest is found, assign it
	// to lowest.

	for (int count = 1; count < size; count++)
	{
		if (array[count] < lowest)
			lowest = array[count];
	}
	// Return the lowest value.
	return lowest;
}
