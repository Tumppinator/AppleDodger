#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameObjectManager.h"
#include "Text.h"
#include <vector>

class Game
{
public:
	static bool GAMEOVER;
	static void Start();

	static const int ScreenWidth = 1366;
	static const int ScreenHeight = 768;

private:
	static void init(); // Used for initializing values before entering the "Playing" gamestate
	static bool isExiting();
	static void gameLoop();

	static void showStartScreen();
	static void showMenu();
	static void showGameOverScreen();

	enum GameState { Uninitialized, ShowingStart, Paused, ShowingMenu, Playing, ShowingGameOver, Exiting };

	static GameState gameState;
	static sf::RenderWindow mainWindow;
	static GameObjectManager gameObjectManager;

	static Text scoreText;
	static Text highScoreText;

	static const unsigned int AppleCount;
	static unsigned int appleScore;
	static std::vector<std::string> appleNames;
};

#endif
