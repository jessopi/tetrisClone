#include "HighScoreMenu.h"

HighScoreMenu::HighScoreMenu()
{
	theme = tgui::Theme::create("./Black.txt");
	state = displayScore;
	auto picture = tgui::Picture::create("./Images/t.png");
	picture->setSize(1024, 768);
	picture->setOpacity(.5);
	construct_playerNameList();
	construct_playerScoreList();
	gui.add(picture);
	contruct_backButton();

}
void HighScoreMenu::contruct_backButton()
{
	backButton = theme->load("Button");
	backButton->setSize(50, 50);
	backButton->setPosition(50, 100);
	backButton->setText("Back");
	backButton->connect("pressed", &HighScoreMenu::changeState, this, displayMenu);
	gui.add(backButton);
}
void HighScoreMenu::construct_playerNameList()
{
	//scoreBox = theme->load("ListBox");
	playerNameList = tgui::ListBox::create();
	playerNameList->setSize(200, 450);
	playerNameList->setPosition(200, 100);
	playerNameList->setItemHeight(35);

	auto boxsettings = playerNameList->getRenderer();
	boxsettings->setBackgroundColor(sf::Color::Black);
	boxsettings->setTextColor(sf::Color::White);
	boxsettings->setTextColorHover(sf::Color::White);
	boxsettings->setHoverBackgroundColor(sf::Color::Black);
	gui.add(playerNameList);
}
void HighScoreMenu::construct_playerScoreList()
{
	//scoreBox = theme->load("ListBox");
	playerScoreList = tgui::ListBox::create();
	playerScoreList->setSize(200, 450);
	playerScoreList->setPosition(700, 100);
	playerScoreList->setItemHeight(35);

	auto boxsettings = playerScoreList->getRenderer();
	boxsettings->setBackgroundColor(sf::Color::Black);
	boxsettings->setTextColor(sf::Color::White);
	boxsettings->setTextColorHover(sf::Color::White);
	boxsettings->setHoverBackgroundColor(sf::Color::Black);
	gui.add(playerScoreList);
}
void HighScoreMenu::getList(std::vector<std::pair<std::string,int>> &list)
{
	playerNameList->removeAllItems();
	playerScoreList->removeAllItems();
	for (auto &e : list)
	{
		playerNameList->addItem(e.first);
		playerScoreList->addItem(std::to_string(e.second));
	}
}
void HighScoreMenu::display(sf::RenderWindow & window,int currentState, gameSound &sound)
{
	state = (GameState)currentState;
	gui.setWindow(window);
	
	while (state == displayScore)
	{
		while (window.pollEvent(event))
		{
			// When the window is closed, the application ends
			if (event.type == sf::Event::Closed)
				window.close();
			// Pass the event to all the widgets
			gui.handleEvent(event);
		}

		window.clear();

		// Draw all created widgets
		gui.draw();
		window.display();

	}
	sound.playSFX("Select");
}