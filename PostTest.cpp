//This program subtracts 2 until 30 goes to 0.
//by Josh Donaway

#include <iostream>
using namespace std;

void main()
{
	int x=30;
	do
	{
		cout << x << " ";
		x = x - 2;
	} while ( x >= 0);
}
