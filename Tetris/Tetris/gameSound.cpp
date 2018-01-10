#include "gameSound.h"

 gameSound::gameSound(std::string themePath,std::string pausePath,std::string rotationPath,
	 std::string gameOverPath,std::string landedPath,std::string levelIncreasePath,
	 std::string lineClearPath, std::string tetrisClearPath)
{
	 theme.openFromFile(themePath);
	 theme.setLoop(true);
	 theme.setVolume(50);

	 pausebuffer.loadFromFile(pausePath);
	 pause.setBuffer(pausebuffer);

	 //fix volume for beep
	 rotateBuffer.loadFromFile(rotationPath);
	 rotation.setBuffer(rotateBuffer);

	 gameOverBuffer.loadFromFile(gameOverPath);
	 gameOverSound.setBuffer(gameOverBuffer);


	 landedBuffer.loadFromFile(landedPath);
	 landedSound.setBuffer(landedBuffer);
	 levelIncreaseBuffer.loadFromFile(levelIncreasePath);
	 levelIncreaseSound.setBuffer(levelIncreaseBuffer);
	 tetrisClearBuffer.loadFromFile(tetrisClearPath);
	 tetrisClearSound.setBuffer(tetrisClearBuffer);
	 lineClearBuffer.loadFromFile(lineClearPath);
	 lineClearSound.setBuffer(lineClearBuffer);
}
 void gameSound::playTheme()
 {
	 theme.play();
 }
 void gameSound::endTheme()
 {
	 theme.stop();
 }
 void gameSound::playPauseSound()
 {
	 pause.play();
 }
 void gameSound::rotationSFX()
 {
	 rotation.play();
 }
 void gameSound::gameOver()
 {
	 gameOverSound.play();
 }

 void gameSound::landed()
 {
	 landedSound.play();
 }
 void gameSound::levelIncrease()
 {
	 levelIncreaseSound.play();
 }
 void gameSound::lineClear()
 {
	 lineClearSound.play();
 }
 void gameSound::tetrisClear()
 {
	 tetrisClearSound.play();
 }