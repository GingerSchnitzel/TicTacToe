#pragma once

#include <vector>
#include <array>
#include <random>
#include <iostream>

std::pair<size_t,size_t> selectRandomPosition()
{
	static std::random_device rd{};                                                 // Random device for seeding the twister
	static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };      // std::seed_seq resolves underseeding issues 
	static std::mt19937 engine(ss);                                                 // seeding the random engine with the random data
	static std::uniform_int_distribution<size_t> dist(0, 3);                        // generated random integers withing specified range
	size_t randomRow = dist(engine);                                                // generates a random integer for row
	size_t randomColumn = dist(engine);                                             // generates a random integer for column
	std::pair<size_t, size_t> rowColumn = { randomRow, randomColumn };
	
	// all made static in order not to create objects all over again when function is called
	return rowColumn;
}

// TIC TAC TOE GAME
// 3 x 3 board
// User selects the symbol of his choice for playing
// Machine goes with the other symbol
// The first time playing the game, the user starts
// Then, if the users wants to keep playing, the winner gets to choose first in a new game (either the user or the machine)
// The machine will look at the available spots withing the board and mark one at its turn with the assigned symbol
// The first one to fill 3 spots in a row with his symbol, wins.

class TicTacToeSession
{
private:

	std::array<std::array<char, 3>, 3> board{};
	std::array <char, 2> symbols{ 'X', 'O' };
	static bool firstGame;

public:

	char getUserSymbol()
	{

		while (true)
		{
			std::cout << "Enter your preffered symbol (X or O):";
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

			if (c != symbols[0] || c != symbols [1])
			{
				std::cout << "That wasn't a valid input. Please try again.\n";
				continue;
			}

			return c;
		}

	}

	std::pair<size_t, size_t> getSymbolPosition()
	{

		while (true)
		{
			std::cout << "Enter the position where you want to place your chosen symbol: \n";
			std::cout << "Row: ";
			size_t row{};
			std::cin >> row;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cout << "That wasn't a valid input. Please try again.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (c != symbols[0] || c != symbols[1])
			{
				std::cout << "That wasn't a valid input. Please try again.\n";
				continue;
			}

			return ;
		}
	}
	// if the user has chosen a symbol, the machine should be assigned the other

	char determineMachineSymbol(char& userGuess)
	{
		char machineSymbol{};
		switch (userGuess)
		{ 
			case 'X':
				machineSymbol = 'O';
			case 'O':
				machineSymbol = 'X';
		}
	}
	// when the player and the machine have a symbol, the game should start


};