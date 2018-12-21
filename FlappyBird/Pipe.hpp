#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"


class Pipe
{
public:
	Pipe(GameDataRef data);
	~Pipe();													// not used

	void DrawPipes();
	void SpawnBottomPipe();
	void SpawnTopPipe();
	void SpawnInvisiblePipe();
	void MovePipes(float dt);
	void RandomizePipeOffset();
	const std::vector<sf::Sprite> &GetSprites() const;

private:
	GameDataRef _data;
	std::vector<sf::Sprite> _pipeSprites;
	int _landHeight;
	int _pipeSpawnYOffset;
};

