/*
Write the definition of a function minMax that has five parameters. 
The first three parameters are integers. 
The last two are set by the function to the largest and smallest of the values 
of the first three parameters. The function does not return a value.

The function can be used as follows:

	int a=31, b=5, c=19 big, small;
	minMax(a,b,c,&big,&small);
	big is now 31 
	small is now 5 
		*/

void minMax(int a,int b,int c,int &big,int &small)
{
    int max;
    int min;
   /* 
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    min = (a < b) ? a : b;
    min = (min < c) ? min : c;
   */

   if (a > b) 
   {
	   max = a;
	   min = b;
   }
   else
   {
		max = b;
		min = a;
   }
	if (max < c)
		max = c;
	else if (min > c)
		min = c;
	
    big = max;
    small = min;
}
    
    
