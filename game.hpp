#pragma once

#include <vector>
#include <array>
#include <random>
#include <iostream>
#include <utility>
#include <algorithm>


std::vector<std::pair<size_t, size_t>> makeInitialVector();
std::pair<size_t, size_t> selectRandomPosition();

// TIC TAC TOE GAME
// 3 x 3 board
// User selects the symbol of his choice for playing
// Machine goes with the other symbol
// The first time playing the game, the user starts
// Then, if the users wants to keep playing, the winner gets to choose first in a new game (either the user or the machine)
// The machine will look at the available spots withing the board and mark one at its turn with the assigned symbol
// The first one to fill 3 spots in a row with his symbol, wins.
static bool firstGame{ true };

class TicTacToeSession
{
private:
	std::array<std::array<char, 3>, 3> board;
	std::vector<std::pair<size_t, size_t>> availablePositions;
	//std::array <char, 2> symbols{ 'X', 'O' };
	char userSymbol;
	char machineSymbol;


public:

	TicTacToeSession()
		: board{ {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
		} },
		availablePositions{ makeInitialVector() },
		userSymbol{},
		machineSymbol{}
	{

	}

	std::pair<size_t, size_t> selectRandomPosition();
	char getUserSymbol()
	{
		std::cout << "Enter your preffered symbol (X or O): ";
		while (true)
		{

			char c{};
			std::cin >> c;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cout << "That wasn't a valid input. Please try again.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (c != 'X' && c != 'O')
			{
				std::cout << "That wasn't a valid input. Please try again.\n";
				continue;
			}
			userSymbol = c;
			return c;
		}

	}
	// if the user has chosen a symbol, the machine should be assigned the other
	char determineMachineSymbol(const char& userGuess)
	{
		switch (userGuess)
		{
		case 'X':
			return machineSymbol = 'O';
		case 'O':
			return machineSymbol = 'X';
		}
	}

	// when the player and the machine have a symbol, the game should start
	// get the user prompt for the position of the symbol (has to be called twice for Row/Column)
	size_t getPositionIndex(const std::string& positionName)
	{
		while (true)
		{
			std::cout << positionName << " (1, 2, 3): ";
			size_t index{};
			std::cin >> index;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cout << "That wasn't a valid input. Please try again.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			if (index != 1 && index != 2 && index != 3)
			{
				std::cout << "That wasn't a valid input. Please try again.\n";
				continue;
			}

			size_t validatedIndex = index - 1;

			return validatedIndex;
		}
	}


	//the prompt, both in the case of the user or the machine, should be valitated and only if the spot is empty it should be filled. else, the user and 
	// and the machine, respectively, should generate a new prompt

	bool positionAvailable(const std::pair<size_t, size_t>& rowColumn)
	{
		if (board[rowColumn.first][rowColumn.second] != ' ')
		{
			//if (symbol == userSymbol)
			//{
			std::cout << "That spot is already taken! Please choose another! \n";
			//}

			return false;
		}
		else
		{
			board[rowColumn.first][rowColumn.second] = userSymbol;
			findAndErasePosition(rowColumn);
			return true;
		}
	}



	void findAndErasePosition(const std::pair<size_t, size_t>& rowColumn)
	{
		for (size_t position{ 0 }; position < availablePositions.size(); ++position)
		{
			if (rowColumn.first == availablePositions[position].first && rowColumn.second == availablePositions[position].second)
			{
				availablePositions.erase(availablePositions.begin() + position);
				return;
			}
		}

	}


	bool winner()
	{
		if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]))
		{
			if (board[0][0] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[0][0] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;
			}
		}

		if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]))
		{
			if (board[1][0] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[1][0] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}

		if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]))
		{
			if (board[2][0] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[2][0] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}

		if ((board[0][0] == board[1][0]) && (board [1][0] == board[2][0]))
		{
			if (board[0][0] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[0][0] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}

		if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]))
		{
			if (board[0][1] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[0][1] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}

		if ((board[0][2] == board[1][2] && board[1][2] == board[2][2]))
		{
			if (board[0][2] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[0][2] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}

		if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
		{
			if (board[0][0] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[0][0] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}

		if ((board[0][2] == board[1][1]) &&  (board [1][1] == board[2][0]))
		{
			if (board[0][2] == userSymbol)
			{
				std::cout << "Congrats, you have won!\n";
				return true;
			}
			else if (board[0][2] == machineSymbol)
			{
				std::cout << "You have lost! \n";
				return true;

			}
		}
		return false;
	}

	void printBoard()
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


	// if user wins and wants to play again, he will start the game first (else the machine will start)


	// if he wants to play again, chooser also gets to choose symbol again






	//Play game
	void playGame()
	{
		std::cout << "Welcome to Tic Tac Toe! \n";
		std::cout << "You are going to take turns with me (your PC) in placing the symbol you're going to pick (X or O) at a position of your choosing. \n";
		std::cout << "The first one of us that gets 3 of his/her marks in a row (up, down, across, or diagonally) is the winner. \n";
		std::cout << '\n';
		userSymbol = getUserSymbol();
		machineSymbol = determineMachineSymbol(userSymbol);

		while (!winner() && availablePositions.size() != 0)
		{
			std::cout << "Enter the position for your symbol: \n";
			size_t userRow{ getPositionIndex("Row") };
			size_t userColumn{ getPositionIndex("Column") };
			std::pair <size_t, size_t> userRowColumn{ userRow, userColumn };

			while (!positionAvailable(userRowColumn))
			{
				userRowColumn.first = getPositionIndex("Row");
				userRowColumn.second = getPositionIndex("Column");
			}
			
			if (winner() || availablePositions.size() == 0)
			{
				std::cout << '\n';
				printBoard();
				return;
			}

			std::pair<size_t, size_t> machinePosition = selectRandomPosition();
			board[machinePosition.first][machinePosition.second] = machineSymbol;

			std::cout << '\n';
			printBoard();
		}


	}
};


