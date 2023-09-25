#pragma once
#include <vector>

using namespace std;
class MergeSort
{
	///Need: A main functio to split up and merge smaller segments of the original array.
	///Need: A function to merge these segments and return the sorted values into the original array. 

	void merge(vector<int>& RightSide, vector<int>& LeftSide, vector<int>& list); 

public:
	void mergeSort(vector<int>& list);  
	void printMsort(vector<int>& vector); 
};

