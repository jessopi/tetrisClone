#pragma once
#include "Board.h"
#include "Controller.h"
#include "Score.h"
//Class the contains the game loop and initializes other class objects
class Game
{
private:
	float time;
	sf::Sprite background;
	sf::Texture backgroundTexture;
	Score *text;
	Board *board;
	Controller *controller;
	sf::RenderWindow *window;
	sf::Clock clock;
	sf::Event event;
	float timer;
	float delay;
	bool isPaused;
	void updateDelay(int);
	void reset();
public:
	Game();
	void start();	
};