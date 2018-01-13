#pragma once
#include <string>
#include <SFML\Graphics.hpp>
/*
*	Handles and displays text to screen
*/
class DisplayText
{
public:

	DisplayText();

	//loads font from file and contructs text objects
	DisplayText(std::string);

	//updates position for score, prevents it from spilling over box
	void updateText(int,int);

	//draws text for when the game ends
	void overText(sf::RenderWindow &);

	//draws the score & level text to the screen
	void draw(sf::RenderWindow &);

	//resets variables
	void reset();

	//draws text when the game is paused
	void paused(sf::RenderWindow &);

private:

	//constructs text objects
	void constructPause();
	void constructScore();
	void constructLevel();
	void constructGameOver();

	void updatePosition(int);

	//text objects
	sf::Font font;
	sf::Text gameOver_part1;
	sf::Text gameOver_part2;
	sf::Text scoreText;
	sf::Text levelText;
	sf::Text pauseText;
};