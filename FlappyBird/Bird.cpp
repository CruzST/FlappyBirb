#include "Bird.hpp"


/*
	constructor, will take in the game data from game.hpp
	Function will set the sprite ups
*/
Bird::Bird(GameDataRef data) : _data(data)
{
	_animationIterator = 0;
	// push the frames to the vector
	_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
	_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
	_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
	_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));

	// load the first frame
	_birdSprite.setTexture(_animationFrames.at(_animationIterator));

	//set starting pos
	_birdSprite.setPosition((_data->window.getSize().x / 4 - _birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2 - _birdSprite.getGlobalBounds().height / 2));

	// bird starting settings
	_birdState = BIRD_STATE_STILL;
	sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);
	_birdSprite.setOrigin(origin);
	_rotation = 0;

}

/*
	Function will draw the bird to the window
*/
void Bird::Draw()
{
	_data->window.draw(_birdSprite);
}


/*
	Function will animate the bird
*/
void Bird::Animate(float dt)
{
	// cycle through the frames, if it his the last, reset to the first
	if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
	{
		if (_animationIterator < _animationFrames.size() - 1)
		{
			_animationIterator++;
		}
		else
		{
			_animationIterator = 0;
		}
		_birdSprite.setTexture(_animationFrames.at(_animationIterator));
		_clock.restart();		// restart the clock after each iteration of the bird
	}
}


/*
	Function updates the state of the bird, depending on the state
	the rotation will change
*/
void Bird::Update(float dt)
{
	if (BIRD_STATE_FALLING == _birdState)
	{
		// move the bird down
		_birdSprite.move(0, GRAVITY * dt);
		
		// set new rotation, and if it his a max, then default
		_rotation += ROTATION_SPEED * dt;
		if (_rotation > 25.0f)
		{
			_rotation = 25.0f;
		}
		_birdSprite.setRotation(_rotation);
	}
	else if (BIRD_STATE_FLYING == _birdState)
	{
		// move bird up
		_birdSprite.move(0, -FLYING_SPEED * dt);
		// set new rotation, and if it his a min, then default
		_rotation -= FLYING_SPEED * dt;
		if (_rotation < -25.0f)
		{
			_rotation = -25.0f;
		}
		_birdSprite.setRotation(_rotation);
	}

	// if the bird has flown the max time, set it to fall
	if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
	{
		_movementClock.restart();
		_birdState = BIRD_STATE_FALLING;
	}
}


/*
	Function to handle the tapping
*/
void Bird::Tap()
{
	_movementClock.restart();
	_birdState = BIRD_STATE_FLYING;
}


const sf::Sprite &Bird::GetSrpite() const
{
	return _birdSprite;
}



/****** not used *******/
Bird::~Bird()
{
}
