//This program determines whether a number is equal to, greater, or less than another number.
//by Josh Donaway

#include <iostream>
using namespace std;

void main()
{
	double x, y;

	cout << "Input X: ";
	cin >> x;
	cout << "Input Y: ";
	cin >> y;

	if (x == y)
	{
		cout << x << " is equal to " << y;
	}
	if (x > y)
	{
		cout << x << " is greater than " << y;
	}
	if (x < y)
	{
		cout << x << " is less than " << y;
	}
}