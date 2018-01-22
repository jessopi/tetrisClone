#pragma once
#include <string>
#include "TGUI\TGUI.hpp"

/*
*	Pop up window that accepts a string from the user with a maximum of 10 characters
*	string is used as name for new highscore entry.
*/

class NameEntryWindow
{
public:

	//Recieves path for Black.txt theme & constructs buttons & nameBox
	NameEntryWindow(std::string, std::string);

	//Draws gui & text to the renderWindow
	void draw();

	//Outputs the entered name
	std::string enteredName();

	//destructor
	~NameEntryWindow();
private:

	//Function for confirmButton signal
	//playerName = Input , if input is empty playerName set to "Blank"
	void getName();

	//Constructs the confirm button
	void construct_confirmButton();

	//constructs the nameBox
	void construct_playerNameBox();

	//constructs text for display
	void construct_text();

	int playerScore;
	std::string playerName;

	//New renderwindow 
	sf::RenderWindow *window;
	
	tgui::Gui gui;
	sf::Event event;

	sf::Font font;
	sf::Text congrats;
	sf::Text info;

	//ptr for theme 
	tgui::Theme::Ptr theme;

	//tgui ptrs for objects
	tgui::EditBox::Ptr playerNameBox;
	tgui::Button::Ptr confirmButton;
};