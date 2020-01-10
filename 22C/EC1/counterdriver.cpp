#include "counter.h"
#include <iostream>

using namespace std;

int main()
{
	//Set values for counter and limit var
	Counter myCounter(12, 13);		
	
	// Call increment function
	myCounter.increment();			

	//display values of counter
	cout <<	"Counter = " << myCounter.getValue() << endl;	
	// Call decrement function
	myCounter.decrement();

	// Display values of counter 
	cout <<	"Counter = " << myCounter.getValue() << endl;

	// Display value of nCounter	
	cout << "nCounter = " << myCounter.getNCounters() << endl;

	system("pause");

	return 0;
}
