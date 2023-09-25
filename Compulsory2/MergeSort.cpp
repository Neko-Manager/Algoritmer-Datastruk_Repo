#include "MergeSort.h"
#include <vector>
#include <iostream>

using namespace std;

///Has the function of merging the sub arrays back to its original array, but sorted.
void MergeSort::merge(vector<int>& RightArray, vector<int>& LeftArray, vector<int>& list)
{
	///Left Index size.
	int LeftSize = list.size() / 2; 
	///Right Index size.
	int RightSize = list.size() - LeftSize;

	///Index default value before iteration per given array.
	int i = 0;
	int LeftArrayIndex = 0;  
	int RightArrayIndex = 0;  

	///Writing the conditions for when to merge.
	///If both arrays are less than their array limit, the following actions wil run.
	while(LeftArrayIndex < LeftSize and RightArrayIndex < RightSize) 
	{
		///Checking if the leftArray contains a smaller value than the right, if yes insert the value to the original list (list[]).
		if (LeftArray[LeftArrayIndex] < RightArray[RightArrayIndex]) 
		{
			list[i] = LeftArray[LeftArrayIndex];     
			i++; 
			LeftArrayIndex++; 
		}

		///Checking if the opposite condition is met, if yes insert the value to the original list (list[]).
		else
		{
			list[i] = RightArray[RightArrayIndex];
			i++; 
			RightArrayIndex++;
		}
	}

    ///If there are no opposite elements to compare to. For example; if there is only one index left not sorted.
	///This applies for both the arrays.
	while(LeftArrayIndex < LeftSize)  
	{
		list[i] = LeftArray[LeftArrayIndex];  
		i++;  
		LeftArrayIndex++; 
	}
	while(RightArrayIndex < RightSize) 
	{
		list[i] = RightArray[RightArrayIndex];   
		i++;    
		RightArrayIndex++;    
	}
}

///
void MergeSort::mergeSort(vector<int>& list)
{
	///Control if the list is smaller or equal to one. Returns the typed value if case. (Nothing to sort)
	int ListLength = list.size(); 

	if (ListLength <= 1)
	{
		return;
	}

	///reating a variable whichs stores half the size of the dynamic array.
	int Middle = ListLength / 2;

	///Creating two new sub arrays which is defined by spliting the original array in half.

	///Left is from 0-->Middle
	vector<int>* LeftArray = new vector<int>[Middle];    
	///Right is from Middle-->End, or the remaining size.
	vector<int>* RightArray = new vector<int>[ListLength-Middle];    

	///LeftArray. Updates after loops are run, not in it.
	int i = 0;

	///RightArray. Updates after loops are run, not in it.
	int j = 0;

	for (; i < ListLength; i++) 
	{
		///If the index in list[i] is less than the middle value, it will be used in the left array.
		if (i < Middle) 
		{ 
			LeftArray->emplace_back(list[i]);   
		}
		///If the index in list[i] is greater than the middle value, it will be used in the right array.
		else 
		{
			RightArray->emplace_back(list[i]);   
			j++; 
		}
	}
	///Calling on funstions for recursion.
	mergeSort(*LeftArray);
	mergeSort(*RightArray); 
	merge(*RightArray, *LeftArray, list);

}

void MergeSort::printMsort(vector<int>& vector)
{ 
	{
		///Printing the elements. 
		for (int i = 0; i < vector.size(); i++)
		{
			cout << vector[i] << " ";
		}
	}
}
