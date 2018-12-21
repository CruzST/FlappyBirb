#include "SplashState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "MainMenuState.hpp"

/*
	Doesn't do anything but pass it the data from game.hpp
*/
SplashState::SplashState(GameDataRef data) : _data(data)
{

}


/*
	Init the splash screen
*/
void SplashState::Init()
{
	std::cout << "Initializing Splash State" << std::endl;
	_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
}


/*
	Only input allowed on the splash screen is the X window
*/
void SplashState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}
	}
}


/*
	Upon updating, it will be sent to the main menu state
*/
void SplashState::Update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() >= SPLASH_STATE_SHOW_TIME)
	{
		_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
	}
}


/*
	Draw the items to the splash
*/
void SplashState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}


/**** not used ****/
SplashState::~SplashState()
{
}
