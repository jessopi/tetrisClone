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

	//testing new feature
	void swapTetromino();

	//resets variables and gets new blocks
	void reset();

private:

	//draws the next block in the display window
	void drawNext(sf::RenderWindow &);

	//draw hold block to the screen
	void drawHold(sf::RenderWindow &);

	//checks if the current tetromino collides with boundries/other tetrominos
	bool collision(Board);

	bool holdIsEmpty;
	bool hasBeenSwapped;
	bool gameOver;

	sf::Texture texture;

	//holds tetromino shapes
	std::vector<std::vector<int>> currentShape;
	std::vector<std::vector<int>> nextShape;
	std::vector<std::vector<int>> holdShape;

	Tetromino next;
	Tetromino current;
	Tetromino hold;

	BlockCreation tetrominoBag;
	sf::Vector2f currentPos;
	float BlockSize = 35;
};