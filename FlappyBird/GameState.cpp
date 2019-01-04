#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
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
	_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
	_data->assets.LoadTexture("Land", LAND_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
	_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
	_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

	
	_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH);
	_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH);
	_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH);
	_hitSound.setBuffer(_hitSoundBuffer);
	_wingSound.setBuffer(_wingSoundBuffer);
	_pointSound.setBuffer(_pointSoundBuffer);
	
	/*
	_data->assets.LoadSoundBuffer("Hit Sound Buffer", HIT_SOUND_FILEPATH);
	_data->assets.LoadSoundBuffer("Wing Sound Buffer", WING_SOUND_FILEPATH);
	_data->assets.LoadSoundBuffer("Point Sound Buffer", POINT_SOUND_FILEPATH);

	_hitSound.setBuffer(this->_data->assets.GetSoundBuffer("Hit Sound Buffer"));
	_wingSound.setBuffer(this->_data->assets.GetSoundBuffer("Wing Sound Buffer"));
	_pointSound.setBuffer(this->_data->assets.GetSoundBuffer("Point Sound Buffer"));
	*/
	

	// declare new objects
	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);
	flash = new Flash(_data);
	hud = new HUD(_data);

	// set the background
	_background.setTexture(this->_data->assets.GetTexture("Game Background"));

	// set score to 0
	_score = 0;
	hud->UpdateScore(_score);

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
				_wingSound.play();
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
			pipe->SpawnScoringPipe();
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
				clock.restart();
				_hitSound.play();
			}
		}

		// check for collision with the pipes
		std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
		for (int i = 0; i < pipeSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision2(bird->GetSrpite(), 0.625f, pipeSprites.at(i), 1.0f))		// have to play with the scaling
			{
				_gameState = GameStates::eGameOver;
				clock.restart();
				_hitSound.play();
			}
		}

		// check for collision with the scoring pipes
		if (GameStates::ePlaying == _gameState) {
			std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites();
			for (int i = 0; i < scoringSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision2(bird->GetSrpite(), 0.625f, scoringSprites.at(i), 1.0f))		// have to play with the scaling
				{
					_score++;
					hud->UpdateScore(_score);
					scoringSprites.erase(scoringSprites.begin() + i);
					_pointSound.play();
				}
			}
		}
		
	}

	if (GameStates::eGameOver == _gameState)
	{
		flash->Show(dt);
		if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
		{
			_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
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
	flash->Draw();
	hud->Draw();

	_data->window.display();
}


/**** not used ****/
GameState::~GameState()
{
}
