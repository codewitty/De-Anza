/*
  Exam Statistics II.
 
NAME: JOSHUA N GOMES 
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
void	sort_ascending(string [], int [], int size);
void	sort_descending(string s[], int array[], int size);
void	output_info(string [], int [], int size, double lowestScore, double highestScore, double average);
void	write_to_file(ofstream &outFile, const string [], const int [], int size);
double	getTotal(const int [], int size);
void	exit_message(void);

int main()
{
	string inputFile;
	string outputFile;
	ifstream inFile;
	ofstream outFile1;
	ofstream outFile2;
	const int SIZE = 45;		// Array maximum size
	int size = 0;			// Array actual size
	string s_id[SIZE];		// Array of student id's
	int	finalScores[SIZE];	// Array of final exam scores
        double	total,			// Total of the scores
		lowestScore,		// Lowest test score
		highestScore,		// Highest exam score
		average;		// Average test score
		
	welcome();
	//Prompt the user to enter name of file
	cout << "Please enter the name of the file that contains the student id's and exam scores.\n";
	cin >> inputFile;

	//open inut file and check validity
	inFile.open(inputFile);
	if(!inFile)
    		{
        		cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        		return(1);
    		}

	// Read the contents of the file into two parallel arrays.
	while (getScores(inFile, s_id, finalScores, size))
      		size++;

	//close the input file
	inFile.close();
	
	//sort the scores in the ascending order
	sort_ascending(s_id, finalScores, size);

	// Open the output file and perform validation
    	outFile1.open("scoresOut1.txt");
	outFile2.open("scoresOut2.txt");


	if(!outFile1)
	{
        	cout << "~*~ Error opening the output file \"scoresOut1.txt\"! ~*~\n";
		return(1);
	}	
	
	if(!outFile2)
	{
        	cout << "~*~ Error opening the output file \"scoresOut2.txt\"! ~*~\n";
		return(1);
	}

	// Write the sorted array contents to the file.
	write_to_file(outFile1, s_id, finalScores, size);

	//sort the scores in the descending order
	sort_descending(s_id, finalScores, size);

	// Write sorted contents to output file
	write_to_file(outFile2, s_id, finalScores, size);

	// Close the files.
	outFile1.close();
	outFile2.close();

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

	//End of Program Message
	exit_message();

	return (0);
}

//This function prints a welcome message to the screen. It also explains what the program does. 
void	welcome(void)
{
	cout	<< "*****Welcome******\nThis program reads the final exam scores and corresponding student id's into 2 parallel arrays.\nIt then does the following: "
		<< "\n• Sort the arrays in ascending order by student ID.\n"
		<< "• Write the sorted arrays to another output file named scoresOut1.txt\n"
		<< "• Sort the arrays in descending order by score.\n"
		<< "• Write the sorted arrays to an output file named scoresOut2.txt\n"
		<< "• The program also displays the following results: \n• The total number of students in the array \n• The class average \n"
		<< "• The lowest score in the array followed by the ids of the students with that score \n"
		<< "• The highest score in the array followed by the ids of the students with that score.\n"
		<< " ****** Let's Begin ******\n\n";
}
 /*~*~*~*
This function checks the input file for data and reads the data line-by-line into the given variables
To accomplish this we pass by reference into the declared variables. 
*/
bool	getScores(ifstream &in, string s[], int scores[], int i)
{
	
	return (bool)(in >> s[i] >> scores[i]);
}

//****************************************************
// The getTotal function accepts a double array      *
// and its size as arguments. The sum of the array's *
// elements is returned as a double.                 *
//****************************************************

double getTotal(const int array[], int i)
{
   double total = 0; // Accumulator

   // Add each element to total.
   for (int counter = 0; counter < i; counter++)
      total += array[counter];

   // Return the total.
   return total;
}

//****************************************************
// The get_highest function accepts a double array   *
// and its size as arguments. The highest value in   *
// the array is returned as a double.                *
//****************************************************


double	get_highest(const int array[], int i)
{
	double high;	// To hold the highest value

	// Get the first array's first element.
	high = array[0];

	// Step through the rest of the array. When a
	// value less than lowest is found, assign it
	// to lowest. When a value more than highest is found assign it to highest.

	for (int count = 1; count < i; count++)
	{
		if (array[count] > high)
			high = array[count];
	}
	// Return the lowest value.
	return high;
}


