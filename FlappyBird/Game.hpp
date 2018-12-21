#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"


struct GameData												// accessable by all classes, accesses all the states
{
	StateMachine machine;									// obj of the state of the machine
	sf::RenderWindow window;								// window of the app
	AssetManager assets;									// obj of an asset manager
	InputManager input;										// obj of an input manager
};

typedef std::shared_ptr<GameData> GameDataRef;				// used when accessing the struct members above

class Game
{
public:
	Game(int width, int height, std::string title);			// Constructor, screen width height, title is name of app
	~Game();												// not used

private:
	const float dt = 1.0f / 60.0f;							// framerate, update per second fps
	sf::Clock _clock;
	GameDataRef _data = std::make_shared<GameData>();		// used to access the gamedata states
	void Run();												// used to start game

};

