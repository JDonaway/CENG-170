//This program sorts various randomly generated arrays using a few different sorting methods
//by Josh Donaway and Adam Campbell

#include <iostream> 
#include <ctime> // For time function
#include "sort.h" // This file must be in the same directory as the .cpp file
using namespace std;


void RandomizeArray(int nums[], int size) // Place a random number between 1 and 100 in each slot of the array 
{
	for (int i = 0; i < size; i++)
	{
		nums[i] = rand() % 100 + 1;
	}
}

void main()
{
	const int NUM_ITEMS = 5;
	int nums[NUM_ITEMS];

	srand(time(NULL)); // Seed the random number generator

	RandomizeArray(nums, NUM_ITEMS);
	cout << "Unsorted: ";
	ShowNumbers(nums, NUM_ITEMS);

	if (IsSorted(nums, NUM_ITEMS)) // Should be false 
		cout << "Numbers are sorted.\n";
	else
		cout << "Numbers are NOT sorted.\n";
	SelectionSort(nums, NUM_ITEMS);
	cout << "Sorted: ";
	ShowNumbers(nums, NUM_ITEMS);

	if (IsSorted(nums, NUM_ITEMS)) // Should be true
		cout << "Numbers are sorted.\n";
	else
		cout << "Numbers are NOT sorted.\n";	RandomizeArray(nums, NUM_ITEMS);
	cout << "Unsorted: ";
	ShowNumbers(nums, NUM_ITEMS);

	SelectionSortDescending(nums, NUM_ITEMS); // sorts largest to smallest
	cout << "Sorted: ";
	ShowNumbers(nums, NUM_ITEMS);

	BubbleSort(nums, NUM_ITEMS); // sorts through the bubble method
	cout << "Bubble Sorted: ";
	ShowNumbers(nums, NUM_ITEMS);
}