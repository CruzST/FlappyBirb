#include "AssetManager.hpp"


/*
	Inputs: string name, filepath
	Function takes in inputs, and assigns it to the map of texture/string
*/
void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName))
	{
		this->_textures[name] = tex;
	}
}

/*
	Inputs: string name
	Function will return a texture depending on the name passed
*/
sf::Texture &AssetManager::GetTexture(std::string name)
{
	return this->_textures.at(name);
}

/*
	Inputs: string name, filepath
	Function takes in inputs, and assigns it to the map of font/string
*/
void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName))
	{
		this->_fonts[name] = font;
	}
}

/*
	Inputs: string name
	Function will return a font depending on the name passed
*/
sf::Font &AssetManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}

/********* Not used **********/
AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}
