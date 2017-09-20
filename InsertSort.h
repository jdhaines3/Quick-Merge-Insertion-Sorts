/*
*	David Haines
* 	362: Data Structures
* 	Project 1: Sorting
*	Insertion Sort Header File
*/

//--Header Guard--//
#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <time.h>


//--Insertion Sort Class--//
class InsertSort
{
	private:
	
	//declare class member variables
	clock_t startTime, endTime;
	int stepCount;
	
	
	//needs constructor and Destructor (called in line as blank)
	
	public:
		//--Default Constructor--//
		InsertSort() {};
		
		//--Sort Array--//
		void sortArray(int []);
		
		//--Print Array--//
		void printArray(int []);
		
		//--Print Runtime and Step-Count--//
		void timeAndSteps(int);
		
		//--Destructor--//
		~InsertSort() {};
		
};
//end header guard
#endif