#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>


class Bird
{
public:
	Bird(GameDataRef data);									// constructor
	void Draw();
	void Animate(float dt);
	void Update(float dt);
	void Tap();
	const sf::Sprite &GetSrpite() const;

	~Bird();												// not used

private:
	GameDataRef _data;
	sf::Sprite _birdSprite;
	std::vector<sf::Texture> _animationFrames;				// vector will hold all the frames
	unsigned int _animationIterator;						// current anime frame
	sf::Clock _clock;										// clock for animation
	sf::Clock _movementClock;								// clock for movement, specifically flying
	int _birdState;											// falling/still/flying
	float _rotation;										// will depend on the state
};

