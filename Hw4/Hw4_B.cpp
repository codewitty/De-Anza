/**~*~*~*
   PART B

 Project: Guess a number within a given range.

 Find and fix the errors.
 Run the program twice and save each output as a comment at the end
 of the source file.

 The program generates a random number within the range 1 to 8 (inclusive)
 and asks the user to guess it in one or two tries.

Name : Joshua N. Gomes

*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MIN = 1;
const int MAX = 8;
int main()
{
	int random_num;
	int num;
	unsigned seed = time(0) ;
	
	srand(seed);
	random_num = rand() % (MAX - MIN + 1) + MIN;
	cout << "Enter a number within the range 1 to 8: ";
	cin >> num; // first try
	if( num == random_num )
	{
		cout << "Congratulations! You did it!\n";
		return(0);	
	}
	
	
		if( num < random_num )
            	cout << "Your guess is low!";
        	else
			cout << "Your guess is high!";
            		cout << " Try again!\n\n";
			cout << "Enter a number within the range 1 to 8: " ;
        		cin >> num; // second try
        		if( num == random_num )
           			cout << "Congratulations! You did it!\n\n";
        		else
   				cout << "Sorry, the number was\n" << random_num << endl;
    
    return(0);
}

/**~*~*~*~*~*~*~*~*~*
Enter a number within the range 1 to 8: 2
Your guess is high! Try again!

Enter a number within the range 1 to 8: 4
Sorry, the number was
1

*/


/**~*~*~*~*~*~*~*~*~*
Enter a number within the range 1 to 8: 2
Your guess is low! Try again!

Enter a number within the range 1 to 8: 5
Sorry, the number was
6

*/

