#include "Text.h"
#include "Game.h"

Text::Text(std::string pathToFolder, std::string text, int charSize, int xPos, int yPos, int choise) :
text(text)
{
	font.loadFromFile(pathToFolder);
	atext.setFont(font);
	atext.setCharacterSize(charSize);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::Blue);

	if (choise == 1) // Places text at top-left corner
		atext.setPosition(charSize / 5, charSize / 5);
	else if (choise == 2) // Places text at top-right corner
		atext.setPosition(Game::ScreenWidth - text.size()*  charSize, charSize / 5);
	else if (choise == 3) // Intended to be used with gameOver screen
		atext.setPosition((Game::ScreenWidth / 2) - text.size()* (charSize / 2), (Game::ScreenHeight / 5) * 4);
	else
		atext.setPosition(xPos, yPos);
}

Text::~Text()
{
}


void Text::drawScore(sf::RenderWindow& window, int appleScore)
{
	appleScoreCopy = appleScore;
	scoreString = text + std::to_string(appleScore);
	atext.setString(scoreString);
	window.draw(atext);
}

void Text::drawHighScore(sf::RenderWindow& window, bool IS_G_OVER_SCREEN)
{
	if (IS_G_OVER_SCREEN)
	{
		scoreStringCopy = "\t\t SCORE: " + std::to_string(appleScoreCopy) + "\n";
		if (NEW_HIGHSCORE)
		{
			scoreString = "NEW " + text + std::to_string(highScore) + "  !!!";
			NEW_HIGHSCORE = false;
			atext.setColor(sf::Color(rand() % 255 + 15, rand() % 255 + 15, rand() % 255 + 15));
		}
		else
			scoreString = scoreStringCopy + text + std::to_string(highScore);
	}
	else
		scoreString = text + std::to_string(highScore);

	atext.setString(scoreString);
	window.draw(atext);
}


void Text::resetScoreTimer()
{
	appleScoreCopy = 0;
}

void Text::setHighScore()
{
	if (highScore < appleScoreCopy)
	{
		highScore = appleScoreCopy;
		if (highScore > newHighScore)
		{
			NEW_HIGHSCORE = true;
			newHighScore = highScore;
		}
	}
}


int Text::appleScoreCopy = 0;
int Text::highScore = 0;
int Text::newHighScore = -1;
bool Text::NEW_HIGHSCORE = false;