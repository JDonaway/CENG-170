#include <iostream>
#include <ctime>
using namespace std;

// Array parameters do NOT have a size (nothing in [])
double Average(int num[], int array_size)
{
	int total = 0;
	for (int i = 0; i < array_size; i++)
		total += num[i];
	return double(total) / array_size;
}

int Largest(int num[], int array_size)
{
	int Largest = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (num[i] > Largest || i == 0)
			Largest = num[i];
	}
	return Largest;
}

int Smallest(int num[], int array_size)
{
	int Smallest = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (num[i] < Smallest || i == 0)
			Smallest = num[i];	
	}
	return Smallest;
}

void main()
{
	const int ARRAY_SIZE = 500;

	int num[ARRAY_SIZE], i;

	srand(time(0));

	// Get numbers
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		//cout << "Number " << i + 1 << "? ";
		//cin >> num[i];

		// Pick a random number between 0 and 100
		num[i] = rand() % 101;
	}

	// Find the sum of the array
	int total = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
		total += num[i];

	

	// Output the original numbers
	for (i = 0; i < ARRAY_SIZE; i++)
		cout << "Number " << i + 1 << ": " << num[i] << endl;

	cout << "Sum of the array is " << total << endl;
	cout << endl << "Average is " << Average(num, ARRAY_SIZE) << endl;
	cout << "Largest is " << Largest(num, ARRAY_SIZE) << endl;
	cout << "Smallest is " << Smallest(num, ARRAY_SIZE) << endl;

}