#pragma once

#include <vector>
#include <array>
#include <random>

std::array<std::array<char, 3>, 3> board{};

std::pair<size_t,size_t> selectRandomPosition()
{
	static std::random_device rd{};                                                 // Random device for seeding the twister
	static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };      // std::seed_seq resolves underseeding issues 
	static std::mt19937 engine(ss);                                                 // seeding the random engine with the random data
	static std::uniform_int_distribution<size_t> dist(0, 3);         // generated random integers withing specified range
	size_t randomRow = dist(engine); 
	size_t randomColumn = dist(engine);
	std::pair<size_t, size_t> rowColumn = { randomRow, randomColumn };
	// generated a random integer withing the set range and stores it in randomIndex
	// all made static in order not to create objects all over again when function is called
	return rowColumn;
}

// TIC TAC TOE GAME
// 3 x 3 board
// User selects the symbol of his choice for playing
