#include "MainMenuState.hpp"

#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>


MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

/*
	Function will initialize the elements that make up the main menu.
*/
void MainMenuState::Init()
{
	// Load the textures and assign them to a string?
	_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
	_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

	// Set the loaded textures to the class members of MainMenuState
	_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
	_title.setTexture(this->_data->assets.GetTexture("Game Title"));
	_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

	// Reposition the title and the button
	_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
	_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));

}


/*
	Inputs that are specific to the main menu
*/
void MainMenuState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		// if X is clicked
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		// if play button is pressed
		if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "go to game" << std::endl;
		}
	}
}

void MainMenuState::Update(float dt)
{

}


void MainMenuState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_title);
	_data->window.draw(_playButton);
	_data->window.display();
}



// not used
MainMenuState::~MainMenuState()
{
}
