/*Write a function double average(int arr[] , int n), that returns the average of the even elements of the array. If the array has no even elements, throw an integer-based exception containing the value 0. The number of elements in the array is specified by the parameter n.
*/

double average(int arr[] , int n)
{
    int evn = 0;
    double avg;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            avg += arr[i];
            evn++;
        }
    }
    if(evn == 0)
        throw 0;
    return avg/evn;
}
