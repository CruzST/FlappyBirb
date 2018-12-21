#pragma once

#include <SFML/Graphics.hpp>


class Collision
{
public:
	Collision();		// not used

	// rectangle detection
	bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
	
	// alpha
	bool CheckSpriteCollision2(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
	~Collision();		// not used
};

