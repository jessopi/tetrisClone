#include "MainMenu.h"

MainMenu::MainMenu()
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
void MainMenu::construct_playButton()
{
	playButton = theme->load("Button");
	playButton->setSize(200, 50);
	playButton->setPosition(400, 100);
	playButton->setText("Play");
	playButton->connect("pressed", &MainMenu::changeState, this, displayGame);
	gui.add(playButton);
}
void MainMenu::construct_scoreButton()
{
	scoreButton = theme->load("Button");
	scoreButton->setSize(200, 50);
	scoreButton->setPosition(400, 200);
	scoreButton->setText("HighScores");
	scoreButton->connect("pressed", &MainMenu::changeState, this, displayScore);
	gui.add(scoreButton);
}
void MainMenu::construct_controlButton()
{
	controlButton = theme->load("Button");
	controlButton->setSize(200, 50);
	controlButton->setPosition(400, 300);
	controlButton->setText("Controls");
	controlButton->connect("pressed", &MainMenu::changeState, this, displayControls);
	gui.add(controlButton);
}
void MainMenu::construct_exitButton()
{
	exitButton = theme->load("Button");
	exitButton->setSize(200, 50);
	exitButton->setPosition(400, 400);
	exitButton->setText("Exit");
	exitButton->connect("pressed", &MainMenu::changeState, this, Exit);
	gui.add(exitButton);
}
void MainMenu::display(sf::RenderWindow &window,int currentState, gameSound &sound)
{
	state = (GameState)currentState;
	gui.setWindow(window);
	while (state == displayMenu && window.isOpen())
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