#include "BubbleSort.h"
#include <iostream>
#include <vector>

using namespace std;

void BubbleSort::swap(int* WillBeSwaped, int* CheckForSwap)
{
	///An integer to temporarely store the value that will be swaped until the checked element has swaped.
	///Example;
	/// Will = 1
	/// Check = 2

	int tempPosition = *WillBeSwaped; ///Example:Nothing-->1
	*WillBeSwaped = *CheckForSwap;     ///Example:1-->2
	*CheckForSwap = tempPosition;     ///Example:2-->1
}

///Function will check if the previous index is lower than to the right.
void BubbleSort::bubbleSort(vector<int>& list)
{
	int listSize = list.size();

	///For loop over array with recursion.
	/// 
	///Itterates over the array. Serves as the right index.
	for (int i = 0; i < listSize - 1; i++)  
	{
		///Itterates over the array. Serves as the left index. 
		for (int j = 0; j < listSize - i - 1; j++)   
		{
			///If the left index is smaler than the right, they will swap.
			if (list[j] > list[j+1])  
			{
				swap(&list[j], &list[j+1]);  
			}
		} 
	}

}

void BubbleSort::printBsort(vector<int>& vector)
{
	{
		///Printing the elements. 
		for (int i = 0; i < vector.size(); i++)
		{
			cout << vector[i] << " ";
		}
	}
}

