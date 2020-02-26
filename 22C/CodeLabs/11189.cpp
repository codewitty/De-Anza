bool isSorted(int someArray[], int n, bool flag) {
    bool result = false;
    if (flag == true) {
        // Array has one or no element
        if (n == 0 || n == 1)
            result = true;
        else
        {
            for (int i = 1; i < n; i++)
            {
                // Unsorted pair found 
                if (someArray[i - 1] > someArray[i])
                {
                    result = false;
                    break;
                }
      
            // No unsorted pair found 
                else
                    result = true;
            }
        }
    }
    else
    {
        // Array has one or no element
        if (n == 0 || n == 1)
            result = true;
        else
        {
            for (int i = 1; i < n; i++)
            {
                // Unsorted pair found 
                if (someArray[i - 1] < someArray[i])
                {
                    result = false;
                    break;
                }
      
            // No unsorted pair found 
                else
                    result = true;
            }
        }
    }
    return result;
}
