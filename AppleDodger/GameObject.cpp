#include "GameObject.h"
#include "Game.h"

GameObject::GameObject()
{
}

GameObject::~GameObject(void)
{
}


void GameObject::load(std::string filename)
{
	texMgr.loadTexture("rect", filename);
	sprite.setTexture(texMgr.getRef("rect"));
}

void GameObject::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(sprite);
}

void GameObject::update(float elapsedTime)
{
}


void GameObject::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void GameObject::setRandXPosition()
{
	randXpos = rand() % Game::ScreenWidth - GetWidth() + 1;
	sprite.setPosition(randXpos, -GetHeight());
}


sf::Vector2f GameObject::GetPosition() const
{
	return sprite.getPosition();
}

float GameObject::GetWidth() const
{
	return sprite.getLocalBounds().width;
}

float GameObject::GetHeight() const
{
	return sprite.getLocalBounds().height;
}

sf::Rect<float> GameObject::GetBoundingRect() const
{
	return sprite.getGlobalBounds();
}


sf::Sprite& GameObject::getSprite()
{
	return sprite;
}

