#include "Fibbonaci.h"
#include <iostream>


int main()
{
	Fibbonaci Test;

	std::cout << "Type the amount of recursions." << std::endl;

	std::cin >> Test.amount;
	std::cout << " " << std::endl;

	std::cout << "Amount of recursion." << std::endl;
	std::cout << Test.Fibb(Test.amount, Test.element1,Test.element2) << std::endl;

}


int Fibbonaci::Fibb(int amount, int element1, int element2)
{

	//Printing elements according to the amount of recursion requested in the input.
	std::cout << element1 << " " ;

	//Condition if the current amount is either  0 or 1.
	if(amount == 0 or amount == 1)
	{
		//If condition is met, the function will return element two.
		return element2;
	}

	//Condition which run if the first condition is not met.
	else
	{
		//The main fibbonaci calculations.
		Fibb(amount - 1, element2, element1 + element2);
	}

}
