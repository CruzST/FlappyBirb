#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>


class Land
{
public:
	Land(GameDataRef data);

	void MoveLand(float dt);
	void DrawLand();

	// not used
	~Land();

private:
	GameDataRef _data;
	std::vector<sf::Sprite> _landSprites;
};

