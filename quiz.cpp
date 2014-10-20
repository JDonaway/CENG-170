
/*This program runs as a math quiz game, that asks the user for a difficulty level, and then produces random mathematical
problems based on the difficulty. 3 questions each of addition, subtraction, multiplication, and division, respectively,
are asked. Time is tracked for how long it takes the user to answer the questions, and how many were answered
correctly the first and second try. How many missed is output at the end. The user can then restart it again
by inputting anything other than 'q' or 'Q'.
*/
//By Josh Donaway

#include <iostream>
#include <ctime>
using namespace std;

// returns random value based on difficulty level
int RandNum(int difficulty)
{
	if (difficulty == 1)
		return rand() % 9;
	else if (difficulty == 2)
		return rand() % 100;
	else if (difficulty == 3)
		return (rand() % 199) - 99;
}

// Runs three addition problems in a row, problem difficulty set by difficulty level
// Outputs first and second tries, if there are any
void Addition(int difficulty, int &FirstTryCorrect, int &SecondTryCorrect)
{
	int x, y, tries = 0, answer, CorrectCount = 0;
	cout << "\nAddition:\n ------------------------------------------------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		x = RandNum(difficulty);
		y = RandNum(difficulty);
		cout << x << " + " << y << " = ";

		do //Lets the user try two times before running the next problem
		{
			if (tries != 0)
				cout << "Try again!\n";
			cin >> answer;

			tries++;

			if (answer == x + y)
			{
				cout << "Correct!\n";
				if (tries == 1)
					FirstTryCorrect++;
				else
					SecondTryCorrect++;
				tries = 0;
			}
			else
				cout << "Sorry, that is incorrect.\n";
		} while (tries != 0 && tries < 2);

		if (tries == 2)
			cout << "Correct answer is " << x + y << ".\n";
		tries = 0;
	}
}

// Runs three subtraction problems in a row, problem difficulty set by difficulty level
// Outputs first and second tries, if there are any
void Subtraction(int difficulty, int &FirstTryCorrect, int &SecondTryCorrect)
{
	int x, y, tries = 0, answer, CorrectCount = 0;
	cout << "\nSubtraction:\n ------------------------------------------------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		//Makes sure the subtraction does not cause negative answers for begginner or intermediate
		if (difficulty == 1 || difficulty == 2)
		{
			do 
			{
				x = RandNum(difficulty);
				y = RandNum(difficulty);
			} while (x - y < 0);
		}
		else
		{
			x = RandNum(difficulty);
			y = RandNum(difficulty);
		}

		cout << x << " - " << y << " = ";

		do //Lets the user try two times before running the next problem
		{
			if (tries != 0)
				cout << "Try again!\n";
			cin >> answer;

			tries++;

			if (answer == x - y)
			{
				cout << "Correct!\n";
				if (tries == 1)
					FirstTryCorrect++;
				else
					SecondTryCorrect++;
				tries = 0;
			}
			else
				cout << "Sorry, that is incorrect.\n";
		} while (tries != 0 && tries < 2);

		if (tries == 2)
			cout << "Correct answer is " << x - y << ".\n";

		tries = 0;
	}
}

// Runs three multiplication problems in a row, problem difficulty set by difficulty level
// Outputs first and second tries, if there are any
void Multiplication(int difficulty, int &FirstTryCorrect, int &SecondTryCorrect)
{
	int x, y, tries = 0, answer, CorrectCount = 0;
	cout << "\nMultiplication:\n ------------------------------------------------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		x = RandNum(difficulty);
		y = RandNum(difficulty);

		cout << x << " * " << y << " = ";

		do //Lets the user try two times before running the next problem
		{
			if (tries != 0)
				cout << "Try again!\n";

			cin >> answer;

			tries++;

			if (answer == x * y)
			{
				cout << "Correct!\n";
				if (tries == 1)
					FirstTryCorrect++;
				else
					SecondTryCorrect++;
				tries = 0;
			}
			else
				cout << "Sorry, that is incorrect.\n";
		} while (tries != 0 && tries < 2);

		if (tries == 2)
			cout << "Correct answer is " << x * y << ".\n";

		tries = 0;
	}
}

// Runs three division problems in a row, problem difficulty set by difficulty level
// Outputs first and second tries, if there are any
void Division(int difficulty, int &FirstTryCorrect, int &SecondTryCorrect)
{
	int x, y, tries = 0, answer, CorrectCount = 0;
	cout << "\nDivision:\n ------------------------------------------------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		//Makes sure the division gives an integer as an answer
		//and does not divide by 0
		do
		{
			x = RandNum(difficulty);
			y = RandNum(difficulty);
		} while (y == 0 || x % y != 0);


		cout << x << " / " << y << " = ";

		do //Lets the user try two times before running the next problem
		{
			if (tries != 0)
				cout << "Try again!\n";
			cin >> answer;

			tries++;

			if (answer == x / y)
			{
				cout << "Correct!\n";
				if (tries == 1)
					FirstTryCorrect++;
				else
					SecondTryCorrect++;
				tries = 0;
			}
			else
				cout << "Sorry, that is incorrect.\n";
		} while (tries != 0 && tries < 2);

		if (tries == 2)
			cout << "Correct answer is " << x / y << ".\n";

		tries = 0;
	}
}

void main()
{
	int difficulty = 0, FirstTryScore = 0, SecondTryScore = 0;
	char difficultySelection, PlayAgain;

	srand(time(NULL));

	cout << "Math Quiz!\n\n";
	do
	{
		cout << "Select difficulty : Beginner(B), Intermediate(I), or Advanced(A)\n";

		do // Data Validation for difficulty input
		{
			cin >> difficultySelection;

			switch (toupper(difficultySelection))
			{
			case 'B':
				difficulty = 1;
				break;
			case 'I':
				difficulty = 2;
				break;
			case 'A':
				difficulty = 3;
				break;
			default:
				cout << "Please select a difficulty(B, I, or A).\n";
				difficulty = 0;
			}
		} while (difficulty == 0);

		time_t start, end;
		time(&start); // Starts the clock

		Addition(difficulty, FirstTryScore, SecondTryScore);
		Subtraction(difficulty, FirstTryScore, SecondTryScore);
		Multiplication(difficulty, FirstTryScore, SecondTryScore);
		Division(difficulty, FirstTryScore, SecondTryScore);

		time(&end); // Stops the clock

		cout << "\nIt took you " << difftime(end, start) << " seconds to complete this quiz!\n";
		cout << "You answered " << FirstTryScore << " correctly on your first try!\n";
		cout << "You answered " << SecondTryScore << " correctly on your second try!\n";
		cout << "You missed " << 12 - FirstTryScore - SecondTryScore << ".\n";
		cout << "Press any key to play again, or press \"Q\" to quit.\n";
		cin >> PlayAgain;
	} while (PlayAgain != 'Q' && PlayAgain != 'q'); //Runs program again as long as the user does not input 'q' or 'Q'
}