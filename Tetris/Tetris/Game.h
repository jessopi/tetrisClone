#pragma once
#include "Board.h"
#include "Ui.h"
#include "Controller.h"
#include "DisplayText.h"
#include "gameSound.h"
#include "Controls.h"
#include "MainMenu .h"
#include "HighScores.h"
#include "Score.h"
#include "NameEntryWindow.h"
//Class the contains the game loop and initializes other class objects
class Game
{
private:
	bool popUpEntry;
	float time;
	int prevLevel;
	sf::Sprite background;
	sf::Texture backgroundTexture;
	DisplayText *text;
	Board *board;
	Controller *controller;
	gameSound *sound;
	MainMenu  *m;
	HighScores *h;
	Controls *c;
	Score *score;
	NameEntryWindow *pu;
	sf::RenderWindow *window;
	sf::Clock clock;
	sf::Event event;
	float timer;
	float delay;
	bool isPaused;
	void updateDelay(int);
	void reset();
	enum GameState 
	{ShowingMenu, Playing, displayingHighScores, displayingControls, GameEnding, Exiting};
	void loop();
	GameState _gameState;

public:
	Game();
	void start();	
};