#pragma once
#include "TGUI\TGUI.hpp"
#include "gameSound.h"

/*
*	Abstact class to be used in gui classes
*/
class Ui
{
public:

	//Ui(){}
	virtual void display(sf::RenderWindow &, int,gameSound &) = 0;
	//outputs what state the game is in
	int getState()
	{
		return state;
	}
protected:

	//Enums for gameStates, Exit is set to 5 since gameOver is 4 and not available in classs
	enum GameState
	{
		displayMenu, displayGame, displayScore, displayControls, Exit = 5
	};
	GameState state;

	//Linked with button signals
	void changeState(GameState input)
	{
		state = input;
	}

	tgui::Theme::Ptr theme;
	tgui::Theme::Ptr theme2;

	sf::Event event;
	tgui::Gui gui;
};