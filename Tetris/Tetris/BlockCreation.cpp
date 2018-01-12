#include "BlockCreation.h"

	BlockCreation::BlockCreation()
	{
		fill();
		number_of_Shapes = 7;
	}

	//Checks if vector is empty before refilling, returns Tetromino type
	Tetromino BlockCreation::nextBlock()
	{
		if (blockVector.empty())
		{
			fill();
		}
		auto nextBlock = blockVector.back();
		blockVector.pop_back();
		return nextBlock;
	}
	Tetromino BlockCreation::peek()
	{
		if (blockVector.empty())
			fill();

		auto block = blockVector.back();
		return block;
	}
	//fills blockVector with every Tetromino shape twice and then shuffles.
	void BlockCreation::fill()
	{
		//i coorespsonds to shape of block
		for (int i = 0; i < number_of_Shapes; i++)
		{
			Tetromino tempBlock(i);
			blockVector.push_back(tempBlock);
			blockVector.push_back(tempBlock);
		}
		
		std::mt19937 mt(rd());

		std::shuffle(blockVector.begin(), blockVector.end(), mt);
	}

	void BlockCreation::reset()
	{
		blockVector.clear();
		fill();
	}