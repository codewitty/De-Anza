#include <iostream>

using namespace std;

template <typename Type>
Type MinMax(Type tX, Type tY)
{
	return (tX > tY) ? tX : tY;
}

class Cents
{
private:
	int m_nCents;

public:
	Cents(int nCents) { m_nCents = nCents; }
	int GetCents() { return m_nCents; }
	friend bool operator>(Cents &c1, Cents&c2)
		{ return (c1.m_nCents > c2.m_nCents) ? true : false; }
};

int main()
{
	int nValue = MinMax(3,7);
	cout << nValue << endl;

	double dValue = MinMax(6.35,18.345);
	cout << dValue << endl;

	char cValue = MinMax('a','A');
	cout << cValue << endl;

	Cents cNickle(5);
	Cents cDime(10);
	Cents cBigger = MinMax(cNickle, cDime);
	cout << cBigger.GetCents() << endl;

	cout << endl << endl << endl;

	system("pause");
	return 0;
}

