/**~*~*~*~*~*
 Project 6C: Performers
 
 A particular talent competition has five judges, each of whom awards a score between
 0 and 10 to each performer. Fractional scores, such as 8.3, are allowed.
 A performer's final score is determined by dropping the highest and the lowest score
 received, then averaging the three remaining scores. Write a program that calculates
 the score of each performer and determines the winner.
 Assume there's only one winner!
 
 Input: Read data from an input file named performers.txt.
 Output: Write the number of participants, the name of the winner and winner’s score to
 the screen. Write to a file named results.txt the names of the performers and their
 final score.
 
 NAME:
 
 *~**/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int DE_BUG = false;

void	printInfo(void);
bool	getScores(ifstream &inFile, string &name, double &, double &, double &, double &, double &);
double	calcScore(double sc1, double sc2, double sc3, double sc4, double sc5);
double	findLowest(double, double, double, double, double);
double	findHighest(double, double, double, double, double);
void	writeScore(ofstream &, string name, double finalScore);
void	printEnd(void);

int main()
{
	string name, winnerName;
	double sc1, sc2, sc3, sc4, sc5;
	int counter = 0;
	double winnerScore = 0;
	double finalScore;
	ifstream inFile;
	ofstream outFile;

	inFile.open("Performers.txt");
    	if(!inFile)
    		{
        		cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        		return 1; // or you could use exit(1);
    		}
	
	outFile.open("results.txt");
	if(!outFile)
    		{
        		cout << "\a\a~*~ ERROR opening the output file! ~*~\n";
        		return 1; // or you could use exit(1);
    		}

    
	while (getScores(inFile, name, sc1, sc2, sc3, sc4, sc5))
    	{
		finalScore = calcScore(sc1, sc2, sc3, sc4, sc5);
		if (winnerScore < finalScore)
		{
			winnerScore = finalScore;
			winnerName = name;
		} 
		writeScore(outFile, name, finalScore);
		counter++;
	}
	inFile.close();
	outFile.close();
	
	cout 	<< "\nWe had " << counter << " players today!\n"
		<< "The winner is " << winnerName << " with a score of " << showpoint << fixed << setprecision(2) 
		<< winnerScore << "!\n\n";

    printEnd();
    return (0);
}

/*~*~*~*
This function prints a welcome message to the screen and explains what the program does. 
 */
void	printInfo(void)
{
	cout	<< "Welcome to the De Anza Talent Competition!\n" << "This program takes the judges' scores for each participant,"
		<< " calculates their final score, and outputs the"
		<< " winner of the competition.\n\n";
}

/*~*~*~*
This function checks the input file for data and reads the data line-by-line into the given variables
To accomplish this we pass by reference into the declared variables. 
 */

bool	getScores(ifstream &inFile, string &name, double &sc1, double &sc2, double &sc3, double &sc4, double &sc5)
{
	return inFile >> name >> sc1 >> sc2 >> sc3 >> sc4 >> sc5;
}


/*~*~*~*
This function calculates the final score of each participant by discarding the highest and lowest values
and getting the average of the remaining three.  
 */
double	calcScore(double sc1, double sc2, double sc3, double sc4, double sc5)
{
	if (DE_BUG)
        	cout << "This is the calcScore function" << endl;
	double low = findLowest(sc1, sc2, sc3, sc4, sc5);
	double high = findHighest(sc1, sc2, sc3, sc4, sc5);
	return (sc1 + sc2 + sc3 + sc4 + sc5 - (low + high))/ 3;
}

/*~*~*~*
This function compares all 5 scores of each participant to find the lowest score. 
 */
double	findLowest(double sc1, double sc2, double sc3, double sc4, double sc5)
{
	double  min = sc1;
	if (min > sc2)
		min = sc2;
	if (min > sc3)
		min = sc3;
	if (min > sc4)
		min = sc4;
	if (min > sc5)
		min = sc5;
	return (min);
}

/*~*~*~*
This function compares all 5 scores of each participant to find the highest score. 
 
 */
double	findHighest(double sc1, double sc2, double sc3, double sc4, double sc5)
{
	double max = sc1;
	if (max < sc2)
		max = sc2;
	if (max < sc3)
		max = sc3;
	if (max < sc4)
		max = sc4;
	if (max < sc5)
		max = sc5;
	return (max);
	
}

/*~*~*~*
This function writes the final score for each performer to the output file 
We need this function in order to write to the file "results.txt"
 */
void	writeScore(ofstream &outFile, string name, double finalScore)

{
	if (DE_BUG)
		cout << "This is the writeScore function" << endl;
	outFile << "Performer Name: " << name << "\tFinal Score: " << showpoint << fixed << setprecision(2) <<  finalScore << endl;

}

/*~*~*~*
This function writes an exit message telling the user to check 
the file "results.txt" for the results of the contest 
 */
void	printEnd(void)
{
	cout << "Congratulations to all the performers! \n"
		<< "Check the file named results.txt for the results of the competition\n"
		<< "*******The End*******\n\n";
}

/************************************************************************************************************************************
OUTPUT

We had 8 players today!
The winner is Sue with a score of 9.13!

Congratulations to all the performers! 
Check the file named results.txt for the results of the competition
*******The End*******


*************************************************************************************************************************************/
