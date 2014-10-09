#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	int NumHeads = 0;
	srand(time(0));

	for (int i = 1; i <= 200000; i++)
	{
		if (rand() % 2 == 0)
		{
			//cout << "Heads\n";
			NumHeads++;
		}
		else
			;//cout << "Tails\n"
	}
	cout << "Number of Heads: " << NumHeads << endl;
	cout << "Number of Tails: " << 200000 - NumHeads << endl;
}