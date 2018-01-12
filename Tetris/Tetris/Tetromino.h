#pragma once
#include<vector>
#include <SFML\Graphics.hpp>

/*
*	Handles Tetromino block variables (type,color,orientation)
*	**Consider splitting Tetromino class into smaller classes representing each block
*/
class Tetromino
{
public:
	Tetromino();
	//Uses integer between 0-6 to to set the type of tetromino block
	Tetromino(int i);	

	//Returns Rect representing coordinates for color (Used with blocks.png)
	sf::IntRect blockColor();

	//Returns matrix representing block shape;
	std::vector<std::vector<int>> getShape();
	std::vector<std::vector<int>> clockWiseRotation();
	std::vector<std::vector<int>> counterClockWiseRotation();
private:
	int shapeIndex;

	//controls size of individual tetromino blocks
	int BlockSize;
	enum Kind { I, J, L, O, S, T, Z };
	Kind type;
	typedef std::vector<std::vector<int>> Shape;
	
	//Contains 2D vectors of all possible orientations of all the tetromino blocks
	std::map<Kind, std::vector<Shape>> Shapes = {
		{
			Kind::I,
			{
				{
					{ 0, 0, 0, 0 },
					{ 1, 1, 1, 1 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
				},{
					{ 0, 0, 1, 0 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 1, 0 },
				}
			}
		}, //I
		{
			Kind::J,
			{
				{
					{ 0, 0, 0, 0 },
					{ 2, 2, 2, 0 },
					{ 0, 0, 2, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 0, 2, 0, 0 },
					{ 0, 2, 0, 0 },
					{ 2, 2, 0, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 0, 0, 0, 0 },
					{ 2, 0, 0, 0 },
					{ 2, 2, 2, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 0, 2, 2, 0 },
					{ 0, 2, 0, 0 },
					{ 0, 2, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			}

		}, //J
		{
			Kind::L,
			{
				{
					{ 0, 0, 0, 0 },
					{ 3, 3, 3, 0 },
					{ 3, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 3, 3, 0, 0 },
					{ 0, 3, 0, 0 },
					{ 0, 3, 0, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 0, 0, 0, 0 },
					{ 0, 0, 3, 0 },
					{ 3, 3, 3, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 0, 3, 0, 0 },
					{ 0, 3, 0, 0 },
					{ 0, 3, 3, 0 },
					{ 0, 0, 0, 0 }
				}
			}
		}, //L
		{
			Kind::O,
			{
				{
					{ 0, 0, 0, 0 },
					{ 0, 4, 4, 0 },
					{ 0, 4, 4, 0 },
					{ 0, 0, 0, 0 }
				}
			}
		}, //O
		{
			Kind::S,
			{
				{
					{ 0, 0, 0, 0 },
					{ 0, 5, 5, 0 },
					{ 5, 5, 0, 0 },
					{ 0, 0, 0, 0 },
				},{
					{ 5, 0, 0, 0 },
					{ 5, 5, 0, 0 },
					{ 0, 5, 0, 0 },
					{ 0, 0, 0, 0 },
				}
			}
		}, // S
		{
			Kind::T,
			{
				{
					{ 0, 0, 0, 0 },
					{ 0, 6, 0, 0 },
					{ 6, 6, 6, 0 },
					{ 0, 0, 0, 0 }
				},{
					{ 0, 0, 0, 0 },
					{ 0, 6, 0, 0 },
					{ 0, 6, 6, 0 },
					{ 0, 6, 0, 0 }
				},{
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 6, 6, 6, 0 },
					{ 0, 6, 0, 0 }
				},{
					{ 0, 0, 0, 0 },
					{ 0, 6, 0, 0 },
					{ 6, 6, 0, 0 },
					{ 0, 6, 0, 0 }
				}
			}

		}, // T
		{
			Kind::Z,
			{
				{
					{ 0, 0, 0, 0 },
					{ 7, 7, 0, 0 },
					{ 0, 7, 7, 0 },
					{ 0, 0, 0, 0 },
				},{
					{ 0, 0, 7, 0 },
					{ 0, 7, 7, 0 },
					{ 0, 7, 0, 0 },
					{ 0, 0, 0, 0 },
				}
			}
		}  // Z
	};
};