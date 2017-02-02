#include "StartScreen.h"
#include "Game.h"

void StartScreen::Show(sf::RenderWindow& renderWindow)
{
	texMgr.loadTexture("start", "sprites/startscreen.png");
	sprite.setTexture(texMgr.getRef("start"));

	// Resizing the menu image according to screen size
	sf::Vector2f targetSize(Game::ScreenWidth, Game::ScreenHeight);
	sprite.setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}

