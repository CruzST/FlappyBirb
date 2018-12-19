#include "InputManager.hpp"

/*
	Function will return true or false if a button is clicked via mouse.
	object: A sprite object
	button: a button on the mouse
	&window: the window, will usually be this->_data->window
*/
bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		// Creates a temprect with the origins at the objects.getPosition X/Y, with the size object.GlobalBounds Width x Height
		// getGlobalBounds().width / .height returns the width/height of the image
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (tempRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

sf::Vector2i GetMousePosition(sf::RenderWindow &window)
{
	return sf::Mouse::getPosition(window);
}

// Not used
InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}