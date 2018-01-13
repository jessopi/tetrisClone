#include "Game.h"

Game::Game()
{
	popUpEntry = true;
	prevLevel = 1;
	isPaused = false;
	nameEntryWindow = new NameEntryWindow("./tguiTheme/blackButton.txt","./Font/courbd.ttf");
	highScoreMenu = new HighScoreMenu();
	mainMenu = new MainMenu();
	controlsMenu = new ControlsMenu();
	score = new Score("./Leaderboard/leaderBoard.dat");
	displayText = new DisplayText("./Font/courbd.ttf");
	board = new Board("./Images/blocks.png");
	controller = new Controller("./Images/blocks.png");
	sound = new gameSound("./Audio/gameTheme.ogg","./Audio/pause.wav","./Audio/blockRotation.wav",
		"./Audio/gameOver.wav","./Audio/collision.wav","./Audio/levelIncrease.wav","./Audio/lineClear.wav","./Audio/tetrisClear.wav"
		,"./Audio/select.wav","./Audio/newHighScore.wav");
	backgroundTexture.loadFromFile("./Images/backgroundFrame.png");
	background.setTexture(backgroundTexture);
	background.setPosition(280, 0);
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Tetris!", sf::Style::Close | sf::Style::Titlebar);
	timer = 0;
	time = 0;
	delay = 0.8F; //in milliseconds
	_gameState = Game::ShowingMenu;
}

//GameState loop
void Game::start()
{
	while (window->isOpen())
	{
		//Checks current _gamestate and chooses according case
		switch (_gameState)
		{
			//Plays mainMenu theme and goes to mainMenu
			case Game::ShowingMenu:
			{	
				sound->playMenuTheme();
				sound->endTheme();
				mainMenu->display(*window,_gameState,*sound);
				_gameState = (GameState)mainMenu->getState();
				break;
			}
			//Begins go tetris game and plays game music
			case::Game::Playing:
			{
				sound->endMenuTheme();
				sound->playTheme();
				gameplayLoop();
				break;
			}
			//Displays controlsMenu
			case::Game::displayingControls:
			{
				controlsMenu->display(*window, _gameState,*sound);
				_gameState = (GameState)controlsMenu->getState();
				break;
			}
			//Displays highScoresMenu & gets leaderboards from score
			case::Game::displayingHighScores:
			{
				highScoreMenu->getList(score->leaderBoard());
				highScoreMenu->display(*window,_gameState,*sound);
				_gameState = (GameState)highScoreMenu->getState();
				break;
			}
			//Called when game is over & new HS, updates leadbord and writes to file
			case::Game::GameEnding:
			{
				nameEntryWindow->draw();
				score->updateLeaderBoard(nameEntryWindow->enteredName());
				_gameState = Playing;
				break;
			}
			//Called when exit button is clicked in mainMenu
			case::Game::Exiting:
			{
				window->close();
				break;
			}
		}
	}
}

void Game::gameplayLoop() 
{
	//Polls user for input (Esc,Left,Right,Up,Down,P,Spacebar)
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
		
		//Conditionals for keyboard inputs
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
		{
			isPaused = !isPaused;
			sound->playSFX("Pause");
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
			sound->playSFX("Rotate");
			controller->movement(sf::Keyboard::Key::Up, board, *sound);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			_gameState = ShowingMenu;
			sound->playSFX("Pause");
			if (controller->isGameOver())
				reset();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && controller->isGameOver())
		{
			reset();
		}
	}

	//calculates time 
	time = clock.restart().asSeconds();
	timer += time;

	//If current time > current delay and game is not over or paused move block down 1 square
	if (timer > delay && !controller->isGameOver() && !isPaused)
	{
		timer = 0;
		controller->movement(sf::Keyboard::Key::Down, board, *sound);
	}
	
	//calls update & draw functions
	//To improve efficiency slightly check if gameisOver || paused in gameUpdate
	//No need to update when under those game conditions.
	gameUpdate();
	gameDraw();

	//if game is paused display text
	if (isPaused)
	{
		displayText->paused(*window);
	}

	//If gameOver and new highscore display messagebox & overText else just text
	if (controller->isGameOver())
	{
		sound->endTheme();

		if (score->isNewHighScore() && popUpEntry == true)
		{
			_gameState = GameEnding;
			popUpEntry = false;
			sound->playSFX("HighScore");
		}

		displayText->overText(*window);
	}
	
	window->display();
}

//draws functions for objects
void Game::gameDraw()
{
	window->clear();
	window->draw(background);
	controller->draw(*window);
	board->draw(*window);
	displayText->draw(*window);
}

//update functions for objects
void Game::gameUpdate()
{
	board->rowFull(*sound);
	score->getNumberOfRowsCleared(board->getCompletedRows());
	displayText->updateText(score->currentScore(), score->currentLevel());
	updateDelay(score->currentLevel());
}

//call reset for all classes/variable
void Game::reset()
{
	popUpEntry = true;
	displayText->reset();
	score->reset();
	board->reset();
	controller->reset();
	timer = 0;
	delay = 0.8F;
}

//decreases delay of blocks falling according to current level
void Game::updateDelay(int level)
{
	if (level > prevLevel)
	{
		sound->playSFX("LevelIncrease");
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