#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"


class Bird
{
public:
	Bird(GameDataRef data);
	void Draw();
	~Bird();

private:
	GameDataRef _data;
	sf::Sprite _birdSprite;
};

