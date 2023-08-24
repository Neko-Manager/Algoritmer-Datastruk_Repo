#include "Fibbonaci.h"
#include <iostream>
#include "Recursion.h"
#include <string>

int main()
{
	Fibbonaci Test;
	Recursion Test2;

	std::cout << "Type the amount of fibbonaci recursions." << std::endl;
	std::cin >> Test.amount;

	std::cout << " " << std::endl;

	std::cout << "Type the amount of factorial recursions." << std::endl;
    std::cin >> Test2.lim;

	std::cout << " " << std::endl;

	//___________________________________________________________________________

	std::cout << "Amount of  fibbonaci recursion." << std::endl;
	std::cout << Test.Fibb(Test.amount, Test.element1,Test.element2) << std::endl;

	std::cout << " " << std::endl;

	std::cout << "Amount of factorial recursions." << std::endl;
	std::cout << Test2.Rec(Test2.lim) << std::endl;

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

