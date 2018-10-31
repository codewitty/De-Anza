/**~*
   PART A
 
   This program displays a menu and asks the user to make a
   selection. A do-while loop repeats the program until the
   user selects item 4 from the menu.

   JOSHUA N. GOMES
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Variables
    int choice;       // Menu choice

    do
    {
        // Display the menu.
        cout << "\n\t\tC++ Loops Menu: Print the powers of 2 using a\n\n"
             << "1. for loop\n"
             << "2. while loop\n"
             << "3. do - while loop\n"
             << "4. Quit the Program\n\n"
             << "Enter your choice: " << endl;
        cin  >> choice;
        
        // Validate the menu selection.
        while (choice < 1 && choice > 4)
        	{
            		cout << "Please enter a valid menu choice: ";
            		cin >> choice;
        	}
        
        // Process the user's choice.
        int i, power, n = 6; // variables needed for loops
        
        switch (choice)
	{
            case 1:
                cout << "Your choice is the \"for loop\":\n\n";
		for(i = 0, power = 1; i < n; i++)
			{
				cout << "2 to " << i << " is " << power << endl;
                    		power *= 2;
                	}
		break;
                
            case 2:
                cout << "Your choice is the \"while loop\": \n\n";
                i = 0;
                power = 1;
                while (i < n)
		{
			cout << "2 to " << i << " is " << power << endl;
			power *= 2;
                    	i++;
		}
		break;
            case 3:
                cout << "Your choice is the \"do-while loop\": \n\n";
                i = 0;
                power = 1;
                do
                {
                    cout << "2 to " << i << " is " << power << endl;
                    power *= 2;
                    i++;
                } while (i <= n);
                break;
            case 4:
                cout << "Good bye!\n\n";
                break;
        } // end switch
        
    } while (choice != 4);

    return 0;
}

/**~*~*~*~*~*~*~*~*~*
 OUTPUT

*/
