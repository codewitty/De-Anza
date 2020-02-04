#pragma once

//**********************************************************************//
// Template for Selection Sort utilty function                          //
//**********************************************************************//
#include "ArrayTemplateClass.h"
#include "Dollar.h"

// The templated predecessor operator (>)
// Predecessor for generic items
template<typename T>
bool pred(T& Lhs, T& Rhs) {
	return Lhs > Rhs;
}

//**********************************************************************//
// Swap Template                                                        //
// pre: Left and Right hand operator									//
// post: Swapped values for left and right hand operator			    //
// return: void															//
//**********************************************************************//
template<typename T>
void swapit(T& L, T& R) {
	T tmp = L;
	L = R;
	R = tmp;
}


//**********************************************************************//
// recurSelectionSort Template - This template allows sorting of		//
//	integral types, system library types, and user defined objects.		//
//																		//
// pre: Unordered item list												//
// post: Ordered item list in descending order							//
// return: void															//
//**********************************************************************//
template<typename T>
void recurSelectionSort(Array<T>& ArrayToSort, int ArraySize, int PartitionIndex = 0) {
	ofstream exelog;
	exelog.open("Lab02_Log.txt", ios::app);

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
		cout << "   " << ArrayToSort[i];
		exelog << "   " << ArrayToSort[i];
	}
	cout << endl;
	exelog << endl;
	exelog.close();

	// Now everything until PartitionIndex is sorted. recurse on beyond the PartitionIndex
	recurSelectionSort(ArrayToSort, ArraySize, PartitionIndex + 1);
}

