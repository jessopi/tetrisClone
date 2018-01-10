#pragma once
#include <string>
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
	Controller(std::string s);
	void draw(sf::RenderWindow &);
	void drawNext(sf::RenderWindow &);
	void getNewBlock();
	void movement(sf::Keyboard::Key , Board* ,gameSound &);
	bool isGameOver();
	bool endGameCollision(Board );
	void reset();
private:
	bool gameOver;
	bool collision(Board );
	sf::Texture texture;
	std::vector<std::vector<int>> currentShape;
	std::vector<std::vector<int>> nextShape;
	Tetromino next;
	Tetromino current;
	BlockCreation rTet;
	sf::Vector2f currentPos;
	float BlockSize = 35;
};