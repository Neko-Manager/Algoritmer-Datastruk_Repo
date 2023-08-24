#include "Recursion.h"
#include <iostream>

int Recursion::Rec(int lim)
{
	//Printing elements according to the amount of recursion requested in the input.
	std::cout << lim << " ";

	//Condition if the current amount is either  gretaer or equal to one
	if (lim <= 1) 
	{
		//Returning value if reruirenment er is met.
		return lim;
	}

	else 
	{
		//The main calculation
		return lim * Rec(lim - 1);
	}

}
