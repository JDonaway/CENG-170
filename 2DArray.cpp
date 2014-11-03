#include <iostream>
#include <ctime>
using namespace std;

void Printarray(int nums[][5])
{
	int total;
	for (int r = 0; r < 4; r++)
	{
		total = 0;
		for (int c = 0; c < 5; c++)
		{
			cout << nums[r][c] << " ";
			total += nums[r][c];
		}
		cout << "Ave: " << total / (r + 5);
		cout << endl;
	}
}

int FindAve(const int nums[][5])
{
	int total = 0;
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 5; c++)
			total += nums[r][c];
	}
	return (total/ (4 + 5));
}

void main()
{
	int nums[4][5];
	
	srand(time(NULL));

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 5; c++)
			nums[r][c] = rand() % 101;
	}

	Printarray(nums);
	cout << "Average for the array is " << FindAve(nums) << ".\n";
}