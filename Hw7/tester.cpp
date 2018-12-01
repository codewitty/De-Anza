#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const bool DEBUG = false;

// Function declarations
void printInfo();
bool getData(ifstream &inputFile, string studentIDs[], int examScores[],
             int students);
double calculateAverage(const int examScores[], int students);
int findLowest(const int examScores[], int students);
int findHighest(const int examScores[], int students);
void displayInfo(const string studentIDs[], const int examScores[],
                 const int students, double average, int lowestScore,
                 int highestScore);
void writeScores(ofstream &outputFile, const string studentIDs[],
                 const int examScores[], int students, double average);
void printEnd();

int main()
{
    // Declare the variables
    const int MAX_CLASS_SIZE = 45;
    string studentIDs[MAX_CLASS_SIZE];
    int examScores[MAX_CLASS_SIZE];

    int students = 0;
    double average;
    int lowestScore,
        highestScore;

    ifstream inputFile;
    string inputFileName;

    ofstream outputFile;
    string outputFileName;

    printInfo();

    // Ask the user for the name of an input file
    cout << "Please enter the name of an input file: ";
    getline(cin, inputFileName);

    // Open the input file and perform validation
    inputFile.open(inputFileName);

    if(!inputFile)
    {
        cout << "~*~ Error opening the input file! ~*~\n";
        exit(1);
    }

    while (students < MAX_CLASS_SIZE && getData(inputFile, studentIDs,
                                                examScores, students))
    {
        students++;
    }

    cout << endl;

    // Close the input file
    inputFile.close();

    average = calculateAverage(examScores, students);

    lowestScore = findLowest(examScores, students);
    highestScore = findHighest(examScores, students);

    displayInfo(studentIDs, examScores, students, average,
                lowestScore, highestScore);

    // Ask the user for the name of an output file
    cout << "Please enter the name of an output file: ";
    getline(cin, outputFileName);

    // Open the output file and perform validation
    outputFile.open(outputFileName);

    if(!outputFile)
    {
        cout << "~*~ Error opening the output file! ~*~\n";
        exit(1);
    }

    writeScores(outputFile, studentIDs, examScores, students, average);
    cout << "\n\tThe students with scores below the average have\n"
         << "\tbeen saved to " << outputFileName << ".\n\n";

    // Close the output file
    outputFile.close();

    printEnd();

    return 0;
}

/*~*~*~*
    The printInfo function displays a welcome message and
    information about the program.
 */
void printInfo()
{
    if (DEBUG)
    {
        cout << "We are in the printInfo function" << endl;
    }

    cout << "Welcome to the Exam Statistics Program!\n\n";
    cout << "\tThis program reads a file that contains student IDs\n"
         << "\tand final exam scores. It calculates the total number\n"
         << "\tof students, average score, lowest score, and\n"
         << "\thighest score. It also writes the students\n"
         << "\twho are below the average to another file.\n\n";
}

/*~*~*~*
    The getData function reads the input file for the student ID
    and final exam score of each student. It stores this information
    to the corresponding array.
 */
bool getData(ifstream &inputFile, string studentIDs[], int examScores[],
             int students)
{
    if (DEBUG)
    {
        cout << "We are in the getData function." << endl;
    }

    return inputFile >> studentIDs[students] >> examScores[students];
}

/*~*~*~*
    The calculateAverage function calculates the average score by
    finding the total and dividing it by the number of students.
    It returns the average as a double back to main.
 */
double calculateAverage(const int examScores[], int students)
{
    if (DEBUG)
    {
        cout << "We are in the calculateAverage function." << endl;
    }

    double total = 0.0;

    for (int index = 0; index < students; index++)
    {
        total += examScores[index];
    }

    return total / students;
}

/*~*~*~*
    The findLowest function finds the lowest final exam score
    from the array. It returns it back to main.
 */
int findLowest(const int examScores[], int students)
{
    if (DEBUG)
    {
        cout << "We are in the findLowest function." << endl;
    }

    int lowestScore = examScores[0];

    for (int index = 1; index < students; index++)
    {
        if (examScores[index] < lowestScore)
        {
            lowestScore = examScores[index];
        }
    }

    return lowestScore;
}

/*~*~*~*
    The findHighest function finds the highest final exam score
    from the array. It returns it back to main.
 */
int findHighest(const int examScores[], int students)
{
    if (DEBUG)
    {
        cout << "We are in the findHighest function." << endl;
    }

    int highestScore = examScores[0];

    for (int index = 1; index < students; index++)
    {
        if (examScores[index] > highestScore)
        {
            highestScore = examScores[index];
        }
    }

    return highestScore;
}

/*~*~*~*
    The displayInfo function displays the number of students,
    the average exam score, the lowest score, and the highest score.
    It also displays the student IDs of students who got the lowest
    or highest score.
 */
void displayInfo(const string studentIDs[], const int examScores[],
                 const int students, double average, int lowestScore,
                 int highestScore)
{
    if (DEBUG)
    {
        cout << "We are in the displayInfo function." << endl;
    }

    cout << fixed << showpoint << setprecision(2);

    cout << "There are " << students << " students.\n";
    cout << "The average is " << average << ".\n\n";

    cout << "The lowest score is " << lowestScore << ".\n";
    cout << "The students with the lowest score are:\n";
    for (int index = 0; index < students; index++)
    {
        if (examScores[index] == lowestScore)
        {
            cout << "\t" << studentIDs[index] << endl;
        }
    }
    cout << endl;

    cout << "The highest score is " << highestScore << ".\n";
    cout << "The students with the highest score are:\n";
    for (int index = 0; index < students; index++)
    {
        if (examScores[index] == highestScore)
        {
            cout << "\t" << studentIDs[index] << endl;
        }
    }
    cout << endl;
}

/*~*~*~*
    The writeScores function writes the scores and student IDs
    below the average to an user-defined output file.
 */
void writeScores(ofstream &outputFile, const string studentIDs[],
                 const int examScores[], int students, double average)
{
    if (DEBUG)
    {
        cout << "We are in the writeScores function." << endl;
    }

    for (int index = 0; index < students; index++)
    {
        if (examScores[index] < average)
        {
            outputFile << studentIDs[index] << " "
                       << examScores[index] << endl;
        }
    }
}

/*~*~*~*
    The printEnd function displays an ending message,
    signaling the end of the program.
 */
void printEnd()
{
    if (DEBUG)
    {
        cout << "We are in the printEnd function." << endl;
    }

    cout << "\t       ~~*~~\n"
         << "\t~~*~~ The End ~~*~~\n"
         << "\t       ~~*~~\n";
}

