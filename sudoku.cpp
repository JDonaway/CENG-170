


#include <iostream>
using namespace std;

const int PUZZLE_SIZE = 6;

//This function takes in the puzzle board and displays it, returning nothing
void DisplayPuzzle(const int puzzle[][PUZZLE_SIZE])
{
	for (int i = 0; i < PUZZLE_SIZE; i++)
	{
		for (int j = 0; j < PUZZLE_SIZE; j++)
		{
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}

//This function takes in the puzzle and row that is unsolved
//tests to find the values that are in place, and fills a blank (0)
//with the integer that is missing, returning the missing value
int SolveRow(int puzzle[][PUZZLE_SIZE], int row)
{
	int returnVal;
	bool nums_present[PUZZLE_SIZE] = { false };
	
	for (int c = 0; c < PUZZLE_SIZE; c++)
	{
		if (puzzle[row][c] != 0)
		{
			nums_present[puzzle[row][c] - 1] = true;
		}
	}
	
	for (int i = 0; i < PUZZLE_SIZE; i++)
	{
		if (nums_present[i] == false)
		{
			returnVal = i += 1 ;
		}
	}
	
	return returnVal;
}

void SolvePuzzle(int puzzle[][PUZZLE_SIZE])
{
	for (int r = 0; r < PUZZLE_SIZE; r++)
	{
		for (int c = 0; c < PUZZLE_SIZE; c++)
		{
			if (puzzle[r][c] == 0)
				puzzle[r][c] = SolveRow(puzzle, r);
		}
	}
}

void main()
{
	int puzzle[PUZZLE_SIZE][PUZZLE_SIZE] = { 1, 0, 2, 4, 5, 6,
											 5, 4, 6, 2, 1, 3,
											 6, 2, 1, 3, 0, 5,
											 3, 5, 0, 0, 6, 2,
											 0, 6, 3, 5, 2, 1,
		   								   	 2, 1, 5, 6, 3, 0 };	DisplayPuzzle(puzzle);	SolvePuzzle(puzzle);	cout << endl << "Solved" << endl;	DisplayPuzzle(puzzle);
}