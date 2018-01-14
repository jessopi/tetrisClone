#include "Game.h"
#include <Windows.h>
/*
*	Fully functional tetris clone programmed by Ian Jessop
*	https://github.com/jessopi/tetrisClone
*	Requires SFML 2.4 & TGUI 0.7 libraries
*	Features include:
*   -----------------
*	Main Menu
*	Leaderboard
*	Background music and SFX	
*	tetris blocks with textures
*	Difficulty Increase and score tracking
*/
int main()
{
	//windows only
	FreeConsole();
	Game game;
	game.start();
	return 0;
}