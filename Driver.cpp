/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Driver
*/

//import the classes for mergesort, quicksort, and insertion sort
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

//import libraries for operations
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>

//function prototypes
void runSort (int [], int [], int [], int [], int); 
void fillArrays (int [], int [], int [], int []);

////----Main----////
int main()
{
	//call 4 arrays; one for each array size to be sorted
	int a[100];
	int b[1000];
	int c[5000];
	int d[10000];
	
	//call srand to seed random
	srand(time(0));
	
	//loop bool and input variables
	int menuOne = 0;
	std::string inputOne = "";
	
	//intro menu 
	while (menuOne == 0)
	{
		std::cout << "Welcome to Array Sorting! Please begin by selecting an option!" << std::endl;
		std::cout << "1) Fill arrays" << std::endl;
		std::cout << "2) Exit program" << std::endl;
		std::cout << "Please enter the numeral of your choice." << std::endl;
		std::cin >> inputOne;
		
		if (inputOne == "1")
		{
			//second loop bool and input variables
			std::string inputTwo = "";
			int menuTwo = 0;
			
			//second menu listing sorts
			while (menuTwo == 0)
			{
				
				//fill array function then next loop
				std::cout << "" << std::endl;
				std::cout << "Please choose one of the following sort methods:" << std::endl;
				std::cout << "1) Insertion Sort" << std::endl;
				std::cout << "2) Merge Sort" << std::endl;
				std::cout << "3) Quick Sort" << std::endl;
				std::cout << "4) Exit program" << std::endl;
				std::cin >> inputTwo;
				
				if (inputTwo == "1")
				{
					runSort(a, b, c, d, 1);
					menuTwo = 1;
				}
				else if (inputTwo == "2")
				{
					runSort(a, b, c, d, 2);
					menuTwo = 1;
				}
				else if (inputTwo == "3")
				{
					runSort(a, b, c, d, 3);
					menuTwo = 1;
				}
				else if (inputTwo == "4")
				{
					std::cout << "Exiting program. Goodbye." << std::endl;
					menuTwo = 1;
					menuOne = 1;
				}
				else
				{
					std::cout << "Not sure what you are trying to do. Please enter '1' or '2'." << std::endl;
				}	
			}
		}
		else if (inputOne == "2")
		{
			std::cout << "Exiting program. Goodbye." << std::endl;
			menuOne = 1;
		}
		else
		{
			std::cout << "Not sure what you are trying to do. Please enter '1' or '2'." << std::endl;
		}
	}
	
	return 0;
}
//will have a menu which will start with random number generation
//run the FILL ARRAYS function
//print that random arrays are generated, ask if user would like to print arrays
//move on to menu asking which sort to use.  Go to that specific function which uses sort classes. 
//After one full sort, go back to beginning and redo the arrays.

////----Fill Arrays----//// 
void fillArrays(int a[], int b[], int c[], int d[])
{
	
	//fill first array of 100
	for (i = 0; i < 100; i++)
	{
		//random number 0 through 99
		a[i] = rand() % 100;
	}
	
	//fill second array of 1000
	for (i = 0; i < 1000; i++)
	{
		b[i] = rand() % 100;
	}
	
	//fill third array of 5000
	for (i = 0; i < 5000; i++)
	{
		c[i] = rand() % 100;
	}
	
	//fill fourth array of 10000
	for (i = 0; i < 10000; i++)
	{
		d[i] = rand() % 100;
	}
	
	std::cout << "Arrays are filled!" << std::endl;
	
	return;
}

////----Insertion Sort----////
void runSort (int a[], int b[], int c[], int d[], int choice)
{
	if (choice == 1)
	{
		InsertSort * insSortA = new InsertSort();
		InsertSort * insSortB = new InsertSort();
		InsertSort * insSortC = new InsertSort();
		InsertSort * insSortD = new InsertSort();
		
		insSortA->sortArray(a);
		insSortB->sortArray(b);
		insSortC->sortArray(c);
		insSortD->sortArray(d);
		
		insSortA->printArray(a);
		insSortA->timeAndSteps(100);
		
		insSortB->printArray(b);
		insSortB->timeAndSteps(1000);
		
		insSortC->timeAndSteps(5000);
		insSortD->timeAndSteps(10000);
		
		delete insSortA;
		delete insSortB;
		delete insSortC;
		delete insSortD;
		
	}
	else if (choice == 2)
	{
		MergeSort * merSortA = new MergeSort();
		MergeSort * merSortB = new MergeSort();
		MergeSort * merSortC = new MergeSort();
		MergeSort * merSortD = new MergeSort();
		
		merSortA->mergeSrt(a, 0, 99);
		merSortB->mergeSrt(b, 0, 999);
		merSortC->mergeSrt(c, 0, 4999);
		merSortD->mergeSrt(d, 0, 9999);
		
		merSortA->printArray(a);
		merSortA->timeAndSteps(100);
		
		merSortB->printArray(b);
		merSortB->timeAndSteps(1000);
		
		merSortC->timeAndSteps(5000);
		merSortD->timeAndSteps(10000);
		
		delete merSortA;
		delete merSortB;
		delete merSortC;
		delete merSortD;
	}
	else if (choice == 3)
	{
		QuickSort * quiSortA = new QuickSort();
		QuickSort * quiSortB = new QuickSort();
		QuickSort * quiSortC = new QuickSort();
		QuickSort * quiSortD = new QuickSort();
		
		insSortA->sortArray(a);
		insSortB->sortArray(b);
		insSortC->sortArray(c);
		insSortD->sortArray(d);
		
		insSortA->printArray(a);
		insSortA->timeAndSteps(100);
		
		insSortB->printArray(b);
		insSortB->timeAndSteps(1000);
		
		insSortC->timeAndSteps(5000);
		insSortD->timeAndSteps(10000);
		
		delete insSortA;
		delete insSortB;
		delete insSortC;
		delete insSortD;
	}
	else
	{
		std::cout << "Error in runSort function." << std::endl;
	}
	
	return;
}

	
	
//Will call an insertion sort class, 1 for each array.
//for first two arrays will call the print sorted array class method
//for all arrays will call the count time method 
//for all arrays will call the print steps method
//deletes all 4 objects
