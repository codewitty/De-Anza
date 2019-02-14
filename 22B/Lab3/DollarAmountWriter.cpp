// Program name: Lab1a
//
// Description: This program prints a greeting on the user's screen.
//
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: Joshua Gomes
//
// Date: mm/dd/yyyy
//
// IDE Used: Xcode
//

// Note: DO NOT remove these include statements.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class DollarAmount {
private:
    // The dollar amount held in this object
    int amount;
public:
    // The constructor to create an instance of the object
    DollarAmount(int);
    // Return the amount in English
    string getDollarAmountString() const;
    // Return the amount held in the object
    int getAmount() const;

};

// Constructor defiinition
DollarAmount::DollarAmount(int amt) {
    amount = amt;
}

// The accessor function getAmount
int DollarAmount::getAmount() const}{
    return amount;
}

// The accessor function getAmountString
string DollarAmount::getDollarAmountString() const {


}

// Remove the following line if the definition foo is removed.
int foo (int *ptr, int size);

int main() {
    cout << "Hello, C++!" << endl;
    return 0;
}

// Remove the function template below for the labs not requiring functions.
//************************************************************************
//* Function name: foo
//*
//* This function . . .
//*
//* Parameters:
//*    ptr - describe the purpose of this parameter
//*    size - describe the purpose of this parameter
//*
//* Returns:
//*
//*    Describe the return value
//*
//************************************************************************

/*
 Copy output of this program below this line.
 --------------------------------------------

 */