//****************************************************
// The sort_ascending function accepts a double      *
// array, a string array and its size as arguments   *
// It then sorts the array in ascending order while  *
// matching the initial indexes of the string array  *
// to the corresponding value of the int array.	     *			   
//****************************************************


void	sort_ascending(string s[], int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
        	// look for smallest
        	int minIndex = i;
		int mindex = i;
        	for(int k = i + 1; k < size; k++)
        	{
            		if (array[k] < array[minIndex])
			{
				minIndex = k;
				mindex = k;
			}

		}
        	// swap
        	int hold = array[minIndex];
		string keep = s[mindex];
        	array[minIndex] = array[i];
		s[mindex] = s[i];
        	array[i] = hold;
		s[i] = keep;
    	}
}

//****************************************************
// The sort_descending function accepts a double     *
// array, a string array and its size as arguments   *
// It then sorts the array in descending order while *
// matching the initial indexes of the string array  *
// to the corresponding value of the int array.	     *			   
//****************************************************



void	sort_descending(string s[], int array[], int size)
{
	for (int i = 0; i <= size + 1; i++)
	{
		//find the maximum value
		int minIndex = i;
		int mindex = i;
        	for(int k = i + 1; k < size; k++)
        	{
            		if (array[k] > array[minIndex])
			{
				minIndex = k;
				mindex = k;
			}

		}
        	// swap
        	int hold = array[minIndex];
		string keep = s[mindex];
        	array[minIndex] = array[i];
		s[mindex] = s[i];
        	array[i] = hold;
		s[i] = keep;
    	}
}




//****************************************************
// The getLowest function accepts a double array and *
// its size as arguments. The lowest value in the    *
// array is returned as a double.                    *
//****************************************************


double	getLowest(const int array[], int i)
{
	double lowest;	// To hold the lowest value
	
	// Get the first array's first element.
	lowest = array[0];

	// Step through the rest of the array. When a
	// value less than lowest is found, assign it
	// to lowest.

	for (int count = 1; count < i; count++)
	{
		if (array[count] < lowest)
			lowest = array[count];
	}
	// Return the lowest value.
	return lowest;
}

 /*~*~*~*
This function prints the required information to the screen. It also checks the input file for all the scores that are equal to the lowest and highest scores and prints them out along with the respective student id's, the class strength and the class average.
*/

void	output_info(string s[], int scores[], int i, double low, double high, double avg){
	int count = 0;
	cout 	<< "The highest score achieved is : " << high << endl
		<< "The students who achieved the highest score are: \n"; 
	//find and print the highest scores with corresponding id's
	while (count < i)
	{
		if (scores[count] == high)
		{
			cout << s[count] << " score : " << high << endl;
		}
		count++;
	}	
	
	cout	<< "The lowest score achieved is: " << low << endl
		<< "The students with the lowest score are: \n";
	//find and print the lowest scores with corresponding id's
	count = 0;	
	while (count < i)
	{
		if (scores[count] == low)
		{
			cout << s[count] << " score : " << low << endl;
		}
		count++;
	}

	cout	<< "The class strength is: " << i << ".\nThe class average score is: "
		<< setprecision(2) << fixed << showpoint << avg << ".\n" << endl;
}

 /*~*~*~*
This function writes all the sorted scores to the appropriate file.
*/

void	write_to_file(ofstream &o, const string s[] , const int scores[], int size) 
{
	for (int y = 0; y < size; y++)
	{
		o << s[y] << " : " << scores[y] << endl;	
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
This program reads the final exam scores and corresponding student id's into 2 parallel arrays.
It then does the following: 
• Sort the arrays in ascending order by student ID.
• Write the sorted arrays to another output file named scoresOut1.txt
• Sort the arrays in descending order by score.
• Write the sorted arrays to an output file named scoresOut2.txt
• The program also displays the following results: 
• The total number of students in the array 
• The class average 
• The lowest score in the array followed by the ids of the students with that score 
• The highest score in the array followed by the ids of the students with that score.
 ****** Let's Begin ******

Please enter the name of the file that contains the student id's and exam scores.
scores.txt
The highest score achieved is : 100
The students who achieved the highest score are: 
DR123 score : 100
2ABCD score : 100
AK323 score : 100
The lowest score achieved is: 45
The students with the lowest score are: 
SW111 score : 45
TY4XZ score : 45
9QWE9 score : 45
The class strength is: 13.
The class average score is: 81.69.

*************************** End of Program *****************************
~~~~~~~~~~~That's All Folks!!!~~~~~~~~~~~~~~~
*/
