#pragma once
#include "Ui.h"

/*
*	Menu that displays the controls for the game using a png
*/
class ControlsMenu : public Ui
{
public:

	//Loads in texture for button & picture and contructs button
	ControlsMenu();

	//Displays window & gui to screen
	void display(sf::RenderWindow &, int,gameSound &);

private:

	//constructs the back button to return to the mainMenu
	void construct_backButton();

	//loads picture for text
	void construct_textBox();

	tgui::Button::Ptr backButton;
};