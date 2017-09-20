/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Quick Sort CPP File
*/

//includes
#include "QuickSort.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>

void QuickSort::quickSrt(int numb[], int leftPos, int rightPos)
{
	if (startTime == NULL)
	{
		startTime = clock();
	}
	
	//determine sub-array size for quick vs insertion
	if (leftPos + 10 <= rightPos)
	{
		
		//find middle position
		int midPos = (leftPos + rightPos)/2;
	
		//find median value for 0, n, and n/2
		if (numb[midPos] < numb[leftPos])
		{
			swap(&numb[midPos], &numb[leftPos]);
			stepCount = stepCount + 1;
		}
		if (numb[rightPos] < numb[leftPos])
		{
			swap(&numb[leftPos], &numb[rightPos]);
			stepCount = stepCount + 1;
		}
		if (numb[rightPos] < numb[midPos])
		{
			swap(&numb[midPos], &numb[rightPos]);
			stepCount = stepCount + 1;
		}
	
		swap(&numb[midPos], &numb[rightPos - 1];
		stepCount = stepCount + 1;
		
		int pivot = numb[rightPos - 1];
	
		//index variables, start j from one behind pivot
		//start i from one in front of a[0] since a[0] will be lower than pivot
		int j = rightPos - 2;
		int i = leftPos + 1;
		
		while (i <= j)
		{
			while (numb[i] < pivot)
			{
				i++;
			}
			while (numb[j] > pivot)
			{
				j--;
			}
			
			if (i <= j)
			{
				swap(&numb[i], &numb[j]);
				i++;
				j--;
				stepCount = stepCount + 1;
			}
		}
		
		swap(&numb[i], &numb[pivot];
		stepCount = stepCount + 1;
		
		
		quickSrt(numb, leftPos, i - 1);
		quickSrt(numb, i + 1, rightPos);
		
	}
	else
	{
		//--Insertion Sort--//
		int k;
		int temp;
	
		for (leftPos; leftPos < rightPos; leftPos++)
		{
			k = leftPos;

			stepCount = stepCount + 1;

			while( k >= 1 && numb[k - 1] > numb[k] )
			{
				temp = numb[k];
				numb[k] = numb[k - 1];
				numb[k - 1] = temp;

				k = k - 1;

				stepCount = stepCount + 1;
			}
		}
	}
	
	if (endTime == NULL)
	{
		endTime = clock();
	}
	
	return;
}

void QuickSort::swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

///---Print Array Method---///
void QuickSort::printArray(int numb[])
{
	std::string stringArray;
	
	//get array size to use in print out
	int arraySize = (sizeof(numb)/sizeof(numb[0]));
	
	//loop through array, append "a[i], " to string
	for (auto i : numb)
	{
		stringVal = std::to_string(i);
		stringArray = stringArray + stringVal + ", ";
	}
	
	//remove last space and comma from string
	std::string completeArray = stringArray.substr (0, stringArray.length() - 2);
	
	//print out completed array
	std::cout << "Sorted Array of " + arraySize + " elements: [" + completeArray + "]" <<std::endl;
	
	return;
}

///---Print out time and steps function---///
void QuickSort::timeAndSteps(int elements)
{
	//find difference between start and end clock time
	float diff = ((float)endTime - (float)startTime);
	
	//convert clock time to seconds
	float timeSeconds = diff / CLOCKS_PER_SECOND;
	
	//Print out steps and clock time
	std::cout << "Number of steps for array of " + elements + " elements: " + stepCount << std::endl;
	std::cout << "Computer processing time for Insertion Sort of " + elements + " elements: " + timeSeconds + " seconds" << std::endl;
	
	return;
}
