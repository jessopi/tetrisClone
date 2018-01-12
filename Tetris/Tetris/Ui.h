#pragma once
#include "TGUI\TGUI.hpp"
#include "gameSound.h"
//abstract
class Ui
{
public:
	//Ui(){}
	virtual void display(sf::RenderWindow &, int,gameSound &) = 0;
	int getState()
	{
		return state;
	}
protected:
	enum GameState
	{
		displayMenu, displayGame, displayScore, displayControls, Exit = 5
	};
	GameState state;
	void changeState(GameState input)
	{
		state = input;
	}
	tgui::Theme::Ptr theme;
	tgui::Theme::Ptr theme2;
	sf::Event event;
	tgui::Gui gui;
};