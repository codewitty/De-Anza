#include "counter.h"
#include <iostream>

using namespace std;

int main()
{
	Counter myCounter(12, 13);
	myCounter.increment();
	myCounter.increment();
	myCounter.decrement();
	myCounter.increment();
	

	cout <<	myCounter.getValue() << endl;
	cout << myCounter.getNCounters() << endl;

	return 0;
}
