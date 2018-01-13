#include "ControlsMenu.h"

ControlsMenu::ControlsMenu()
{
	theme = tgui::Theme::create("./Black.txt");
	state = displayControls;
	auto picture = tgui::Picture::create("./Images/t.png");
	picture->setSize(1024, 768);
	picture->setOpacity(.5);

	gui.add(picture);
	construct_textBox();
	construct_backButton();
}
void ControlsMenu::construct_backButton()
{
	backButton = theme->load("Button");
	backButton->setSize(50, 50);
	backButton->setPosition(50, 100);
	backButton->setText("Back");
	backButton->connect("pressed", &ControlsMenu::changeState, this, displayMenu);
	gui.add(backButton);
}
void ControlsMenu::construct_textBox()
{
	auto pic = tgui::Picture::create("./Images/r.png");
	gui.add(pic);
}
void ControlsMenu::display(sf::RenderWindow & window, int currentState,gameSound &sound)
{
	state = (GameState)currentState;
	gui.setWindow(window);

	while (state == displayControls)
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