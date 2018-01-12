#include "PopUp.h"

Popup::Popup(std::string path)
{
	theme = tgui::Theme::create(path);
	playerName = "";
	auto picture = tgui::Picture::create("./Images/mm.png");
//	gui.add(picture);
	construct_confirmButton();
	construct_playerNameBox();
	font.loadFromFile("./Font/courbd.ttf");

	

	picture->setSize(500, 200);
}

void Popup::construct_confirmButton()
{
	confirmBUtton = theme->load("Button");
	confirmBUtton->setSize(180, 30);
	confirmBUtton->setPosition(55,130);
	confirmBUtton->setText("Confirm");
	confirmBUtton->connect("Pressed", &Popup::getName,this);
	gui.add(confirmBUtton);
}
void Popup::construct_playerNameBox()
{
	f.setFont(font);
	f.setString("		 Congratulations!\n	  You're in the top 10!");
	f.setCharacterSize(15);
	f.setFillColor(sf::Color::White);
	f.setPosition(0,5 );

	f1.setFont(font);
	f1.setString("	Enter your nickname below.");
	f1.setCharacterSize(15);
	f1.setFillColor(sf::Color::White);
	f1.setPosition(0, 45);



	playerNameBox = theme->load("EditBox");
	playerNameBox->setSize(200, 35);
	playerNameBox->setPosition(45, 80);
	playerNameBox->setDefaultText("Nickname");
	playerNameBox->setMaximumCharacters(10);
	gui.add(playerNameBox, "Username");
}
std::string Popup::enteredName()
{
	return playerName;
}
void Popup::getName()
{
	playerName = playerNameBox->getText().toAnsiString();
	std::cout << playerName << std::endl;
	window->close();
}
void Popup::draw()
{
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
		window->draw(f);
		window->draw(f1);

		window->display();
	}
}