/*This program plays TicTacToe
by Josh Donaway and Adam Campbell
*/


#include <iostream>
#include <ctime> // For time function
using namespace std;
const int BOARD_SIZE = 9;

void DisplayBoard(const char board[])
{
	cout << endl;
	cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "-----------\n";
	cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "-----------\n";
	cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << endl;
}

void GetUserMove(char board[]) // Gets user's move
{
	int move,
		 error = 0;
	do 
	{
		cout << "Enter your move: ";
		cin >> move;

		if (move > 8 || move < 0)
		{
			cout << "Not a valid move! Valid moves between 0-8.\n";
			error = 1;
		}
		else
		{
			if (board[move] == 'X' || board[move] == 'O')
			{
				cout << "That spot already has been filled!\n";
				error = 1;
			}
			else
			{
				board[move] = 'X';
				error = 0;
			}
		}
	} while (error);
}

int CheckForWinner(const char board[])
{
	int returnValue = 1;
	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
		returnValue = 2;
	else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
		returnValue = 2;
	else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
		returnValue = 2;
	else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
		returnValue = 2;
	else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
		returnValue = 2;
	else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
		returnValue = 2;
	else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
		returnValue = 2;
	else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
		returnValue = 2;
	else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
		returnValue = 3;
	else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
		returnValue = 3;
	else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
		returnValue = 3;
	else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
		returnValue = 3;
	else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
		returnValue = 3;
	else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
		returnValue = 3;
	else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
		returnValue = 3;
	else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
		returnValue = 3;


	if (returnValue == 1)
	{
		for (int i = 0; i < 9; i++) //cycles through board
		{
			if (board[i] != 'O' && board[i] != 'X') // if there is an empty location, return 0
				returnValue = 0;
		}
	}

	return returnValue;
}

void GetComputerMove(char board[])
{
	int computer_move; // Get a random number between 0 and 8
	int error = 0;
	int temp;
	bool change = false;


	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 'X' && board[i] != 'O' && change == false)
		{
			temp = board[i];
			board[i] = 'O';

			if (CheckForWinner(board) == 3)
			{
				board[i] = 'O';
				cout << "Computer is moving to " << i << endl;
				change = true;
			}
			else
				board[i] = temp;
		}
	}

	if (change == false)
	{
		for (int i = 0; i < 9; i++)
		{
			if (board[i] != 'X' && board[i] != 'O' && change == false)
			{
				temp = board[i];
				board[i] = 'X';

				if (CheckForWinner(board) == 2)
				{
					board[i] = 'O';
					cout << "Computer is moving to " << i << endl;
					change = true;
				}
				else
					board[i] = temp;
			}
		}
	}

	if (change == false)
	{
		do
		{
			computer_move = rand() % 9;


			if (computer_move > 8 || computer_move < 0)
			{
				error = 1;
			}
			else
			{
				if (board[computer_move] == 'X' || board[computer_move] == 'O')
				{
					error = 1;
				}
				else
				{
					board[computer_move] = 'O';
					cout << "Computer is moving to " << computer_move << endl;
					error = 0;
				}
			}
		} while (error);
	}
}

void main()
{
	char board[BOARD_SIZE] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
	char turn = 'X'; // X always starts first
	int win = 0; // Set to 1, 2, or 3 when game is over
	// Seed random number generator
	srand(time(NULL));
	// Keep playing game until there's a tie or a winner
	while (win == 0)
	{
		DisplayBoard(board);
		if (turn == 'X')
		{
			GetUserMove(board);
			turn = 'O';
		}
		else
		{
			GetComputerMove(board);
			turn = 'X';
		}
		win = CheckForWinner(board);
	}
	DisplayBoard(board);
	cout << endl;
	if (win == 1)
		cout << "It's a tie." << endl;
	else if (win == 2)
		cout << "X wins!!" << endl;
	else if (win == 3)
		cout << "O wins!!" << endl;
	else
		cout << "Unexpected return value: " << win << endl;
}