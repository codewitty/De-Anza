#include "counter.h"



int counter;
int limit;

int Counter::nCounters = 0;		//initialize nCounters to 0


/* Set values for the constructor */
Counter::Counter(int a, int b)
{
    counter = a;
    limit = b;
    nCounters++;
}


// Increment function definition
void Counter::increment()
{
    if (counter < limit) {
        counter++;
    }
}


// Decrement function definition
void Counter::decrement()
{
    if(counter > 0){
        counter--;
    }
}


// getValue function definition
int Counter::getValue()
{
    return counter;
}


// getNCounters function definition
int Counter::getNCounters()
{
    return nCounters;
}
//end of class definition file
