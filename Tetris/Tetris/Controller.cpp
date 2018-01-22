#include "Controller.h"
#include <iostream>
	Controller::Controller(std::string s) : tetrominoBag(), current(),next()
	{
		texture.loadFromFile(s);
		getNewBlock();
		gameOver = false;
		holdIsEmpty = true;
		hasBeenSwapped = false;
		
	};
	void Controller::getNewBlock()
	{
		current = tetrominoBag.nextBlock();
		currentPos.x = 3;
		currentPos.y = 0;
		currentShape = current.getShape();
	
		next = tetrominoBag.peek();
		nextShape = next.getShape();
	}
	void Controller::reset()
	{
		gameOver = false;
		holdIsEmpty = true;
		hasBeenSwapped = false;
		tetrominoBag.reset();
		getNewBlock();
	}
	//draws the current shape to screen
	void Controller::draw(sf::RenderWindow &window)
	{
		for (unsigned i = 0; i < currentShape.size(); ++i) {
			for (unsigned j = 0; j < currentShape[0].size(); ++j) {
				if (currentShape[i][j]) {
					sf::RectangleShape Block(sf::Vector2f(BlockSize, BlockSize));
					Block.setTexture(&texture);
					Block.setTextureRect(this->current.blockColor());
					Block.setPosition(316 + (currentPos.x + j) * BlockSize, (currentPos.y + i) * BlockSize);
					window.draw(Block);
				}
			}
		}

		drawNext(window);
		drawHold(window);
	}
	
	void Controller::drawNext(sf::RenderWindow &window)
	{
		for (unsigned i = 0; i < nextShape.size(); ++i) {
			for (unsigned j = 0; j < nextShape[0].size(); ++j) {
				if (nextShape[i][j]) {
					sf::RectangleShape Block(sf::Vector2f(BlockSize, BlockSize));
					Block.setTexture(&texture);
					
					Block.setTextureRect(next.blockColor());
					//aligning shapes with background
					if (nextShape[i][j] == 1)
					{
						Block.setPosition(678 + (j * BlockSize), i * BlockSize + 115);
					}
					else if (nextShape[i][j] == 4)
					{
						Block.setPosition(675 + (j * BlockSize), i * BlockSize + 100);
					}
					else
						Block.setPosition(695 + (j * BlockSize), i * BlockSize + 102);

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
		for (size_t i = 0; i < currentShape.size(); i++)
		{
			for (size_t j = 0; j < currentShape[0].size(); j++)
			{
				if (currentShape[i][j] != 0 && board.Grid[(int)currentPos.y + i - 1][(int)currentPos.x + j] != 0)
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
				currentShape = current.clockWiseRotation();
				if (!collision(*board))
					currentShape = current.counterClockWiseRotation();
				break;
			}
			case::sf::Keyboard::Key::Down:
			{
				currentPos.y++;
				//if collision occurs copy index value of shape to the corresponding grid location
				if (!collision(*board))
				{
					currentPos.y--;

					for (size_t i = 0; i < currentShape.size(); i++) {
						for (size_t j = 0; j < currentShape[0].size(); j++) {
							if (currentShape[i][j]) {
								board->Grid[(int)currentPos.y + i - 1][(int)currentPos.x + j] = currentShape[i][j];
							}

						}
					}

					sound.playSFX("Collision");
					hasBeenSwapped = false;
					getNewBlock();

					//if collision is still occuring after moveback then the game is over
					if (!endGameCollision(*board))
					{
						gameOver = true;
						sound.playSFX("GameOver");
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
			for (auto &e : currentShape)
			{
				if (e[-(int)currentPos.x - 1])
				{
					return false;
				}
			}
		}
		// Checks if block has gone beyond right wall
		if (currentPos.x + currentShape[0].size() > 10) 
		{
			for (auto &Row : currentShape)
			{
				if (Row[10 - (int)currentPos.x]) 
				{
					return false;
				}
			}
		}
		//Checks if object has reached the bottom of the playing field
		for (size_t i = 0; i < currentShape.size(); i++)
		{
			for (size_t j = 0; j < currentShape[0].size(); j++)
			{
				if (currentShape[i][j])
				{
					if (currentPos.y + i > 20)
						return false;
				}
			}
		}
		//Prevents the object from rotating through ceiling & causing out of bounds error
		for (size_t i = 0; i < currentShape.size(); i++)
		{
			for (size_t j = 0; j < currentShape[0].size(); j++)
			{
				if (currentShape[j][j])
				{
					if (currentPos.y + i  <= 0)
						return false;
				}
			}
		}

		//Checks for blocks below the shape
		for (size_t i = 0; i < currentShape.size(); i++)
		{
			for (size_t j = 0; j < currentShape[0].size(); j++)
			{
				if (currentShape[i][j] != 0 && board.Grid[(int)currentPos.y + i - 1][(int)currentPos.x + j] != 0)
					return false;
			}
		}

		return true;
	}

	void Controller::drawHold(sf::RenderWindow &window)
	{
		if (!holdIsEmpty)
		{
			for (unsigned i = 0; i < holdShape.size(); ++i) {
				for (unsigned j = 0; j < holdShape[0].size(); ++j) {
					if (holdShape[i][j]) {
						sf::RectangleShape Block(sf::Vector2f(BlockSize, BlockSize));
						Block.setTexture(&texture);

						Block.setTextureRect(hold.blockColor());
						//aligning shapes with background
						if (holdShape[i][j] == 1)//I tetromino
						{
							Block.setPosition(167 + (j * BlockSize), i * BlockSize + 115);
						}
						else if (holdShape[i][j] == 4)//O tetromino
						{
							Block.setPosition(165 + (j * BlockSize), i * BlockSize + 100);
						}
						else
							Block.setPosition(180 + (j * BlockSize), i * BlockSize + 102);

						window.draw(Block);
					}
				}
			}
		}
	}

	void Controller::swapTetromino()
	{
		if (holdIsEmpty)
		{	
			//call getShape instead of using currentShape because you need base position
			hold = current;
			holdShape = current.getShape();

			//grabs new current and next tetromino
			getNewBlock();

			holdIsEmpty = false;
		}
		else
		{
			//allows only once swap per bottom collision
			if (!hasBeenSwapped)
			{
				//temp object for swapping current and hold piece
				auto tempObject = hold;
				hold = current;
				current = tempObject;

				holdShape = hold.getShape();
				currentShape = current.getShape();
				hasBeenSwapped = true;

				//resets x & y to start at top
				currentPos.x = 3;
				currentPos.y = 0;
			}
		}
	}
