#pragma once
#include <vector>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <algorithm>
#include "gameSound.h"
/*
*	Mananges Tetris grid (drawing,deleting rows and adding score)
*	
*/
class Board
{
public:
	std::vector<std::vector<int>> Grid; //May need to add accessor for vector
	Board();
	Board(std::string );
	void draw(sf::RenderWindow &);
	int getCompletedRows();
	void rowFull(gameSound &sound);
	int getLevel();
	void reset();
private:
	sf::RectangleShape gblocks;
	sf::Texture texture;
	float BlockSize;	
	void createGrid();
	int completedRows;
	int totalCompletedRows;
};