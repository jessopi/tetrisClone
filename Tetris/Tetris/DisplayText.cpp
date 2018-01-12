#include "DisplayText.h"


DisplayText::DisplayText(std::string s)
{
	font.loadFromFile(s);
	constructGameOver();
	constructLevel();
	constructScore();
	constructPause();
}
void DisplayText::reset()
{
	constructLevel();
	constructScore();
}
//initializes text variables
void DisplayText::constructPause()
{
	pauseText.setString("Paused");
	pauseText.setFont(font);
	pauseText.setCharacterSize(70);
	pauseText.setFillColor(sf::Color::White);
	pauseText.setPosition(375, 200);
}
void DisplayText::constructScore()
{
	scoreText.setString("0");
	scoreText.setFont(font);
	scoreText.setCharacterSize(35);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(720, 502);
}
void DisplayText::constructLevel()
{
	levelText.setString("1");
	levelText.setFont(font);
	levelText.setCharacterSize(35);
	levelText.setFillColor(sf::Color::White);
	levelText.setPosition(725, 640);
}
void DisplayText::constructGameOver()
{
	gameOver_part1.setFont(font);
	gameOver_part1.setString("Game Over!");
	gameOver_part1.setCharacterSize(90);
	gameOver_part1.setFillColor(sf::Color::White);
	gameOver_part1.setPosition(225, 200);

	
	gameOver_part2.setFont(font);
	gameOver_part2.setString("Press spacebar to play again\n			 or\n Esc to go to the MainMenu!");
	gameOver_part2.setCharacterSize(30);
	gameOver_part2.setFillColor(sf::Color::White);
	gameOver_part2.setPosition(225, 345);
}
//draws game over text
void DisplayText::overText(sf::RenderWindow &window)
{
	window.draw(gameOver_part1);
	window.draw(gameOver_part2);
}
//draws paused text
void DisplayText::paused(sf::RenderWindow &window)
{
	window.draw(pauseText);
}
//updates text for new values;
void DisplayText::updateText(int score, int level)
{
	levelText.setString(std::to_string(level));
	scoreText.setString(std::to_string(score));
	updatePosition(score);
}
//draws text to screen
void DisplayText::draw(sf::RenderWindow &window)
{
	window.draw(scoreText);
	window.draw(levelText);
}
// updates textposition depending on number of digits
void DisplayText::updatePosition(int score)
{
	int tempScore = score;
	if (tempScore > 0)
	{
		int length = 1;
		while (tempScore /= 10)
			length++;
		scoreText.setPosition(720 - (length * 5), 502);
	}
}