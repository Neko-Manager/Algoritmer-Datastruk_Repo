#include "QuickSort.h"
#include <math.h>
#include <iostream>

using namespace std;

///Swapping function.
void QuickSort::swap(int* WillBeSwaped, int* CheckForSwap)
{   
	///An integer to temporarely store the value that will be swaped until the checked element has swaped.
	///Example;
	/// Will = 1
	/// Check = 2
	
	int tempPosition = *WillBeSwaped; ///Example:Nothing-->1
	*WillBeSwaped = *CheckForSwap;     ///Example:1-->2
	*CheckForSwap = tempPosition;     ///Example:2-->1
}


///Functyion = divide the elements in values lesser and greater than the pivot point.
int QuickSort::partition(vector<int>& list, int Start, int End)
{
	///Need to find pivot point.
	int pivot = list[End];

	///The current index need to be one less than the index that will be checked next.
	int Currentindex = (Start - 1);

	///Itterates over the list until the last index is reached.
	/// |-------->|
	for (int NextIndex = Start; NextIndex <= End - 1; NextIndex++)
	{
		///Checks if the element in the next index is less than the pivot.
		if (list[NextIndex] < pivot)
		{
			///If the next index fulfuill the criteria, the CurrentIndex moves to the next index and swaps the indexes.
			Currentindex++; 
			swap(&list[Currentindex], &list[NextIndex]);
		}
	}
	///Runs when the last index is the pivot.
	Currentindex++; 
	swap(&list[Currentindex],&list[End]);  

	return Currentindex;
}

///Actually sorting the elements.
void QuickSort::quickSort(vector<int>& list, int Start, int End)
{
	///Safety check if the end value is out of bounds.
	if (End <= Start)
	{
		return;
	}

	///Creating an integer which calculates the pivot.
	int pivot = partition(list, Start, End);

	///Left side or int < pivot - 1.
	quickSort(list, Start, pivot - 1);

	///Right side or int > pivot + 1.
	quickSort(list, pivot + 1, End);

}

void QuickSort::printQsort(vector<int>& vector)
{
	///Printing the elements.
	for(int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << " ";
	}

}
