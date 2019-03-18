/*
Write a function named maxOccuringChar that can find the maximum occurring character in a C-string.
Test the function using 3 test C-strings of lengths 11, 13 and 31
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int    main() {

int    array[5] = {6, 3, 5, 2, 8};

int n = sizeof(array)/sizeof(array[0]);



for (int p = 0; p < n; p++) {
	cout << array[p] << " ";
}
return 0;

}


void	sort_array(int arr[], int size) {
int i = 0;

if (i < (n - 1)) {
    for (int i = 0; i < n; i++) {

        int mindex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[mindex]) {
                mindex = j;
            }
        }
        int temp = array[i];
        array[i] = mindex;
        mindex = temp;
        i++;
}
}
