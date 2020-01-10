#include "counter.h"



int counter;
int limit;

int Counter::nCounters = 0;

Counter::Counter(int a, int b)
{
    counter = a;
    limit = b;
    nCounters++;
}

void Counter::increment()
{
    if (counter < limit) {
        counter++;
    }
}

void Counter::decrement()
{
    if(counter > 0){
        counter--;
    }
}

int Counter::getValue()
{
    return counter;
}

int Counter::getNCounters()
{
    return nCounters;
}
