//This program determines if a temperature is hot or cold.
//by Josh Donaway

#include <iostream>
using namespace std;

void main()
{
	double t;

	cout << "Input temperature: ";
	cin >> t;

	if (t >= 70)
	{ cout << "Hot" << endl;}
	else
	{
		if (t < 50)
		{cout << "Cold" << endl;}
		else
		{cout << "Warm" << endl;}
	}
}