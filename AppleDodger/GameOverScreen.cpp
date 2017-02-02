#include "GameOverScreen.h"
#include "Game.h"
#include "Text.h"

GameOverScreen::GameOverScreen()
{
}

GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::Show(sf::RenderWindow& renderWindow)
{
	Text highScoreText("fonts/constan.ttf", "HIGHSCORE: ", 30, 0, 0, 3);

	texMgr.loadTexture("over", "sprites/gameover.png");
	sprite.setTexture(texMgr.getRef("over"));

	// Resizing the menu image according to screen size
	sf::Vector2f targetSize(Game::ScreenWidth, Game::ScreenHeight);
	sprite.setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	renderWindow.draw(sprite);
	highScoreText.setHighScore();
	highScoreText.drawHighScore(renderWindow, true);
	renderWindow.display();

	sf::Event event;
	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;

			if (event.type == sf::Event::Closed || event.type == sf::Event::MouseButtonPressed)
				return;
		}
	}
	Game::GAMEOVER = false;
}

