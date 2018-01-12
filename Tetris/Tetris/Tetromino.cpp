#include "Tetromino.h"

	Tetromino::Tetromino()   {}

	Tetromino::Tetromino(int i)  
	{
		type = Kind(i);
		shapeIndex = 0;
		BlockSize = 35;
	}

	//(imageX,imageY,size of block,size of block)
	// used image looks like this [][][][][][][]
	sf::IntRect Tetromino::blockColor()
	{
		return sf::IntRect(BlockSize * type, 0, BlockSize, BlockSize);
	}
	
	std::vector<std::vector<int>> Tetromino::getShape()
	{
		return Shapes[type][shapeIndex];
	}
	
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
