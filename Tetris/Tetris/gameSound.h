#pragma once
#include <SFML\Audio.hpp>
#include <string>
#include <unordered_map>
class gameSound
{
public:
	//Move into calling file locations from constructor instead of passing them in?
	gameSound(std::string,std::string,std::string,std::string, 
		std::string, std::string, std::string, std::string,std::string,std::string);
	gameSound();
	void playTheme();
	void endTheme();
	void playMenuTheme();
	void endMenuTheme();
	void playSFX(std::string);

private:

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

	std::unordered_map<std::string, sf::SoundBuffer> sfxMap;
};