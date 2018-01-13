#include "Game.h"
#include <Windows.h>
int main()
{
	//windows only
	FreeConsole();

	Game game;
	game.start();
	return 0;
}