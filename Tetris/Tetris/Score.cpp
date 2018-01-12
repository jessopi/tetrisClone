#include "Score.h"

Score::Score(std::string path)
{
	reset();
	readFile(path);
}

void Score::readFile(std::string path)
{
	std::ifstream fin(path);
	std::string name;
	int score;
	std::pair<std::string, int> scorePair;
	while (fin >> name >> score)
	{
		scorePair.first = name;
		scorePair.second = score;
		topScores.push_back(scorePair);
	}
	fin.close();
}
void Score::reset()
{
	level = 1;
	playerScore = 0;
	totalRowsCompleted = 0;
}

bool Score::isNewHighScore()
{
	return playerScore > topScores[9].second;
}
void Score::updateLeaderBoard(std::string name)
{
	std::pair<std::string, int> p1;
	p1.first = name;
	p1.second = playerScore;
	//0 ----- 9

	int i = 0;
	while (p1.second < topScores[i].second)
	{
		i++;
	}
	topScores.insert(topScores.begin() + i, p1);
	topScores.pop_back();
}
std::vector<std::pair<std::string, int>> Score::leaderBoard()
{
	return topScores;
}

int Score::currentScore()
{
	return playerScore;
}
int Score::currentLevel()
{
	return level;
}

void Score::getNumberOfRowsCleared(int completedRows)
{
	calculateLevel(completedRows);
	calculateScore(completedRows);
}

void Score::calculateLevel(int completedRows)
{
	totalRowsCompleted += completedRows;

	if (totalRowsCompleted < 10)
	{
		level = 1;
	}
	else if (totalRowsCompleted < 20)
	{
		level = 2;
	}
	else if (totalRowsCompleted < 30)
	{
		level = 3;
	}
	else if (totalRowsCompleted < 40)
	{
		level = 4;
	}
	else if (totalRowsCompleted < 50)
	{
		level = 5;
	}
	else if (totalRowsCompleted < 60)
	{
		level = 6;
	}
	else if (totalRowsCompleted < 70)
	{
		level = 7;
	}
	else if (totalRowsCompleted < 80)
	{
		level = 8;
	}
	else if (totalRowsCompleted < 90)
	{
		level = 9;
	}
	else
		level = 10;
}
void Score::calculateScore(int completedRows)
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

	playerScore += points * level;
}
