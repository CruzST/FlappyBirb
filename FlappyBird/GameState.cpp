#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>



/*

*/
GameState::GameState(GameDataRef data) : _data(data)
{

}


/*
	Function will init the game after play is hit from the splash screen
*/
void GameState::Init()
{
	std::cout << "Initializing Game State" << std::endl;

	// load all relavent textures
	_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
	_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	_data->assets.LoadTexture("Land", LAND_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

	// declare new objects
	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);

	// set the background
	_background.setTexture(this->_data->assets.GetTexture("Game Background"));

	// sets gamestate to "ready" the bird isn't moving yet, nor the pipes, but they will spawn
	_gameState = GameStates::eReady;

}



/*
	Function will handle any inputs while in the game state
*/
void GameState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		// check if the X is hit
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		// check if left mouse was clicked
		if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Left, this->_data->window))
		{
			// if not game over, then process the click
			if (GameStates::eGameOver != _gameState)
			{
				_gameState = GameStates::ePlaying;
				bird->Tap();
			}
		}
	}
}


/*
	Update the gamestate
*/
void GameState::Update(float dt)
{
	// if the game is not over, move the bird and the land
	if (GameStates::eGameOver != _gameState)
	{
		bird->Animate(dt);
		land->MoveLand(dt);
	}
	
	// if playing, play the game
	if (GameStates::ePlaying == _gameState)
	{
		pipe->MovePipes(dt);
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			pipe->RandomizePipeOffset();
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			clock.restart();
		}
		bird->Update(dt);

		// check for collision with the land
		std::vector<sf::Sprite> landSprites = land->GetSprites();
		for (int i = 0; i < landSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision2(bird->GetSrpite(), 0.7f, landSprites.at(i), 1.0f))			// play with the scaling
			{
				_gameState = GameStates::eGameOver;
			}
		}

		// check for collision with the pipes
		std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
		for (int i = 0; i < pipeSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision2(bird->GetSrpite(), 0.625f, pipeSprites.at(i), 1.0f))		// have to play with the scaling
			{
				_gameState = GameStates::eGameOver;
			}
		}
	}
}


/*
	Function will draw the window for the gamestate
*/
void GameState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	pipe->DrawPipes();
	land->DrawLand();
	bird->Draw();
	_data->window.display();
}


/**** not used ****/
GameState::~GameState()
{
}
