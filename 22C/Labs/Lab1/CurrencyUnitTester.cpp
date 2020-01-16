#include <iostream>
#include "Currency.h"
#include "Dollar.h"
using namespace std;

int main()
{
	int whole, fractional;  // To hold input for feet and inches

	// Create three Currency opjects all initialized with defaults.
	Currency first, second, third;

	// Get dollars and cents from the user.
	cout << "Enter your dollars and cents: ";
	cin >> whole >> fractional;

	// Store some dollars and cents.
	first.setWholePart(whole);
	first.setFractionalPart(fractional);

	// Get another dollars and cents from the user.
	cout << "Enter another dollars and cents: ";
	cin >> whole >> fractional;

	// Store the distance in second.
	second.setWholePart(whole);
	second.setFractionalPart(fractional);

	// Assign first + second to third.
	third = first + second;

	// Display the result.
	cout << "first + second = ";
	cout << third.getWholePart() << " dollars, ";
	cout << third.getFractionalPart() << " cents.\n";

	// Assign first - second to third.
	third = first - second;

	// Display the result.
	cout << "first + second = ";
	cout << third.getWholePart() << " dollars, ";
	cout << third.getFractionalPart() << " cents.\n";

	// Compare the two objects.
	if (first == second)
		cout << "first is equal to second.\n";
	if (first > second)
		cout << "first is greater than second.\n";
	if (first < second)
		cout << "first is less than second.\n";

	// ----- Dollar class stuff -----
	Dollar firstDollar, secondDollar;  // Define two objects.

	// use overloaded in stream to initialize the first dollar
	cin >> firstDollar;

	// use overloaded in stream to initialize thesecond dollar
	cin >> secondDollar;

	// Display the values in the objects.
	cout << "The values you entered are:\n";
	cout << firstDollar << " and " << secondDollar << endl;

	return 0;
}