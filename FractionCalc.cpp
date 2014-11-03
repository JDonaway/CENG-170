/* This program works as a fraction calculator: it computes basic calculations to positive 
fractions and returns the answer.
by Josh Donaway and Adam Campbell*/

#include <iostream> 
using namespace std;

// Missing functions go here! 

int GCD(int a, int b)
{
	int c;
	while (a != 0) 
	{
		c = a; 
		a = b%a;
		b = c;
	}
	return b;
}

void ReduceFraction(int &num, int &den)
{
	int gcd = GCD(num, den);
	num /= gcd;
	den /= gcd;
}

int LCM(int den1, int den2)
{
	int lcm = (den1 * den2) / GCD(den1, den2);
	return lcm;
}
void CommonDenominator(int &num1,int &den1,int &num2,int &den2)
{
	int lcm = LCM(den1, den2);
	if (lcm != den1)
		num1 = lcm / den1;
	if (lcm != den2)
		num2 = lcm / den2;
	den1 = den2 = lcm;
}
int main()
{
	int num1, den1, num2, den2, newnum, newden;
	char slash1, slash2, op;
	cout << "\nFraction Calculator\n\n";
	cout << "Add, subtract, multiply & divide - positive fractions only\n";
	cout << "Enter '0/0 + 0/0' to quit.\n";
	// Input will be assumed to be in correct form for simplification 
	// Input data before loop in case they want to exit right away 
	cout << "\n> ";
	cin >> num1 >> slash1 >> den1 >> op >> num2 >> slash2 >> den2;
	while (num1 + den1 + num2 + den2 > 0)
	{
		// Reduce both fractions to keep integers as small as possible 
		ReduceFraction(num1, den1);
		ReduceFraction(num2, den2);
		switch (op)
		{
		case '+':
			// Find common denominator and add 
			CommonDenominator(num1, den1, num2, den2);
			newnum = num1 + num2;
			newden = den1;
			break;
		case '-':
			// Find common denominator and subtract 
			CommonDenominator(num1, den1, num2, den2);
			newnum = num1 - num2;
			newden = den1;
			break;
		case '*':
			// Multiply numerators and multiply denominators 
			newnum = num1 * num2;
			newden = den1 * den2;
			break;
		case '/':
			// Invert and multiply 
			newnum = num1 * den2;
			newden = den1 * num2;
		}
		// Reduce the answer to lowest terms 
		ReduceFraction(newnum, newden);
		// Output the results 
		cout << num1 << "/" << den1 << " " << op << " ";
		cout << num2 << "/" << den2 << " = ";
		cout << newnum << "/" << newden << endl;
		// Input data for next iteration of loop 
		cout << "\n> ";
		cin >> num1 >> slash1 >> den1 >> op >> num2 >> slash2 >> den2;
	}
}