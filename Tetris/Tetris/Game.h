#pragma once
#include "Board.h"
#include "Controller.h"
#include "DisplayText.h"
#include "gameSound.h"
#include "ControlsMenu.h"
#include "MainMenu.h"
#include "HighScoreMenu.h"
#include "Score.h"
#include "NameEntryWindow.h"

//Class the contains the game loop and initializes other class objects
class Game
{
private:

	//Holds the total clock time
	float timer;

	//How many seconds should pass before block moves down
	float delay;

	//checks if the game is pauseed
	bool isPaused;

	//decreases the delay depending on current level
	void updateDelay(int);

	//calls draw functions for objects
	void gameDraw();

	//calls update functions for objects
	void gameUpdate();

	//calls reset functions of other objects and some member variables
	void reset();

	//Loop for the game
	void gameplayLoop();
	
	//Set to true, allows nameEntryWindow to be called only once per game
	bool popUpEntry;
	
	//holds time in seconds
	float time;

	//holds prevLevel for update delay check
	int prevLevel;

	//object holding background texture for board
	sf::Sprite background;

	//loads in texture from file
	sf::Texture backgroundTexture;

	//OBJECTS
	DisplayText *displayText;
	Board *board;
	Controller *controller;
	gameSound *sound;
	MainMenu  *mainMenu;
	HighScoreMenu *highScoreMenu;
	ControlsMenu *controlsMenu;
	Score *score;
	NameEntryWindow *nameEntryWindow;
	

	//renderwindow for game
	sf::RenderWindow *window;

	//Clock object
	sf::Clock clock;

	//holds keyboard events
	sf::Event event;

	//Gamestate enums
	enum GameState 
	{ShowingMenu, Playing, displayingHighScores, displayingControls, GameEnding, Exiting};
	GameState _gameState;

public:

	//Initializes objects and variables
	Game();

	//begins the initial game loop
	void start();	
};