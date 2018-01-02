#pragma once
#include <SFML\Audio.hpp>
#include <string>
class gameSound
{
public:
	gameSound(std::string,std::string);
	gameSound();
	void playTheme();
	void endTheme();
	void playPauseSound();
private:
	sf::Music theme;
	sf::Sound pause;
	sf::SoundBuffer pausebuffer;
	//sf::SoundBuffer themeBuffer;
};