/*
The integer variables first and last have been declared and assigned values (with last >= first). Allocate an integer array that can hold the squares of the numbers between first and last (inclusively), assign the resulting pointer to the variable squares (which you must declare), and initialize the array to the squares of the numbers from first to last (in that order).
*/

int *squares;
int num = 0;

for (int i = first; i <= last; i++)
    num++;

squares = new int[num];

for (int j = first; j <= last; j++)
    squares[j - first] = j*j;
