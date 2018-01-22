#include "NameEntryWindow.h"

NameEntryWindow::NameEntryWindow(std::string themepath,std::string fontpath)
{
	theme = tgui::Theme::create(themepath);
	playerName = "";

	construct_confirmButton();
	construct_playerNameBox();
	font.loadFromFile(fontpath);
	construct_text();
	//loads text font
}

void NameEntryWindow::construct_confirmButton()
{
	confirmButton = theme->load("Button");
	confirmButton->setSize(180, 30);
	confirmButton->setPosition(55,130);
	confirmButton->setText("Confirm");
	confirmButton->connect("Pressed", &NameEntryWindow::getName,this);
	gui.add(confirmButton);
}
void NameEntryWindow::construct_playerNameBox()
{
	playerNameBox = theme->load("EditBox");
	playerNameBox->setSize(200, 35);
	playerNameBox->setPosition(45, 80);
	playerNameBox->setDefaultText("Nickname");
	playerNameBox->setMaximumCharacters(10);
	gui.add(playerNameBox, "Username");
}
void NameEntryWindow::construct_text()
{
	congrats.setFont(font);
	congrats.setString("		 Congratulations!\n	  You're in the top 10!");
	congrats.setCharacterSize(15);
	congrats.setFillColor(sf::Color::White);
	congrats.setPosition(0, 5);

	info.setFont(font);
	info.setString("	Enter your nickname below.");
	info.setCharacterSize(15);
	info.setFillColor(sf::Color::White);
	info.setPosition(0, 45);
}
std::string NameEntryWindow::enteredName()
{
	return playerName;
}
void NameEntryWindow::getName()
{
	playerName = playerNameBox->getText().toAnsiString();

	if (playerName.empty())
		playerName = "Blank";

	window->close();
}
void NameEntryWindow::draw()
{
	//window is initialized here so it dosnt show up when object is constructed
	window = new sf::RenderWindow(sf::VideoMode(300, 175), "LeaderBoard Entry", sf::Style::Titlebar );
	gui.setWindow(*window);
	
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			gui.handleEvent(event);
		}


		window->clear();
		gui.draw();
		window->draw(congrats);
		window->draw(info);

		window->display();
	}
}

NameEntryWindow::~NameEntryWindow()
{
	delete window;
}