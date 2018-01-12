#pragma once
#include <vector>
#include <fstream>
#include <sstream>

class Score
{
public:
	Score(std::string);
	void reset();

	bool isNewHighScore();
	
	std::vector<std::pair<std::string, int>> leaderBoard();

	void updateLeaderBoard(std::string);
	int currentScore();
	int currentLevel();
	void getNumberOfRowsCleared(int);
private:
	void readFile(std::string);
	void calculateScore(int);
	void calculateLevel(int);

	int level;
	int playerScore;
	int totalRowsCompleted;
	std::vector<std::pair<std::string, int>> topScores;
};