#ifndef Text_H
#define Text_H
#include <SFML/Graphics.hpp>
#include <string>

class Text
{
public:
	Text(std::string pathToFolder, std::string text, int charSize, int xPos, int yPos, int choise);
	~Text();

	void drawScore(sf::RenderWindow& window, int appleScore);
	void drawHighScore(sf::RenderWindow& window, bool IS_G_OVER_SCREEN); // False boolean value used for showing default highScore text, and true for alternative version

	static void resetScoreTimer();
	static void setHighScore();

private:
	static bool NEW_HIGHSCORE;
	static int appleScoreCopy;
	static int highScore;
	static int newHighScore;

	int charSize;
	sf::Text atext;
	sf::Font font;

	std::string text;
	std::string scoreString;
	std::string scoreStringCopy;
	sf::RenderWindow window;
};

#endif