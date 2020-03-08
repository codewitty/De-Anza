#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "ArrayTemplateClass.h"
#include "StdioAndFileStreamer.h"
#include "HandyUtils.h"
#include "Person.h"
#include "BSTNode.h"
#include "BNTree.h"

using namespace std;

// Forward Declarations
void displayPersonName(Person & anItem);
void displayPersonBday(Person & anItem);
void displayPerson(Person & anItem);

// our global file handles
ofstream namefh;  // file handle for the name ordered traversals.
ofstream bdayfh;  // file handle for the birthday ordered traversals.

// our global 'log' and standard out file streamers
StdioAndFileStreamer nameOut(namefh, std::cout);
StdioAndFileStreamer bdayOut(bdayfh, std::cout);

//****************************************************************************
// int main() - Main is our menu driven system for BST Tree based Person DB.
//				Our DB has a record type that allows you to sort record types
//				based on a persons name or birthday.
//				
// You can add, delete or find persons. You can also print the DB using tree
// options that display preorder, postorder, inorder and breadthfirst displays
// from the tree structure.
// 
// PSEUDOCODE: 
// 
// While not done
//	  select action from list of menu options for DB manipulation 
//	  executes action from method list 
//	  ask if done
//	  	  exit
//	  else continue
//	  
//***************************************************************************
int main()
{
	const int       MAX_PERSONS = 500;              // Maximum persons in our database
	Array<Person *> aPersonByName(MAX_PERSONS);		// An array of type 'Person' using Array Template
	Array<Person *> aPersonByBday(MAX_PERSONS);		// An array of type 'Person' using Array Template

	//   Print Header
	cout << "\n\nLab05\n"
		<< "Names : Joseph Saunders and Joshua Gomes\n"
		<< "Class : CIS22C61Y"
		<< endl << endl;

	// Working Variables for Menu Processing
	string path;
	string outPath;
	string input;
	string name;
	string bday;
	string nameOutPath;
	string bdayOutPath;
	int choice = 0;
	bool loop = true;
	fstream inFile;
	int number_of_lines = 0;
	int count = 0;
	BNTree<Person> nameTree;
	BNTree<Person> bdayTree;
	int objectCount = 0;

	// Ask user for file paths for input and output files
	cout << "   Please enter the full path of the input file\n" << "   ";
	getline(cin, path);

	cout << "   Please enter the full path where you would like to store the Output Files\n" << "   ";
	getline(cin, outPath);

	// Append required file names to user defined output path
	nameOutPath = outPath + "/namesOutput.txt";
	bdayOutPath = outPath + "/birthdaysOutput.txt";

	// Open output files
	namefh.open(nameOutPath);
	bdayfh.open(bdayOutPath);

	inFile.open(path, ios::in);

	// This if block creates Person objects and seeds them into the array.
	if (inFile) {
		DeleteEmptyLines(path);
		// Check number of lines
		while (getline(inFile, name)) {
			++number_of_lines;
		}
		if (number_of_lines % 2 != 0) {
			cout << "Error!!! Input file invalid!!!" << endl;
			return 0;
		}

		inFile.clear();
		inFile.seekg(0, ios::beg);

		objectCount = number_of_lines / 2;

		while (!inFile.eof() && count < objectCount) {
			// Get the name and birthday...
			getline(inFile, name);
			getline(inFile, bday);
			// Normalize the name and birthday...
			string tname = trim(name);
			string tbday = trim(bday);
			// Add the person to the name and birthday arrays...
			aPersonByName[count] = new Person(tname, tbday, NAME);
			aPersonByBday[count] = new Person(tname, tbday, BDAY);
			// Add to person to name and birthday BST's
			nameTree.add(*aPersonByName[count]);
			bdayTree.add(*aPersonByBday[count]);
			count++;
		}
		inFile.close();
	}
	else {
		cout << "   Error!!!" << endl;
	}


	//**********************************************************************//
	// Main menu Loop.														//
	// pre: Successfully seeded Binary Trees.								//
	// post: Updated Database per User Request.								// 
	//**********************************************************************//
	while (loop)
	{
		// Output User Menu
		cout << endl
			<< "   What operation would you like to carry out?" << endl;
		cout << "   1: Add a Node" << endl;
		cout << "   2: Search for a Node" << endl;
		cout << "   3: Delete a Node" << endl;
		cout << "   4: Print data" << endl;
		cout << "   5: EXIT" << endl << endl;
		cout << "   Your Choice: ";
		// User response recorded
		cin >> choice;
		cin.ignore(32767, '\n');
		cout << endl << endl;

		// This switch will execute all actions from the menu
		switch (choice)
		{
		//************************************************************//
		// case 1 ADDS a node to both existing trees.				  //
		//************************************************************//
		case 1: // Add a Node to both Trees 
		{
			bool flag = true;
			int add_choice;
			string check;
			string new_name;
			string new_bday;
			while (flag) {
				cout << "Enter the name data item for the new node.\n";
				getline(cin, new_name);
				cout << "Enter the birthday data item for the new node. "
					<< "Format is yyy-mm-dd.\n";
				getline(cin, new_bday);
				// Normalize the name and birthday...
				string tname = trim(new_name);
				string tbday = trim(new_bday);
				Person new_person(tname, tbday, NAME);
				Person bday_person(tname, tbday, BDAY);
				objectCount += 1;
				// Add the person to the name and birthday arrays...
				aPersonByName[objectCount] = new Person(tname, tbday, NAME);
				aPersonByBday[objectCount] = new Person(tname, tbday, BDAY);
				nameTree.add(new_person);
				bdayTree.add(bday_person);
				cout << endl << "Would you like to add another data item? \n"
					<< "Enter 1 for \"Yes\" or any other key for \"No\"\n";
				cin >> add_choice;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Exiting to main menu" << endl; 
					flag = false;
				}
				else if (add_choice == 1)
					flag = true;
				else {
					cout << "Exiting to main menu" << endl; 
					flag = false;
				}
			}
			break;
		}
		//************************************************************//
		// case 1 SEARCHES for a user specified node.				  //
		//************************************************************//
		case 2: // Search for a particular Node
		{
			bool sflag = true;
			bool sflag2 = true;
			int s_choice;
			int search_choice;
			string search_name;
			string search_bday;
			while (sflag)
			{
				while (sflag2) {
					cout << "\nWould you like to search for a Name or a Birthday?"
						<< "\nType 1 for Name and 2 for Birthday and 3 to Exit." << endl;
					cin >> search_choice;
					cin.ignore(32767, '\n');
					if (cin.fail()) {
						cin.clear();
						cin.ignore(32767, '\n');
					cout << endl << "!!!!!! Please Enter 1 , 2 or 3 !!!!!!" << endl; 
						sflag2 = true;
					}
					else if (search_choice == 1)
					{
						cout << " Enter the name you would like to look for.\n";
						getline(cin, search_name);
						Person search_person(search_name, "0000-00-00", NAME);
						if (nameTree.contains(search_person))
						{
							cout << "\nData item found" << endl;
							cout << nameTree.find(search_person);
						}
						else
						{
							cout << "\nData item not found" << endl;
						}

					}
					else if (search_choice == 2)
					{
						cout << " Enter the birthday you would like to look for.\n";
						getline(cin, search_bday);
						Person search_person("zzz zzzz", search_bday, BDAY);
						if (bdayTree.contains(search_person))
						{
							cout << "\nData item found" << endl;
							cout << bdayTree.find(search_person);
						}
						else
						{
							cout << "\nData item not found" << endl;
						}
					}
					else if (search_choice == 3)
						sflag2 = false;
					else
					{
						cout << "Please enter 1 or 2.\n" << endl;
						sflag2 = true;
					}
				}
				cout << "Would you like to search for another data item? \n"
					<< "Enter 1 for \"Yes\" or any other key for \"No\"\n";
				cin >> s_choice;
				cin.ignore(32767, '\n');
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Exiting to main menu" << endl; 
					sflag = false;
				}
				else if (s_choice == 1) {
					sflag = true;
					sflag2 = true;
				}
				else {
					cout << "Exiting to main menu" << endl; 
					sflag = false;
			}
		}
			break;
		}
		//************************************************************//
		// case 3 DELETES a node from both existing trees.			  //
		//************************************************************//
		case 3: // Delete a particular Node 
		{
			bool rflag = true;
			bool rflag2 = true;
			char rem_choice;
			int r_choice;
			string r_name;
			string r_bday;
			while (rflag) {
				while (rflag2)
				{
					cout << "Would you like to delete by Name or by Birthday? "
						<< "Type 1 for Name, 2 for Birthday and 3 to exit.\n";
					cin >> r_choice;
					cin.ignore(32767, '\n');
					if (cin.fail()) {
						cin.clear();
						cin.ignore(32767, '\n');
						cout << endl << "!!!!!! Please Enter 1 , 2 or 3 !!!!!!" << endl; 
					}
					else if (r_choice == 1)
					{
						cout << "Enter the name of the data item to be deleted.\n";
						getline(cin, r_name);
						Person new_person(r_name, "", NAME);
						nameTree.remove(new_person);
					}
					else if (r_choice == 2)
					{
						cout << "Enter the birthdate of the data item to be deleted. ";
						cout << "Birthdate must be in yyy-mm-dd format.\n";
						getline(cin, r_bday);
						Person bday_person("", r_bday, BDAY);
						bdayTree.remove(bday_person);
					}
					else if (r_choice == 3)
						rflag2 = false;
					else {
						cout << "Please enter 1, 2 or 3.\n" << endl;
					}
				}
				cout << "Would you like to remove another data item? \n"
					<< "Enter Y for \"Yes\" or any other key for \"No\"\n";
				cin >> rem_choice;
				cin.ignore(32767, '\n');
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Exiting to main menu" << endl; 
					rflag = false;
				}
				if (rem_choice == 'Y' || rem_choice == 'y') {
					rflag = true;
					rflag2 = true;
				}
				else
					rflag = false;
			}
			break;
		}
		//************************************************************//
		// case 4 PRINTS all node from both existing trees.			  //
		// Name Tree is printed in Preorder and Postorder modes.	  //
		// Birthday Tree is printed in Inorder and BreadthFirst mode. //
		//************************************************************//
		case 4:
		{

			nameOut << endl << "...!!!!...DISPLAYING NAME TREE...!!!!..." << endl;
			nameOut << endl << endl << "Nametree in PREORDER" << endl;
			nameOut << string(80,'=') << endl; 
			nameOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			nameOut << string(80,'=') << endl; 
			nameTree.preorderTraverse(displayPersonName);
			nameOut << endl << endl << "Nametree in POSTORDER" << endl;
			nameOut << string(80,'=') << endl; 
			nameOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			nameOut << string(80,'=') << endl; 
			nameTree.postorderTraverse(displayPersonName);
			bdayOut << endl << endl << "...!!!!...DISPLAYING BIRTHDAY TREE...!!!!..." << endl;
			bdayOut << endl << endl << "Birthday Tree in INORDER" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayTree.inorderTraverse(displayPersonBday);
			bdayOut << endl << endl << "Birthday Tree in BREADTHFIRST ORDER" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayTree.breadthfirstTraverse(displayPersonBday);
		}
		break;
		// End Case 4

		//************************************************************//
		// case 6 PRINTS all node from both existing trees and		  //
		//		 exits the menu.									  //
		// Name Tree is printed in Preorder and Postorder modes.	  //
		// Birthday Tree is printed in Inorder and BreadthFirst mode. //
		//************************************************************//
		case 5:
		{
			nameOut << endl << "...!!!!...DISPLAYING NAME TREE...!!!!..." << endl;
			nameOut << endl << endl << "Nametree in PREORDER" << endl;
			nameOut << string(80,'=') << endl; 
			nameOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			nameOut << string(80,'=') << endl; 
			nameTree.preorderTraverse(displayPersonName);
			nameOut << endl << endl << "Nametree in POSTORDER" << endl;
			nameOut << string(80,'=') << endl; 
			nameOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			nameOut << string(80,'=') << endl; 
			nameTree.postorderTraverse(displayPersonName);
			bdayOut << endl << endl << "...!!!!...DISPLAYING BIRTHDAY TREE...!!!!..." << endl;
			bdayOut << endl << endl << "Birthday Tree in INORDER" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayTree.inorderTraverse(displayPersonBday);
			bdayOut << endl << endl << "Birthday Tree in BREADTHFIRST ORDER" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayOut << left << setw(60) << "NAME" << right << setw(20) << "BIRTHDAY" << endl;
			bdayOut << string(80,'=') << endl; 
			bdayTree.breadthfirstTraverse(displayPersonBday);
			cout << endl << endl << "~~~~~~~~~~~~EXITING PROGRAM~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
			loop = false;
			break;
		} // End Case 5
		default:
			cout << "   Please enter a valid choice between"
				<< "   1-5" << endl;
		} // End Switch for Menu
	} // End While loop for Menu

	// size variable is same for both arrays because of parallel arrays.
	int personCount = aPersonByName.GetLength();

	// Clean up allocated memory for Person Objects.
	for (int index = 0; index < personCount; ++index) {
		delete aPersonByName[index];
		delete aPersonByBday[index];
	}
	return 0;
}

void displayPersonName(Person & anItem)
{
	nameOut << anItem << endl;
}

void displayPersonBday(Person & anItem)
{
	bdayOut << anItem << endl;
}

void displayPerson(Person & anItem)
{
	cout << anItem << endl;
}

// EOF Lab05BST_main.cpp
