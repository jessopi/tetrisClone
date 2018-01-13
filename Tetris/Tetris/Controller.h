#pragma once
#include <SFML\Graphics.hpp>
#include "Board.h"
#include "gameSound.h"
#include "Tetromino.h"
#include "BlockCreation.h"

/*
*	Manages current tetrominos movement & collision
*/
class Controller
{
public:

	//loads block texture from file and calls getNewBlock
	Controller(std::string s);

	//draws the current shape to the screen
	void draw(sf::RenderWindow &);

	//draws the next block in the display window
	void drawNext(sf::RenderWindow &);

	//sets gets new block and gets the matrix for it
	//does the same with next block
	void getNewBlock();

	//Checks input and checks if any collisions occured
	//If true then move block back to original position
	//If collision with block occurs set board->grid = shape[][];
	void movement(sf::Keyboard::Key , Board* ,gameSound &);

	//Returns status of game
	bool isGameOver();

	//Is called after first collision to check if blocks are still colliding
	//If true then game is over
	bool endGameCollision(Board);

	//resets variables and gets new blocks
	void reset();

private:
	bool gameOver;
	bool collision(Board );
	sf::Texture texture;
	std::vector<std::vector<int>> currentShape;
	std::vector<std::vector<int>> nextShape;
	Tetromino next;
	Tetromino current;
	BlockCreation tetrominoBag;
	sf::Vector2f currentPos;
	float BlockSize = 35;
};