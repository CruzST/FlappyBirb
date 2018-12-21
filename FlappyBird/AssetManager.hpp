#pragma once

#include <map>
#include <SFML\Graphics.hpp>

class AssetManager
{
public:
	AssetManager();													  // not used
	~AssetManager();												  // not used

	void LoadTexture(std::string name, std::string fileName);		  // name: name of the texture fileName: path of the texture
	sf::Texture &GetTexture(std::string name);						  // returns a texture reference, name: name of texture

	void LoadFont(std::string name, std::string fileName);			  // name: name of the Font fileName: path of the Font
	sf::Font &GetFont(std::string name);							  // returns a font reference, name: name of Font


private:
	std::map<std::string, sf::Texture> _textures;					  // string and a texture to a map
	std::map<std::string, sf::Font> _fonts;							  // string and a font to a map
};

