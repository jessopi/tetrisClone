#pragma once
#include <SFML\Audio.hpp>
#include <string>
class gameSound
{
public:
	//questionable declaration
	//might be a better way of getting file paths
	gameSound(std::string,std::string,std::string,std::string, std::string, std::string, std::string, std::string);
	gameSound();
	void playTheme();
	void endTheme();
	void rotationSFX();
	void playPauseSound();
	void gameOver();
	void landed();
	void levelIncrease();
	void lineClear();
	void tetrisClear();
	void select();
	void playMenuTheme();
	void endMenuTheme();
private:
	bool played;
	sf::Music theme;
	sf::Sound pause;
	sf::Sound rotation;
	sf::Sound gameOverSound;
	sf::Sound landedSound;
	sf::Sound levelIncreaseSound;
	sf::Sound lineClearSound;
	sf::Sound tetrisClearSound;

	sf::SoundBuffer pausebuffer;
	sf::SoundBuffer rotateBuffer;
	sf::SoundBuffer gameOverBuffer;
	sf::SoundBuffer landedBuffer;
	sf::SoundBuffer levelIncreaseBuffer;
	sf::SoundBuffer lineClearBuffer;
	sf::SoundBuffer tetrisClearBuffer;

	sf::SoundBuffer selectBuffer;
	sf::Sound selectSound;

	sf::Music mainMenuTheme;

};