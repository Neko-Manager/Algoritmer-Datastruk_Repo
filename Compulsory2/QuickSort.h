#pragma once
#include <vector>

using namespace std;
class QuickSort
{
	///Need: Swap function --> to swap the position of the pivot points.
	///Need: Partition function --> to calculate and swapping the pivot points.
	///Need: quicksort function --> to do all at once.
	///Need: printing function.

	void swap(int* WillBeSwaped, int* CheckForSwap); ///Sorts, but does not calculate anything.
	int partition(vector<int>& list, int Start, int End); ///Calculates and sort the pivot position with partition. Example 3,7,1,4,2-->1,7,3,4,2-->1,2,3,4,7
	
public:
	void quickSort(vector<int>& list, int Start, int End); ///Main function which both sorts and swaps the elements to its corrcet places.
	void printQsort(vector<int>& vector);
};

