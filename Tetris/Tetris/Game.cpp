#include "Game.h"
Game::Game()
{
	isPaused = false;
	text = new Score("./Font/courbd.ttf");
	board = new Board("./Images/blocks.png");
	controller = new Controller("./Images/blocks.png");
	backgroundTexture.loadFromFile("./Images/Frame.png");
	background.setTexture(backgroundTexture);
	background.setPosition(280, 0);
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Tetris!", sf::Style::Close | sf::Style::Titlebar);
	timer = 0;
	time = 0;
	delay = 0.8F; //in milliseconds
}

void Game::start()
{
	while (window->isOpen())
	{
		
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				controller->movement(sf::Keyboard::Key::Right, board);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				controller->movement(sf::Keyboard::Key::Left, board);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				controller->movement(sf::Keyboard::Key::Down, board);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				controller->movement(sf::Keyboard::Key::Up, board);
			}
			
		}
		
				window->clear();
				time = clock.restart().asSeconds();
				timer += time;
				

				if (timer > delay && !controller->isGameOver())
				{
					timer = 0;
					controller->movement(sf::Keyboard::Key::Down, board);
				}

				board->rowFull();
				text->updateText(board->getCompletedRows(), board->getLevel());
				updateDelay(board->getLevel());

				window->draw(background);
				controller->draw(*window);
				board->draw(*window);
				text->draw(*window);

				//Display gameOver Text to the screen
				//need to add game->reset();
				if (controller->isGameOver())
				{
					text->overText(*window);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
					{
						reset();
					}
				}
				window->display();
	}
}
//call reset for all classes/variable
void Game::reset()
{
	text->reset();
	board->reset();
	controller->reset();
	timer = 0;
	delay = 0.8F;
}
//decreases delay of blocks falling according to current level
void Game::updateDelay(int level)
{
	switch (level)
	{
	case 1:
		delay = .80F;
		break;
	case 2:
		delay = .75F;
		break;
	case 3:
		delay = .70F;
		break;
	case 4:
		delay = .65F;
		break;
	case 5:
		delay = .60F;
		break;
	case 6:
		delay = .55F;
		break;
	case 7:
		delay = .50F;
		break;
	case 8:
		delay = .45F;
		break;
	case 9:
		delay = .40F;
		break;
	case 10:
		delay = .35F;
		break;
	default:
		break;
	}
}