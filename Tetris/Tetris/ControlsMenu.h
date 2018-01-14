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

	void construct_keyBinds();
	void construct_keyBindInfo();


	//Object pts
	tgui::Button::Ptr backButton;
	tgui::ListBox::Ptr keyBinds;
	tgui::ListBox::Ptr keybindInfo;
};