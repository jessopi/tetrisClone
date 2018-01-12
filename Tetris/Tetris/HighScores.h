#pragma once
#include "Ui.h"
class HighScores : public Ui
{
public:
	HighScores() ;
	void display(sf::RenderWindow &,int, gameSound &);
	void getList(std::vector<std::pair<std::string, int>> &);
private:
	void contruct_backButton();
	void construct_scoreBox();
	tgui::Button::Ptr backButton;
	tgui::ListBox::Ptr scoreBox;
};