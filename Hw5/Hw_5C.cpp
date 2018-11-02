/**~*~*~*
 PART C - Gas Station
 
 This is a simple guessing game between a computer and a player. First, the computer prompts the player to enter
 his/her name then it generates a random number between 10 and 30. The player has up to five tries to guess the 
 number. After each guess, the program displays messages such as “Congratulations Susan, you’ve guessed the 
 number in 2 tries!”, or “Sorry Susan, the random number was  28!” . Ask the player if s/he wants to play again 
 (Y or y for yes, anything else for no) “Susan, would you like to play again?”.  When the current player decides 
 to stop playing, ask if there is another player, and start all over again. This program also creates an output 
 file named players.txt that contains the players’ names and their game results. Write to the screen a welcome 
 message, explaining what is the purpose of the program, and an end of the program another message that includes 
 the name of the output file.
 
 NAME: JOSHUA N. GOMES 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	const int MAX = 30;
	const int MIN = 10;
	int rand_num;
	int ctr = 1;
	string name;
	int guess;
	unsigned seed = time(0);
	srand(seed);
	bool guessed = false;
	char playerChoice;
	ofstream outputFile;
	outputFile.open("players.txt");
	

	cout << "                 *********************" << endl;
	cout << "               ***   Guessing Game   ***" << endl;
	cout << "                 *********************" << endl;
	cout << endl;
 	cout << "           This is a simple guessing game" << endl;
	cout << "           between a computer and a player." << endl;
	cout << endl;

	do
	{
		int gameNbr = 1;
		cout << "Please enter your name\n";
		getline(cin,name);
		outputFile << endl << name << endl;
		
		do
		{
			rand_num = rand() % (MAX - MIN + 1) + MIN;		
			cout << "Please guess a number between 10 and 30\n";
			
			while (ctr <= 5 && !guessed)
			{
				if (ctr > 1)
					cout << "Try again: \n";
				cin >> guess;
				if ( guess == rand_num)
				{	
					cout << "Congratulations " << name << " You've guessed the number in " << ctr << " tries!\n";
					guessed = true;
				}
				else if (guess < 10)
					cout << guess << " is too small. Out of range. "; 
				else if (guess > 30)
					cout << guess << " is too large. Out of range. ";
				else if (guess > rand_num)
					cout << guess << " is too high. ";
				else
					cout << guess << " is too low. ";
				ctr++;
			}
			if (!guessed)
			{
				cout << "\nSorry, the number was : " << rand_num << endl;
				outputFile << "Game " << gameNbr << " : " << rand_num << " - Not guessed\n";
		
			}
			else
			{
				outputFile << "Game " << gameNbr << " : " << rand_num << " - Guessed in " << ctr - 1 << " tries!\n";
			}
			ctr = 1;
			guessed = false;
			cout << "\nWould you like to play again?(Y/N)\n";
			cin >> playerChoice;
			if (playerChoice == 'y' || playerChoice == 'Y')
				gameNbr += 1;
		}while (playerChoice == 'y' || playerChoice == 'Y');
		cout << "Is there another player who would like to play? (Y/N).\n";
		cin >> playerChoice;
		cin.ignore();
	}while (playerChoice == 'Y' || playerChoice == 'y');
	
	cout << "      Please check the output file \"Players.txt\"\n\n"

    	     << "        **************************************\n"
    	     << "      ***   This is the end of the program   ***" << endl;

return 0;
}


/**~*~*~*~*~*~*~*~*~*

           This is a simple guessing game
           between a computer and a player.
                 *********************
               ***   Guessing Game   ***
                 *********************

Please enter your name
Joshua Gomes
Please guess a number between 10 and 30
12
12 is too low. Try again: 
18
18 is too low. Try again: 
25
25 is too low. Try again: 
29
29 is too high. Try again: 
27
Congratulations Joshua Gomes You've guessed the number in 5 tries!

Would you like to play again?(Y/N)
y
Please guess a number between 10 and 30
15
15 is too low. Try again: 
25
25 is too high. Try again: 
21
21 is too low. Try again: 
23
23 is too high. Try again: 
22
Congratulations Joshua Gomes You've guessed the number in 5 tries!

Would you like to play again?(Y/N)
y
Please guess a number between 10 and 30
22
22 is too low. Try again: 
12
12 is too low. Try again: 
12
12 is too low. Try again: 
12
12 is too low. Try again: 
12
12 is too low. 
Sorry, the number was : 23

Would you like to play again?(Y/N)
n
Is there another player who would like to play? (Y/N).
y
Please enter your name
Kvothe Kingkiller
Please guess a number between 10 and 30
22
22 is too high. Try again: 
12
12 is too low. Try again: 
18
Congratulations Kvothe Kingkiller You've guessed the number in 3 tries!

Would you like to play again?(Y/N)
y
Please guess a number between 10 and 30
22
22 is too high. Try again: 
11
11 is too high. Try again: 
1
1 is too small. Out of range. Try again: 
32
32 is too large. Out of range. Try again: 
33
33 is too large. Out of range. 
Sorry, the number was : 10

Would you like to play again?(Y/N)
y
Please guess a number between 10 and 30
22
22 is too low. Try again: 
22
22 is too low. Try again: 
22
22 is too low. Try again: 
22
22 is too low. Try again: 
22
22 is too low. 
Sorry, the number was : 27

Would you like to play again?(Y/N)
n 
Is there another player who would like to play? (Y/N).
y
Please enter your name
Raja Ram Mohan Roy
Please guess a number between 10 and 30
33
33 is too large. Out of range. Try again: 
12
12 is too high. Try again: 
11
11 is too high. Try again: 
10
Congratulations Raja Ram Mohan Roy You've guessed the number in 4 tries!

Would you like to play again?(Y/N)
y
Please guess a number between 10 and 30
33
33 is too large. Out of range. Try again: 
33
33 is too large. Out of range. Try again: 
22
22 is too low. Try again: 
22
22 is too low. Try again: 
22
22 is too low. 
Sorry, the number was : 28

Would you like to play again?(Y/N)
n 
Is there another player who would like to play? (Y/N).
n
      Please check the output file "Players.txt"

        **************************************
      ***   This is the end of the program   ***
~/Desktop/Hw5$ cat players.txt 

Joshua Gomes
Game 1 : 27 - Guessed in 5 tries!
Game 2 : 22 - Guessed in 5 tries!
Game 3 : 23 - Not guessed

Kvothe Kingkiller
Game 1 : 18 - Guessed in 3 tries!
Game 2 : 10 - Not guessed
Game 3 : 27 - Not guessed

Raja Ram Mohan Roy
Game 1 : 10 - Guessed in 4 tries!
Game 2 : 28 - Not guessed
*/
