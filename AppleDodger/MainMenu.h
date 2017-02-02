#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
#include <list>

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);
private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);

	TextureManager texMgr;
	sf::Sprite sprite;
	std::list<MenuItem> menuItems;
};

#endif