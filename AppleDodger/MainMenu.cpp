#include "MainMenu.h"
#include "Game.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	texMgr.loadTexture("menu", "sprites/mainmenu.png");
	sprite.setTexture(texMgr.getRef("menu"));

	// Resizing the menu image according to screen size
	sf::Vector2f targetSize(Game::ScreenWidth, Game::ScreenHeight);
	sprite.setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	unsigned int tempHeight = Game::ScreenHeight;

	// Setup clickable regions	

	// Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = (tempHeight / 6) * 2;
	playButton.rect.left = 0;
	playButton.rect.width = Game::ScreenWidth;
	playButton.rect.height = tempHeight / 6;
	playButton.action = Play;

	// Exit menu item coordinates 
	MenuItem exitButton;
	exitButton.rect.top = (tempHeight / 6) * 3;
	exitButton.rect.left = 0;
	exitButton.rect.width = Game::ScreenWidth;
	exitButton.rect.height = tempHeight / 6;
	exitButton.action = Exit;

	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = menuItems.begin(); it != menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = it->rect;
		if (x > menuItemRect.left
			&& x < menuItemRect.left + menuItemRect.width
			&& y > menuItemRect.top
			&& y < menuItemRect.height + menuItemRect.top)
		{
			return it->action;
		}
	}
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
