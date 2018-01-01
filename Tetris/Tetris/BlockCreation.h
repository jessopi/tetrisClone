#pragma once
#include "Tetromino.h"
#include <chrono>
#include <random>
/*
*	Class to fill vector with every type of Tetromino shape twice and then shuffle it randomly.
*	Outputs the next shape in the vector and then removes it, refills vector when empty.
*/
class BlockCreation
{
public:
	BlockCreation();
	Tetromino nextBlock();
	void reset();
private:
	std::random_device rd;
	int number_of_Shapes;
	std::vector<Tetromino> blockVector;
	void fill();	
};
