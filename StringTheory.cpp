#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void main()
{
	string team;
	cout << "Favorite football team? ";
	getline(cin, team);

	cout << "Number of char: " << team.length() << endl;

	int space = team.find(" ");
	string s1 = team.substr(0, space);
	string s2 = team.substr(space + 1);

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
}