/*
 * Main.cpp
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#include <iostream>
#include "Game.h"
#include "allegroincludes.h"


using namespace std;
using namespace fsaga_oop;


int main(int argc, char **argv)
{

	Game::logger("Launching application\n");

	Game game;

	game.setup_allegro();

	game.main_game_loop();

	game.shutdown_allegro();

	Game::logger("Application run complete. Returning");

	return 0;
}


