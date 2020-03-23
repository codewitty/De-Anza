double a = 1;
double b = x;

while ( a-b < 0.00001) {
	int mid = (a-b) / 2;
	mid *= mid;
	if ( mid < x)
		a = mid;
	else
		b = mid;
}
root = (a - b) / 2;
