// 20190105
// r/dailyprogrammer Challenge #25 [difficult] N queens
// https://www.reddit.com/r/dailyprogrammer/comments/qxv8h/3152012_challenge_25_difficult/
// Write a program that places N queens on an NxN chessboard such that no two
// queens are on the same row, column, or diagonal, and no queen is on either of
// the two major diagonals (corner to corner). Get a solution for as large a
// value of N as you can.

#include <iostream>


// Here's a depth first search solution to the N queens problem.
int main(int argc, char *argv[])
{
	std::cout << "Enter a number (greater then 0) to determine both the chess board size and the number of queens" << std::endl;

	int n;
	std::cin >> n;

	if (n < 1)
	{
		std::cout << "Invalid Input" << std::endl;
		return 1;
	}

	// array index = queen's board column
	// index value = queen's board row
	int * board = new int[n];

	// Board indices start at 0
	// (column,row)
	// 
	// ...   ...   ...   ...
	// (0,2) (1,2) (2,2) ...
	// (0,1) (1,1) (2,1) ...
	// (0,0) (1,0) (2,0) ...
	// 
	// Being placing queens onto the board one column at a time
	int currentQueenColumn = 0;
	int currentQueenRow = 0;
	while (currentQueenColumn >= 0)
	{
		// Assume the current row and column are a good place to put the queen
		bool goodPlacement = true;

		// Place the queen
		board[currentQueenColumn] = currentQueenRow;

		// Check if the queens placement is valid
		// ---------------------------------------------------------------------
		// Queen can't be on a major diagonal
		if (currentQueenRow == currentQueenColumn ||
			currentQueenRow == (n - 1 - currentQueenColumn))
		{
			goodPlacement = false;
		}
		else
		{
			// Check if this queen placement conflicts with any of the previously
			// placed queens
			for (int oldQueenColumn = 0; oldQueenColumn < currentQueenColumn;
				oldQueenColumn++)
			{
				const int & oldQueenRow = board[oldQueenColumn];

				// Same row check
				if (currentQueenRow == oldQueenRow)
				{
					goodPlacement = false;
					break;
				}

				// Diagonal check (slope should be 1 or -1)
				if (std::abs(currentQueenRow - oldQueenRow) ==
					std::abs(currentQueenColumn - oldQueenColumn))
				{
					goodPlacement = false;
					break;
				}
			}
		}
		
		// Decide what to do next
		// ---------------------------------------------------------------------
		if (goodPlacement)
		{
			// Good queen placement. If this is not the last column, move to the
			// next column. If this is the last column, a valid queen placement
			// has been found and we're done
			if (currentQueenColumn < n - 1)
			{
				currentQueenColumn++;
				currentQueenRow = 0;
			}
			else
			{
				break;
			}
		}

		if (!goodPlacement)
		{
			// Bad queen placement. Try another row. If no rows available in the
			// current column. Try a new row in the previous column.
			currentQueenRow++;
			while (currentQueenRow == n)
			{
				currentQueenColumn--;
				if (currentQueenColumn < 0)
				{
					break;
				}
				currentQueenRow = board[currentQueenColumn] + 1;
			}
		}

		// Debugging Output:
		// for (int i = 0; i < n; i++) std::cout << (int)board[i] << ", ";
		// std::cout << std::endl;
	}

	// Debugging Output:
	// for (int i = 0; i < n; i++) std::cout << (int)board[i] << ", ";
	// std::cout << std::endl;

	if (currentQueenColumn < 0)
	{
		std::cout << "Faild to find solution." << std::endl;
	}
	else
	{
		// Note: Drawing the board also messes it up because I incement it's values.
		// Next time I should have had array index = queen's board row and
		// index value = queen's board column
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[j] != n - 1)
				{
					std::cout << '.';
				}
				else
				{
					std::cout << 'Q';
				}
				std::cout << ' ';

				board[j]++;
			}
			std::cout << '\n';
		}
	}

	delete[] board;

	return 0;
}

/*
31
. . . . . . . . . . . . . . . . Q . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . Q . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . Q . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . Q . . . . . . . . . . . . 
. . . . . . . . . . . . . . . Q . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . Q . . . . . . . . . . . . . 
. . . . . . . . . . . Q . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . Q . . . . . . . . . . . . . . . . . 
. . . . . . . . . . Q . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . Q . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Q 
. . . . . . . . . . . . . . . . . . . . . . . . . Q . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . Q . 
. . . . . . . . . . . . . . . . . . . . Q . . . . . . . . . . 
. . . . . . . . . Q . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . Q . . . . . . . 
. . . . . . . . . . . . . . . . . . . Q . . . . . . . . . . . 
. . . . . . . Q . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . Q . . . 
. . . . . . Q . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . Q . . . . . . 
. . . . . Q . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . Q . . . . . . . . . 
. . . . Q . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . Q . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . Q . . . . 
. . . . . . . . Q . . . . . . . . . . . . . . . . . . . . . . 
. Q . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . Q . . . . . . . . . . . . . . . . . . . . . . . . . . . 
Q . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . Q . . . . . . . . . . . . . . . . . . . . . . . . . . . .
*/

