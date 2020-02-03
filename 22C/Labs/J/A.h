#include "Dollar.h"
#include "Currency.h"
#pragma once
using namespace std;

template <typename T>
class Array
{
private:
	int m_nLength;
	T *m_ptData;

public:
	//**********************************************************************//
	// Array operator [] - our Array subscript operator                     //
	// PRE    : target index array request.                                 //
	// RETURN : Reference of the Array object we are targeting.             //
	//**********************************************************************//

	// The length of the array is always an integer
	// It does not depend on the data type of the array

Array()
{
	m_nLength = 0;
	m_ptData = 0;
}

Array(int nLength)
{
	m_ptData = new T[nLength];
	m_nLength = nLength;
}

~Array()
{
	delete[] m_ptData;
}

void Erase()
{
	delete[] m_ptData;
	// We need to make sure we set m_pnData to 0 here, otherwise it will
	// be left pointing at deallocated memory!
	m_ptData = 0;
	m_nLength = 0;
}

T & operator[](int & nIndex)
{
	if (nIndex >= 0 && nIndex < m_nLength)
		return m_ptData[nIndex];
	return m_ptData[0];
}

int GetLength() { return m_nLength; }
};
