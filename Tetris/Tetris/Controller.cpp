#include "Controller.h"
	Controller::Controller(std::string s) : rTet(), current()
	{
		texture.loadFromFile(s);
		getNewBlock();
		gameOver = false;
		
	};
	void Controller::getNewBlock()
	{
		current = rTet.nextBlock();
		currentPos.x = 3;
		currentPos.y = 0;
		this->Shape = current.getShape();
	}
	void Controller::reset()
	{
		gameOver = false;
		rTet.reset();
		getNewBlock();
	}
	//draws the current shape to screen
	void Controller::draw(sf::RenderWindow &window)
	{
		for (unsigned i = 0; i < Shape.size(); ++i) {
			for (unsigned j = 0; j < Shape[0].size(); ++j) {
				if (Shape[i][j]) {
					sf::RectangleShape Block(sf::Vector2f(BlockSize, BlockSize));
					Block.setTexture(&texture);
					Block.setTextureRect(this->current.blockColor());
					Block.setPosition(316 + (currentPos.x + j) * BlockSize, (currentPos.y + i) * BlockSize);
					window.draw(Block);
				}
			}
		}
	}
	bool Controller::isGameOver()
	{
		return gameOver;
	}
	//temp fix for checking if game is over after 2nd collision (first collision function not working as intended)
	bool Controller::endGameCollision(Board board)
	{
		//below blocks
		for (size_t i = 0; i < Shape.size(); i++)
		{
			for (size_t j = 0; j < Shape[0].size(); j++)
			{
				if (Shape[i][j] != 0 && board.Grid[(int)currentPos.y + i - 1][(int)currentPos.x + j] != 0)
				{
					
					return false;
				}		
			}
		}

		return true;
	}
	//Handles movement depending on keyboard event
	void Controller::movement(sf::Keyboard::Key input, Board* board, gameSound &sound)
	{
		//Exits function if game is over
		if (gameOver)
			return;

		//switch case the checks collisions and moves block back if one occurs
		switch (input)
		{
			case sf::Keyboard::Key::Left:
			{
				currentPos.x--;
				if (!collision(*board))
					currentPos.x++;
				break;
			}
			case sf::Keyboard::Key::Right:
			{
				currentPos.x++;
				if (!collision(*board))
					currentPos.x--;
				break;
			}
			case::sf::Keyboard::Key::Up:
			{
				this->Shape = current.clockWiseRotation();
				if (!collision(*board))
					this->Shape = current.counterClockWiseRotation();
				break;
			}
			case::sf::Keyboard::Key::Down:
			{
				currentPos.y++;
				//if collision occurs copy index value of shape to the corresponding grid location
				if (!collision(*board))
				{
					currentPos.y--;

					for (size_t i = 0; i < Shape.size(); i++) {
						for (size_t j = 0; j < Shape[0].size(); j++) {
							if (Shape[i][j]) {
								board->Grid[(int)currentPos.y + i - 1][(int)currentPos.x + j] = Shape[i][j];
							}

						}
					}

					//get the next block
					sound.landed();
					getNewBlock();

					//if collision is still occuring after moveback then the game is over
					if (!endGameCollision(*board))
					{
						gameOver = true;
						return;
					}

					break;
				}
			}
		}
	}
	//Checks for collision during tetromino movement (Ceiling/Walls/Floors/Objects)
	bool Controller::collision(Board board)
	{
		//Checks if block has gone beyond left wall
		if (currentPos.x < 0)
		{
			for (auto &e : Shape)
			{
				if (e[-(int)currentPos.x - 1])
				{
					return false;
				}
			}
		}
		// Checks if block has gone beyond right wall
		if (currentPos.x + Shape[0].size() > 10) 
		{
			for (auto &Row : Shape) 
			{
				if (Row[10 - (int)currentPos.x]) 
				{
					return false;
				}
			}
		}
		//Checks if object has reached the bottom of the playing field
		for (size_t i = 0; i < Shape.size(); i++)
		{
			for (size_t j = 0; j < Shape[0].size(); j++)
			{
				if (Shape[i][j])
				{
					if (currentPos.y + i > 20)
						return false;
				}
			}
		}
		//Prevents the object from rotating through ceiling & causing out of bounds error
		for (size_t i = 0; i < Shape.size(); i++)
		{
			for (size_t j = 0; j < Shape[0].size(); j++)
			{
				if (Shape[j][j])
				{
					if (currentPos.y + i  <= 0)
						return false;
				}
			}
		}

		//Checks for blocks below the shape
		for (size_t i = 0; i < Shape.size(); i++)
		{
			for (size_t j = 0; j < Shape[0].size(); j++)
			{
				if (Shape[i][j] != 0 && board.Grid[(int)currentPos.y + i - 1][(int)currentPos.x + j] != 0)
					return false;
			}
		}

		return true;
	}
