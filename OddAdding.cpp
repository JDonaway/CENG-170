//By Josh Donaway

#include <iostream>
using namespace std;

void main()
{
	int x,y,z,r=0,t;

	cout << "Input X: "; cin >> x;
	cout << "Input Y: "; cin >> y;
	cout << "Input Z: "; cin >> z;

	do
	{
		cout << x + r * y << " ";
		r++;
		t=x + r*y;
	}
	while (t <= z);
}