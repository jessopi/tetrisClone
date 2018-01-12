#include "Menu.h"

Menu::Menu()
{
	state = displayMenu;
	theme = tgui::Theme::create("./Black.txt");
	auto picture = tgui::Picture::create("./Images/t.png");
	picture->setSize(1024, 768);
	gui.add(picture);

	construct_playButton();
	construct_scoreButton();
	construct_controlButton();
	construct_exitButton();
	

}
void Menu::construct_playButton()
{
	playButton = theme->load("Button");
	playButton->setSize(200, 50);
	playButton->setPosition(400, 100);
	playButton->setText("Play");
	playButton->connect("pressed", &Menu::changeState, this, displayGame);
	gui.add(playButton);
}
void Menu::construct_scoreButton()
{
	scoreButton = theme->load("Button");
	scoreButton->setSize(200, 50);
	scoreButton->setPosition(400, 200);
	scoreButton->setText("HighScores");
	scoreButton->connect("pressed", &Menu::changeState, this, displayScore);
	gui.add(scoreButton);
}
void Menu::construct_controlButton()
{
	controlButton = theme->load("Button");
	controlButton->setSize(200, 50);
	controlButton->setPosition(400, 300);
	controlButton->setText("Controls");
	controlButton->connect("pressed", &Menu::changeState, this, displayControls);
	gui.add(controlButton);
}
void Menu::construct_exitButton()
{
	exitButton = theme->load("Button");
	exitButton->setSize(200, 50);
	exitButton->setPosition(400, 400);
	exitButton->setText("Exit");
	exitButton->connect("pressed", &Menu::changeState, this, Exit);
	gui.add(exitButton);
}
void Menu::display(sf::RenderWindow &window,int currentState, gameSound &sound)
{
	state = (GameState)currentState;
	gui.setWindow(window);
	while (state == displayMenu)
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