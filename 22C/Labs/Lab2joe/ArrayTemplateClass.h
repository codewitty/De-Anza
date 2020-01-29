#pragma once
using namespace std;

template <typename T>
class Array
{
private:
	int m_nLength;
	T *m_ptData;

public:
	Array();

	Array(int nLength);

	~Array();

	void Erase();

	//**********************************************************************//
	// Array operator [] - our Array subscript operator                     //
	// PRE    : target index array request.                                 //
	// RETURN : Reference of the Array object we are targeting.             //
	//**********************************************************************//
	T& operator[](int &nIndex);

	// The length of the array is always an integer
	// It does not depend on the data type of the array
	int GetLength(); // templated GetLength() function defined below
};

template<typename T>
inline Array<T>::Array()
{
	m_nLength = 0;
	m_ptData = 0;
}

template<typename T>
inline Array<T>::Array(int nLength)
{
	m_ptData = new T[nLength];
	m_nLength = nLength;
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] m_ptData;
}

template<typename T>
inline void Array<T>::Erase()
{
	delete[] m_ptData;
	// We need to make sure we set m_pnData to 0 here, otherwise it will
	// be left pointing at deallocated memory!
	m_ptData = 0;
	m_nLength = 0;
}

template<typename T>
inline T & Array<T>::operator[](int & nIndex)
{
	if (nIndex >= 0 && nIndex < m_nLength)
		return m_ptData[nIndex];
}

template <typename T>
int Array<T>::GetLength() { return m_nLength; }
