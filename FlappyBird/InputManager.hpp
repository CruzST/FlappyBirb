#pragma once
#include <SFML\Graphics.hpp>

class InputManager
{
public:
	InputManager();				// not used
	~InputManager();			// not used

	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};

