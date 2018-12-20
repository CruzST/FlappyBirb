#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"


class Pipe
{
public:
	Pipe(GameDataRef data);
	~Pipe();

	void DrawPipes();
	void SpawnBottomPipe();
	void SpawnTopPipe();
	void SpawnInvisiblePipe();
	void MovePipes(float dt);
	void RandomizePipeOffset();

private:
	GameDataRef _data;
	std::vector<sf::Sprite> pipeSprites;
	int _landHeight;
	int _pipeSpawnYOffset;
};

