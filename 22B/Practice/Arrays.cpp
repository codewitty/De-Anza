/*
Write a function named secondSmallest that can find the second smallest element in an array which is unsorted.
Test the function using 3 test arrays of size 5, 11, 13.
Write a function that can find the k-th smallest element in an array which is unsorted, k <= array size.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int    ft_strlen(int arr[])
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

int    main() {

int    array[5] = {6, 3, 5, 2, 8};

int n = sizeof(array)/sizeof(array[0]);

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

for (int p = 0; p < n; p++) {
	cout << array[p] << " ";
}
return 0;

}
