#pragma once
#include <string>
#include "TGUI\TGUI.hpp"
class Popup
{
public:
	Popup(std::string);
	void draw();
	std::string enteredName();
private:
	void getName();
	void construct_confirmButton();
	void construct_playerNameBox();
	std::string playerName;
	int playerScore;
	sf::RenderWindow *window;
	tgui::Gui gui;
	sf::Text f;
	sf::Font font;
	sf::Text f1;
	sf::Event event;
	tgui::Theme::Ptr theme;
	tgui::EditBox::Ptr playerNameBox;
	
	tgui::Button::Ptr confirmBUtton;
};