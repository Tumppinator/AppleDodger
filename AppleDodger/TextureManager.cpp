#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}


void TextureManager::loadTexture(const std::string &name, const std::string &filename)
{
	sf::Texture teksi;
	teksi.loadFromFile(filename);
	this->textures[name] = teksi;

	return;
}

sf::Texture &TextureManager::getRef(const std::string &texture)
{
	return this->textures.at(texture);
}