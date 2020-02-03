#pragma once
#include "A.h"
#include "Dollar.h"
// The templated predecessor operator (<)

// 
template<typename T>
bool pred(T& Lhs, T& Rhs) {
	return Lhs < Rhs;
}

bool pred(Dollar& Lhs, Dollar& Rhs) {
	if (Lhs < Rhs)
		return true;
	return false;
}

// Our template for our swap...
template<typename T>
void swapit(T& L, T& R) {
	T tmp = L;
	L = R;
	R = tmp;
}

template<typename T>
void recurSelectionSort(Array<T>& ArrayToSort, int ArraySize, int PartitionIndex = 0) {
	if (PartitionIndex >= ArraySize)
		return; // Should be sorted.
	  // Find min element
	T MinElem = ArrayToSort[PartitionIndex];

	int MinElemIdx = PartitionIndex;
	for (int ndx = PartitionIndex; ndx < ArraySize; ++ndx)
		if (pred(ArrayToSort[ndx], MinElem)) {
			MinElem = ArrayToSort[ndx];
			MinElemIdx = ndx;
		}
	// Found the minimum element. It's in MinElemIdx
	swapit(ArrayToSort[PartitionIndex], ArrayToSort[MinElemIdx]);

	for (int i = 0; i < ArraySize; i++)
	{
		cout << ArrayToSort[i] << " ";
	}
	cout << endl;
	// Now everything until PartitionIndex is sorted. recurse on beyond the PartitionIndex
	recurSelectionSort(ArrayToSort, ArraySize, PartitionIndex + 1);
}

