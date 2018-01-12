#include "Board.h"

	Board::Board(){}
	Board::Board(std::string s)
	{

		Grid.resize(20, std::vector<int>(10));
		BlockSize = 35.0;
		gblocks.setSize(sf::Vector2f(BlockSize, BlockSize));
		texture.loadFromFile(s);
		gblocks.setTexture(&texture);
		createGrid();
		completedRows = 0;
		totalCompletedRows = 0;
	}
	void Board::reset()
	{
		totalCompletedRows = 0;
		completedRows = 0;
		createGrid();
	}
	//checks if a row is filled and then deletes and pushes a new row onto grid
	void Board::rowFull(gameSound &sound)
	{
		completedRows = 0;
		std::vector<int> row = { 0,0,0,0,0,0,0,0,0,0 };
		for (unsigned i = 0; i < 20; ++i) {
			bool isFilled = true;
			for (unsigned j = 0; j < Grid[i].size(); ++j) {
				if (Grid[i][j] == 0)
				{
					isFilled = false;
				}
			}
			if (isFilled)
			{
				Grid.erase(Grid.begin() + i);
				Grid.insert(Grid.begin(), row);
				completedRows++;
			}
		}
		if (completedRows != 0 && completedRows % 4 == 0)
		{
			sound.tetrisClear();
		}
		else if (completedRows != 0 && completedRows % 4 != 0)
		{
			sound.lineClear();
		}
	}
	//outputs number of completed rows
	int Board::getCompletedRows()
	{
		return completedRows;
	}
	//draws blocks to screen according to the index
	void Board::draw(sf::RenderWindow &window)
	{
		for (unsigned i = 0; i < 20; ++i) {
			for (unsigned j = 0; j < Grid[i].size(); ++j)
			{
				if (Grid[i][j] != 0)
				{
					gblocks.setTextureRect(sf::IntRect((Grid[i][j] - 1) * BlockSize, 0, BlockSize, BlockSize));
					gblocks.setPosition(316 + j * BlockSize, (i + 1) * BlockSize);
					window.draw(gblocks);
				}
			}
		}
	}
	//Initializes tetris Grid indexes to 0
	void Board::createGrid()
	{
		for (auto &rows : Grid)
		{
			for (auto &cols : rows)
			{
				cols = 0;
			}
		}
	}