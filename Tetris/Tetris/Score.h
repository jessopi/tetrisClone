#pragma once
#include <vector>
#include <fstream>
#include <sstream>

/*
*	Handles score and level calculations for the game including LeaderBoard calculations.
*	Outputs current score & level to other objects.
*/
class Score
{
public:

	//Initializes variables and opens leaderBoard.dat containing the saved leaderboards.
	Score(std::string);

	//Resets level,score and totalrowsCompleted when starting a new game.
	void reset();

	//Checks if there is a new highscore to be added.
	bool isNewHighScore();
	
	//Outputs vector containing names and scores from leaderboard.dat
	std::vector<std::pair<std::string, int>> leaderBoard();

	//To be called after user enters name into popup window
	//Updates leaderBoard with new highscore
	void updateLeaderBoard(std::string);

	//Outputs the current score
	int currentScore();

	//Outputs the current level
	int currentLevel();

	//Gets the number of rows cleared 0-4
	void getNumberOfRowsCleared(int);

private:

	//Reads in leaderboard.dat and stores in topScores
	void readFile(std::string);

	//Calculates Score and Level
	void calculateScore(int);
	void calculateLevel(int);

	//Variables
	int level;
	int playerScore;
	int totalRowsCompleted;

	//Vector of pair<string,int> holding data from leaderboard.dat
	std::vector<std::pair<std::string, int>> topScores;
};