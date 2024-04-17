#include <iostream>
#include <array>

void printBoard (std::array<std::array<char, 3>, 3> board)
{
	for (size_t i{ 0 }; i < board.size(); ++i)
	{
		for (size_t j{ 0 }; j < board.size(); j++)
		{

			if (j == 2)
			{
				std::cout << board[i][j];
				continue;
			}
			else
			{
				std::cout << board[i][j] << ' ' << '|' << ' ';
				continue;
			}

		}
		std::cout << "\n";
		if (i == 0 || i == 1)
		{
			std::cout << "---------";
		}
		std::cout << "\n";
	}
	
}


int main()
{
	std::array<std::array<char, 3>, 3> board = {{
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
	} };
	printBoard(board);
}

	