/*
You are given a 6x8 (6 rows, 8 columns) array of integers, x, already initialized and three integer variables: max, i and j. Write the necessary code so that max will have the largest value in the array x.
*/

for (int i = 0; i < 6; i++)
{
	for (int j = 0; j < 8; j++)
	{
		if(x[i][j] > max)
        max = x[i][j];
	}
}
