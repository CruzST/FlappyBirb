#pragma once

#include <map>
#include <SFML\Graphics.hpp>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void LoadTexture(std::string name, std::string fileName);	// name: name of the texture fileName: path of the texture
	sf::Texture &GetTexture(std::string name);	// name: name of texture

	void LoadFont(std::string name, std::string fileName);	// name: name of the Font fileName: path of the Font
	sf::Font &GetFont(std::string name);	// name: name of Font


private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
};

