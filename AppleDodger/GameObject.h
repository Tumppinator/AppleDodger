#ifndef GameObject_H
#define GameObject_H
#include "TextureManager.h"

class Game;

class GameObject
{
public:

	GameObject();
	virtual ~GameObject(void);

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual void setRandXPosition();

	virtual sf::Vector2f GetPosition() const;
	virtual sf::Rect<float> GetBoundingRect() const;
	virtual float GetWidth() const;
	virtual float GetHeight() const;

protected:
	sf::Sprite& getSprite();

private:
	sf::Sprite sprite;
	TextureManager texMgr;
	float randXpos;
};

#endif