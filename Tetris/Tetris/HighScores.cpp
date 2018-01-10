#include "HighScores.h"

HighScores::HighScores()
{
	theme = tgui::Theme::create("./Black.txt");
	state = displayScore;
	auto picture = tgui::Picture::create("./Images/t.png");
	picture->setSize(1024, 768);
	picture->setOpacity(.5);
	construct_scoreBox();

	gui.add(picture);
	contruct_backButton();

}
void HighScores::contruct_backButton()
{
	backButton = theme->load("Button");
	backButton->setSize(50, 50);
	backButton->setPosition(50, 100);
	backButton->setText("Back");
	backButton->connect("pressed", &HighScores::changeState, this, displayMenu);
	gui.add(backButton);
}
//temp until db is added
void HighScores::construct_scoreBox()
{
	//scoreBox = theme->load("ListBox");
	scoreBox = tgui::ListBox::create();
	scoreBox->setSize(400, 450);
	scoreBox->setPosition(300, 100);
	scoreBox->addItem("");
	scoreBox->addItem("Ian						45,000");
	scoreBox->addItem("");
	scoreBox->addItem("Ian						37,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						36,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						35,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						34,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						33,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						32,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						31,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						30,000");
	scoreBox->addItem("");

	scoreBox->addItem("Ian						29,000");
	scoreBox->setTextSize(35);
	auto boxsettings = scoreBox->getRenderer();
	boxsettings->setBackgroundColor(sf::Color::Black);
	boxsettings->setTextColor(sf::Color::White);
	boxsettings->setTextColorHover(sf::Color::White);
	boxsettings->setHoverBackgroundColor(sf::Color::Black);

	gui.add(scoreBox);
}
void HighScores::display(sf::RenderWindow & window,int currentState, gameSound &sound)
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
	sound.select();
}