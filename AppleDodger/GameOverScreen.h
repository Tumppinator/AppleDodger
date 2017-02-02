#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H
#include "TextureManager.h"

class GameOverScreen
{
public:
	GameOverScreen();
	~GameOverScreen();

	void Show(sf::RenderWindow& renderWindow);

private:
	TextureManager texMgr;
	sf::Sprite sprite;
};

#endif
