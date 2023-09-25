#pragma once
#include <iostream>
#include <vector>

using namespace std;

class BubbleSort
{
	///Need: A swap function.
	///Need: A main bubblesort function.
	void swap(int* WillBeSwaped, int* CheckForSwap); ///Sorts, but does not calculate anything.

public:
	void bubbleSort(vector<int>& list); 
	void printBsort(vector<int>& vector); 
};

