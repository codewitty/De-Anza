/*
  Exam Statistics.
 
NAME: JOSHUA  GOMES 
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes
void	welcome(void);
bool	getScores(ifstream &inFile, string s_id[], int finalScores[], int size);
double 	getLowest(const int [], int size);
double 	get_highest(const int [], int size);
void	output_info(const string [], const int [], int size, double lowestScore, double highestScore, double average);
void	write_to_file(ofstream &outFile, const string [], const int [], int size, double average);
double	getTotal(const int [], int size);
void	exit_message(void);

int main()
{
	string inputFile;
	string outputFile;
	ifstream inFile;
	ofstream outFile;
	const int SIZE = 45;		// Array maximum size
	int size = 0;			// Array actual size
	string s_id[SIZE];		// Array of student id's
	int	finalScores[SIZE];	// Array of final exam scores
        double	total,			// Total of the scores
		lowestScore,		// Lowest test score
		highestScore,		// Highest exam score
		average;		// Average test score
		
	welcome();
	cout << "Please enter the name of the file that contains the student id's and exam scores.\n";
	cin >> inputFile;
	inFile.open(inputFile);
	if(!inFile)
    		{
        		cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        		return(1);
    		}
	while (getScores(inFile, s_id, finalScores, size))
      		size++;
	// Get the total of the test scores.
	total = getTotal(finalScores, size);
	
	// Calculate the average
	average = total / size;

	//Calculate the lowest score in the list
	lowestScore = getLowest(finalScores, size);
	
	//Calculate the highest score in the list
	highestScore = get_highest(finalScores, size);

	//Display the required info
	output_info(s_id, finalScores, size, lowestScore, highestScore, average);
	
	//close the input file
	inFile.close();
	
	//Prompt user to enter output file  name
	cout << "Please enter the name of the file you'd like to write the results to.\n";
	cin >> outputFile;
	
	// Open the output file and perform validation
    	outFile.open(outputFile);

	if(!outFile)
	{
        	cout << "~*~ Error opening the output file! ~*~\n";
		return(1);
	}	
	
	// Write the array contents to the file.
	write_to_file(outFile, s_id, finalScores, size, average);

	// Close the file.
	outFile.close();

	//End of Program Message
	exit_message();

	return (0);
}

//This function prints a welcome message to the screen. It also explains what the program does. 
void	welcome(void)
{
	cout	<< "*****Welcome******\nThis program reads the final exam scores and corresponding student id's it then "
		<< "displays the following results: \n• The total number of students in the array \n• The class average \n"
		<< "• The lowest score in the array followed by the ids of the students with that score \n"
		<< "• The highest score in the array followed by the ids of the students with that score.\n"
		<< "The program also prompts the user to enter the name of an output file it writes all the" 
		<< " scores below the average, and the corresponding id's.\n"
		<< " ****** Let's Begin ******\n\n";
}
 /*~*~*~*
This function checks the input file for data and reads the data line-by-line into the given variables
To accomplish this we pass by reference into the declared variables. 
*/
bool	getScores(ifstream &inFile, string s_id[], int finalScores[], int size)
{
	
	return (bool)(inFile >> s_id[size] >> finalScores[size]);
}

//****************************************************
// The getTotal function accepts a double array      *
// and its size as arguments. The sum of the array's *
// elements is returned as a double.                 *
//****************************************************

double getTotal(const int array[], int size)
{
   double total = 0; // Accumulator

   // Add each element to total.
   for (int counter = 0; counter < size; counter++)
      total += array[counter];

   // Return the total.
   return total;
}

//****************************************************
// The get_highest function accepts a double array   *
// and its size as arguments. The highest value in   *
// the array is returned as a double.                *
//****************************************************


double	get_highest(const int array[], int size)
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

//****************************************************
// The getLowest function accepts a double array and *
// its size as arguments. The lowest value in the    *
// array is returned as a double.                    *
//****************************************************


double	getLowest(const int array[], int size)
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

 /*~*~*~*
This function prints the required information to the screen. It also checks the input file for all the scores that are equal to the lowest and highest scores and prints them out along with the respective student id's.
*/

void	output_info(const string s_id[], const int finalScores[], int size, double lowestScore, double highestScore, double average){
	int count = 0;
	cout 	<< "The average class score is: "
		<< average << " and the class strength is " << size << ".\n"
		<< "The students with the lowest score are: \n";
	while (count < size)
	{
		if (finalScores[count] == lowestScore)
		{
			cout << s_id[count] << " score : " << lowestScore << endl;
		}
		count++;
	}

	cout	<< "The students with the highest score are: \n";
	count = 0;
	while (count < size)
	{
		if (finalScores[count] == highestScore)
		{
			cout << s_id[count] << " score : " << highestScore << endl;
		}
		count++;
	}
}

 /*~*~*~*
This function writes all the scores that are below average along with the respective student id's 
to the user specified file.
*/

void	write_to_file(ofstream &outFile, const string s_id[] , const int finalScores[], int size, double average)
{
	for (int y = 0; y < size; y++)
	{
		if (finalScores[y] < average)
		{
			 outFile << s_id[y] << " : " << finalScores[y] << endl;
		}
	}
}

//This function prints an exit message to the screen
void	exit_message(void)
{
	cout << "*************************** End of Program *****************************\n"
		<< "~~~~~~~~~~~That's All Folks!!!~~~~~~~~~~~~~~~" << endl;
}

/*************************************************
OUTPUT
*****Welcome******
This program reads the final exam scores and corresponding student id's it then displays the following results: 
• The total number of students in the array 
• The class average 
• The lowest score in the array followed by the ids of the students with that score 
• The highest score in the array followed by the ids of the students with that score.
The program also prompts the user to enter the name of an output file it writes all the scores below the average, and the corresponding id's.
 ****** Let's Begin ******

Please enter the name of the file that contains the student id's and exam scores.
scores.txt
The average class score is: 81.6923 and the class strength is 13.
The students with the lowest score are: 
SW111 score : 45
TY4XZ score : 45
9QWE9 score : 45
The students with the highest score are: 
DR123 score : 100
2ABCD score : 100
AK323 score : 100
Please enter the name of the file you'd like to write the results to.
yes.txt
*************************** End of Program *****************************
~~~~~~~~~~~That's All Folks!!!~~~~~~~~~~~~~~~

***OUTPUT FILE*****
cat yes.txt
SW111 : 45
TY4XZ : 45
AC234 : 78
9QWE9 : 45

*/
