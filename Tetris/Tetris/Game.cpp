#include "Game.h"
#include <iostream>
#include "SFML\Graphics.hpp"]
#include "TGUI\TGUI.hpp"

Game::Game()
{
	popUpEntry = true;
	prevLevel = 1;
	isPaused = false;
	pu = new Popup("./Black.txt");
	h = new HighScores();
	m = new Menu();
	c = new Controls();
	score = new Score("./leaderBoard.dat");
	text = new DisplayText("./Font/courbd.ttf");
	board = new Board("./Images/blocks.png");
	controller = new Controller("./Images/blocks.png");
	sound = new gameSound("./Audio/theme.ogg","./Audio/pause.wav","./Audio/block-rotate.wav",
		"./Audio/gameOver.wav","./Audio/landed.wav","./Audio/lvlup.wav","./Audio/normalClear.wav","./Audio/tetrisClear.wav");
	backgroundTexture.loadFromFile("./Images/Frame1.png");
	background.setTexture(backgroundTexture);
	background.setPosition(280, 0);
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Tetris!", sf::Style::Close | sf::Style::Titlebar);
	timer = 0;
	time = 0;
	delay = 0.8F; //in milliseconds
	_gameState = Game::ShowingMenu;
}

void Game::start()
{
	while (window->isOpen())
	{
		switch (_gameState)
		{
			case Game::ShowingMenu:
			{	
				sound->playMenuTheme();
				sound->endTheme();
				m->display(*window,_gameState,*sound);
				_gameState = (GameState)m->getState();
				break;
			}
			case::Game::Playing:
			{
				sound->endMenuTheme();
				sound->playTheme();
				loop();
				break;
			}
			case::Game::displayingControls:
			{
				c->display(*window, _gameState,*sound);
				_gameState = (GameState)c->getState();
				break;
			}
			case::Game::displayingHighScores:
			{
				h->getList(score->leaderBoard());
				h->display(*window,_gameState,*sound);
				_gameState = (GameState)h->getState();
				break;
			}
			case::Game::GameEnding:
			{
				//needs to add bgm for highscore!;
				//popup needs to take in sound object for confirm button
				pu->draw();
				score->updateLeaderBoard(pu->enteredName());
				_gameState = Playing;
				break;
			}
			case::Game::Exiting:
			{
				window->close();
				break;
			}
		}
	}
}

void Game::loop() 
{
	
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed )
			window->close();
		//pauses game
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
		{
			isPaused = !isPaused;
			sound->playPauseSound();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !isPaused)
		{
			controller->movement(sf::Keyboard::Key::Right, board, *sound);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !isPaused)
		{
			controller->movement(sf::Keyboard::Key::Left, board, *sound);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !isPaused)
		{
			controller->movement(sf::Keyboard::Key::Down, board, *sound);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !isPaused)
		{
			sound->rotationSFX();
			controller->movement(sf::Keyboard::Key::Up, board, *sound);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			_gameState = ShowingMenu;
			sound->playPauseSound();
		}
	}

	time = clock.restart().asSeconds();
	timer += time;

	if (timer > delay && !controller->isGameOver() && !isPaused)
	{
		timer = 0;
		controller->movement(sf::Keyboard::Key::Down, board, *sound);
	}

	board->rowFull(*sound);

	score->getNumberOfRowsCleared(board->getCompletedRows());
	text->updateText(score->currentScore(), score->currentLevel());
	updateDelay(score->currentLevel());
	window->clear();
	window->draw(background);
	controller->draw(*window);
	board->draw(*window);
	text->draw(*window);

	if (isPaused)
	{
		text->paused(*window);
	}

	//Display gameOver Text to the screen

	
	if (controller->isGameOver())
	{
		sound->endTheme();
		sound->gameOver();
		if (score->isNewHighScore() && popUpEntry == true)
		{
			_gameState = GameEnding;
			popUpEntry = false;
		}

		//still a problem needs to sound once!, create a checker in sound->gameOver(class)
		//sound->gameOver();



		//fix what overText says
		//Spacebar to play again, Esc to go to main menu;
		//when hitting esc game should reset;
		text->overText(*window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			reset();
		}
	}
	window->display();

}
//call reset for all classes/variable
void Game::reset()
{
	popUpEntry = true;
	text->reset();
	score->reset();
	board->reset();
	controller->reset();
	//sound->playTheme();
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