#include "Game.h"
#include <iostream>
Game::Game()
{
	prevLevel = 1;
	isPaused = false;
	text = new Score("./Font/courbd.ttf");
	board = new Board("./Images/blocks.png");
	controller = new Controller("./Images/blocks.png");
	sound = new gameSound("./Audio/theme.ogg","./Audio/pause.wav","./Audio/block-rotate.wav",
		"./Audio/gameOver.wav","./Audio/landed.wav","./Audio/lvlup.wav","./Audio/normalClear.wav","./Audio/tetrisClear.wav");
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
	/* Sounds to be added in

		block collision with another block(below block collision)
		sound on rotation
		pausing the game sound
		gameover Sound
		default clearing lines sound
		clearing 4 lines sound (needs to be similar to default but more impressive)

		bgm louder or quieter than sound effects?
	*/
	//loud need to add option to turn music down in menu (possible feature in future)
	sound->playTheme();
	while (window->isOpen())
	{	
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window->close();
			//pauses game
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
			{
				isPaused = !isPaused;
				sound->playPauseSound();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !isPaused)
			{
				controller->movement(sf::Keyboard::Key::Right, board,*sound);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !isPaused)
			{
				controller->movement(sf::Keyboard::Key::Left, board,*sound);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !isPaused)
			{
				controller->movement(sf::Keyboard::Key::Down, board,*sound);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !isPaused)
			{
				sound->rotationSFX();
				controller->movement(sf::Keyboard::Key::Up, board,*sound);
			}
		}
			
				window->clear();
				time = clock.restart().asSeconds();
				timer += time;
				

				if (timer > delay && !controller->isGameOver() && !isPaused)
				{
					timer = 0;
					controller->movement(sf::Keyboard::Key::Down, board,*sound);
				}

				board->rowFull(*sound);
				text->updateText(board->getCompletedRows(), board->getLevel());
				updateDelay(board->getLevel());

				window->draw(background);
				controller->draw(*window);
				board->draw(*window);
				text->draw(*window);
				
				if(isPaused)
				{
					text->paused(*window);		
				}
				
				//Display gameOver Text to the screen
			
				if (controller->isGameOver())
				{
					text->overText(*window);
					sound->endTheme();

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
					{
						reset();
						sound->gameOver(); //<- move in class
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
	sound->playTheme();
	timer = 0;
	delay = 0.8F;
}
//decreases delay of blocks falling according to current level
void Game::updateDelay(int level)
{
	if (level > prevLevel)
	{
		//sound is not very good quality and slightly too long
		sound->levelIncrease();
		prevLevel = level;
	}
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