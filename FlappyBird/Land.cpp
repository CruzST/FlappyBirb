#include "Land.hpp"
#include "DEFINITIONS.hpp"


/*
	Constructor uses the data from the game.hpp file.
*/
Land::Land(GameDataRef data) : _data(data)
{
	// use 2 sprites to allow smoother transitioning
	sf::Sprite sprite(_data->assets.GetTexture("Land"));
	sf::Sprite sprite2(_data->assets.GetTexture("Land"));

	// set the positions of the sprites
	sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
	sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);

	// add them to a vector
	_landSprites.push_back(sprite);
	_landSprites.push_back(sprite2);
}


/*
	Move the land on the ground
*/
void Land::MoveLand(float dt) 
{
	for (unsigned short int i = 0; i < _landSprites.size(); i++)
	{
		float movement = PIPE_MOVEMENT_SPEED * dt;
		_landSprites.at(i).move(-movement, 0.0f);

		// get the sprites position relative to the size of it
		if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width)
		{
			// update the position
			sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
			_landSprites.at(i).setPosition(position);
		}
	}
}


/*
	Draw the land to the window
*/
void Land::DrawLand() 
{
	for (unsigned short int i = 0; i < _landSprites.size(); i++)
	{
		_data->window.draw(_landSprites.at(i));
	}
}

/*
	Function returns the vector containing the sprites
*/
const std::vector<sf::Sprite> &Land::GetSprites() const
{
	return _landSprites;
}


/**** not used ****/
Land::~Land()
{
}
