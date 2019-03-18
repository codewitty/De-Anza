/*
Write a function named maxOccuringChar that can find the maximum occurring character in a C-string.
Test the function using 3 test C-strings of lengths 11, 13 and 31
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

char	maxOccuringChar(char []);

int    main() {

char	arr[] = {'a', 'a', 'b', 'c', 'a', 'b', 'a', 'c', 'a', 'b', 'a'};

char n = maxOccuringChar(arr);
cout << "The Max occuring character is: " << n << endl;

return 0;

}

char	maxOccuringChar(char array[]) {

int maxindex = 0;
int length;
//strlen(array) = length;
int i = 0; 
    while (array[i] != '\0') 
    { 
        ++i; 
    } 
length = i;

char max[(length +1)];

for (int i = 0; i <= length; ++i) {
	int count = 1;
	char check = array[i];
	for (int m = i + 1; m <= length; ++m) {
		if (char check = array[m]) {
			count += 1;
		}
	}
	max[i] = count;
}

for (int k = 0; k <= length; ++k) {
	int maxx = 0;
	if ( maxx < max[k]) {
		maxx = max[k];
		maxindex = max[k];
	}
}
return array[maxindex];
} 






	
