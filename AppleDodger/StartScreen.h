#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "TextureManager.h"

class StartScreen
{
public:
	void Show(sf::RenderWindow& window);

private:
	sf::Sprite sprite;
	TextureManager texMgr;
};

#endif