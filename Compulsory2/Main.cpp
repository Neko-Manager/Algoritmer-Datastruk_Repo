#include "Main.h"
#include <iostream>
#include <string>
#include "QuickSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include <chrono>

using namespace std; 
using namespace std::chrono;

void Main::SelectInput()
{
	srand(time(NULL));

	char UserInputNumber;
	char UserInputMethod;

	cout << "Choose between a random or manualy inputed number" << endl;
	cout << "r = random" << "," << "m = manualy" << endl;
	cin >> UserInputNumber; 
	cout << " " << endl;

	switch (UserInputNumber)
	{
	case 'r':
	{
		if (UserInputNumber == 'r')
		{
			cout << "Choose a sorting method" << endl;
			cout << "q = quicksort" << "," << "m = merge sort" << "," << "b = bubble sort" << endl;
			cin >> UserInputMethod;
			switch (UserInputMethod)
		{
			case 'q':
			{
				QuickSort sort; 
				vector<int> InsertList; 

				cout << " " << endl << "Choosen quicksort" << " " << endl; 
				cout << "Put amount of random numbers. One number:" << " " << endl; 

				///A while function to insert a manual amount of integers in the list.
				while (true)
				{
					///All whitspaces will be ignored.
					cin >> ws; 

					///Creating an integer which will store a input value which will be itterated over and turned into rnadom numbers.
					int  AmountOfRandomNumbers = cin.peek(); 

					///If the typed variable is an integer, the code will procced to the for loop.
					if (isdigit(AmountOfRandomNumbers)) 
					{
						cin >> AmountOfRandomNumbers; 
						cout << " " << endl << " " << endl;

						///Turns the all elements in the given amount to random numbers.
						for (int i = 0; i < AmountOfRandomNumbers; i++) 
						{
							InsertList.push_back(rand() % 500 + 1); 
						}
						break;
					}

					///If the typed is a letter, then the program wil break.
					else if (isalpha(AmountOfRandomNumbers)) 
					{
						///Screan is cleared if this condition is met.
						cout << "This is not an integer. Restart and try again" << endl << " "; 
						system("pause"); 
						system("cls"); 
					}
				}
				///If the condition is met and the code has been verified and runned, this code will print the original typed list for a comparison.
				cout << "Original typed list" << endl; 

				for (int i = 0; i < InsertList.size(); i++)
				{
					cout << InsertList[i] << " ";
				}

				cout << " " << endl << " " << endl;
				cout << "QuickSorted list" << endl;
				
				auto start = high_resolution_clock::now(); 
				sort.quickSort(InsertList,0, InsertList.size() - 1); 
				auto stop = high_resolution_clock::now();  
				auto duartion = duration_cast<microseconds>(stop - start);
                sort.printQsort(InsertList);  

				cout << " " << endl << " " << endl;  
				cout << "Calculation Time:" << duartion.count() << "Microseconds" << endl;
				break;
			}
			case 'm':
			{	
			MergeSort sort; 
			vector<int> InsertList;

			cout << " " << endl << "Choosen quicksort" << " " << endl;
			cout << "Put amount of random numbers. One number:" << " " << endl; 

			///A while function to insert a manual amount of integers in the list.
			while (true)
			{
				///All whitspaces will be ignored.
				cin >> ws; 

				///Creating an integer which will store a input value which will be itterated over and turned into rnadom numbers.
				int  AmountOfRandomNumbers = cin.peek(); 

				///If the typed variable is an integer, the code will procced to the for loop.
				if (isdigit(AmountOfRandomNumbers)) 
				{
					cin >> AmountOfRandomNumbers; 
					cout << " " << endl << " " << endl; 

					///Turns the all elements in the given amount to random numbers.
					for (int i = 0; i < AmountOfRandomNumbers; i++) 
					{
						InsertList.push_back(rand() % 500 + 1); 
					}
					break;
				}

				///If the typed is a letter, then the program wil break.
				else if (isalpha(AmountOfRandomNumbers)) 
				{
					///Screan is cleared if this condition is met.
					cout << "This is not an integer. Restart and try again" << endl << " ";
					system("pause");
					system("cls");
				}
			}
			///If the condition is met and the code has been verified and runned, this code will print the original typed list for a comparison.
			cout << "Original typed list" << endl;

			for (int i = 0; i < InsertList.size(); i++)
			{
				cout << InsertList[i] << " ";
			}

			cout << " " << endl << " " << endl;
			cout << "MergeSorted list" << endl;

			auto start = high_resolution_clock::now();  
			sort.mergeSort(InsertList); 
			auto stop = high_resolution_clock::now(); 
			auto duartion = duration_cast<microseconds>(stop - start); 
			sort.printMsort(InsertList); 

			cout << " " << endl << " " << endl;
			cout << "Calculation Time:" << duartion.count() << "Microseconds" << endl;
			break;
			}
			case 'b':
			{
				BubbleSort sort; 
				vector<int> InsertList; 

				cout << " " << endl << "Choosen quicksort" << " " << endl; 
				cout << "Put amount of random numbers. One number:" << " " << endl; 

				///A while function to insert a manual amount of integers in the list.
				while (true)
				{
					///All whitspaces will be ignored.
					cin >> ws; 

					///Creating an integer which will store a input value which will be itterated over and turned into rnadom numbers.
					int  AmountOfRandomNumbers = cin.peek(); 

					///If the typed variable is an integer, the code will procced to the for loop.
					if (isdigit(AmountOfRandomNumbers)) 
					{
						cin >> AmountOfRandomNumbers; 
						cout << " " << endl << " " << endl; 

						///Turns the all elements in the given amount to random numbers.
						for (int i = 0; i < AmountOfRandomNumbers; i++) 
						{
							InsertList.push_back(rand() % 500 + 1); 
						}
						break;
					}

					///If the typed is a letter, then the program wil break.
					else if (isalpha(AmountOfRandomNumbers)) 
					{
						///Screan is cleared if this condition is met.
						cout << "This is not an integer. Restart and try again" << endl << " "; 
						system("pause"); 
						system("cls"); 
					}
				}
				///If the condition is met and the code has been verified and runned, this code will print the original typed list for a comparison.
				cout << "Original typed list" << endl;

				for (int i = 0; i < InsertList.size(); i++)
				{
					cout << InsertList[i] << " ";
				}

				cout << " " << endl << " " << endl;
				cout << "BubbleSorted list" << endl;

				auto start = high_resolution_clock::now(); 
				sort.bubbleSort(InsertList); 
				auto stop = high_resolution_clock::now(); 
				auto duartion = duration_cast<microseconds>(stop - start); 
				sort.printBsort(InsertList);
				 
				cout << " " << endl << " " << endl;
				cout << "Calculation Time:" << duartion.count() << "Microseconds" << endl;
				break;
			}
			{
			default:
				cout << " " << endl;
				SelectInput();
				break;
			}
		}
		break;
	}

	case 'm':
	{
		if (UserInputNumber == 'm')
		{
			cout << "Choose a sorting method" << endl;
			cout << "q = quicksort" << "," << "m = merge sort" << "," << "b = bubble sort" << endl;
			cin >> UserInputMethod; 
			switch (UserInputMethod) 
			{
			case 'q':
			{
				QuickSort sort;       
				vector<int> InsertList;     
				 
				cout << " " << endl << "Choosen quicksort" << " " << endl;
				cout << "Put in list elements:" << " " << endl;      
				int InsertedElements;   
				
				///A while function to insert a manual amount of integers in the list.
				while (true)
				{
					///Creating statements for the vector list.

					///All whitspaces will be ignored.
					cin >> ws;

					///Typing in one element at time, which will be pushed back in the list.
					int InsertElement = cin.peek();

					///If the typed variable is an integer, positive or negative, the input will be stored and pushed in the list.
					if (isdigit(InsertElement) or InsertElement == '-')  
					{  
						cin >> InsertedElements;
						InsertList.push_back(InsertedElements);
					}

					///If the typed is a letter, then the program wil break.
					else if (isalpha(InsertElement))
					{
						///Screan is cleared if this condition is met.
						///Screan is cleared if this condition is met. 
						cout << "This is not an integer. Restart and try again" << endl << " "; 
						system("pause"); 
						system("cls");
					}

					else 
					{
						///If the condition is met and the code has been verified and runned, this code will print the original typed list for a comparison.
						cout << "Original typed list" << endl; 

						for (int i = 0; i < InsertList.size(); i++)
						{
							cout << InsertList[i] << " "; 
						}
						break;
					}	    
				}
				cout << " " << endl << " " << endl;
				cout << "BubbleSorted list" << endl;

				auto start = high_resolution_clock::now(); 
				sort.quickSort(InsertList, 0, InsertList.size() - 1); 
				auto stop = high_resolution_clock::now(); 
				auto duartion = duration_cast<microseconds>(stop - start); 
				sort.printQsort(InsertList); 

				cout << " " << endl << " " << endl; 
				cout << "Calculation Time:" << duartion.count() << "Microseconds" << endl; 
		 
				break;
			}
			case 'm':
			{ 
				MergeSort sort;  
				vector<int> InsertList; 

				cout << " " << endl << "Choosen Mergesort" << " " << endl; 
				cout << "Put in list elements:" << " " << endl; 
				int InsertedElements; 

				///A while function to insert a manual amount of integers in the list.
				while (true)
				{
					///Creating statements for the vector list.

					///All whitspaces will be ignored.
					cin >> ws; 

					///Typing in one element at time, which will be pushed back in the list.
					int InsertElement = cin.peek(); 

					///If the typed variable is an integer, positive or negative, the input will be stored and pushed in the list.
					if (isdigit(InsertElement) or InsertElement == '-') 
					{
						cin >> InsertedElements; 
						InsertList.push_back(InsertedElements); 
					}

					///If the typed is a letter, then the program wil break.
					else if (isalpha(InsertElement)) 
					{
						///Screan is cleared if this condition is met.
							///Screan is cleared if this condition is met.
						cout << "This is not an integer. Restart and try again" << endl << " "; 
						system("pause"); 
						system("cls"); 
					} 

					else
					{
						///If the condition is met and the code has been verified and runned, this code will print the original typed list for a comparison.
						cout << "Original typed list" << endl; 

						for (int i = 0; i < InsertList.size(); i++) 
						{
							cout << InsertList[i] << " ";
						}
						break;
					}
				}
				cout << " " << endl << " " << endl;
				cout << "BubbleSorted list" << endl;

				auto start = high_resolution_clock::now(); 
				sort.mergeSort(InsertList); 
				auto stop = high_resolution_clock::now(); 
				auto duartion = duration_cast<microseconds>(stop - start); 
				sort.printMsort(InsertList); 

				cout << " " << endl << " " << endl; 
				cout << "Calculation Time:" << duartion.count() << "Microseconds" << endl; 
				 
				break;
			}
			case 'b':
			{
				BubbleSort sort; 
				vector<int> InsertList;

				cout << " " << endl << "Choosen BubbleSort" << " " << endl;
				cout << "Put in list elements:" << " " << endl;
				int InsertedElements;

				///A while function to insert a manual amount of integers in the list.
				while (true)
				{
					///Creating statements for the vector list.

					///All whitspaces will be ignored.
					cin >> ws; 

					///Typing in one element at time, which will be pushed back in the list.
					int InsertElement = cin.peek(); 

					///If the typed variable is an integer, positive or negative, the input will be stored and pushed in the list.
					if (isdigit(InsertElement) or InsertElement == '-') 
					{
						cin >> InsertedElements; 
						InsertList.push_back(InsertedElements); 
					}

					///If the typed is a letter, then the program wil break.
					else if (isalpha(InsertElement))
					{
						///Screan is cleared if this condition is met.
						///Screan is cleared if this condition is met.
						cout << "This is not an integer. Restart and try again" << endl << " "; 
						system("pause"); 
						system("cls"); 
					}

					else
					{
						///If the condition is met and the code has been verified and runned, this code will print the original typed list for a comparison.
						cout << "Original typed list" << endl;

						for (int i = 0; i < InsertList.size(); i++)
						{
							cout << InsertList[i] << " ";
						}
						break;
					}
				}
				cout << " " << endl << " " << endl;
				cout << "BubbleSorted list" << endl;

				auto start = high_resolution_clock::now();
				sort.bubbleSort(InsertList); 
				auto stop = high_resolution_clock::now(); 
				auto duartion = duration_cast<microseconds>(stop - start);
				sort.printBsort(InsertList); 

				cout << " " << endl << " " << endl;
				cout << "Calculation Time:" << duartion.count() << "Microseconds" << endl;
				break;
			}
			{
			default:
				cout << " " << endl;
				SelectInput();
				break;
			}
			}
			break;
		}
	}
	}

	default:
		SelectInput();
		break;
	}

	
}

int main() 
{
	Main thisMain;
	thisMain.SelectInput();
}