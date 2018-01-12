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
	DisplayText(std::string);
	void updateText(int,int);
	void overText(sf::RenderWindow &);
	void draw(sf::RenderWindow &);
	void reset();
	void paused(sf::RenderWindow &);
private:
	void constructPause();
	void constructScore();
	void constructLevel();
	void constructGameOver();
	void updatePosition(int);
	sf::Font font;
	sf::Text gameOver_part1;
	sf::Text gameOver_part2;
	sf::Text scoreText;
	sf::Text levelText;
	sf::Text pauseText;
};