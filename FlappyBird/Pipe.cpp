#include "Pipe.hpp"
#include <iostream>


/*
	Constructor. takes the data from game.hpp
	Sets the land height to the size of the land.png file
*/
Pipe::Pipe(GameDataRef data) : _data(data)
{
	_landHeight = _data->assets.GetTexture("Land").getSize().y;
	_pipeSpawnYOffset = 0;
}


/*
	Draw the pipes in the pipeSprite vector
*/
void Pipe::DrawPipes()
{
	for (unsigned short int i = 0; i < _pipeSprites.size(); i++)
	{
		_data->window.draw(_pipeSprites.at(i));
	}
}

/*
	Determine a random pipe offset
*/
void Pipe::RandomizePipeOffset()
{
	_pipeSpawnYOffset = rand() % (_landHeight + 1);
}

/*
	Spawn bottom pipe
*/
void Pipe::SpawnBottomPipe()
{
	sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
	_pipeSprites.push_back(sprite);
}

/*
	Spawn top pipe
*/
void Pipe::SpawnTopPipe() 
{
	sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
	sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
	_pipeSprites.push_back(sprite);
}

/*
	Spawns an invisible pipe
*/
void Pipe::SpawnInvisiblePipe()
{
	sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
	sprite.setColor(sf::Color(0, 0, 0, 0));	// invisible pipe
	_pipeSprites.push_back(sprite);
}


/*
	Spawn a scoring pipe 
*/
void Pipe::SpawnScoringPipe()
{
	sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
	sprite.setPosition(_data->window.getSize().x, 0);
	_scoringPipes.push_back(sprite);
}


/*
	Move the pipes
*/
void Pipe::MovePipes(float dt)
{
	// move regular pipes
	for (unsigned short int i = 0; i < _pipeSprites.size(); i++)
	{
		if (_pipeSprites.at(i).getPosition().x < 0 - _pipeSprites.at(i).getGlobalBounds().width)
		{
			_pipeSprites.erase(_pipeSprites.begin() + i);		// will delete the sprite as it exits the screen
		}
		else
		{
			float movement = PIPE_MOVEMENT_SPEED * dt;			// allows frame independant gameplay

			_pipeSprites.at(i).move(-movement, 0);
		}
	}

	// move the scoring pipes
	for (unsigned short int i = 0; i < _scoringPipes.size(); i++)
	{
		if (_scoringPipes.at(i).getPosition().x < 0 - _scoringPipes.at(i).getGlobalBounds().width)
		{
			_scoringPipes.erase(_scoringPipes.begin() + i);		// will delete the sprite as it exits the screen
		}
		else
		{
			float movement = PIPE_MOVEMENT_SPEED * dt;			// allows frame independant gameplay

			_scoringPipes.at(i).move(-movement, 0);
		}
	}
}


/*
	return the vector of pipes
*/
const std::vector<sf::Sprite> &Pipe::GetSprites() const
{
	return _pipeSprites;
}

/*
	return the scoring pipe vector
*/
std::vector<sf::Sprite> &Pipe::GetScoringSprites()
{
	return _scoringPipes;
}




/**** not used ****/
Pipe::~Pipe()
{
}
