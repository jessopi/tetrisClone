#include "Tetromino.h"

	Tetromino::Tetromino()   {}
	Tetromino::Tetromino(int i)  //used to create randoms
	{
		type = Kind(i);
		shapeIndex = 0;
		BlockSize = 35;
	}
	//	Returns what color the tetromino should be
	sf::IntRect Tetromino::blockColor()
	{
		return sf::IntRect(BlockSize * type, 0, BlockSize, BlockSize);
	}
	//outputs vector containing the shape of the currently selected tetromino
	std::vector<std::vector<int>> Tetromino::getShape()
	{
		return Shapes[type][shapeIndex];
	}
	// finds and returns the rotated vector from the map
	std::vector<std::vector<int>> Tetromino::clockWiseRotation()
	{
		shapeIndex = (shapeIndex + 1) % Shapes[type].size();
		return Shapes[type][shapeIndex];
	}
	std::vector<std::vector<int>> Tetromino::counterClockWiseRotation()
	{
		shapeIndex = (shapeIndex - 1) % Shapes[type].size();
		return Shapes[type][shapeIndex];
	}
