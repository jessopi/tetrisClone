#pragma once
#include "Ui.h"
#include <algorithm>

/*
*	Menu Screen for showing the top 10 leaderboard
*	Contains two ListBoxes holding playerName & score
*/
class HighScoreMenu : public Ui
{
public:

	//Initializes objects & sets background Image
	HighScoreMenu();

	//Displays listbox data to screen
	void display(sf::RenderWindow &,int, gameSound &);
	
	//Retrieves vector containing leaderboard data
	void getList(std::vector<std::pair<std::string, int>> &);
private:

	//Functions for constructing button & boxes
	void contruct_backButton();
	void construct_playerNameList();
	void construct_playerScoreList();

	//Ptrs for tgui objects
	tgui::Button::Ptr backButton;
	tgui::ListBox::Ptr playerNameList;
	tgui::ListBox::Ptr playerScoreList;
};