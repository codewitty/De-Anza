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

using namespace std;

int main()
{
	const int MAX = 30;
	const int MIN = 10;
	int rand_num;
	int ctr;
	string name;
	int guess;
	char playerChoice;
	

	do
	{
		cout << "This is a fun guessing game that allows multiple players and also saves their results in a file called players.txt\n"
	   	     << "Please enter your name\n";
		cin >> name;
		
		do
		{
			rand_num = rand() % (MAX - MIN + 1) + MIN;
			for (ctr = 1; ctr <= 5 ; ctr++)
				{
					cout << "Please guess a number between 10 and 30\n";
					cin >> guess;
					if (rand_num == guess)
						cout << "Congratulations " << name << ", you have guessed the correct number in " << ctr << " tries!\n";
					else if (guess < 10 || guess > 30)
						cout << "Please enter a valid choice between 10 and 30\n";
					else
						cout << "Try again\n";
				}
			if (rand_num != guess)
				cout << "Sorry " << name << ", the random number was " << rand_num << "!\n";	
			cout << "Would you like to play again?\nType Y or y for Yes and anything else for no.\n";
			cin >> playerChoice;
		}while (playerChoice == 'Y' || playerChoice == 'y');
   		cout << "Is there another player who would like to play?\nType Y or y for Yes and anything else for no.\n";
		cin >> playerChoice;
	}while (playerChoice == 'Y' || playerChoice == 'y');
    return 0;
}
/**~*~*~*~*~*~*~*~*~*
 OUTPUT
 
 */
