#362: Data Structures
#Project 1: Sorting
#Sorting Header File

SortArray.exe: Driver.o InsertSort.o MergeSort.o QuickSort.o
	g++ Driver.o InsertSort.o MergeSort.o QuickSort.o -o SortArray.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp
	
InsertSort.o: InsertSort.cpp
	g++ -c InsertSort.cpp

MergeSort.o: MergeSort.cpp
	g++ -c MergeSort.cpp

QuickSort.o: QuickSort.cpp
	g++ -c QuickSort.cpp

clean:
	rm -f *.o
	rm SortArray.exe