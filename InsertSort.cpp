/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Insertion Sort CPP File
*/

//includes
#include "InsertSort.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>

///---Insertion Sort---///
void InsertSort::sortArray(int numb[])
{
	//needs variables for index, swap counter, and temp variable
	int index = 1;
	int j;
	int temp;
	//get array size
	int arraySize = (sizeof(numb)/sizeof(numb[0]));
	
	startTime = clock();
	
	//index starts at one because first element is already "sorted"; j is set to index whenever index incremented
	for (index; index < arraySize; index++)
	{
		j = index;
		//increment step count variable
		stepCount = stepCount + 1;
		
		/*
		*j will check to see if element at current index bigger than last, if it is, swap and decrement j
		*it will continue checking the previous element swapping until j gets to 1 OR the previous element
		*is greater than the one at index j 
		*/
		while( j >= 1 && numb[j - 1] > numb[j] )
		{
			//perform swap
			temp = numb[j];
			numb[j] = numb[j - 1];
			numb[j - 1] = temp;
			
			//decrement j to check if previous number in sorted sub-array is less
			j = j - 1;
			
			//increment step Count
			stepCount = stepCount + 1;
		}
	}
	
	endTime = clock();
	
	return;
 }

 ///---Print Sorted Array function---///
void InsertSort::printArray(int numb[])
{
	std::string stringArray;
	
	int size = (sizeof(numb)/sizeof(numb[0]));
	int i;
	
	std::cout << "Sorted array: [" << std::flush;
	
	for (i = 0; i < size; i++)
	{
		std::cout << numb[i] << std::flush;
		if (i != size - 1)
		{
			std::cout << ", " << std::flush;
		}
		else
		{
			std::cout << "]\n" << std::endl;
		}
	}
	
	return;
}

///---Print function for time and steps---///
void InsertSort::timeAndSteps(int elements)
{
	//find difference between start and end clock time
	float diff = ((float)endTime - (float)startTime);
	
	//convert clock time to seconds
	float timeSeconds = diff / CLOCKS_PER_SEC;
	
	std::stringstream ss;
	
	ss << timeSeconds;
	std::string timSec = ss.str();
	
	ss.clear();
	ss.str("");
	
	ss << elements;
	std::string elem = ss.str();
	
	ss.clear();
	ss.str("");
	
	ss << stepCount;
	std::string steps = ss.str();
	
	
	//Print out steps and clock time
	std::cout << "Number of steps for array of " + elem + " elements: " + steps << std::endl;
	std::cout << "Computer processing time for Insertion Sort of " + elem + " elements: " + timSec + " seconds" << std::endl;
	
	return;
}


		
		
		
		
		
		
		
		
		