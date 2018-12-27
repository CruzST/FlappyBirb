#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

class HUD
{
public:
	HUD(GameDataRef data);
	void Draw();
	void UpdateScore(int score);
	
	~HUD();												// not used

private:
	GameDataRef _data;
	sf::Text _scoreText;

};

