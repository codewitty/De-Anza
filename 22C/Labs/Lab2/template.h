template <typename T>
class Array
{
protected:
	int m_nLength;
	T *m_ptData;

public:
	Array();
	Array(int nLength);
	~Array();

	void Erase();
	T& operator[](int nIndex);

	// The length of the array is always an integer
	// It does not depend on the data type of the array
	int GetLength(); // templated GetLength() function defined below
};

template <typename T>
Array<T>::Array()
{
	m_nLength = 0;
	m_ptData = 0;
}

template <typename T>
Array<T>::Array(int nLength)
{
	m_ptData = new T[nLength];
	m_nLength = nLength;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_ptData;
}

template <typename T>
void Array<T>::Erase()
{
	delete[] m_ptData;
	// We need to make sure we set m_pnData to 0 here, otherwise it will
	// be left pointing at deallocated memory!
	m_ptData = 0;
	m_nLength = 0;
}


template <typename T>
T& Array<T>::operator[](int nIndex)
{
	if (nIndex >= 0 && nIndex < m_nLength)
	return m_ptData[nIndex];
}

template <typename T>
int Array<T>::GetLength() { return m_nLength; }

