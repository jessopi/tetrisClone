#include "HighScoreMenu.h"

HighScoreMenu::HighScoreMenu()
{
	theme = tgui::Theme::create("./tguiTheme/blackButton.txt");
	state = displayScore;
	auto picture = tgui::Picture::create("./Images/menuBackground.png");
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
	backButton->setSize(70, 35);
	backButton->setPosition(25, 25);
	backButton->setText("Back");
	backButton->connect("pressed", &HighScoreMenu::changeState, this, displayMenu);
	gui.add(backButton);
}
void HighScoreMenu::construct_playerNameList()
{
	playerNameList = tgui::ListBox::create();
	playerNameList->setSize(200, 450);
	playerNameList->setPosition(250, 100);
	playerNameList->setItemHeight(38);

	auto boxsettings = playerNameList->getRenderer();
	boxsettings->setBackgroundColor(sf::Color::Black);
	boxsettings->setTextColor(sf::Color::White);
	boxsettings->setTextColorHover(sf::Color::White);
	boxsettings->setHoverBackgroundColor(sf::Color::Black);
	gui.add(playerNameList);
}
void HighScoreMenu::construct_playerScoreList()
{
	playerScoreList = tgui::ListBox::create();
	playerScoreList->setSize(200, 450);
	playerScoreList->setPosition(650, 100);
	playerScoreList->setItemHeight(38);

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
	
	while (state == displayScore && window.isOpen())
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