#include "Collision.hpp"


/*
	Function will check for rectangular collision
*/
bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
	sf::Rect<float> rect1 = sprite1.getGlobalBounds();		// create a rect around the sprite
	sf::Rect<float> rect2 = sprite2.getGlobalBounds();

	if (rect1.intersects(rect2))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
	Function will check of alpha collision, the og rectangle sprites are scaled down
	to emulate a "better collision" this is NOT pixel perfect
*/
bool Collision::CheckSpriteCollision2(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
{
	sprite1.setScale(scale1, scale2);
	sprite2.setScale(scale1, scale2);

	sf::Rect<float> rect1 = sprite1.getGlobalBounds();		// create a rect around the sprite
	sf::Rect<float> rect2 = sprite2.getGlobalBounds();

	if (rect1.intersects(rect2))
	{
		return true;
	}
	else
	{
		return false;
	}
}



/**** not used ****/
Collision::Collision()
{
}
Collision::~Collision()
{
}
