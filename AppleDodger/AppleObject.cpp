#include "AppleObject.h"
#include "Game.h"

AppleObject::AppleObject(int apples) :
RUN_YET(false),
appleCount(apples),
velocity(600.0f),
SpeedRate(3.50f)
{
	load("sprites/apple.png");
	if (countingAppleCount == 0)
		tempChar = "";
}

AppleObject::~AppleObject()
{
}


void AppleObject::update(float elapsedTime)
{
	if (RUN_YET == false)
	{
		RUN_YET = true;
		velocityTracker = velocity;
	}
	else
	{
		timeSinceStart += elapsedTime;
		if (timeSinceStart > SpeedRate)
		{
			velocityTracker += 1;
			timeSinceStart = 0;
		}

		sf::Vector2f pos = this->GetPosition();
		if (pos.y > Game::ScreenHeight)
		{
			this->setRandXPosition(); // AppleObject spawns at random x-position just above the screen
			scoreTracker += 1;
			velocity = velocityTracker;
		}
		getSprite().move(0, velocity * elapsedTime);
	}
}

void AppleObject::setStartingPosition()
{
	randXpos = rand() % Game::ScreenWidth + 1;
	startYpos += Game::ScreenHeight / appleCount;
	getSprite().setPosition(randXpos, startYpos);
	countingAppleCount += 1;
	if (countingAppleCount == appleCount - 1)
	{
		startYpos = -Game::ScreenHeight;
		countingAppleCount = 0;
	}
}

std::string AppleObject::getIndexChar(int i)
{
	tempChar += _A_char;
	return tempChar;
}


int AppleObject::scoreTracker = 0;
int AppleObject::countingAppleCount = 0;

float AppleObject::startYpos = -Game::ScreenHeight;
float AppleObject::timeSinceStart = 0;
float AppleObject::velocityTracker = 0;

std::string AppleObject::tempChar = "";
std::string AppleObject::_A_char = "A";
