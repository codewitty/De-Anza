/*
Lab04
Names : Joseph Saunders and Joshua Gomes
Class : CIS22C61Y
*/
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Calculator.h"

using namespace std;


//******************************************************************************
// int main() - Main declares an array to store the infix expression 
//
// Our calculator class allows us to convert infix expressions from the user
// into prefix and postfix operations
// Main demonstrates this functionality. 
// 
// PSEUDOCODE:
// 
//	  Print Header
//	  Declare string and ask the user for space separated expression. 
//		Demonstrate calculator class functionality by converting
//		infix to post-fix.
//		Output post-fix expression and result.
//					OR
//		Convert infix expression to pre-fix.
//		Print resulting pre-fix expression and the result.
//******************************************************************************

int main()
{
	// 1.  Print Header
	cout << "\n\nLab03B\n"
		<< "Names : Joseph Saunders and Joshua Gomes\n"
		<< "Class : CIS22C61Y"
		<< endl << endl;

	// 2. Declare empty string for user input 
	string exprString("");
	bool loop = true;

	// Loop until done
	while (loop)
	{
		int choice = 0;
		string postFix;	  // Forward declaration of string to store postfix expr
		string preFix;	  // Forward declaration of string to store prefix expr

		// Output User Menu
		cout << endl
			<< "   What operation would you like to carry out?" << endl;
		cout << "   1: Evaluate expression" << endl;
		cout << "   2: EXIT" << endl << endl;
		cout << "   Your Choice: ";

		// User response recorded
		cin >> choice;
		cin.ignore();
		cout << endl << endl;

		// This switch will execute all actions from the menu
		switch (choice)
		{
		case 1: // Process infix to postfix conversion 
			cout << "   Please enter your mathematical expression separated by spaces.\n";
			cout << "   ";
			getline(cin, exprString);
			if (inputValidationOp(exprString) && balancedParentheses(exprString)) {
				postFix = infixToPostfix(exprString);
				cout << endl << "   The postfix string is : "<< postFix << endl;
				cout << endl << "   The result of postfix operation is : " << EvaluatePostfix(postFix) << endl;
				preFix = infixToPrefix(exprString);
				cout << endl << "   The prefix string is : " << preFix << endl;
				cout << endl << "   The result of prefix operation is : " << EvaluatePrefix(preFix) << endl;
			}
			else {
				cout << "****Please enter a valid expression**** \n";
			}
			break;
		case 2: // We are done. Exiting now.
			cout << "   Exiting your Program" << endl << endl;
			loop = false;
			break;
		default: // We re-prompt the user to input a correnct menu option.
			cout << "   Please enter a valid choice between"
				<< "   1-3" << endl;

			break;
		}
	}
	return 0; // Program Finished
}
