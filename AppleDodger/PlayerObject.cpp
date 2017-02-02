#include "PlayerObject.h"
#include "AppleObject.h"
#include "Game.h"
#include <iostream>

PlayerObject::PlayerObject(std::string Pname) :
velocity(0.0f),
playerName(Pname),
maxVelocity(800.0f),
rotRate(0.0f),
SpeedRate(7.0f),
RUN_YET(false)
{
	load("sprites/android.png");

	getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2); // Sets the playerObjects origin to the center of the sprite
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::update(float elapsedTime)
{
	if (RUN_YET == false)
		RUN_YET = true;
	else
	{
		timeSinceStart += elapsedTime;
		if (timeSinceStart > SpeedRate)
		{
			velocityTracker += 1.0f;
			timeSinceStart = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ARROW_UP = true;
			velocity -= velocityTracker;
			if (ROT_L)
			{
				ROT_R = true;
				rotRate += 0.00023f;
				getSprite().rotate(-rotRate);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ARROW_UP = true;
			velocity += velocityTracker;
			if (ROT_R)
			{
				ROT_L = true;
				rotRate += 0.00023f;
				getSprite().rotate(rotRate);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ARROW_UP)
		{
			ARROW_UP = false;
			AppleObject::scoreTracker -= 10; // If ARROW_UP == true decrease score count by 10
			rotAngle = getSprite().getRotation();
			getSprite().rotate(-rotAngle);
			velocity = 0;
		}

		if (velocity > maxVelocity)
			velocity = maxVelocity;
		if (velocity < -maxVelocity)
			velocity = -maxVelocity;

		sf::Vector2f pos = this->GetPosition();

		if ((pos.x < GetWidth() / 2 || pos.x >(Game::ScreenWidth - GetWidth() / 2)) && CHECK_SIGN) // If CHECK_SIGN is false it means player position is still outside of the defined bounds which means the block below if-statement will be ignored
		{
			velocity = -velocity;// Bounce the current velocity in opposite direction

			rotAngle = getSprite().getRotation();
			if (rotAngle > 307.0f && rotAngle < 310.0f)
				getSprite().setRotation(-(rotAngle + 1));
			else if (rotAngle > 50.0f && rotAngle < 53.0f)
				getSprite().setRotation(-(rotAngle - 1));
			else
				getSprite().setRotation(-rotAngle);

			CHECK_SIGN = false;
		}

		if (pos.x > GetWidth() / 2 && pos.x < (Game::ScreenWidth - GetWidth() / 2))
			CHECK_SIGN = true;

		rotAngle = getSprite().getRotation();
		if ((rotAngle < 360.0f && rotAngle > 310.0f) || (rotAngle >= 0 && rotAngle < 50.0f))
		{
			ROT_L = true;
			ROT_R = true;
		}
		else if (rotAngle > 307.0f && rotAngle < 310.0f)
		{
			ROT_L = false;
		}
		else if (rotAngle > 50.0f && rotAngle < 53.0f)
		{
			ROT_R = false;
		}

		getSprite().move(velocity * elapsedTime, 0);
	}
}

void PlayerObject::resetVelocity()
{
	velocityTracker = 3.0f;
}

bool PlayerObject::ARROW_UP = false;
bool PlayerObject::ROT_L = true;
bool PlayerObject::ROT_R = true;
float PlayerObject::velocityTracker = 3;
