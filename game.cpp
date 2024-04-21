#include <vector>
#include <array>
#include <random>
#include <iostream>
#include <utility>
#include "game.hpp"

std::pair<size_t, size_t> TicTacToeSession::selectRandomPosition()
{
	static std::random_device rd{};                                                 // Random device for seeding the twister
	static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };      // std::seed_seq resolves underseeding issues 
	static std::mt19937 engine(ss);                                                 // seeding the random engine with the random data
	std::uniform_int_distribution<size_t> dist(0, availablePositions.size()-1);     // generated random integers withing specified range
	size_t randomIndex = dist(engine);                                              // generates a random integer for row
	std::pair<size_t, size_t> position = availablePositions[randomIndex];                                     // generates a random integer for column
	availablePositions.erase(availablePositions.begin() + randomIndex);
	                                                                                    // all made static in order not to create objects all over again when function is called
	return position;
}



std::vector<std::pair<size_t, size_t>> makeInitialVector()
{
	std::vector<std::pair<size_t, size_t>> initialVector{};

	for (size_t i{ 0 }; i < 3; ++i)
	{
		for (size_t j{ 0 }; j < 3; ++j)
		{
			initialVector.push_back(std::make_pair(i, j));
		}
	}
	return initialVector;
}