#include <iostream>
using namespace std;

char GetGrade()
{
	int error = 0;
	char grade;
	do
	{
		cout << "Class Grade(A-F): ";
		cin >> grade;

		grade = toupper(grade);
		switch (grade)
		{
		case 'A':
			return grade;
			break;
		case 'B':
			return grade;
			break;
		case 'C':
			return grade;
			break;
		case 'D':
			return grade;
			break;
		case 'F':
			return grade;
			break;
		default:
			cout << "Must input grade from A-F.\n"; error = 1;
		}
	} while (error = 1);
}

int GetCreditHours()
{
	int hours;
	do
	{

		cout << "Class Hours(1-5): ";
		cin >> hours;

		if (hours > 5 || hours < 1)
			cout << "Error: Hours must be between 1-5.\n";
	} while (hours > 5 || hours < 1);
	return hours;
}

void main()
{
	char grade;
	int creditHours, courses;

	cout << "Enter number of courses: ";
	cin >> courses;
	for (int n = 0; n < courses; n++)
	{
		cout << "Class " << n + 1 << endl;
		grade = GetGrade();
		creditHours = GetCreditHours();
		cout << grade << " " << creditHours << endl;
	}
}