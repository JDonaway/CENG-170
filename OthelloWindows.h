// *From Josh Donaway*

/* OthelloWindows.h
*
* This header file contains functions that implement the Othello board game.
*
*/

// Size of game board (8x8 is the standard)
const int MAX_ROWS = 8;
const int MAX_COLS = 8;

// Characters used to represtent spaces in game board
const char BLACK_PLAYER = 'H';   // Human (moves first)
const char WHITE_PLAYER = 'C';   // Computer
const char UNOCCUPIED = ' ';   // Unoccupied

// The game board (global variable)
char board[MAX_ROWS][MAX_COLS];

// Call this function when someone has won or the game is a tie. 
// It displays a modal dialog box indicating who won and the score.
//
// [in] player - BLACK_PLAYER or WHITE_PLAYER or 'T' for a tie
// [in] discs_human - The number of discs that are black
// [in] discs_computer - The number of discs that are white
void DisplayWinner(char player, int discs_human, int discs_computer);

// Call this function to force the board to redraw itself
void RedrawBoard();

// Call this function when the human or the computer have finished
// making their move by changing the contents of the board
void MoveFinished();

/****************************************************************************/


// Place initial four discs on the board.
//
// No parameters
void InitializeBoard()
{
	// Empty entire board
	for (int r = 0; r < MAX_ROWS; r++)
		for (int c = 0; c < MAX_COLS; c++)
			board[r][c] = UNOCCUPIED;

	// Place starting discs
	int starting_row = MAX_ROWS / 2;
	int starting_col = MAX_COLS / 2;
	board[starting_row - 1][starting_col - 1] = WHITE_PLAYER;
	board[starting_row][starting_col] = WHITE_PLAYER;
	board[starting_row - 1][starting_col] = BLACK_PLAYER;
	board[starting_row][starting_col - 1] = BLACK_PLAYER;
}

/****************************************************************************/

// Initializes temporaryBoard to match the actual board.
void setTemporaryBoard(char tempBoard[][MAX_COLS])
{
	for (int tempRow = 0; tempRow < MAX_ROWS; tempRow++)
	{
		for (int tempCol = 0; tempCol < MAX_COLS; tempCol++)
		{
			// Sets each spot on the board to be the same as the
			// actual gameboard.
			tempBoard[tempRow][tempCol] = board[tempRow][tempCol];
		}
	}
}

// Place the disc on the board, flip the discs affected, and
// return the number of discs flipped.  Note if 0 is returned,
// the position moved is illegal, and the board is not changed.
//
// [in/out] board - Game board which will have its discs flipped
// [in]     row   - Row in board to move to
// [in]     col   - Col in board to move to
// [in]     disc  - Player's disc to be placed 
int PlaceDisc(char board[][MAX_COLS], int row, int col, char disc)
{
	int num_flipped = 0;

	if (board[row][col] != UNOCCUPIED)
		return 0;

	board[row][col] = disc;

	char opposing_disc;
	if (disc == BLACK_PLAYER)
		opposing_disc = WHITE_PLAYER;
	else
		opposing_disc = BLACK_PLAYER;

	// Do we have discs to the right to flip?
	int disc_pos = -1;
	for (int c = col + 1; c < MAX_COLS && board[row][c] != UNOCCUPIED && disc_pos == -1; c++)
	{
		if (board[row][c] == disc)
			disc_pos = c;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos > col + 1)
	{
		// Flip discs to the right
		for (int c = col + 1; c < disc_pos; c++)
		{
			board[row][c] = disc;
			num_flipped++;
		}
	}

	// Do we have discs to the left to flip?
	disc_pos = -1;
	for (int c = col - 1; c >= 0 && board[row][c] != UNOCCUPIED && disc_pos == -1; c--)
	{
		if (board[row][c] == disc)
			disc_pos = c;
	}

	//if (disc_pos > -1) cout << "left disc_pos = " << disc_pos << endl;

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos < col - 1)
	{
		// Flip discs to the left
		for (int c = col - 1; c > disc_pos; c--)
		{
			board[row][c] = disc;
			num_flipped++;
		}
	}

	// Do we have discs above to flip?
	disc_pos = -1;
	for (int r = row - 1; r >= 0 && board[r][col] != UNOCCUPIED && disc_pos == -1; r--)
	{
		if (board[r][col] == disc)
			disc_pos = r;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos < row - 1)
	{
		// Flip discs above
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][col] = disc;
			num_flipped++;
		}
	}

	// Do we have discs below to flip?
	disc_pos = -1;
	for (int r = row + 1; r < MAX_ROWS && board[r][col] != UNOCCUPIED && disc_pos == -1; r++)
	{
		if (board[r][col] == disc)
			disc_pos = r;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos > row + 1)
	{
		// Flip discs below
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][col] = disc;
			num_flipped++;
		}
	}

	// Do we have discs diagnally up-left to flip?
	disc_pos = -1;
	int c = col - 1;
	for (int r = row - 1; c >= 0 && r >= 0 && board[r][c] != UNOCCUPIED && disc_pos == -1; r--)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c--;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos < row - 1)
	{
		c = col - 1;
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][c] = disc;
			num_flipped++;
			c--;
		}
	}

	// Do we have discs diagnally up-right to flip?
	disc_pos = -1;
	c = col + 1;
	for (int r = row - 1; c < MAX_COLS && r >= 0 && board[r][c] != UNOCCUPIED && disc_pos == -1; r--)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c++;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos < row - 1)
	{
		c = col + 1;
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][c] = disc;
			num_flipped++;
			c++;
		}
	}

	// Do we have discs diagnally down-left to flip?
	disc_pos = -1;
	c = col - 1;
	for (int r = row + 1; c >= 0 && r < MAX_ROWS && board[r][c] != UNOCCUPIED && disc_pos == -1; r++)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c--;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos > row + 1)
	{
		c = col - 1;
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][c] = disc;
			num_flipped++;
			c--;
		}
	}

	// Do we have discs diagnally down-right to flip?
	disc_pos = -1;
	c = col + 1;
	for (int r = row + 1; c < MAX_COLS && r < MAX_ROWS && board[r][c] != UNOCCUPIED && disc_pos == -1; r++)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c++;
	}

	// Make sure we found a disc and that it is at least 2 spots away
	if (disc_pos != -1 && disc_pos > row + 1)
	{
		c = col + 1;
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][c] = disc;
			num_flipped++;
			c++;
		}
	}

	// Reset board if nothing was flipped... illegal move
	if (num_flipped == 0)
		board[row][col] = UNOCCUPIED;

	return num_flipped;
}

