/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Merge Sort Header File
*/

//--Header Guard--//
#ifndef MERGESORT_H
#define MERGESORT_H

#include <time.h>


//--Merge Sort Class--//
class MergeSort
{
	private:
	
	//declare class member variables
	clock_t startTime, endTime;
	int stepCount;
	
	
	//needs constructor and Destructor (called in line as blank)
	
	public:
		//--Default Constructor--//
		MergeSort() {};
		
		//--Sort Array--//
		void mergeSrt(int [], int left, int right);
		
		//--Merge Function--//
		void merge(int [], int leftPos, int middlePos, int rightPos);
		
		//--Print Array--//
		void printArray(int []);
		
		//--Print Runtime and Step-Count--//
		void timeAndSteps(int);
		
		//--Destructor--//
		~MergeSort() {};
		
};
//end header guard
#endif