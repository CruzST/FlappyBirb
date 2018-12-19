#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main()
{
	// Calls the game consturctor from the game.cpp file
	// within the game.cpp file it calls run, which starts everyhing
	Game(SCREEN_WIDTH, SCREEN_HEIGHT, "FLAPPY BIRB");
	return EXIT_SUCCESS;
}