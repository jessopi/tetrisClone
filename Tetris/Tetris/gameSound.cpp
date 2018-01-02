#include "gameSound.h"

 gameSound::gameSound(std::string themePath,std::string pausePath)
{
	 theme.openFromFile(themePath);
	 theme.setLoop(true);

	 pausebuffer.loadFromFile(pausePath);
	 pause.setBuffer(pausebuffer);
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