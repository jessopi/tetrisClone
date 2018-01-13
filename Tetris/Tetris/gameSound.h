#pragma once
#include <SFML\Audio.hpp>
#include <string>
#include <unordered_map>

/*
*	Sound manager for tetris Clone
*	Plays sfx according to what string is passed to playSFX
*	Contains vector of soundbuffers for managing SFX
*	
*/
class gameSound
{
public:

	//HardCode string in constructor ?
	//Receives sound paths and sets them to soundbuffers
	//inserts sfx sounds into sfxMap to be called later
	gameSound(std::string,std::string,std::string,std::string, 
		std::string, std::string, std::string, std::string,std::string,std::string);
	gameSound();

	//Plays theme during game
	void playTheme();

	//Stops theme playing
	void endTheme();

	//Plays theme in the MainMenu
	void playMenuTheme();

	//Ends Menu Theme
	void endMenuTheme();

	//Plays sfx depending on passed in string
	/* Available sfx
		"Pause"
		"Rotate"
		"Select"
		"Collision";
		"LevelIncrease"
		"LineClear"
		"tetrisClear"
		"HighScore"
		"GameOver"
	*/
	void playSFX(std::string);

private:

	//Sound buffers and sound objects
	sf::Music theme;
	sf::Music mainMenuTheme;

	sf::SoundBuffer pause;
	sf::SoundBuffer rotate;
	sf::SoundBuffer select;
	sf::SoundBuffer collision;
	sf::SoundBuffer levelIncrease;

	sf::SoundBuffer lineClear;
	sf::SoundBuffer tetrisClear;

	sf::SoundBuffer highScore;
	sf::SoundBuffer gameOver;

	sf::Sound sound;

	//Map containing sfx soundBuffers and corresponding string
	std::unordered_map<std::string, sf::SoundBuffer> sfxMap;
};