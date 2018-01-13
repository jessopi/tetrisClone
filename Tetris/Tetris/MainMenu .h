#pragma once

#include "Ui.h"
#include "gameSound.h"

/*
*	Derived Class of Ui
*	Handles the main menu of tetrisClone
*	Contains buttons connected with signals that point to game,controls,highscores and exit
*/

class MainMenu : public Ui
{
public:

	//initializes buttons
	MainMenu();

	//Displays buttons to screen along with select sound when clicked
	//Parameters (ref of renderwindow, current gameState , gameSound ref)
	void display(sf::RenderWindow &, int, gameSound &);

private:

	//contructs buttons
	void construct_playButton();
	void construct_scoreButton();
	void construct_controlButton();
	void construct_exitButton();

	//tgui ptrs of objects
	tgui::Button::Ptr playButton;
	tgui::Button::Ptr scoreButton;
	tgui::Button::Ptr controlButton;
	tgui::Button::Ptr exitButton;
};