#include "Bird.hpp"



Bird::Bird(GameDataRef data) : _data(data)
{
	_birdSprite.setTexture(_data->assets.GetTexture("Bird Frame 1"));
}

void Bird::Draw()
{
	_data->window.draw(_birdSprite);
}



// not used
Bird::~Bird()
{
}
