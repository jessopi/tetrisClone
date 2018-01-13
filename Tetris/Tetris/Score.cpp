#include "Score.h"
Score::Score(std::string path)
{
	fpath = path;
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

void Score::writeFile()
{
	std::ofstream file;
	file.open(fpath, std::ios::trunc);
	for (auto &e : topScores)
	{
		file << e.first << " " << e.second << std::endl;
	}
	file.close();
}

void Score::reset()
{
	level = 1;
	playerScore = 0;
	totalRowsCompleted = 0;
}

//Compares current playerScore to last index of topScore
bool Score::isNewHighScore()
{
	return playerScore > topScores.back().second;
}

void Score::updateLeaderBoard(std::string name)
{
	//stores playerScore & player name in pair
	std::pair<std::string, int> p1;
	p1.first = name;
	p1.second = playerScore;

	int i = 0;
	while (p1.second < topScores[i].second)
	{
		i++;
	}
	topScores.insert(topScores.begin() + i, p1);
	//pops the previous last index of topScores
	//Max number of items in vector is 10
	topScores.pop_back();

	writeFile();
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

//Switch case to calculate lvl according to total rows completed
//Increments of 10, subject to change
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

//Calculates points recieved by clearing rows depending on number cleared at one time
//1 = 50, 2 = 150, 3 = 350 , 4 = 1000
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
