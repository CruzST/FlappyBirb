#pragma once

#include <map>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class AssetManager
{
public:
	AssetManager();													  // not used
	~AssetManager();												  // not used

	void LoadTexture(std::string name, std::string fileName);		  // name: name of the texture fileName: path of the texture
	sf::Texture &GetTexture(std::string name);						  // returns a texture reference, name: name of texture

	void LoadFont(std::string name, std::string fileName);			  // name: name of the Font fileName: path of the Font
	sf::Font &GetFont(std::string name);							  // returns a font reference, name: name of Font


	/*
	void LoadSoundBuffer(std::string name, std::string fileName);			  // name: name of the Font fileName: path of the Sound file
	sf::SoundBuffer &GetSoundBuffer(std::string name);
	*/

private:
	std::map<std::string, sf::Texture> _textures;					  // string and a texture to a map
	std::map<std::string, sf::Font> _fonts;							  // string and a font to a map
	
	
	//std::map<std::string, sf::SoundBuffer> _soundBuffers;			// string and a sound buffer to a map
	
};