// Checks the board to see if there is an available move for the designated player.
bool AvailableMove(char disc)
{
	bool availableMove = false;
	char tempBoard[MAX_ROWS][MAX_COLS];

	//Matches the temporary board to the gameboard
	setTemporaryBoard(tempBoard);

	for (int r = 0; r < MAX_ROWS; r++)
	{
		for (int c = 0; c < MAX_COLS; c++)
		{
			if (PlaceDisc(tempBoard, r, c, disc) != 0)
				availableMove = true;

			//No need to loop through entire board if there is still an available move left.
			if (availableMove == true)
				break;
		}
		if (availableMove == true)
			break;
	}
	return availableMove;
}

//Checks for available moves for both players. If there are no more legal moves, the function returns true.
bool IsGameOver()
{
	bool availableMove = false;
	
	if (AvailableMove(WHITE_PLAYER) || AvailableMove(BLACK_PLAYER))
		availableMove = true;

	//If there are no possible available moves, the game is over.
	if (availableMove == false)
		return true;
	else
		return false;
}

// This function checks if the game is over and, if so, calls the DisplayWinner function
// which is supposed to end the game.
void CheckForWinner()
{
	int whiteChips = 0, blackChips = 0;
	if (IsGameOver())
	{
		for (int r = 0; r < MAX_ROWS; r++)
		{
			for (int c = 0; c < MAX_COLS; c++)
				if (board[r][c] == WHITE_PLAYER)
					whiteChips++;
				else if (board[r][c] == BLACK_PLAYER)
					blackChips++;
		}
		if (whiteChips > blackChips)
			DisplayWinner(WHITE_PLAYER, blackChips, whiteChips);
		else if (whiteChips < blackChips)
			DisplayWinner(BLACK_PLAYER, blackChips, whiteChips);
		else
			DisplayWinner('T', blackChips, whiteChips);
	}
}

// This function is called automatically when it's the user's turn and
// the user clicks the left mouse button.
//
// [in] row - The row where the user clicked
// [in] col - The column where the user clicked
void MouseClicked(int row, int col)
{
	int discs_flipped = PlaceDisc(board, row, col, BLACK_PLAYER);

	if (AvailableMove(BLACK_PLAYER))
	{
		if (discs_flipped > 0)
		{
			// Display the board with the newly placed black discs
			RedrawBoard();

			CheckForWinner();

			// Indicate that I'm finished moving so ComputerMove() will get called
			MoveFinished();
		}
	}
	else // If no available moves, the player is skipped
	{
		CheckForWinner();
		MoveFinished();
	}
}

// This function is called automatically when it's the computer's turn to move
//
// No parameters
// The computer is set as a 'Greedy' AI.
// It will simply make the move that will allow it to
// get the most flips.
void ComputerMove()
{
	if (AvailableMove(WHITE_PLAYER)) // Checks for available moves
	{
		int flips = 0, maxFlips = 0, largestFlipMoveRow, largestFlipMoveCol;

		char temporaryBoard[MAX_ROWS][MAX_COLS];
		setTemporaryBoard(temporaryBoard); 	//Matches the temporary board to the gameboard

		for (int row = 0; row < MAX_ROWS; row++) //Find the move that will flip the most chips in one move
		{
			for (int col = 0; col < MAX_COLS; col++)
			{
				if (board[row][col] == UNOCCUPIED)
				{
					flips = PlaceDisc(temporaryBoard, row, col, WHITE_PLAYER);
					if (flips > maxFlips)
					{
						maxFlips = flips;
						largestFlipMoveRow = row; //Sets the spot on the board that allows the most flips
						largestFlipMoveCol = col;
					}
					setTemporaryBoard(temporaryBoard); //resets temporary board from any changes
				}
			}
		}
		flips = PlaceDisc(board, largestFlipMoveRow, largestFlipMoveCol, WHITE_PLAYER);
		if (flips > 0)
		{
			RedrawBoard(); // Display the board with the new white disc
		}
	} // If there are no available moves, the computer is skipped

	CheckForWinner(); 	// Checks to see if the game is over

	// Indicate the computer is finished moving so MouseClicked() can get called again
	MoveFinished();
}