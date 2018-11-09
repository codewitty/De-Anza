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
#include <fstream>
#include <string>

using namespace std;

const int DE_BUG = true;

void printInfo(void);
bool getScores(ifstream &inFile, string &, double &, double &, double &, double &, double &);
void calcScore(void);
void findLowest(void);
void findHighest(void);
void writeScore(void);
void printEnd(void);

int main()
{
    // declare the variables needed in main()
	ifstream inFile;
	inFile.open("rectangles.txt");
    	if(!inFile)
    		{
        		cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        		return 1; // or you could use exit(1);
    		}
	ofstream outFile;
	outFile.open("results.txt");
	
	// open the input file + validation
    // open the output file + validation
    
    while (getScores())
    {
        calcScore();
        // determine the winner so far
        writeScore();
    }
    // close the input file
    // close the output file
    
    // display the number of participants
    // display the winner and the winner's score
    
    printEnd();
    return 0;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void printInfo(void)
{
    if (DE_BUG)
        cout << "This is the welcome function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
bool getScores(ifstream &inFile, string &name, double &sc1, double &sc2, double &sc3, double &sc4, double &sc5)
{
    if (DE_BUG)
        cout << "This is the getScores function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void calcScore(void)
{
    if (DE_BUG)
        cout << "This is the calcScore function" << endl;
    findLowest();
    findHighest();
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void findLowest(void)
{
    if (DE_BUG)
        cout << "\tThis is the findLowest function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void findHighest(void)
{
	if (DE_BUG)
		cout << "\tThis is the findHighest function" << endl;
	int i = 0;

	
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void writeScore(void)
{
    if (DE_BUG)
        cout << "This is the writeScore function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void printEnd(void)
{
    if (DE_BUG)
        cout << "This is the END function" << endl;
}
