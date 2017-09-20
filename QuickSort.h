/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Quick Sort Header File
*/

//--Header Guard--//
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <time.h>


//--Merge Sort Class--//
class QuickSort
{
	private:
	
	//declare class member variables
	clock_t startTime, endTime;
	int stepCount;
	
	
	//needs constructor and Destructor (called in line as blank)
	
	public:
		//--Default Constructor--//
		QuickSort() {};
		
		//--Swap Function--//
		void swap (int* i, int* j);
		
		//--Quick Sort--//
		int quickSrt(int [], int, int);
		
		//--Print Array--//
		void printArray(int []);
		
		//--Print Runtime and Step-Count--//
		void timeAndSteps(int);
		
		//--Destructor--//
		~QuickSort() {};
		
};
//end header guard
#endif