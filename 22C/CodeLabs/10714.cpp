/*

Write a function max that has two C string parameters and returns the larger of the two.
*/

char * max(char * string1,char * string2)
{
    if (strcmp(string1, string2) > 0)
        return string1;
    else
        return string2;
}
