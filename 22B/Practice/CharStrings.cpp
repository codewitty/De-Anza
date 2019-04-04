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

char	arr[] = {'a','o','v', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 
			'z', 'z', 'a', 'g', 'c', 'a', 'b', 'a', 'c', 'a', 'b', 'a', 'z', 'z'};
char	arr1[] = {'a', 'b', 'c', 'c', 'g'};

char m = maxOccuringChar(arr);
char n = maxOccuringChar(arr1);
cout << "The Max occuring character is: " << n << endl;
cout << "The Max occuring character is: " << m << endl;

return 0;

}

char	maxOccuringChar(char array[]) {

int maxindex = 0;
int length;

int i = 0; 
    while (array[i] != '\0') 
    { 
        ++i; 
    } 
cout << "The length of the string is: " << i << endl;
length = i;

char max[(length +1)];

for (int i = 0; i < length; ++i) {
	int count = 1;
	char check = array[i];
	for (int m = i + 1; m <= length; ++m) {
		if (char check = array[m]) {
			count += 1;
		}
	}
	max[i] = count;
}

for (int k = 0; k < length; ++k) {
	int maxx = 0;
	if ( maxx < max[k]) {
		maxx = max[k];
		maxindex = max[k];
	}
}
return array[maxindex];
} 






	
