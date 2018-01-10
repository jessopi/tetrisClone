#pragma once
#include "Ui.h"
class HighScores : public Ui
{
public:
	HighScores() ;
	void display(sf::RenderWindow &,int, gameSound &);
private:
	void contruct_backButton();
	void construct_scoreBox();
	tgui::Button::Ptr backButton;
	tgui::ListBox::Ptr scoreBox;
};