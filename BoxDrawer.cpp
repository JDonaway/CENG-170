#include <iostream>
using namespace std;

void DrawBox(int rows, int columns, char symbol)
{
	for (int r = 1; r <= rows; r++)
	{
		for (int c = 1; c <= columns; c++)
			cout << symbol;
		cout << endl;
	}
}

void main()
{
	int rows, columns;
	char symbol;
	cout << "Rows: ";
	cin >> rows;
	cout << "Columns: ";
	cin >> columns;
	cout << "Symbol: ";
	cin >> symbol;

	DrawBox(rows, columns, symbol);
}

