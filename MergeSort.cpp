/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Merge Sort CPP File
*/

//includes
#include "InsertSort.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>

void MergeSort::merge(int numb[], int leftPos, int middlePos, int rightPos)
{
	//needs variables for first and second index (split arrays) and index for temp array, and for swap counter
	int firIndex, secIndex, tempIndex;
	int temp[rightPos - leftPos + 1];
	
	firIndex = leftPos;
	secIndex = middlePos + 1;
	tempIndex = 0;
	
	
	//while loop that merges until each index hits the end of their respective sub-arrays
	while (firIndex <= middlePos && secIndex <= rightPos)
	{
		
		//if-else statement comparing the number in numb[firIndex] to numb[secIndex]
		if (numb[firIndex] <= numb[secIndex])
		{
			//if number in first sub-array slot smaller than number in second sub-array slot, add it to temp array, then increment indexes of fir/temp
			temp[tempIndex] = numb[firIndex];
			tempIndex++;
			firIndex++;
		}
		else
		{
			temp[tempIndex] = numb[secIndex];
			tempIndex++;
			secIndex++;
		}
		
		//increment step count
		stepCount = stepCount + 1;
	}
	
	//fill in remaining numbers in either sub-array
	while (firIndex <= middlePos)
	{
		temp[tempIndex] = numb[firIndex];
		tempIndex++;
		firIndex++;
		stepCount = stepCount + 1;
	}
	while (secIndex <= rightPos)
	{
		temp[tempIndex] = numb[secIndex];
		tempIndex++;
		secIndex++;
		stepCount = stepCount + 1;
	}
	
	//put back into numb array from temp array
	for (i = leftPos; i <= rightPos; i++)
	{
		numb[i] = temp[i - leftPos];
		stepCount = stepCount + 1;
	}
	
	return;
 }

 
void MergeSort::mergeSrt(int numb[], int l, int r)
{
	//declare middle position variable
	int m;
	
	if (startTime == NULL)
	{
		startTime = clock();
	}
	
	//recursive call to have this function keep going until left = right (1 element) 
	if (l < r)
	{
		//define the middle
		int m = (l + r)/2;
		
		//Split data recursively
		mergeSrt (numb, l, m);
		stepCount = stepCount + 1;
		
		mergeSrt (numb, m + 1; r);
		stepCount = stepCount + 1;
		
		//once splitting done, merge!
		merge(numb, l, m, r);
	}
	
	if (endTime == NULL)
	{
		endTime = clock();
	}
	
	return;
}


///---Print Sorted Array Function---///
void MergeSort::printArray(int numb[])
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


///---Print Function for time and steps---///
void MergeSort::timeAndSteps(int elements)
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
