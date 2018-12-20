#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>




GameState::GameState(GameDataRef data) : _data(data)
{

}


void GameState::Init()
{
	std::cout << "Initializing Game State" << std::endl;

	_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
	_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	_data->assets.LoadTexture("Land", LAND_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);

	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));

}


void GameState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Left, this->_data->window))
		{
			
		}
	}
}

void GameState::Update(float dt)
{
	pipe->MovePipes(dt);
	land->MoveLand(dt);
	if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
	{
		pipe->RandomizePipeOffset();
		pipe->SpawnInvisiblePipe();
		pipe->SpawnBottomPipe();
		pipe->SpawnTopPipe();

		clock.restart();
	}
}


void GameState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	pipe->DrawPipes();
	land->DrawLand();
	bird->Draw();

	_data->window.display();
}


// not used
GameState::~GameState()
{
}
