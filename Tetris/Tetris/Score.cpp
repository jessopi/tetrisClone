#include "Score.h"


Score::Score(std::string s)
{
	font.loadFromFile(s);
	constructGameOver();
	constructLevel();
	constructScore();
	constructPause();
}
void Score::reset()
{
	constructLevel();
	constructScore();
}
//initializes text variables
void Score::constructPause()
{
	pauseText.setString("Paused");
	pauseText.setFont(font);
	pauseText.setCharacterSize(70);
	pauseText.setFillColor(sf::Color::White);
	pauseText.setPosition(375, 200);
}
void Score::constructScore()
{
	score = 0;
	scoreText.setString("0");
	scoreText.setFont(font);
	scoreText.setCharacterSize(35);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(720, 502);
}
void Score::constructLevel()
{
	levelText.setString("1");
	levelText.setFont(font);
	levelText.setCharacterSize(35);
	levelText.setFillColor(sf::Color::White);
	levelText.setPosition(725, 640);
}
void Score::constructGameOver()
{
	gameOver_part1.setFont(font);
	gameOver_part1.setString("Game Over!");
	gameOver_part1.setCharacterSize(90);
	gameOver_part1.setFillColor(sf::Color::White);
	gameOver_part1.setPosition(225, 200);

	
	gameOver_part2.setFont(font);
	gameOver_part2.setString("Press spacebar to play again or Esc to quit!");
	gameOver_part2.setCharacterSize(30);
	gameOver_part2.setFillColor(sf::Color::White);
	gameOver_part2.setPosition(100, 350);
}
//draws game over text
void Score::overText(sf::RenderWindow &window)
{
	window.draw(gameOver_part1);
	window.draw(gameOver_part2);
}
//draws paused text
void Score::paused(sf::RenderWindow &window)
{
	window.draw(pauseText);
}
//updates text for new values;
void Score::updateText(int completedRows, int level)
{
	levelText.setString(std::to_string(level));
	calculateScore(completedRows,level);
	scoreText.setString(std::to_string(score));
	updatePosition();
}
//calcualtes points according to how many rows were completed at once
void Score::calculateScore(int completedRows,int level)
{
	int points = 0;
	switch (completedRows)
	{
	case 1:
		points = 50;
		break;
	case 2:
		points = 150;
		break;
	case 3:
		points = 350;
		break;
	case 4: 
		points = 1000;
		break;
	default:
		break;
	}
	score += points * level;
}
//draws text to screen
void Score::draw(sf::RenderWindow &window)
{
	window.draw(scoreText);
	window.draw(levelText);
}
// updates textposition depending on number of digits
void Score::updatePosition()
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