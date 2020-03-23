/*
Write a function min that has three C string parameters and returns the smallest.
*/

char * min(char * string1,char * string2, char * string3)
{
    char * min;

    if (strcmp(string1, string2) > 0)
        min = string2;
    else
        min = string1;
    if (strcmp(min, string3) > 0)
        return string3;
    else
        return min;
}
