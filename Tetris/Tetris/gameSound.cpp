#include "gameSound.h"

gameSound::gameSound(std::string themePath, std::string pausePath, std::string rotatePath,
	std::string gameOverPath, std::string collisionPath, std::string levelIncreasePath,
	std::string lineClearPath, std::string tetrisClearPath, std::string selectPath,std::string highScorePath)
{
	 theme.openFromFile(themePath);
	 theme.setLoop(true);
	 theme.setVolume(1);

	 mainMenuTheme.openFromFile("./Audio/menuTheme.ogg");
	 mainMenuTheme.setLoop(true);
	 mainMenuTheme.setVolume(1);

	 pause.loadFromFile(pausePath);
	 rotate.loadFromFile(rotatePath);
	 select.loadFromFile(selectPath);

	 collision.loadFromFile(collisionPath);
	 levelIncrease.loadFromFile(levelIncreasePath);

	 lineClear.loadFromFile(lineClearPath);
	 tetrisClear.loadFromFile(tetrisClearPath);

	 highScore.loadFromFile(highScorePath);
	 gameOver.loadFromFile(gameOverPath);

	 //Case-Sensitive
	 sfxMap["Pause"] = pause;
	 sfxMap["Rotate"] = rotate;
	 sfxMap["Select"] = select;
	 sfxMap["Collision"] = collision;
	 sfxMap["LevelIncrease"] = levelIncrease;
	 sfxMap["LineClear"] = lineClear;
	 sfxMap["TetrisClear"] = tetrisClear;
	 sfxMap["HighScore"] = highScore;
	 sfxMap["GameOver"] = gameOver;

}
 void gameSound::playSFX(std::string trackName)
 {
	 sound.setBuffer(sfxMap[trackName]);
	 sound.setVolume(10);
	 sound.play();
 }
 void gameSound::playTheme()
 {
	 if (theme.getStatus() == theme.Playing)
		 return;
	 else
		 theme.play();
 }
 void gameSound::endTheme()
 {
	 theme.stop();
 }
 void gameSound::playMenuTheme()
 {
	 if (mainMenuTheme.getStatus() == mainMenuTheme.Playing)
		 return;
	 else
		 mainMenuTheme.play();
 }
 void gameSound::endMenuTheme()
 {
	 mainMenuTheme.stop();
 }