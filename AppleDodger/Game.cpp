#include "Game.h"
#include "StartScreen.h"
#include "MainMenu.h"
#include "GameOverScreen.h"
#include "PlayerObject.h"
#include "AppleObject.h"

void Game::Start(void)
{
	if (gameState != Uninitialized)
		return;
	gameState = Game::ShowingStart;

	mainWindow.create(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "AppleDodger");

	init();
	while (!isExiting())
	{
		gameLoop();
	}
	mainWindow.close();
}

void Game::init()
{
	if (GAMEOVER)
	{
		gameObjectManager.remove("Player1");
		for (int i = 0; i < AppleCount; i++)
		{
			gameObjectManager.remove(appleNames[i]); // Removes appleObjects
		}
		appleNames.clear();
		GAMEOVER = false;

		PlayerObject::resetVelocity();
		AppleObject::scoreTracker = 0;

		Text::setHighScore();
		Text::resetScoreTimer();
	}

	PlayerObject *player1 = new PlayerObject("Player1"); // Creation of the playerObject
	player1->setPosition((ScreenWidth / 2), (ScreenHeight / 10) * 9);
	gameObjectManager.add("Player1", player1);

	for (int i = 0; i < AppleCount; i++) // Creation of appleObjects
	{
		appleNames.push_back(AppleObject::getIndexChar(i));
		AppleObject *apple = new AppleObject(AppleCount);
		apple->setStartingPosition();
		gameObjectManager.add(appleNames[i], apple);
	}
}

bool Game::isExiting()
{
	if (gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::gameLoop()
{
	sf::Event currentEvent;
	mainWindow.pollEvent(currentEvent);

	switch (gameState)
	{
	case Game::ShowingMenu:
	{
		showMenu();
		break;
	}
	case Game::ShowingStart:
	{
		showStartScreen();
		break;
	}
	case Game::ShowingGameOver:
	{
		showGameOverScreen();
		break;
	}
	case Game::Playing:
	{
		mainWindow.clear(sf::Color::Black);
		appleScore = AppleObject::scoreTracker;

		// Ugly way of doing collision detection between playerObject and appleObjects
		for (int i = 0; i < AppleCount; i++)
		{
			if (gameObjectManager.Get("Player1")->GetBoundingRect().intersects(gameObjectManager.Get(appleNames[i])->GetBoundingRect()))
				GAMEOVER = true;
		}

		gameObjectManager.updateAll();

		scoreText.drawScore(mainWindow, appleScore);
		highScoreText.drawHighScore(mainWindow, false);
		gameObjectManager.drawAll(mainWindow);

		mainWindow.display();

		if (currentEvent.type == sf::Event::Closed)
		{
			gameState = Game::Exiting;
		}
		if (currentEvent.type == sf::Event::KeyPressed)
		{
			if (currentEvent.key.code == sf::Keyboard::Escape)
			{
				GAMEOVER = true;
				init();
				gameState = Game::ShowingMenu;
			}
		}
		if (GAMEOVER)
		{
			gameState = Game::ShowingGameOver;
		}
		break;
	}
	}
}

void Game::showStartScreen()
{
	StartScreen startScreen;
	startScreen.Show(mainWindow);
	gameState = Game::ShowingMenu;
}

void Game::showMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		gameState = Exiting;
		break;
	case MainMenu::Play:
		gameState = Playing;
		break;
	}
}

void Game::showGameOverScreen()
{
	GameOverScreen gOverScreen;
	gOverScreen.Show(mainWindow);
	init();
	gameState = Game::ShowingMenu;
}


bool Game::GAMEOVER = false;
Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
GameObjectManager Game::gameObjectManager;

Text Game::scoreText("fonts/constan.ttf", "Score: ", 20, 0, 0, 2);
Text Game::highScoreText("fonts/constan.ttf", "HIGHSCORE: ", 20, 0, 0, 1);

const unsigned int Game::AppleCount = int(Game::ScreenWidth / 100); // Changes the amount of apples falling depending on screen width
unsigned int Game::appleScore;
std::vector<std::string> Game::appleNames = {};





