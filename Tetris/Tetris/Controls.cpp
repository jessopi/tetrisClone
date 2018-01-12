#include "Controls.h"

Controls::Controls()
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
void Controls::construct_backButton()
{
	backButton = theme->load("Button");
	backButton->setSize(50, 50);
	backButton->setPosition(50, 100);
	backButton->setText("Back");
	backButton->connect("pressed", &Controls::changeState, this, displayMenu);
	gui.add(backButton);
}
void Controls::construct_textBox()
{
	auto pic = tgui::Picture::create("./Images/r.png");
	gui.add(pic);
	/*
	textBox = tgui::TextBox::create();
	textBox->setPosition(150, 100);
	textBox->setSize(700, 700);
	textBox->setReadOnly(true);
	textBox->addText("Up key roates the block counter clockwise.\n");
	textBox->addText("Left key moves the block left\n");
	textBox->addText("Right key moves the block right\n");
	textBox->addText("Down key moves the block down\n");
	textBox->addText("P key pauses the game\n");
	textBox->addText("Esc returns to the main menu\n");
	textBox->addText("\n");
	textBox->addText("created by Ian Jessop");
	textBox->setTextSize(35);
	auto thing = textBox->getRenderer();
	thing->setBackgroundColor(sf::Color::Black);
	thing->setTextColor(sf::Color::White);
	gui.add(textBox);*/
}
void Controls::display(sf::RenderWindow & window, int currentState,gameSound &sound)
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