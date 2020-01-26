


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
