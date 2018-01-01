#pragma once
#include <string>
#include <SFML\Graphics.hpp>
/*
*	Handles and displays text to screen
*/
class Score
{
public:
	Score();
	Score(std::string);
	void updateText(int,int);
	void overText(sf::RenderWindow &);
	void draw(sf::RenderWindow &);
	void reset();
private:
	void constructScore();
	void constructLevel();
	void constructGameOver();
	int score;
	void calculateScore(int,int);
	void updatePosition();
	sf::Font font;
	sf::Text gameOver_part1;
	sf::Text gameOver_part2;
	sf::Text scoreText;
	sf::Text levelText;
};