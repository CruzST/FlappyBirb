#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"

class GameState : public State
{
public:
	GameState(GameDataRef data);
	~GameState();

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	Pipe *pipe;
	Land *land;
	Bird *bird;
	sf::Clock clock;
};

