#include "gameSound.h"

 gameSound::gameSound(std::string themePath,std::string pausePath,std::string rotationPath,
	 std::string gameOverPath,std::string landedPath,std::string levelIncreasePath,
	 std::string lineClearPath, std::string tetrisClearPath)
{
	 theme.openFromFile(themePath);
	 theme.setLoop(true);
	 theme.setVolume(1);

	 pausebuffer.loadFromFile(pausePath);
	 pause.setBuffer(pausebuffer);
	 pause.setVolume(6);
	 //fix volume for beep
	 rotateBuffer.loadFromFile(rotationPath);
	 rotation.setBuffer(rotateBuffer);
	 rotation.setVolume(10);

	 gameOverBuffer.loadFromFile(gameOverPath);
	 gameOverSound.setBuffer(gameOverBuffer);
	 gameOverSound.setVolume(20);

	 landedBuffer.loadFromFile(landedPath);
	 landedSound.setBuffer(landedBuffer);
	 landedSound.setVolume(10);
	 levelIncreaseBuffer.loadFromFile(levelIncreasePath);
	 levelIncreaseSound.setBuffer(levelIncreaseBuffer);
	 levelIncreaseSound.setVolume(10);
	 tetrisClearBuffer.loadFromFile(tetrisClearPath);
	 tetrisClearSound.setBuffer(tetrisClearBuffer);
	 tetrisClearSound.setVolume(10);
	 lineClearBuffer.loadFromFile(lineClearPath);
	 lineClearSound.setBuffer(lineClearBuffer);
	 lineClearSound.setVolume(10);

	 selectBuffer.loadFromFile("./Audio/select.wav");
	 selectSound.setBuffer(selectBuffer);
	 selectSound.setVolume(20);
	 mainMenuTheme.openFromFile("./Audio/menu.ogg");
	 mainMenuTheme.setLoop(true);
	 mainMenuTheme.setVolume(1);
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
 void gameSound::select()
 {
	 selectSound.play();
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