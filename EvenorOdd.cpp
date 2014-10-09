//This program determines whether a number is even or odd.
//by Josh Donaway

#include <iostream>
using namespace std;

void main()
{
	int x;

	cout << "Input x: ";
	cin >> x;

	if (x % 2 ==0)
	{
		cout << x << " is even.";
	}
	else
	{
		cout << x << " is odd.";
	}
}