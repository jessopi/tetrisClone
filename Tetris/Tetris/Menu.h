#pragma once
#include "Ui.h"
#include "gameSound.h"
class Menu : public Ui
{
public:
	Menu();
	void display(sf::RenderWindow &,int,gameSound &);
private:
	void construct_playButton();
	void construct_scoreButton();
	void construct_controlButton();
	void construct_exitButton();

	tgui::Button::Ptr playButton;
	tgui::Button::Ptr scoreButton;
	tgui::Button::Ptr controlButton;
	tgui::Button::Ptr exitButton;
};