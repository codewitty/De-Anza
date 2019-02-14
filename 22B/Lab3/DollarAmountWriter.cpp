// Program name: Lab1a
//
// Description: This program prints a greeting on the user's screen.
//
// What's on your mind about this lab? This exercise gives me an
// opportunity to get used to various activities needed to write
// a successful C++ program.
//
// Author: John Doe
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
int DollarAmount::getAmount() const{
    return amount;
}

// The accessor function getAmountString
string DollarAmount::getDollarAmountString() const {
    // The string that holds the translated amount
    string result { "" };
    string numbers[20] = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
        "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    string tensString[10] = {
        "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    if (amount > 0 && amount < 10000) {
        //Get the number of thousands
        int thousands = amount / 1000;
        result += numbers[thousands] + " " + "Thousand";
        int remainder = amount % 1000;
        //Get the number of hundreds
        int hundreds = remainder / 100;
        result += " " + numbers[hundreds] + " " + "Hundred";
        remainder = remainder % 100;
        if (remainder < 20) {
            result += " " + numbers[remainder];
        }
        else {
            int tens = remainder / 10;
            result += " " + tensString[tens];
            remainder = remainder % 10;
            result += " " + numbers[remainder];
        }
    }
    else {
        result = "Invalid amount";
    }
    return result;
}



int main() {
    DollarAmount testAmount(312);
    cout << testAmount.getDollarAmountString() << endl;
    DollarAmount TestData[] {
    3012, 3100, 4500
    };
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
