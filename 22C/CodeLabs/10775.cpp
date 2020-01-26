Write a recursive, int-valued function named productOfOdds that accepts an integer array, and the number of elements in the array and returns the product of the odd-valued elements of the array. You may assume the array has at least one odd-valued element. The product of the odd-valued elements of an integer-valued array recursively may be calculated as follows:

If the array has a single element and it is odd, return the value of that element; otherwise return 1.
Otherwise, if the first element of the array is odd, return the product of that element and the result of finding the product of the odd elements of the rest of the array; if the first element is NOT odd, simply return the result of finding the product of the odd elements of the rest of the array


int productOfOdds(int arr[], int n)
{
    int product = 1;
    if (n == 1)
    {
        if (arr[0] % 2 != 0)
            return (arr[0]);
        else
            return 1;
    }
    else
    {
        product = productOfOdds(arr, n-1);
        if(arr[n-1] % 2 != 0)
        {
            product = product * arr[n-1];
        }
    }
        return product;
}
