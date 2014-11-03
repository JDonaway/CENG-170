#include <iostream> 
using namespace std;

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int nums[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		// Look for a smaller number 
		int min_pos = i;
		for (int j = i + 1; j < size; j++)
		if (nums[j] < nums[min_pos])
			min_pos = j;

		// Swap smaller number if it isn't this number
		if (min_pos != i)
			Swap(nums[min_pos], nums[i]);
	}
}

void ShowNumbers(const int nums[], int size)
{
	for (int pos = 0; pos < size; pos++)
		cout << nums[pos] << " ";
	cout << endl;
}

bool IsSorted(int num[], int NUM_ITEMS) // tests if the array is sorted from smallest to largest
{
	bool inOrder = true;

	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if ((i != NUM_ITEMS - 1) && num[i] > num[i + 1])
		{
			inOrder = false;
		}
	}

	return inOrder;
}

void SelectionSortDescending(int nums[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		// Look for a larger number 
		int max_pos = i;
		for (int j = i + 1; j < size; j++)
		if (nums[j] > nums[max_pos])
			max_pos = j;

		// Swap larger number if it isn't this number
		if (max_pos != i)
			Swap(nums[max_pos], nums[i]);
	}
}

void BubbleSort(int nums[], int size)
{
	bool swapped = true;
	int temp;

	do {
		swapped = false;

		for (int i = 0; i < size; i++)
		{
			if ((i != size - 1) && nums[i] > nums[i + 1])
			{
				temp = nums[i + 1];
				nums[i + 1] = nums[i];
				nums[i] = temp;
				
				swapped = true;
			}
		}

	} while (swapped);

}