#include "ControlsMenu.h"

ControlsMenu::ControlsMenu()
{
	theme = tgui::Theme::create("./tguiTheme/blackButton.txt");
	state = displayControls;
	auto picture = tgui::Picture::create("./Images/menuBackground.png");
	picture->setSize(1024, 768);
	picture->setOpacity(.5);
	construct_keyBinds();
	construct_keyBindInfo();
	gui.add(picture);
	construct_backButton();
}
void ControlsMenu::construct_backButton()
{
	backButton = theme->load("Button");
	backButton->setSize(70, 35);
	backButton->setPosition(25, 25);
	backButton->setText("Back");
	backButton->connect("pressed", &ControlsMenu::changeState, this, displayMenu);
	gui.add(backButton);
}

void ControlsMenu::construct_keyBinds()
{
	keyBinds = tgui::ListBox::create();
	keyBinds->setSize(200, 450);
	keyBinds->setPosition(212, 120);
	keyBinds->setItemHeight(40);

	auto boxsettings = keyBinds->getRenderer();
	boxsettings->setBackgroundColor(sf::Color::Black);
	boxsettings->setTextColor(sf::Color::White);
	boxsettings->setTextColorHover(sf::Color::White);
	boxsettings->setHoverBackgroundColor(sf::Color::Black);

	keyBinds->addItem("Up Arrow");
	keyBinds->addItem("Left Arrow");
	keyBinds->addItem("Right Arrow");
	keyBinds->addItem("Down Arrow");
	keyBinds->addItem("Esc");
	keyBinds->addItem("P");
	gui.add(keyBinds);
}
void ControlsMenu::construct_keyBindInfo()
{
	keybindInfo = tgui::ListBox::create();
	keybindInfo->setSize(250, 450);
	keybindInfo->setPosition(612, 120);
	keybindInfo->setItemHeight(40);

	auto boxsettings = keybindInfo->getRenderer();
	boxsettings->setBackgroundColor(sf::Color::Black);
	boxsettings->setTextColor(sf::Color::White);
	boxsettings->setTextColorHover(sf::Color::White);
	boxsettings->setHoverBackgroundColor(sf::Color::Black);

	keybindInfo->addItem("Rotate Block");
	keybindInfo->addItem("Move Left");
	keybindInfo->addItem("Move Right");
	keybindInfo->addItem("Move Down");
	keybindInfo->addItem("Return to Menu");
	keybindInfo->addItem("Pause");

	gui.add(keybindInfo);
}
void ControlsMenu::display(sf::RenderWindow & window, int currentState,gameSound &sound)
{
	state = (GameState)currentState;
	gui.setWindow(window);

	while (state == displayControls && window.isOpen())
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