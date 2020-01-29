#include <iostream>
#include <string>
#include "ArrayTemplateClass.h"
#include "Dollar.h"
using namespace std;

int main()
{
	Array<int> anArray(12);
	Array<double> adArray(12);
	Array<char> acArray(12);
	Array<Dollar> aDollarArray(12);

	for (int nCount = 0; nCount < 12; nCount++)
	{
		Dollar workDollar;
		workDollar.setWholePart(nCount + 1);
		workDollar.setFractionalPart(nCount + 2);

		anArray[nCount] = nCount;
		adArray[nCount] = nCount + 0.5;
		acArray[nCount] = nCount + 65;
		aDollarArray[nCount] = workDollar;
	}

	for (int nCount = 11; nCount >= 0; nCount--) {
		cout << anArray[nCount] << "\t" << adArray[nCount] << "\t" << acArray[nCount] << endl;
		cout << "Dollar : " << aDollarArray[nCount] << endl;
	}

	system("pause");

	cout << "Hello World!" << endl;
	return 0;
}