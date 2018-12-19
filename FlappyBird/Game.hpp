#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"


struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;		// used when accessing the struct members

class Game
{
public:
	Game(int width, int height, std::string title);		// screen width height, title is name of app
	~Game();

private:
	const float dt = 1.0f / 60.0f;		// framerate, update per second
	sf::Clock _clock;
	GameDataRef _data = std::make_shared<GameData>();
	void Run();	// used to start game

};

